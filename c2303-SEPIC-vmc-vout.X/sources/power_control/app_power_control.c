/*
 * File:   app_power_control.c
 * Author: M91406
 *
 * Created on March 12, 2020, 11:55 AM
 */

#include <xc.h>
#include <stdbool.h>

#include "devices/dev_sepic_typedef.h"
#include "devices/dev_sepic_converter.h"
#include "config/mcal.h"
#include "config/hal.h"

#include "fault_handler/app_fault_monitor.h"

/**************************************************************************************************
 * @ingroup app-layer-power-control-properties-public
 * @var volatile CSEPIC_CONVERTER_t  csepic
 * @brief Global data object for a SEPIC CONVERTER 
 * 
 * @details
 * The 'csepic' data object holds all status, control and monitoring values of the SEPIC
 * power controller. The CSEPIC_CONVERTER_t data structure is defined in dev_sepic_converter.h.
 * Please refer to the comments on top of this file for further information.
 * 
 **************************************************************************************************/
volatile CSEPIC_CONVERTER_t csepic;
//#endif


/* PRIVATE FUNCTION PROTOTYPES */
extern volatile uint16_t appPowerSupply_ConverterObjectInitialize(void);
extern volatile uint16_t appPowerSupply_SwitchNodeInitialize(void);
extern volatile uint16_t appPowerSupply_GpioInitialize(void);
extern volatile uint16_t appPowerSupply_FeedbackInitialize(void);
extern volatile uint16_t appPowerSupply_StartupInitialize(void);
extern volatile uint16_t appPowerSupply_ControllerInitialize(void);
extern volatile uint16_t appPowerSupply_PeripheralsInitialize(void);
extern volatile uint16_t appPowerSupply_InterruptsInitialize(void);

/* PRIVATE INTERNAL FUNCTION PROTOTYPES */
volatile uint16_t appPowerSupply_DataCapture(void);

/* *************************************************************************************************
 * PRIVATE VARIABLE DECLARATIONS
 * ************************************************************************************************/
#define ISNS_AVG_BITMASK    (uint16_t)0x0007

/* *************************************************************************************************
 * PUBLIC FUNCTIONS
 * ************************************************************************************************/

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-public
 * @fn	volatile uint16_t appPowerSupply_Execute(void)
 * @brief This is the top-level function call triggering the most recent state 
 * machine of all associated power supply controllers
 * @return 0=failure
 * @return 1=success
 * 
 * @details 
 * After initialization, the proprietary user code has to call this function 
 * on a deterministic, constant time base. In each execution step this function
 * will call the power control state machines of each supported/included power
 * supply unit. 
 * 
 *********************************************************************************/

