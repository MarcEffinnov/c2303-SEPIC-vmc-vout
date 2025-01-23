/* 
 * File:   dev_sepic_substates.c
 * Author: M91406
 * Comments: SEPIC converter operation sub-states header file
 * Revision history: 
 *   10/28/20   1.0  initial version
 */

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer data types
#include <stdbool.h> // include standard boolean data types

#include "dev_sepic_pconfig.h" // include SEPIC converter
#include "dev_sepic_typedef.h" // include SEPIC converter data object declarations

// Private function prototypes of sub-state functions
volatile uint16_t SubState_PowerOnDelay(volatile CSEPIC_CONVERTER_t *csepicInstance);
volatile uint16_t SubState_PrepareRampUp(volatile CSEPIC_CONVERTER_t *csepicInstance);
volatile uint16_t SubState_RampUpStart(volatile CSEPIC_CONVERTER_t *csepicInstance);
volatile uint16_t SubState_RampUp(volatile CSEPIC_CONVERTER_t *csepicInstance);
volatile uint16_t SubState_IRampUp(volatile CSEPIC_CONVERTER_t *csepicInstance);
volatile uint16_t SubState_PowerGoodDelay(volatile CSEPIC_CONVERTER_t *csepicInstance);


// Declaration of function pointer array listing sub-state functions in order of execution
volatile uint16_t (*csepicConverterRampUpSubStateMachine[])(volatile CSEPIC_CONVERTER_t *csepicInstance) = 
{
    SubState_PowerOnDelay,      ///< Sub-State #0: Wait programmed number of state machine ticks until startup is triggered
    SubState_PrepareRampUp,    ///< Sub-State #1: Determine ramp up condition, pre-charge controllers and program PWM/Peripherals
    SubState_RampUpStart,      ///< Sub-State #2: Output voltage ramp up start
    SubState_RampUp,           ///< Sub-State #3: Output voltage ramp up
    SubState_IRampUp,           ///< Sub-State #4: Output current ramp up (optional, for startup current limiting only)
    SubState_PowerGoodDelay     ///< Sub-State #5: Wait until power good delay has expired and optionally set a GPIO
};

// Declaration variable capturing the size of the sub-state function pointer array 
volatile uint16_t csepicRampUpSubStateList_size = (sizeof(csepicConverterRampUpSubStateMachine)/sizeof(csepicConverterRampUpSubStateMachine[0])); 

/***********************************************************************************
 * @fn      uint16_t SubState_PowerOnDelay(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-state-machine-functions
 * @brief   This function delays the startup until the Power-on Delay has expired 
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 * 
 * @details
 *  After the converter has been cleared to get started, the power-on
 *  delay counter is incremented until the defined power-on delay period
 *  has expired.
 **********************************************************************************/

volatile uint16_t SubState_PowerOnDelay(volatile CSEPIC_CONVERTER_t *csepicInstance)
{
   volatile uint16_t retval=0;

    // Set BUSY bit until process is complete
    csepicInstance->status.bits.busy = true;
    
    // delay startup until POWER ON DELAY has expired
    if(csepicInstance->startup.power_on_delay.counter++ > csepicInstance->startup.power_on_delay.period)
    {
        // Clamp POD counter to EXPIRED
        csepicInstance->startup.power_on_delay.counter = 
            (csepicInstance->startup.power_on_delay.period + 1); // Saturate power on counter

        retval = CSEPIC_OPSRET_COMPLETE; 
    }
    else
    // When the period has not expired yet, return to this function
    {
        retval = CSEPIC_OPSRET_REPEAT;
    }    

    return(retval);
}

/***********************************************************************************
 * @fn      uint16_t SubState_PrepareRampUp(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-state-machine-functions
 * @brief   This function calculate and pre-charge PWM outputs with ideal duty cycle 
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 * 
 * @details
 * After the POWER ON DELAY has expired, the ramp up starting point is determined  
 * by measuring the input and output voltage and calculates the ideal duty ratio 
 * of the PWM. This value is then programmed into the PWM module duty cycle register 
 * and is also used to pre-charge the control loop output history. In addition the 
 * measured output voltage also set as reference to ensure the loop starts without 
 * jerks and jumps.
 * 
 * When voltage mode control is enabled, the voltage loop control history is 
 * charged, when average current mode control is enabled, the current loop control 
 * history is charged.
 **********************************************************************************/

