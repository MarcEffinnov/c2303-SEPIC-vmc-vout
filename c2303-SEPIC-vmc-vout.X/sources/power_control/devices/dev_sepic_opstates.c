/*
 * File:   dev_sepic_opstates.c
 * Author: M91406
 * Created on October 9, 2020, 9:16 AM
 */


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer data types
#include <stdbool.h> // include standard boolean data types

#include "dev_sepic_pconfig.h" // include SEPIC converter
#include "dev_sepic_typedef.h" // include SEPIC converter data object declarations
#include "dev_sepic_substates.h" // include state machine sub-state declarations
#include "dev_sepic_special_functions.h" // include SEPIC converter special function declarations


// Private function prototypes of state functions

volatile uint16_t State_Error(volatile CSEPIC_CONVERTER_t *csepicInstance);
volatile uint16_t State_Initialize(volatile CSEPIC_CONVERTER_t *csepicInstance);
volatile uint16_t State_Reset(volatile CSEPIC_CONVERTER_t *csepicInstance);
volatile uint16_t State_Standby(volatile CSEPIC_CONVERTER_t *csepicInstance);
volatile uint16_t State_RampUp(volatile CSEPIC_CONVERTER_t *csepicInstance);
volatile uint16_t State_Online(volatile CSEPIC_CONVERTER_t *csepicInstance);

// Declaration of function pointer array listing op-state functions in order of execution
volatile uint16_t (*csepicConverterStateMachine[])(volatile CSEPIC_CONVERTER_t *csepicInstance) = 
{
    State_Error,        ///< State #0: That's the blank "undefined default state", causing the state machine to reset
    State_Initialize,   ///< State #1: Initialize state machine by resetting all runtime flags to default
    State_Reset,        ///< State #2: Reset key runtime flags when power converter was already turned on
    State_Standby,      ///< State #3: After successful initialization, power converter waits to be launched
    State_RampUp,       ///< State #4: Topology-specific startup sub-states are handled in Ramp-Up function
    State_Online        ///< State #5: During normal operation the converter responds to changes in reference
};

// Declaration variable capturing the size of the sub-state function pointer array 
volatile uint16_t csepicStateList_size = (sizeof(csepicConverterStateMachine)/sizeof(csepicConverterStateMachine[0])); 

/*******************************************************************************
 * @fn uint16_t State_Initialize(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-state-machine-functions
 * @brief   This function resets the counters and conditional flag bits.
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 *
 * @details
 * If the controller has not been run yet, the POWER ON and POWER GOOD delay
 * counters are reset and all conditional flag bits are cleared. Status of 
 * power source, ADC and current sensor calibration have to be set during
 * runtime by system check routines. 
 *********************************************************************************/
volatile uint16_t State_Initialize(volatile CSEPIC_CONVERTER_t *csepicInstance)
{
    volatile uint16_t _i=0;
    
    csepicInstance->startup.power_on_delay.counter = 0;   // Reset power on counter
    csepicInstance->startup.power_good_delay.counter = 0; // Reset power good counter

    // Reset all status bits
    csepicInstance->status.bits.adc_active = false;

    // Initiate current sensor calibration flag bit
    if (csepicInstance->set_values.control_mode == CSEPIC_CONTROL_MODE_VMC)
        csepicInstance->status.bits.cs_calib_complete = true; 
    else if (csepicInstance->status.bits.cs_calib_enable)
        csepicInstance->status.bits.cs_calib_complete = false; 
    else 
        csepicInstance->status.bits.cs_calib_complete = true; 
    
    // Disable control loops
    switch (csepicInstance->set_values.control_mode)
    {
        case CSEPIC_CONTROL_MODE_VMC:
            csepicInstance->v_loop.controller->status.bits.enabled = false; // Disable voltage loop
            
            break;
        case CSEPIC_CONTROL_MODE_ACMC:
            csepicInstance->v_loop.controller->status.bits.enabled = false; // Disable voltage loop
            for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {
            csepicInstance->i_loop[_i].controller->status.bits.enabled = false; // Disable current loop
            }
            break;
        case CSEPIC_CONTROL_MODE_CCMC:
            for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {
            csepicInstance->i_loop[_i].controller->status.bits.enabled = false; // Disable current loop
            }
        default:
            
            break;
    }
    
    // Clear busy bit
    csepicInstance->status.bits.busy = false; // Clear BUSY bit
    csepicInstance->status.bits.ready = true; // Set READY bit indicating state machine has passed INITIALIZED state
    
    // Transition to STATE_RESET
    return(CSEPIC_OPSRET_COMPLETE); 
    
}