volatile uint16_t appPowerSupply_Execute(void)
{ 
    volatile uint16_t retval=1;

    if (csepic.status.bits.enabled == false)
    {
        csepic.status.bits.enabled = true; 
    }
    
    // Capture data values, which are not captured by the controller automatically
    retval &= appPowerSupply_DataCapture();
    
    // Execute SEPIC converter state machine
    retval &= dev_csepicConverter_Execute(&csepic);

    // SEPIC regulation error is only active while controller is running
    // and while being tied to a valid reference
    if(((csepic.state_id.bits.opstate_id  >= CSEPIC_OPSTATE_RAMPUP) &&
        (csepic.state_id.bits.substate_id >= CSEPIC_OPSTATE_V_RAMP_UP)) ||
       ((csepic.state_id.bits.opstate_id  == CSEPIC_OPSTATE_ONLINE)))
    {
        if (csepic.set_values.control_mode != CSEPIC_CONTROL_MODE_CCMC)
        {
            fltobj_CsepicRegErr.ReferenceObject.ptrObject = csepic.v_loop.controller->Ports.ptrControlReference;
        } else
        {
            fltobj_CsepicRegErr.ReferenceObject.ptrObject = csepic.i_loop[0].controller->Ports.ptrControlReference;
        }
        
        #if (PLANT_MEASUREMENT == false)
// ToDo: regulation error must be switched between constant current and constant voltage modes
//       reg error only refers to "output voltage vs reference" comparison
        //fltobj_CsepicRegErr.Status.bits.Enabled = csepic.v_loop.controller->status.bits.enabled;
        //fltobj_CsepicOCP.Status.bits.Enabled = csepic.v_loop.controller->status.bits.enabled;
        #endif
    }
    else {
        fltobj_CsepicRegErr.Status.bits.Enabled = false;
        fltobj_CsepicOCP.Status.bits.Enabled = false;
    }
    
    return(retval); 
}

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-public
 * @fn	volatile uint16_t appPowerSupply_Initialize(void)
 * @brief  Calls the application layer power controller initialization
 * @return 0=failure
 * @return 1=success
 * 
 * @details 
 * The power control application layer is the proprietary user code layer
 * used to tailor the generic power converter device driver to the specific 
 * hardware of this design. The initialization routine covers three levels
 * 
 * - Converter Object Configuration
 * - Controller Configuration
 * - Peripheral Set Configuration
 * - Interrupt Vector Configuration
 * 
 * Once all modules have been configured successfully, the power converter 
 * object is started with control loops and PWM outputs disabled. However, 
 * the PWM module will start triggering the ADC to allow the standby monitoring
 * of system conditions to allow the firmware to decide if it is safe to start
 * up the power converter.
 * 
 *********************************************************************************/

volatile uint16_t appPowerSupply_Initialize(void)
{ 
    volatile uint16_t retval=1;

    // Run initialization sequence
    // Run initialization sequence
    retval &= appPowerSupply_ConverterObjectInitialize();
    retval &= appPowerSupply_SwitchNodeInitialize();
    retval &= appPowerSupply_GpioInitialize();
    retval &= appPowerSupply_FeedbackInitialize();
    retval &= appPowerSupply_StartupInitialize();
    retval &= appPowerSupply_ControllerInitialize();
    retval &= appPowerSupply_PeripheralsInitialize();
    retval &= appPowerSupply_InterruptsInitialize();
    
    return(retval); 
}

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-public
 * @fn	volatile uint16_t appPowerSupply_Start(void)
 * @brief  This function calls the SEPIC converter device driver function starting the power supply 
 * @return 0=failure
 * @return 1=success
 *  
 * @details 
 *  This function exposes the Power Converter Start function of the device driver.
 *********************************************************************************/

volatile uint16_t appPowerSupply_Start(void)
{
    volatile uint16_t retval=1;

    retval &= dev_csepicConverter_Start(&csepic); // Start PWM with outputs disabled to start ADC triggering

    return(retval); 
}

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-public
 * @fn	volatile uint16_t appPowerSupply_Stop(void)
 * @brief This function calls the SEPIC converter device driver function stopping the power supply 
 * @return 0=failure
 * @return 1=success
 *  
 * @details
 *  This function exposes the Power Converter Stop function of the device driver.
 * 
 * @note
 *  The STOP function terminates the state machine and all peripherals used by
 *  the power controller. This includes the PWM and ADC peripheral modules and 
 *  will therefore also stop all data acquisition. 
 *  If you are trying to stop the power supply but keep its state machine and
 *  data acquisition running, use the SUSPEND function instead
 * 
 *********************************************************************************/

volatile uint16_t appPowerSupply_Stop(void)
{
    volatile uint16_t retval=1;

    retval &= dev_csepicConverter_Stop(&csepic); // Shut down all power supply peripherals and data objects

    return(retval); 
}
/*******************************************************************************
 * @ingroup app-layer-power-control-functions-public
 * @fn	   volatile uint16_t appPowerSupply_Suspend(void)
 * @brief  This function stops the power supply operation
 * @return 0=failure
 * @return 1=success
 *  
 * @details
 *  The SUSPEND function stops the power supply operation but keep its state machine
 *  and data acquisition running.
 *********************************************************************************/