volatile uint16_t SubState_PrepareRampUp(volatile CSEPIC_CONVERTER_t *csepicInstance)
{
    volatile uint16_t retval=1;     // Function return value
    volatile uint16_t _i=0;

    // Pre-biased output startup point estimation
    volatile uint32_t _vout=0;      // output voltage data buffer
    volatile uint32_t _isns[CSEPIC_MPHASE_COUNT];      // output current data buffer used in CCMC
    volatile uint32_t _vin=0;       // output voltage data buffer
    volatile uint32_t _start_dc=0;  // Startup-Duty Cycle

    // Open Loop Startup Variables
    volatile uint32_t _vref=0;      // Reference voltage range of open loop startup
//    volatile uint32_t _iref=0;      // Reference current range of open loop startup
    volatile uint32_t _nom_dc=0;    // Nominal Duty Cycle
    volatile uint32_t _ol_step=0;   // Control output step size in open loop
    volatile uint32_t _period=0;    // PWM Period value buffer

    // Set BUSY bit until process is complete
    csepicInstance->status.bits.busy = true;
    
    // Copy user setting of voltage reference into loop reference
    if (csepicInstance->set_values.control_mode == CSEPIC_CONTROL_MODE_CCMC)
    {
        // Copy user setting of output current reference into loop reference when in CCMC mode
        for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++)
        {    
            csepicInstance->i_loop[_i].reference = csepicInstance->set_values.i_ref;
        }
    } else {
        csepicInstance->v_loop.reference = csepicInstance->set_values.v_ref;
    }
    
    // Hijack voltage loop controller reference
    csepicInstance->startup.v_ramp.reference = 0; // Reset Soft-Start Voltage Reference
    csepicInstance->startup.i_ramp.reference = 0; // Reset Soft-Start Current Reference

    if (csepicInstance->set_values.control_mode == CSEPIC_CONTROL_MODE_CCMC)
    {
        // Hijack current loop controller reference to inject startup ramp in CCMC mode
        for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++)
        {    
            csepicInstance->i_loop[_i].controller->Ports.ptrControlReference = &csepicInstance->startup.i_ramp.reference; // Current loop is pointing to Soft-Start Reference
        }
    } else {
        // Hijack voltage loop controller reference to inject startup ramp
        csepicInstance->v_loop.controller->Ports.ptrControlReference = &csepicInstance->startup.v_ramp.reference; // Voltage loop is pointing to Soft-Start Reference
    }
    
    
    
    // Pre-charge reference
    // Never start above the pre-biased output voltage.
    // Always start at or slightly below the pre-biased output voltage
    csepicInstance->startup.v_ramp.reference = csepicInstance->data.v_out;

    // Estimate required startup control output for seamless startup of pre-biased outputs
    if(((csepicInstance->data.v_in - csepicInstance->feedback.ad_vin.scaling.offset) > 0) &&
       ((csepicInstance->data.v_out - csepicInstance->feedback.ad_vout.scaling.offset) > 0) )
    {
        _vout = __builtin_muluu(
            (csepicInstance->data.v_out - csepicInstance->feedback.ad_vout.scaling.offset), 
            csepicInstance->feedback.ad_vout.scaling.factor);
        _vout >>= (16 - csepicInstance->feedback.ad_vout.scaling.scaler);

        _vin = __builtin_muluu(
            (csepicInstance->data.v_in - csepicInstance->feedback.ad_vin.scaling.offset), 
            csepicInstance->feedback.ad_vin.scaling.factor);
        _vin >>= (16 - csepicInstance->feedback.ad_vin.scaling.scaler);
        
        for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {
            _isns[_i] = __builtin_muluu(
            (csepicInstance->data.i_sns[_i] - csepicInstance->feedback.ad_isns[_i].scaling.offset), 
            csepicInstance->feedback.ad_isns[_i].scaling.factor);
            _isns[_i] >>= (16 - csepicInstance->feedback.ad_isns[_i].scaling.scaler);
        
        }
       

        // CALCULATE BUCK-BOOST CONVERTER STARTUP DUTY RATIO 
        // DC = VOUT / (VIN + VOUT), where DC = D * 2x PERIOD
        // The doubled period value is required as the linear control 
        // output from 0 .... 100 % will be broken up in buck-leg and 
        // boost leg duty cycle with
        //      D = 0...0.5 = 0-100% buck leg
        //      D = 0.5...1.0 = 0-100% boost leg
        
        _vref = csepicInstance->set_values.v_ref;
//        _iref = csepicInstance->set_values.i_ref;
        _period = (csepicInstance->sw_node[0].period << 1);
        
        if((_vin > 0) && (_vout > 0))
        {
            _start_dc = __builtin_divud((uint16_t)_vout, ((uint16_t)_vin+(uint16_t)_vout));
            _start_dc = __builtin_muluu((_start_dc), _period);

            _nom_dc = __builtin_divud((uint16_t)_vref, ((uint16_t)_vin+(uint16_t)_vout));
            _nom_dc = __builtin_muluu((_nom_dc), _period);
        }
        else
        { 
            //VG_
            //_start_dc = (uint16_t)csepicInstance->sw_node[_i].buck_leg.duty_ratio_min; 
            //_nom_dc = (uint16_t)csepicInstance->sw_node[_i].buck_leg.duty_ratio_min;
            _start_dc = (uint16_t)csepicInstance->sw_node[_i].sepic_switch.duty_ratio_min; 
            _nom_dc = (uint16_t)csepicInstance->sw_node[_i].sepic_switch.duty_ratio_min;
        }

    }
    else
    // If there is no input voltage or no output voltage, start with minimum duty ratio
    {
        for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {
            //VG_
            //_start_dc = (uint16_t)csepicInstance->sw_node[_i].buck_leg.duty_ratio_min;
            //_nom_dc = (uint16_t)csepicInstance->sw_node[_i].buck_leg.duty_ratio_min;
            _start_dc = (uint16_t)csepicInstance->sw_node[_i].sepic_switch.duty_ratio_min;
            _nom_dc = (uint16_t)csepicInstance->sw_node[_i].sepic_switch.duty_ratio_min;
        }
    }
    
    // Clear loops and pre-charge PWM and control loop history
    switch (csepicInstance->set_values.control_mode)
    {
        case CSEPIC_CONTROL_MODE_VMC:
            
            // Program PWM module and pre-charge control loop
            if(_start_dc < csepicInstance->v_loop.minimum) 
            { _start_dc = csepicInstance->v_loop.minimum; }
            else if(_start_dc > csepicInstance->v_loop.maximum) 
            { _start_dc = csepicInstance->v_loop.maximum; }
            else { /* continue */ }

            // Pre-Charge voltage loop controller with calculated starting point
            csepicInstance->v_loop.ctrl_Precharge(csepicInstance->v_loop.controller, 0, _start_dc);
            *csepicInstance->v_loop.controller->Ports.Target.ptrAddress = _start_dc; // set initial PWM duty ratio
            if(csepicInstance->v_loop.controller->Ports.AltTarget.ptrAddress != NULL)
                *csepicInstance->v_loop.controller->Ports.AltTarget.ptrAddress = _start_dc; // set initial PWM duty ratio
            else { /* continue */ }

            retval = CSEPIC_OPSRET_COMPLETE;
            break;
            
        case CSEPIC_CONTROL_MODE_CCMC:
            
            // Program PWM module and pre-charge control loop
            for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++)
            {    
                // Program PWM module and pre-charge control loop
                if(_start_dc < csepicInstance->i_loop[_i].minimum)
                { _start_dc = csepicInstance->i_loop[_i].minimum; }
                else if(_start_dc > csepicInstance->i_loop[_i].maximum) 
                { _start_dc = csepicInstance->i_loop[_i].maximum; }
                else { /* continue */ }
                
                // Pre-Charge current loop controller with calculated starting point
                csepicInstance->i_loop[_i].ctrl_Precharge(csepicInstance->i_loop[_i].controller, 0, _start_dc);
                *csepicInstance->i_loop[_i].controller->Ports.Target.ptrAddress = _start_dc; // set initial PWM duty ratio
                if(csepicInstance->i_loop[_i].controller->Ports.AltTarget.ptrAddress != NULL)
                    *csepicInstance->i_loop[_i].controller->Ports.AltTarget.ptrAddress = _start_dc; // set initial PWM duty ratio
                else { /* continue */ }
            }
            
            // If converter needs to be started in open loop, calculate the open loop control
            // output increment steps size
            if (csepicInstance->startup.open_loop.enabled) {
                // Calculate desired output voltage step range per ramp-up step to get from 
                // most recent output voltage to common mode voltage minimum level
                _vref = (csepicInstance->startup.open_loop.vout_cutoff - _vout);
                if (_vref < 0) _vref = 0;
                _vref = __builtin_divud((uint16_t)(_vref), csepicInstance->startup.v_ramp.ref_inc_step); 
                
                // Calculate estimated open-loop control output range to get from most recent
                // control output to common mode voltage minimum level
                _ol_step = (_nom_dc - _start_dc);
                if(_ol_step <= 0) _ol_step = 1;
                _ol_step = __builtin_divud((uint16_t)(_ol_step), (uint16_t)_vref); 
                _ol_step >>= 1;
                if(_ol_step <= 0) _ol_step = 1;
                
                csepicInstance->startup.open_loop.output_increment = _ol_step;

                Nop();
                Nop();
                Nop();
            }

            retval = CSEPIC_OPSRET_COMPLETE;
            break;


        // In peak current mode, set duty cycle to max to allow the comparator take control
        //case CSEPIC_CONTROL_MODE_PCMC:
        //    /* not supported yet */
        //    break;
            
        // In average current mode, set current reference limit to max startup current level
        case CSEPIC_CONTROL_MODE_ACMC:
            
            // Disable all current control loops and reset control loop histories
        
            // If user has not specified a startup current limit, copy common current reference
            if ((csepicInstance->startup.i_ramp.ref_start_limit == 0) && (csepicInstance->set_values.i_ref > 0))
                csepicInstance->startup.i_ramp.ref_start_limit = csepicInstance->set_values.i_ref;

            // Set current limit in voltage loop output anti-windup limits
            csepicInstance->v_loop.maximum = csepicInstance->startup.i_ramp.ref_start_limit;
            csepicInstance->v_loop.controller->Limits.MaxOutput = csepicInstance->v_loop.maximum;   
            
            // Limit startup duty cycle to largest minimum/smallest maximum
            for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {

                if(_start_dc < csepicInstance->i_loop[_i].minimum) 
                { _start_dc = csepicInstance->i_loop[_i].minimum; }
                else if(_start_dc > csepicInstance->i_loop[_i].maximum) 
                { _start_dc = csepicInstance->i_loop[_i].maximum; }
                else { /* continue */ }
            }

            // Set initial duty cycle
            for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) 
            {
                // pre-charge current loop control histories with ideal duty cycle
                csepicInstance->i_loop[_i].ctrl_Precharge(
                            csepicInstance->i_loop[_i].controller, 0, _start_dc
                        );

                // pre-charge PWM outputs with ideal duty cycle
                *csepicInstance->i_loop[_i].controller->Ports.Target.ptrAddress = _start_dc; // set initial PWM duty ratio
                if(csepicInstance->i_loop[_i].controller->Ports.AltTarget.ptrAddress != NULL)
                    *csepicInstance->i_loop[_i].controller->Ports.AltTarget.ptrAddress = _start_dc; // set initial PWM duty ratio
                else { /* continue */ }
            }

            // If converter needs to be started in open loop, calculate the open loop control
            // output increment steps size
            if (csepicInstance->startup.open_loop.enabled) {

                // Calculate desired output voltage step range per ramp-up step to get from 
                // most recent output voltage to common mode voltage minimum level
                _vref = (csepicInstance->startup.open_loop.vout_cutoff - _vout);
                if (_vref < 0) _vref = 0;
                _vref = __builtin_divud((uint16_t)(_vref), csepicInstance->startup.v_ramp.ref_inc_step); 
                
                // Calculate estimated open-loop control output range to get from most recent
                // control output to common mode voltage minimum level
                _ol_step = (_nom_dc - _start_dc);
                if(_ol_step <= 0) _ol_step = 1;
                _ol_step = __builtin_divud((uint16_t)(_ol_step), (uint16_t)_vref); 
                _ol_step >>= 1;
                if(_ol_step <= 0) _ol_step = 1;
                
                csepicInstance->startup.open_loop.output_increment = _ol_step;

                Nop();
                Nop();
                Nop();
            }
            
            retval = CSEPIC_OPSRET_COMPLETE;            
            break;
            
        default:
            retval = CSEPIC_OPSRET_ERROR;
            break;
    }    
    

    return(retval);
    
}