/*******************************************************************************
 * @fn uint16_t State_Reset(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-state-machine-functions
 * @brief   This function resets the SEPIC control operation by re-initiating the control mode,
 * references and status bits. 
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 * 
 * @details
 * After successful initialization or after an externally triggered state machine reset,
 * the state machine returns to this RESET mode, re-initiating control mode, references 
 * and status bits before switching further into STANDBY mode. 
 *********************************************************************************/
volatile uint16_t State_Reset(volatile CSEPIC_CONVERTER_t *csepicInstance)
{
    volatile uint16_t retval=1;
    volatile uint16_t _i=0;

    // Disable all PWM outputs & control loops (immediate power cut-off)
    retval &= csepicPWM_Suspend(csepicInstance); // Disable PWM outputs
    
    switch (csepicInstance->set_values.control_mode)
    {
        case CSEPIC_CONTROL_MODE_VMC:
            // Disable voltage loop controller and reset control loop histories
            csepicInstance->v_loop.controller->status.bits.enabled = false; // disable voltage control loop
            csepicInstance->v_loop.ctrl_Reset(csepicInstance->v_loop.controller); // Reset control histories of outer voltage controller
            *csepicInstance->v_loop.controller->Ports.Target.ptrAddress = csepicInstance->v_loop.controller->Limits.MinOutput;
            break;
        case CSEPIC_CONTROL_MODE_ACMC:
            // Disable voltage loop controller and reset control loop histories
            csepicInstance->v_loop.controller->status.bits.enabled = false; // disable voltage control loop
            csepicInstance->v_loop.ctrl_Reset(csepicInstance->v_loop.controller); // Reset control histories of outer voltage controller
            *csepicInstance->v_loop.controller->Ports.Target.ptrAddress = csepicInstance->v_loop.controller->Limits.MinOutput;
            // Disable current loop controller and reset control loop histories
            for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {
            csepicInstance->i_loop[_i].controller->status.bits.enabled = false; 
            csepicInstance->i_loop[_i].ctrl_Reset(csepicInstance->i_loop[_i].controller); 
            *csepicInstance->i_loop[_i].controller->Ports.Target.ptrAddress = csepicInstance->i_loop[_i].controller->Limits.MinOutput;
            }
            break;
        case CSEPIC_CONTROL_MODE_CCMC:
            // Disable current loop controller and reset control loop histories
            for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {
            csepicInstance->i_loop[_i].controller->status.bits.enabled = false; 
            csepicInstance->i_loop[_i].ctrl_Reset(csepicInstance->i_loop[_i].controller); 
            *csepicInstance->i_loop[_i].controller->Ports.Target.ptrAddress = csepicInstance->i_loop[_i].controller->Limits.MinOutput;
            }
        default:
            break;
    }
    
    // Reset the bulk voltage settling counters
    csepicInstance->startup.power_on_delay.counter = 0; // Clear Power On Delay counter
    csepicInstance->startup.power_good_delay.counter = 0; // Clear Power Good Delay counter

    // Reset all status bits
    csepicInstance->status.bits.adc_active = false;
    csepicInstance->status.bits.busy = false; // Clear BUSY bit
    
    // If any sub-function call went unsuccessful, reset state machine
    // else, move on to next state
    
    if (retval)
        return(CSEPIC_OPSRET_COMPLETE);
    else
        return(CSEPIC_OPSRET_ERROR);
    
}
                
