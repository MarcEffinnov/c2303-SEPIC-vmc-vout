/*
 * File:   dev_sepic_converter.c
 * Author: M91406
 *
 * Created on July 9, 2019, 1:10 PM
 */


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer types header file
#include <stdbool.h> // include standard boolean types header file

#include "dev_sepic_typedef.h"
#include "dev_sepic_opstates.h"
#include "dev_sepic_pconfig.h"


/*******************************************************************************
 * @fn	volatile uint16_t dev_csepicConverter_Initialize(volatile CSEPIC_CONVERTER_t *csepicInstance)
 * @ingroup lib-layer-sepic-converter-functions-public
 * @brief   This function initializes all peripheral modules and their instances used by the power controller
 * @param	csepicInstance  Pointer to a SEPIC converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 *  
 * @details
 * This function initializes the PWM module, PWM channels, ADC channels for temperature,
 * input voltage, output voltage and phase current. The SEPIC IO pins are also initialize
 * while keeping the SEPIC converter operation disabled. The state machine is set to 'Initialize'. 
 *********************************************************************************/

volatile uint16_t dev_csepicConverter_Initialize(volatile CSEPIC_CONVERTER_t *csepicInstance) 
{
    volatile uint16_t retval = 1;
    volatile uint16_t _i=0;
    
    retval &= csepicPWM_ModuleInitialize(csepicInstance); // Initialize PWM Module
    retval &= csepicPWM_ChannelInitialize(csepicInstance);  // Initialize PWM Channel of SEPIC Converter
    
    retval &= csepicADC_ModuleInitialize();     // Initialize ADC Module
    
    retval &= csepicADC_ChannelInitialize(&csepicInstance->feedback.ad_temp); // Initialize Temperature Channel
    retval &= csepicADC_ChannelInitialize(&csepicInstance->feedback.ad_vin);  // Initialize Input Voltage Channel
    retval &= csepicADC_ChannelInitialize(&csepicInstance->feedback.ad_vout); // Initialize Output Voltage Channel
    
    for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) // Reset phase current values
        retval &= csepicADC_ChannelInitialize(&csepicInstance->feedback.ad_isns[_i]); // Initialize Phase Current Channel
    
    retval &= csepicGPIO_Initialize(csepicInstance); // Initialize additional control IOs

    
    csepicInstance->v_loop.controller->status.bits.enabled = false; // Disable voltage loop
    
    if ((csepicInstance->set_values.control_mode == CSEPIC_CONTROL_MODE_ACMC) || (csepicInstance->set_values.control_mode == CSEPIC_CONTROL_MODE_CCMC)) { // In current mode...
     
        for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++) // Reset phase current values
        { csepicInstance->i_loop[_i].controller->status.bits.enabled = false; } // Disable current loop
    
    }

    // Set SEPIC device driver defaults
    csepicInstance->status.bits.enabled = false;  // Disable SEPIC Converter
    csepicInstance->state_id.value = (uint32_t)CSEPIC_OPSTATE_INITIALIZE; // Reset state machine
    
    if(csepicInstance->startup.v_ramp.ref_inc_step == 0) // Clamp startup voltage slew rate to minimum
        csepicInstance->startup.v_ramp.ref_inc_step = 1;
    
    if(csepicInstance->set_values.v_slew_rate == 0) // Set voltage reference transition slew rate if note configured
        csepicInstance->set_values.v_slew_rate = csepicInstance->startup.v_ramp.ref_inc_step;
    
    if(csepicInstance->startup.i_ramp.ref_inc_step == 0) // Clamp startup current slew rate to minimum
        csepicInstance->startup.i_ramp.ref_inc_step = 1;

    if(csepicInstance->set_values.i_slew_rate == 0) // Set current reference transition slew rate if note configured
        csepicInstance->set_values.i_slew_rate = csepicInstance->startup.i_ramp.ref_inc_step;
    
    
    return(retval);
}

#if 0
/*******************************************************************************
 * @fn	volatile uint16_t dev_csepicConverter_Execute(volatile CSEPIC_CONVERTER_t * csepicInstance)
 * @ingroup lib-layer-sepic-converter-functions-public
 * @brief   This function is the main SEPIC converter state machine executing the most recent state 
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  0 = CSEPIC_OPSRET_REPEAT
 * @return  1 = CSEPIC_OPSRET_COMPLETE
 * @return  2 = CSEPIC_OPSRET_REPEAT
 *
 * @details
 * This function performs tasks in the state machine.  
 *  - If state machine state returns ERROR, switch to ERROR state in next execution cycle
 *  - If state machine state signals state completion, move on to next state in line
 *  - When state machine state returns REPEAT, the recent state function will be called again
 *  - When state machine state returns an unknown result, the state machine will be reset to INITIALIZE again 
 *********************************************************************************/