/***********************************************************************************
 * @fn      uint16_t SubState_RampUpStart(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-state-machine-functions
 * @brief   This function performs the initial step of the ramp-up process
 * @param	buckInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 * 
 * @details
 * In this step of the startup process the required startup procedure 
 **********************************************************************************/

volatile uint16_t SubState_RampUpStart(volatile CSEPIC_CONVERTER_t *csepicInstance)
{
    volatile uint16_t retval=1;
    volatile uint16_t _i=0;
    
    // Open Loop Startup Variables
    volatile uint16_t _ol_output=0; // open loop startup output value auxiliary variable
    volatile uint16_t _ol_iref=0;   // open loop startup reference current value auxiliary variable
    volatile uint16_t* _ptrTarget;  // pointer to target register during open loop startup  

    // Set BUSY bit until process is complete
    csepicInstance->status.bits.busy = true;
    
    // Enable all PWM channels
    retval &= csepicPWM_Update(csepicInstance); // Enforce PWM timing registers to update
    retval &= csepicPWM_Resume(csepicInstance); // Enable PWM outputs

    // Verify reference increments
    if (csepicInstance->startup.v_ramp.ref_inc_step == 0)
        csepicInstance->startup.v_ramp.ref_inc_step = 1;
    
    // Select/execute control mode specific voltage ramp up initialization steps
    switch (csepicInstance->set_values.control_mode)
    {
        // Voltage mode control special initialization steps
        case CSEPIC_CONTROL_MODE_VMC:

            csepicInstance->v_loop.controller->status.bits.enabled = true; // enable voltage loop controller

            retval = CSEPIC_OPSRET_COMPLETE; // Move on to next state machine step
        break;
            
        case CSEPIC_CONTROL_MODE_CCMC:
            if (!csepicInstance->startup.open_loop.enabled)
                csepicInstance->startup.open_loop.vout_cutoff = 0;

            // Verify startup reference increment is valid
            if (csepicInstance->startup.i_ramp.ref_inc_step == 0)
                csepicInstance->startup.i_ramp.ref_inc_step = 1;
            
            // Initiate ramp-up point of average current feedback loop
            if ((!csepicInstance->startup.open_loop.enabled) || // No open-loop ramp up required or output voltage higher than cut_off
                (csepicInstance->data.v_out >= csepicInstance->startup.open_loop.vout_cutoff))
            {
                
                // Update current loop reference to most recent current level (taking phase 0 as reference)
                csepicInstance->startup.i_ramp.reference = csepicInstance->data.i_sns[0];
                csepicInstance->startup.i_ramp.reference += csepicInstance->startup.i_ramp.ref_inc_step;

                for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {                    
                    // Select pointer address of open loop startup destination
                    if ((csepicInstance->i_loop[_i].controller->Ports.Target.ptrAddress != NULL) && 
                        (!csepicInstance->i_loop[_i].controller->status.bits.swap_target))
                    {
                        _ptrTarget = csepicInstance->i_loop[_i].controller->Ports.Target.ptrAddress;

                    } else if ((csepicInstance->i_loop[_i].controller->Ports.AltTarget.ptrAddress != NULL) && 
                        (csepicInstance->i_loop[_i].controller->status.bits.swap_target))
                    {
                        _ptrTarget = csepicInstance->i_loop[_i].controller->Ports.AltTarget.ptrAddress;
                    }
                    else
                    { return(CSEPIC_OPSRET_ERROR); } // If any pointer of the control loops is not initialized, return an error
                    
                    // Read most recent value from register
                    _ol_output = *_ptrTarget; 
                    
                    // Pre-charge current loop control histories with incremented duty cycle
                    // to ensure smooth transition into regulated control
                    csepicInstance->i_loop[_i].ctrl_Precharge(
                                csepicInstance->i_loop[_i].controller, 0, _ol_output
                            );

                    // Enable current loop controller
                    csepicInstance->i_loop[_i].controller->status.bits.enabled = true; 
                }
                
                retval = CSEPIC_OPSRET_COMPLETE; // Move on to next state machine step
                
            }
            // If converter does require specific open-loop startup schemes to overcome 
            // common mode voltage limit of feedback circuits, ramp up PWM output in open
            // loop until converter output is higher than specified startup minimum
            else if ((csepicInstance->startup.open_loop.enabled) && 
                     (csepicInstance->data.v_out < csepicInstance->startup.open_loop.vout_cutoff))
            {    
                // In open loop ramp-up, the control output across all phases is incremented
                // with the converter output being monitored while the actual feedback loops 
                // are kept disabled
                for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) 
                {
                    // Keep voltage control loop disabled
                    csepicInstance->i_loop[_i].controller->status.bits.enabled = false;
                    // Select pointer address of open loop startup destination
                    if ((csepicInstance->i_loop[_i].controller->Ports.Target.ptrAddress != NULL) && 
                        (!csepicInstance->i_loop[_i].controller->status.bits.swap_target))
                    {
                        _ptrTarget = csepicInstance->i_loop[_i].controller->Ports.Target.ptrAddress;

                    } else if ((csepicInstance->i_loop[_i].controller->Ports.AltTarget.ptrAddress != NULL) && 
                        (csepicInstance->i_loop[_i].controller->status.bits.swap_target))
                    {
                        _ptrTarget = csepicInstance->i_loop[_i].controller->Ports.AltTarget.ptrAddress;
                    }
                    else
                    { return(CSEPIC_OPSRET_ERROR); } // If any pointer of the control loops is not initialized, return an error

                    // Perform open loop startup step
                    //csepicInstance->i_loop[_i].controller->status.bits.enabled = false; // Keep current control loop disabled
                    
                    _ol_output = *_ptrTarget; // read most recent value from register
                    _ol_output += csepicInstance->startup.open_loop.output_increment; // increment control output value
                    
                    // Clamp value to user-defined min/max thresholds
                    if(_ol_output < csepicInstance->i_loop[_i].minimum)
                        _ol_output = csepicInstance->i_loop[_i].minimum;
                    else if(_ol_output > csepicInstance->i_loop[_i].maximum)
                        _ol_output = csepicInstance->i_loop[_i].maximum;
                    
                    *_ptrTarget = _ol_output; // write incremented value back to register 
                    
                }
            
                // Enforce PWM timing registers to update
                retval &= csepicPWM_Update(csepicInstance); 

                // Repeat open loop steps until converter output is higher than specified ramp-up minimum
                retval = CSEPIC_OPSRET_REPEAT; 

            }
           
        break;
        
            
//        // Peak current mode control special initialization steps (not supported yet)
//        case CSEPIC_CONTROL_MODE_PCMC:
//
//            csepicInstance->v_loop.controller->status.bits.enabled = true; // enable voltage loop controller
//
//            retval = CSEPIC_OPSRET_COMPLETE; // Move on to next state machine step
//            break;
//
        // Average current mode control inner current control loops special initialization steps
        case CSEPIC_CONTROL_MODE_ACMC:

            
            // If converter does not require specific open-loop startup schemes or if
            // converter does require specific open-loop startup schemes to overcome 
            // common mode voltage limit of feedback circuits, but the converter output 
            // is greater than specified ramp-up minimum, enable loops and to initiate 
            // common, controlled ramp-up of converter output
            
            // Clear open loop cut-off  voltage setting if open loop startup is disabled
            if (!csepicInstance->startup.open_loop.enabled)
                csepicInstance->startup.open_loop.vout_cutoff = 0;

            // Verify startup reference increment is valid
            if (csepicInstance->startup.i_ramp.ref_inc_step == 0)
                csepicInstance->startup.i_ramp.ref_inc_step = 1;

            // Initiate ramp-up point of average current feedback loop
            if ((!csepicInstance->startup.open_loop.enabled) || 
                (csepicInstance->data.v_out >= csepicInstance->startup.open_loop.vout_cutoff))
            {
                
                // Update voltage loop reference to most recent voltage level
                csepicInstance->startup.v_ramp.reference = csepicInstance->data.v_out;
                csepicInstance->startup.v_ramp.reference += csepicInstance->startup.v_ramp.ref_inc_step;

                // Capture average of most recent output current
                _ol_iref = __builtin_divud(
                            (uint32_t)csepicInstance->data.i_out, 
                            (uint16_t)csepicInstance->set_values.no_of_phases
                        );

                // Pre-charge voltage loop control history with most recent output
                // current to ensure smooth transition into regulated control
                csepicInstance->v_loop.ctrl_Precharge(
                            csepicInstance->v_loop.controller, 0, _ol_iref
                        );

                // Enable voltage loop controller
                csepicInstance->v_loop.controller->status.bits.enabled = true; 

                for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {

                    // Select pointer address of open loop startup destination
                    if ((csepicInstance->i_loop[_i].controller->Ports.Target.ptrAddress != NULL) && 
                        (!csepicInstance->i_loop[_i].controller->status.bits.swap_target))
                    {
                        _ptrTarget = csepicInstance->i_loop[_i].controller->Ports.Target.ptrAddress;

                    } else if ((csepicInstance->i_loop[_i].controller->Ports.AltTarget.ptrAddress != NULL) && 
                        (csepicInstance->i_loop[_i].controller->status.bits.swap_target))
                    {
                        _ptrTarget = csepicInstance->i_loop[_i].controller->Ports.AltTarget.ptrAddress;
                    }
                    else
                    { return(CSEPIC_OPSRET_ERROR); } // If any pointer of the control loops is not initialized, return an error
                    
                    // Read most recent value from register
                    _ol_output = *_ptrTarget; 
                    
                    // Pre-charge current loop control histories with incremented duty cycle
                    // to ensure smooth transition into regulated control
                    csepicInstance->i_loop[_i].ctrl_Precharge(
                                csepicInstance->i_loop[_i].controller, 0, _ol_output
                            );

                    // Enable current loop controller
                    csepicInstance->i_loop[_i].controller->status.bits.enabled = true; 
                }
                
                retval = CSEPIC_OPSRET_COMPLETE; // Move on to next state machine step
                
            }
            // If converter does require specific open-loop startup schemes to overcome 
            // common mode voltage limit of feedback circuits, ramp up PWM output in open
            // loop until converter output is higher than specified startup minimum
            else if ((csepicInstance->startup.open_loop.enabled) && 
                     (csepicInstance->data.v_out < csepicInstance->startup.open_loop.vout_cutoff))
            {
                // Keep voltage control loop disabled
                csepicInstance->v_loop.controller->status.bits.enabled = false; 
                
                // In open loop ramp-up, the control output across all phases is incremented
                // with the converter output being monitored while the actual feedback loops 
                // are kept disabled
                for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) 
                {
                    // Select pointer address of open loop startup destination
                    if ((csepicInstance->i_loop[_i].controller->Ports.Target.ptrAddress != NULL) && 
                        (!csepicInstance->i_loop[_i].controller->status.bits.swap_target))
                    {
                        _ptrTarget = csepicInstance->i_loop[_i].controller->Ports.Target.ptrAddress;

                    } else if ((csepicInstance->i_loop[_i].controller->Ports.AltTarget.ptrAddress != NULL) && 
                        (csepicInstance->i_loop[_i].controller->status.bits.swap_target))
                    {
                        _ptrTarget = csepicInstance->i_loop[_i].controller->Ports.AltTarget.ptrAddress;
                    }
                    else
                    { return(CSEPIC_OPSRET_ERROR); } // If any pointer of the control loops is not initialized, return an error

                    // Perform open loop startup step
                    csepicInstance->i_loop[_i].controller->status.bits.enabled = false; // Keep current control loop disabled
                    
                    _ol_output = *_ptrTarget; // read most recent value from register
                    _ol_output += csepicInstance->startup.open_loop.output_increment; // increment control output value
                    
                    // Clamp value to user-defined min/max thresholds
                    if(_ol_output < csepicInstance->i_loop[_i].minimum)
                        _ol_output = csepicInstance->i_loop[_i].minimum;
                    else if(_ol_output > csepicInstance->i_loop[_i].maximum)
                        _ol_output = csepicInstance->i_loop[_i].maximum;
                    
                    *_ptrTarget = _ol_output; // write incremented value back to register 
                    
                }
            
                // Enforce PWM timing registers to update
                retval &= csepicPWM_Update(csepicInstance); 

                // Repeat open loop steps until converter output is higher than specified ramp-up minimum
                retval = CSEPIC_OPSRET_REPEAT; 

            }

            break;
        
        // If control mode is set to unsupported type, return error
        default:
            retval = CSEPIC_OPSRET_ERROR;
            break;
    }

    return(retval);
    
}