/*******************************************************************************
 * @fn uint16_t State_Standby(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-state-machine-functions
 * @brief   This function waits until all start-up conditions are met.
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 * 
 * @details
 * After a successful state machine reset, the state machine waits in  
 * STANDBY mode until all conditional flag bits are set/cleared allowing  
 * the converter to run.
 *********************************************************************************/
volatile uint16_t State_Standby(volatile CSEPIC_CONVERTER_t *csepicInstance)
{
    volatile uint16_t retval=0;

    // if the 'autorun' option is set, automatically set the GO bit when the 
    // converter is enabled
    if ((csepicInstance->status.bits.enabled) && (csepicInstance->status.bits.autorun))
    { csepicInstance->status.bits.GO = true; }

    // If current sense feedback offset calibration is enabled, 
    // call calibration sub-state routine
    retval = dev_csepicConverter_SpecialFunctionExecute(csepicInstance, CS_OFSET_CALIBRATION);
        
    switch (retval)
    {
        case CSEPIC_OPSRET_COMPLETE:
            csepicInstance->status.bits.cs_calib_complete = true; // Set CS Calibration Flag to COMPLETE
            csepicInstance->status.bits.busy = false; // Clear BUSY bit indicating on-going activity
            break;
        case CSEPIC_OPSRET_REPEAT:
            csepicInstance->status.bits.cs_calib_complete = false; // Set CS Calibration Flag to COMPLETE
            csepicInstance->status.bits.busy = true; // Set BUSY bit indicating on-going activity
            return(CSEPIC_OPSRET_REPEAT);
            break;
        default:
            csepicInstance->status.bits.cs_calib_complete = false; // Set CS Calibration Flag to COMPLETE
            csepicInstance->status.bits.busy = false; // Clear BUSY bit indicating on-going activity
            return(CSEPIC_OPSRET_ERROR);
            break;
    }

    // Wait for all startup conditions to be met
    if ((csepicInstance->status.bits.enabled) &&          // state machine needs to be enabled
        (csepicInstance->status.bits.GO) &&               // GO-bit needs to be set
        (csepicInstance->status.bits.adc_active) &&       // ADC needs to be running
        (csepicInstance->status.bits.pwm_active) &&       // PWM needs to be running 
        (!csepicInstance->status.bits.fault_active) &&    // No active fault is present
        (!csepicInstance->status.bits.suspend) &&         // Power supply is not held in suspend mode
        (csepicInstance->status.bits.cs_calib_complete)   // Current Sensor Calibration complete
        )
    {
        csepicInstance->status.bits.GO = false;
        return(CSEPIC_OPSRET_COMPLETE);
    }
    else
    // Remain in current state until bit-test becomes true
    {
        return(CSEPIC_OPSRET_REPEAT);
    }
    
}

/*******************************************************************************
 * @fn uint16_t State_RampUp(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-state-machine-functions
 * @brief   This function ramps up the voltage/input to its nominal value
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  0 = CSEPIC_OPSRET_REPEAT
 * @return  1 = CSEPIC_OPSRET_COMPLETE
 * @return  2 = CSEPIC_OPSRET_REPEAT
 *
 * @details
 * After a successful state machine Standby, the state machine executes the RAMPUP 
 * mode. In this mode, the voltage/current ramps up to the nominal value.  
 *********************************************************************************/