volatile uint16_t dev_csepicConverter_Execute(volatile CSEPIC_CONVERTER_t *csepicInstance) 
{
    volatile uint16_t retval=1;
    
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    /* NULL POINTER PROTECTION                                                            */
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    // If no SEPIC converter instance has been declared, leave here
    if(csepicInstance == NULL)
        return(0);
    
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    /* CAPTURE ENABLE PIN STATE IF ENABLED BY USER CODE                                   */
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    if(csepicInstance->gpio.EnableInput.enabled)
    {
        // Capture Enable Input pin status (1=high, 0=low)
        uint16_t pin_state = csepicGPIO_GetPinState(&csepicInstance->gpio.EnableInput);
        
        if(!csepicInstance->gpio.EnableInput.polarity)
        // If POLARITY setting 0 = Active High (default)
            csepicInstance->status.bits.enabled = (bool)(pin_state == 1);
        else
        // If POLARITY setting 1 = Active Low
            csepicInstance->status.bits.enabled = (bool)(pin_state == 0);
    }
    
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    /* DISABLE/SUSPEND/FAULT-RESET                                                                      */
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    // When enable status has changed from ENABLED to DISABLED or a fault condition 
    // is active, reset the state machine and hold it in RESET state
    if ((!csepicInstance->status.bits.enabled) || (csepicInstance->status.bits.suspend) ||
        (csepicInstance->status.bits.fault_active))
    {
        if (!csepicInstance->status.bits.ready)
            csepicInstance->state_id.value = (uint32_t)CSEPIC_OPSTATE_INITIALIZE;
        else
            csepicInstance->state_id.value = (uint32_t)CSEPIC_OPSTATE_RESET;
        
        // Call most recent state
        retval = csepicConverterStateMachine[csepicInstance->state_id.bits.opstate_id](csepicInstance);
        
        return((bool)(retval>0)); // Return
    }    
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    /* FUNCTION CALL PROTECTION                                                           */
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    // If the state array pointer is out of range, roll over and start from first 
    // valid state
    if(csepicInstance->state_id.bits.opstate_id >= csepicStateList_size)
        csepicInstance->state_id.value = (uint32_t)CSEPIC_OPSTATE_INITIALIZE;
    
    if (csepicConverterStateMachine[csepicInstance->state_id.bits.opstate_id] == NULL)
        return(0);
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    // Execute state machine step
    retval = csepicConverterStateMachine[csepicInstance->state_id.bits.opstate_id](csepicInstance);
    
    switch (retval) 
    {
        /* If state machine state returns ERROR, switch to ERROR state in next execution cycle */
        case CSEPIC_OPSRET_ERROR:
            
            csepicInstance->state_id.value = (uint32_t)CSEPIC_OPSTATE_INITIALIZE;
            retval = 0;
            break;
            
        /* IF state machine state signals state completion, move on to next state in line */
        case CSEPIC_OPSRET_COMPLETE:
            
            // Increment main operating state pointer by one tick
            csepicInstance->state_id.value = (uint32_t)(csepicInstance->state_id.bits.opstate_id++);
            
            // Check if new index is out of range, reset to RESET if so
            if (csepicInstance->state_id.bits.opstate_id >= csepicStateList_size)
                csepicInstance->state_id.value = (uint32_t)CSEPIC_OPSTATE_RESET;

            retval = 1;
            break;
            
        /* When state machine state returns REPEAT, the recent state function will be called again */
        case CSEPIC_OPSRET_REPEAT:
            // Do nothing, same state will be called next time
            retval = 1;
            break;
            
        /* When state machine state returns an unknown result, the 
         * state machine will be reset to INITIALIZE again */
        default:
            // In case an undefined return value has been received,
            // REset state machine and start from scratch
            csepicInstance->state_id.value = (uint32_t)CSEPIC_OPSTATE_INITIALIZE;
            retval = 0;
            break;
    }

    return(retval);
}
#endif

/*******************************************************************************
 * @fn	volatile uint16_t dev_csepicConverter_Start(volatile CSEPIC_CONVERTER_t * csepicInstance)
 * @ingroup lib-layer-sepic-converter-functions-public
 * @brief   This function starts the SEPIC converter
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 *  
 * @details
 * This function starts the SEPIC converter operation by enabling the the SEPIC PWM and ADC peripherals, 
 * enabling the SEPIC converter and reseting the state machine to Initialize. 
 *********************************************************************************/