/***********************************************************************************
 * @fn      uint16_t SubState_RampUp(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-state-machine-functions
 * @brief   This function ramps up the output voltage to its nominal regulation point
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 * 
 * @details
 * This is the essential step in which the output voltage is ramped up by 
 * incrementing the outer control loop reference. In voltage mode the output  
 * voltage will ramp up to the nominal regulation point. 
 * In average current mode the inner loop will limit the voltage as soon as the 
 * current reference limit is hit and the output is switched to constant current 
 * mode.
 **********************************************************************************/

volatile uint16_t SubState_RampUp(volatile CSEPIC_CONVERTER_t *csepicInstance)
{
    volatile uint16_t retval=1;
    volatile uint16_t _i=0;
//
//    volatile uint16_t _write_dummy=0;
//    volatile bool _open_loop_start=false;

    
    // Set BUSY bit until process is complete
    csepicInstance->status.bits.busy = true;
    
    if (csepicInstance->set_values.control_mode != CSEPIC_CONTROL_MODE_CCMC) { // All modes but CCMC
        // increment reference
        csepicInstance->startup.v_ramp.reference += csepicInstance->startup.v_ramp.ref_inc_step;
        csepicInstance->startup.v_ramp.counter++; // Increment voltage ramp-up counter

        // check if ramp is complete
        if (csepicInstance->startup.v_ramp.reference > csepicInstance->v_loop.reference) 
        {
            // Set start-up reference to the nominal reference voltage desired level
            csepicInstance->startup.v_ramp.reference = csepicInstance->v_loop.reference;

            // Reconnect API reference to controller
            csepicInstance->v_loop.controller->Ports.ptrControlReference = &csepicInstance->v_loop.reference;

            retval = CSEPIC_OPSRET_COMPLETE;

        }
        else
        // remain in this state until ramp is complete
        {
            retval = CSEPIC_OPSRET_REPEAT;
        }
    } else { // CCMC Mode
        csepicInstance->startup.i_ramp.reference += csepicInstance->startup.i_ramp.ref_inc_step;
        csepicInstance->startup.i_ramp.counter++; // Increment voltage ramp-up counter
        // check if ramp is complete
        if (csepicInstance->startup.i_ramp.reference > csepicInstance->i_loop[0].reference)
        {
            // Set start-up reference to the nominal reference current desired level
            csepicInstance->startup.i_ramp.reference = csepicInstance->i_loop[0].reference;

            // Reconnect API reference to controller
            for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {
                csepicInstance->i_loop[_i].controller->Ports.ptrControlReference = &csepicInstance->i_loop[0].reference;
            }

            retval = CSEPIC_OPSRET_COMPLETE;

        }
        else
        // remain in this state until ramp is complete
        {
            retval = CSEPIC_OPSRET_REPEAT;
        }
    }
    
    return(retval);
    
}