volatile uint16_t State_RampUp(volatile CSEPIC_CONVERTER_t *csepicInstance)
{
    volatile uint16_t retval=0;
    
    // If sub-state pointer index is out of range, reset to ZERO
    if ((uint16_t)(csepicInstance->state_id.bits.substate_id) >= (uint16_t)(csepicRampUpSubStateList_size))
        csepicInstance->state_id.bits.substate_id = 0;
    
    // If selected sub-state index contains a NULL-pointer, exit here
    if (csepicConverterRampUpSubStateMachine[csepicInstance->state_id.bits.substate_id] == NULL)
        return(CSEPIC_OPSRET_ERROR);
    
    // Execute ramp-up sub-state
    retval = csepicConverterRampUpSubStateMachine[csepicInstance->state_id.bits.substate_id](csepicInstance);
    
    // Validate sub-state function return
    switch (retval) 
    {   
        // If the sub-state returns a REPEAT, leave the sub-state pointer at the recent 
        // index and return REPEAT to the outer state machine to call State_RampUp again
        case CSEPIC_OPSRET_REPEAT:
            
            retval = CSEPIC_OPSRET_REPEAT;
            
            break;

        // If the sub-state returns a COMPLETE, increment the sub-state pointer to call the 
        // next sub-state next time and return REPEAT to the outer state machine to call
        // State_RampUp again
        case CSEPIC_OPSRET_COMPLETE:

            // Increment sub-state pointer by one tick
            csepicInstance->state_id.bits.substate_id++;
            
            // CHeck if pointer is out of range
            if ((uint16_t)(csepicInstance->state_id.bits.substate_id) < (uint16_t)(csepicRampUpSubStateList_size))
            { // if execution list is not complete yet, return op-state as REPEAT
                retval = CSEPIC_OPSRET_REPEAT;
                
                if (csepicInstance->state_id.bits.substate_id == CSEPIC_OPSTATE_I_RAMP_UP)
                { // if the next state is set to "I Ramp-Up", check if converter supports
                  // this sub-state in its current configuration and step over it if not 
                    switch (csepicInstance->set_values.control_mode)
                    {
                        case CSEPIC_CONTROL_MODE_VMC:
                            csepicInstance->state_id.bits.substate_id++; // Increment sub-state pointer to bypass I_RAMP_UP inner loop        
                            break;
                        case CSEPIC_CONTROL_MODE_ACMC:
                            // Jump to I_RAMP_UP sub-state
                            break;
                        case CSEPIC_CONTROL_MODE_CCMC:
                            csepicInstance->state_id.bits.substate_id++; // Increment sub-state pointer to bypass I_RAMP_UP inner loop as i loop is outter loop    
                            break;
                        default:
                            break;
                    }
                }
            }
            else
            {
            // if last item of execution list is complete. return op-state as COMPLETE
                retval = CSEPIC_OPSRET_COMPLETE;
            }
            
            break;

        // If the sub-state returns any other value, something went wrong. In this case
        // return ERROR to outer state machine triggering a main state machine reset.
        default:
            // if any other return value is received, switch immediately to ERROR
            retval = CSEPIC_OPSRET_ERROR;        
            
            break;
    }
    
    return(retval);
}

/*******************************************************************************
 * @fn uint16_t State_Online(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-state-machine-functions
 * @brief   This function tunes the controller reference to the new user control reference level.
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 * 
 * @details
 * After soft-start and when state POWER_GOOD_DELAY has expired, the converter 
 * enters normal operation.
 * 
 * During normal operation the state machine scans the user reference setting. 
 * Once a change between the user reference setting and the most recent controller 
 * reference has been detected, the state machine will tune the controller 
 * reference to the new user control reference level in incremental steps,
 * applying the same ramp slope as during soft-start.
 * 
 * While ramping the output voltage up or down, the BUSY bit will be set and any 
 * new changes to the reference will be ignored until the ramp up/down is complete.
 *********************************************************************************/