volatile uint16_t dev_csepicConverter_Start(volatile CSEPIC_CONVERTER_t * csepicInstance) {

    volatile uint16_t retval=1;
    volatile uint16_t _i=0;
    
    // Disable control loops
    csepicInstance->v_loop.controller->status.bits.enabled = false; // Disable voltage loop
    
    if (csepicInstance->set_values.control_mode != CSEPIC_CONTROL_MODE_CCMC) {
        csepicInstance->v_loop.ctrl_Reset(csepicInstance->v_loop.controller); // Reset voltage loop histories
    }

    if ((csepicInstance->set_values.control_mode == CSEPIC_CONTROL_MODE_ACMC) || (csepicInstance->set_values.control_mode == CSEPIC_CONTROL_MODE_CCMC)) { // In current mode...
        
        for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++)
        { 
            csepicInstance->i_loop[_i].controller->status.bits.enabled = false; // Disable current loop
            csepicInstance->i_loop[_i].ctrl_Reset(csepicInstance->i_loop[_i].controller); // Reset current loop histories
        }
    }
    
    // Sequence PWM and ADC peripheral startup
    retval &= csepicPWM_Start(csepicInstance);   // Start PWM (All Outputs Disabled)
    if (retval) csepicInstance->status.bits.pwm_active = 1; // IF PWM startup was successful, set PWM_ACTIVE flag
    retval &= csepicADC_Start();              // Start ADC

    // Enable SEPIC converter and reset state machine to INITIALIZE
    //csepicInstance->status.bits.enabled = true;   // Enable SEPIC Converter
    csepicInstance->status.bits.enabled = false;   // disable SEPIC Converter; enabling through application layer
    csepicInstance->state_id.value = (uint32_t)CSEPIC_OPSTATE_INITIALIZE; // Reset state machine

    return(retval);
}

/*******************************************************************************
 * @fn	volatile uint16_t dev_csepicConverter_Stop(volatile CSEPIC_CONVERTER_t * csepicInstance)
 * @ingroup lib-layer-sepic-converter-functions-public
 * @brief  This function stop the SEPIC converter opration
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 * 
 * @details
 * This function stops the SEPIC converter operation by shutting down the PWM generator, 
 * disabling the voltage/current loop and reset the state machine to Initialize.
 * 
 *********************************************************************************/

volatile uint16_t dev_csepicConverter_Stop(volatile CSEPIC_CONVERTER_t *csepicInstance) {

    volatile uint16_t retval=1;
    volatile uint16_t _i=0;
    
    // Stop PWM completely (shuts down PWM generator)
    retval &= csepicPWM_Stop(csepicInstance); // Stop PWM
    
    csepicInstance->v_loop.controller->status.bits.enabled = false; // Disable voltage loop
    
    if ((csepicInstance->set_values.control_mode == CSEPIC_CONTROL_MODE_ACMC) || (csepicInstance->set_values.control_mode == CSEPIC_CONTROL_MODE_CCMC)) {// In current mode...
        for (_i=0; _i<csepicInstance->set_values.no_of_phases; _i++)
        { csepicInstance->i_loop[_i].controller->status.bits.enabled = false; } // Disable current loop
    }
    
    csepicInstance->status.bits.enabled = false;  // Disable SEPIC Converter
    csepicInstance->state_id.value = (uint32_t)CSEPIC_OPSTATE_INITIALIZE; // Reset state machine

    return(retval);
}

/*******************************************************************************
 * @ingroup lib-layer-sepic-converter-functions-public
 * @fn	volatile uint16_t dev_csepicConverter_Suspend(volatile CSEPIC_CONVERTER_t * csepicInstance)
 * @brief  This function suspends the operation of the SEPIC converter
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 *
 * @details
 * This function sets the suspend bit terminating operation. This bit will be evaluated in the
 * State machine tasks which eventually shuts down the operation of the SEPIC converter.
 *********************************************************************************/

volatile uint16_t dev_csepicConverter_Suspend(volatile CSEPIC_CONVERTER_t *csepicInstance) {
    
    volatile uint16_t retval=1;
    
    csepicInstance->status.bits.suspend = true;  // Set SUSPEND bit terminating operation
    retval &= dev_csepicConverter_Execute(csepicInstance);  // Enforce state switch immediately
    
    return(retval);
}

/*******************************************************************************
 * @fn	volatile uint16_t dev_csepicConverter_Resume(volatile CSEPIC_CONVERTER_t * csepicInstance)
 * @ingroup lib-layer-sepic-converter-functions-public
 * @brief   This function resume the operation of the SEPIC converter
 * @param	csepicInstance  Pointer to a SEPIC Converter data object of type CSEPIC_CONVERTER_t
 * @return  unsigned integer (0=failure, 1=success)
 * 
 * @details
 * This function executes the latest task in the state machine enforcing state switch immediately.
 *********************************************************************************/

volatile uint16_t dev_csepicConverter_Resume(volatile CSEPIC_CONVERTER_t *csepicInstance) {
    
    volatile uint16_t retval=1;
    
    csepicInstance->status.bits.suspend = false;  // Reset running state machine
    retval &= dev_csepicConverter_Execute(csepicInstance);  // Enforce state switch immediately
    
    return(retval);
}

// end of file