volatile uint16_t appPowerSupply_Suspend(void)
{ 
    volatile uint16_t retval=1;

    retval &= dev_csepicConverter_Suspend(&csepic); // Shut down PWM immediately

    return(retval); 
}

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-public
 * @fn	   volatile uint16_t appPowerSupply_Resume(void)
 * @brief  This function resumes the power supply operation
 * @return unsigned integer (0=failure, 1=success)
 *  
 * @details
 *  This function calls the SEPIC converter device driver function recovering
 *  the power supply operation from a previously initiated shut-down.
 * 
 *********************************************************************************/

volatile uint16_t appPowerSupply_Resume(void)
{ 
    volatile uint16_t retval=0;

    retval &= dev_csepicConverter_Resume(&csepic); // Shut down PWM immediately
    
    return(retval); 
}

/* *************************************************************************************************
 * PRIVATE FUNCTIONS
 * ************************************************************************************************/

/*********************************************************************************
 * @ingroup app-layer-power-control-functions-private
 * @fn      volatile uint16_t appPowerSupply_DataCapture(void)
 * @brief   Captures runtime data not captured automatically by other firmware modules
 * @return  unsigned integer (0=failure, 1=success)
 * @details
 *  Function appPowerSupply_DataCapture is used to capture runtime data from
 *  ADC inputs which are not used for direct control of the power supply and/or
 *  are used to calculate additional data which is required for system analysis
 *  functions such as fault management, system monitoring and/or communication. 
 * 
 **********************************************************************************/

volatile uint16_t appPowerSupply_DataCapture(void) 
{
    volatile uint16_t retval=0;
    static volatile uint16_t _isns_sample_count = 0;
    static volatile int16_t _isns_samples;

    // Capture runtime data
    csepic.data.v_in = (CSEPIC_VIN_ADCBUF - CSEPIC_VIN_OFFSET);
    
    
    // if control mode is CCMC, no voltage loop running to output output voltage ADC value to data provider
    if (csepic.set_values.control_mode == CSEPIC_CONTROL_MODE_CCMC)
    {
        csepic.data.v_out = (CSEPIC_FB_VOUT_ADCBUF - CSEPIC_VOUT_OFFSET);
    } else
    {
        csepic.data.i_sns[0] = (CSEPIC_ISNS_ADCBUF - CSEPIC_ISNS_FB_OFFSET);
    }
    //csepic.data.v_out_in_V = (float) (csepic.data.v_out * ADC_GRANULARITY * CSEPIC_VOUT_NORM_INV_G);
    
    // WARNING: Disable Data Provider in DCLD tool or the 0 clamp below will not work when offset is applied to vout
    //          DataProvider from assembly routine pushes values in csepic instance structure at compensator rate
    //          which will overwrite this DataCapture clamp with true Vout-Voffset (<0 at startup)
    //if ((int16_t)csepic.data.v_out < 0) csepic.data.v_out = 0; // 0 clamping to Vout value as non-0 offset will drive negative number at startup (not to trigger wrong Faults in RegErr fault object))

    // Track average inductor current value
    _isns_samples += csepic.data.i_sns[0];  // accumulate instantaneous phase current
    
    if(!(++_isns_sample_count & ISNS_AVG_BITMASK)) // If averaging window is complete...
    {
        _isns_samples = (_isns_samples >> 3);               // Build average value
        _isns_samples -= csepic.i_loop[0].feedback_offset;  // subtract offset
        if((int16_t)_isns_samples < 0) _isns_samples = 0;   // Clamp offset to Zero
        csepic.data.i_out = _isns_samples;                  // write result to output current data buffer
        _isns_samples = 0;                                  // clear averaging data buffer
    }
    
    if (csepic.state_id.bits.opstate_id == CSEPIC_OPSTATE_ONLINE)
            csepic.i_loop[0].controller->status.bits.agc_enabled = true;   

    
    return(retval); 
}

// end of file