volatile uint16_t State_Online(volatile CSEPIC_CONVERTER_t *csepicInstance)
{
    volatile uint16_t _i=0;
    
    if (csepicInstance->set_values.control_mode == CSEPIC_CONTROL_MODE_CCMC)   
    {
        // Output current regulated mode (CCMC)
        if(csepicInstance->set_values.i_ref != csepicInstance->i_loop[0].reference) 
        {
            // Set the BUSY bit indicating a delay/ramp period being executed
            csepicInstance->status.bits.busy = true;

            // New reference value is less than controller reference value => ramp down
            if (csepicInstance->set_values.i_ref < csepicInstance->i_loop[0].reference){
                // decrement reference until new reference level is reached
                // Parse all current phases
                for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {
                    csepicInstance->i_loop[_i].reference -= csepicInstance->set_values.i_slew_rate; // decrement reference; 
                    if(csepicInstance->i_loop[_i].reference < csepicInstance->set_values.i_ref) { // check if ramp is complete
                        csepicInstance->i_loop[_i].reference = csepicInstance->set_values.i_ref; // clamp reference level to setting
                    }
                }
            }
            // New reference value is greater than controller reference value => ramp up
            else if (csepicInstance->set_values.i_ref > csepicInstance->i_loop[0].reference){
                // increment reference until new reference level is reached
                // Parse all current phases
                for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {
                    csepicInstance->i_loop[_i].reference += csepicInstance->set_values.i_slew_rate; // decrement reference; 
                    if(csepicInstance->i_loop[_i].reference > csepicInstance->set_values.i_ref) { // check if ramp is complete
                        csepicInstance->i_loop[_i].reference = csepicInstance->set_values.i_ref; // clamp reference level to setting
                    }
                }
            }
        }
        else
        {
            // Clear the BUSY bit indicating "no state machine activity"
            csepicInstance->status.bits.busy = false;
        }   
    } else
    {
        // Output voltage regulated mode (ACMC, VMC ...)
        if(csepicInstance->set_values.v_ref != csepicInstance->v_loop.reference) 
        {
            // Set the BUSY bit indicating a delay/ramp period being executed
            csepicInstance->status.bits.busy = true;

            // New reference value is less than controller reference value => ramp down
            if(csepicInstance->set_values.v_ref < csepicInstance->v_loop.reference){
                // decrement reference until new reference level is reached
                csepicInstance->v_loop.reference -= csepicInstance->set_values.v_slew_rate; // decrement reference
                if(csepicInstance->v_loop.reference < csepicInstance->set_values.v_ref) { // check if ramp is complete
                    csepicInstance->v_loop.reference = csepicInstance->set_values.v_ref; // clamp reference level to setting
                }

            }
            // New reference value is greater than controller reference value => ramp up
            else if(csepicInstance->set_values.v_ref > csepicInstance->v_loop.reference){
                // increment reference until new reference level is reached
                csepicInstance->v_loop.reference += csepicInstance->set_values.v_slew_rate; // increment reference
                if(csepicInstance->v_loop.reference > csepicInstance->set_values.v_ref) { // check if ramp is complete
                    csepicInstance->v_loop.reference = csepicInstance->set_values.v_ref; // clamp reference level to setting
                }

            }

        }
        else
        {
            // Clear the BUSY bit indicating "no state machine activity"
            csepicInstance->status.bits.busy = false;
        }
    }

    // remain in STATE_ONLINE
    return(CSEPIC_OPSRET_REPEAT);
    
}

/*******************************************************************************
 * @fn uint16_t State_Error(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-state-machine-functions
 * @brief   If this function is called, the state machine is reset to INITIALIZE (URL=@ref State_Initialize).
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 * 
 * @details
 * This function is a default anchor in case task list index #0 is ever called.
 * This is the equivalent of a switch case "default".
 *********************************************************************************/
volatile uint16_t State_Error(volatile CSEPIC_CONVERTER_t* csepicInstance)
{
    volatile uint16_t retval=0;
    
    // If this function is ever called, bring state machine back on track 
    // by resetting it to INITIALIZE
    
    retval = csepicPWM_Suspend(csepicInstance);             // Hold PWM output (turning off power)
    csepicInstance->status.bits.busy = false;             // Reset busy bit

    if(retval)
        retval = CSEPIC_OPSRET_COMPLETE;
    else
        retval = CSEPIC_OPSRET_ERROR;

    
    return(retval);
}


// ______________________________________
// end of file