/***********************************************************************************
 * @fn      uint16_t SubState_IRampUp(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-state-machine-functions
 * @brief   This function is for the average current mode control where the output current is ramped up to nominal current
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 * 
 * @details
 * This phase of the soft-start ramp is only executed in average current mode and 
 * will only take effect when the declared current limit is hit before the nominal 
 * voltage regulation point. In this case the outer voltage loop will clamp the 
 * current reference value and the state will be switched to IRampUp, where the 
 * clamping value of the voltage loop output is ramped up to the declared maximum
 * current reference value.
 * This additional state allows powering up the power converter against highly 
 * capacitive loads preventing overshoots caused by down-stream capacitor inrush 
 * currents or when the converter is used as battery charger, where this state 
 * will tune into the constant current charging mode.
 **********************************************************************************/
volatile uint16_t SubState_IRampUp(volatile CSEPIC_CONVERTER_t *csepicInstance)
{
    volatile uint16_t retval=0;
    volatile uint16_t _i=0;
    
    // Set BUSY bit until process is complete
    csepicInstance->status.bits.busy = true;

    // in average current mode if voltage limit is hit, increment 
    // voltage loop limit to ramp up current loop
    if (csepicInstance->set_values.control_mode == CSEPIC_CONTROL_MODE_ACMC)
    {
        // Increment maximum current limit
        csepicInstance->v_loop.controller->Limits.MaxOutput += csepicInstance->startup.i_ramp.ref_inc_step; 

        if (csepicInstance->v_loop.controller->Limits.MaxOutput >= csepicInstance->startup.i_ramp.ref_start_limit)
        // check if ramp is complete 
        {
            csepicInstance->v_loop.maximum = csepicInstance->set_values.i_ref;
            csepicInstance->v_loop.controller->Limits.MaxOutput = csepicInstance->v_loop.maximum;
            retval = CSEPIC_OPSRET_COMPLETE;
        }
        else
        // if ramp is not complete yet, remain in this state
        {
            retval = CSEPIC_OPSRET_REPEAT;
        }
    }
    else // In Non-Current Mode ramp-up ends up here and needs to be lifted to PG_DELAY
    { 
        if (csepicInstance->set_values.control_mode != CSEPIC_CONTROL_MODE_CCMC) {
            csepicInstance->v_loop.controller->Limits.MaxOutput = csepicInstance->v_loop.maximum;
        } else {
            for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) {
                csepicInstance->i_loop[_i].controller->Limits.MaxOutput = csepicInstance->i_loop[_i].maximum;
            }
        }
        retval = CSEPIC_OPSRET_COMPLETE; 
    }

    return(retval);
    
}

/***********************************************************************************
 * @fn      uint16_t SubState_PowerGoodDelay(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-state-machine-functions
 * @brief   In this function, a counter is incremented until the power good delay has expired.
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 * 
 * @details
 * In this phase of the soft-start procedure a counter is incremented until the 
 * power good delay has expired before the soft-start process is marked as COMPLETED.
 * If option for driving a user-defined general purpose output (PG output) is enabled
 * in proprietary user code, this pin will be set automatically.
 **********************************************************************************/
volatile uint16_t SubState_PowerGoodDelay(volatile CSEPIC_CONVERTER_t *csepicInstance)
{
    volatile uint16_t retval=0;
    
    // Set BUSY bit until process is complete
    csepicInstance->status.bits.busy = true;

    // increment delay counter until the GOWER GOOD delay has expired
    if(csepicInstance->startup.power_good_delay.counter++ > csepicInstance->startup.power_good_delay.period)
    {
        csepicInstance->startup.power_good_delay.counter = 
            (csepicInstance->startup.power_good_delay.period + 1); // Clamp to PERIOD_EXPIRED for future startups

        // If defined, set POWER_GOOD output
        if(csepicInstance->gpio.PowerGood.enabled)
        {
            retval = csepicGPIO_Set(&csepicInstance->gpio.PowerGood);
            if(!retval)
                return(CSEPIC_OPSTATE_ERROR);
        }
        
        retval = CSEPIC_OPSRET_COMPLETE;
    }
    else
    // if period has not expired yet, remain in this state
    {
        retval = CSEPIC_OPSRET_REPEAT;
    }

    return(retval);
    
}

// end of file
