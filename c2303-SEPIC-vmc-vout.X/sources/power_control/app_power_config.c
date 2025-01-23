/*
 * File:   app_power_config.c
 * Author: M91406
 *
 * Created on January 13, 2021, 12:18 PM
 */


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer data types
#include <stdbool.h> // include standard boolean data types
#include <stddef.h> // include standard definition data types

#include "config/mcal.h" // include microcontroller abstraction layer declarations
#include "config/hal.h" // include hardware abstraction layer declarations
#include "app_power_control.h"

#include "devices/dev_sepic_converter.h"
#include "drivers/v_loop.h"
#include "drivers/i_loop.h"
#include "drivers/i_loop_agc.h"

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-private
 * @fn	volatile uint16_t appPowerSupply_ConverterObjectInitialize(void)
 * @brief  This function initializes the SEPIC converter device driver instance
 * @return unsigned integer (0=failure, 1=success)
 *  
 * @details
 *  This function initialize the SEPIC converter object status, reset the SEPIC state 
 *  machine, set reference values, clear the runtime data, initialize the switch node,
 *  and setup the feedback channels and start-up settings.
 *********************************************************************************/

volatile uint16_t appPowerSupply_ConverterObjectInitialize(void)
{
    volatile uint16_t retval = 1;
    
    // Initialize SEPIC Converter Object Status
    csepic.status.bits.ready = false; // Clear READY flag
    csepic.status.bits.adc_active = false; // Clear ADC STARTED flag
    csepic.status.bits.pwm_active = false; // clear PWM STARTED flag
    csepic.status.bits.fault_active = true; // Set global FAULT flag
    
    csepic.status.bits.cs_calib_enable = CSEPIC_ISNS_OFFSET_CALIBRATION_ENABLE; // Disable current sense feedback calibration
    csepic.status.bits.autorun = true;    // Allow the SEPIC converter to start automatically when cleared of faults
    csepic.status.bits.enabled = false; // Disable SEPIC converter
 
    // Set Initial State Machine State
    csepic.state_id.value = CSEPIC_OPSTATE_INITIALIZE; // Reset SEPIC State Machine
    
    // Set Reference values
    csepic.set_values.control_mode = CSEPIC_CONTROL_MODE_VMC; // Set Control Mode
    //csepic.set_values.control_mode = CSEPIC_CONTROL_MODE_CCMC; // Set Control Mode
    //csepic.set_values.control_mode = CSEPIC_CONTROL_MODE_ACMC; // Set Control Mode
    
    csepic.set_values.no_of_phases = CSEPIC_NO_OF_PHASES; // Set number of power train phases
    csepic.set_values.i_ref = CSEPIC_ISNS_OCL; // Set current loop maximum
    if (csepic.set_values.control_mode == CSEPIC_CONTROL_MODE_CCMC)
    {
        csepic.set_values.v_ref = CSEPIC_VOUT_OVP_TRIP_CMP; // Set voltage loop reference
        csepic.set_values.v_ref_previous = CSEPIC_VOUT_OVP_TRIP_CMP; // Init previous voltage setting driving voltage loop (used to identify voltage guidance change in LED Driver mode)
    } else
    {
        csepic.set_values.v_ref = CSEPIC_VOUT_REF; // Set voltage loop reference
        csepic.set_values.v_ref_previous = CSEPIC_VOUT_REF; // Init previous voltage setting driving voltage loop (used to identify voltage guidance change in LED Driver mode in ACMC)
    }
    
    csepic.set_values.v_slew_rate = CSEPIC_VOUT_REF_SLEWRATE; // Set voltage transition slew rate applied during runtime reference tuning
    csepic.set_values.i_slew_rate = CSEPIC_ISNS_REF_SLEWRATE; // Set current transition slew rate applied during runtime reference tuning
    
    // Clear Runtime Data
    csepic.data.v_out = 0; // Reset output voltage value
    csepic.data.i_sns[0] = 0; // Reset output current value
    csepic.data.v_in = 0;  // Reset input voltage value
    csepic.data.temp = 0;  // Reset output temperature value
    

    return(retval);
    
}

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-private
 * @fn	volatile uint16_t appPowerSupply_SwitchNodeInitialize(void)
 * @brief  This function initializes the switch node of the buck converter device driver instance 
 * @return unsigned integer (0=failure, 1=success)
 *  
 * @details
 *  This function initializes the switch node of the buck converter object by 
 *  assigning it to a specific PWM generator instance and setting the associated 
 *  GPIO pins. Further, users need to specify basic parameters like commutation 
 *  mode (synchronous or asynchronous drive), switching frequency, phase shift,
 *  duty ratio clamping values, dead times, leading edge blanking and ADC 
 *  trigger offsets to compensate propagation delays of FET drivers and feedback
 *  bandwidth limitations.
 *********************************************************************************/

volatile uint16_t appPowerSupply_SwitchNodeInitialize(void)
{
    volatile uint16_t retval = 1;
 
    // Initialize Switch Node
    csepic.sw_node[0].period = CSEPIC_PWM_PERIOD;
    csepic.sw_node[0].high_resolution_enable = PWM_CLOCK_HIGH_RESOLUTION;

    csepic.sw_node[0].sepic_switch.pwm_instance = CSEPIC_PWM_CHANNEL;
    csepic.sw_node[0].sepic_switch.gpio_instance = CSEPIC_PWM_GPIO_INSTANCE;
    //csepic.sw_node[0].sepic_switch.gpio_high = CSEPIC_PWM_GPIO_PORT_PINH;
    csepic.sw_node[0].sepic_switch.gpio_low = PWM_SEPIC_GPIO_PORT_PIN;
    csepic.sw_node[0].sepic_switch.swap_outputs = CSEPIC_PWM_OUTPUT_SWAP; // Low-side driver, swap enabled!
    csepic.sw_node[0].sepic_switch.sync_drive = false; 
    csepic.sw_node[0].sepic_switch.phase = CSEPIC_PWM_PHASE_SHIFT;
    csepic.sw_node[0].sepic_switch.duty_ratio_min = (CSEPIC_PWM_DC_MIN + CSEPIC_PWM_DEAD_TIME_FE);
    csepic.sw_node[0].sepic_switch.duty_ratio_init = CSEPIC_PWM_DC_MIN;
    csepic.sw_node[0].sepic_switch.duty_ratio_max = CSEPIC_PWM_DC_MAX;
    csepic.sw_node[0].sepic_switch.dead_time_rising = CSEPIC_PWM_DEAD_TIME_LE;
    csepic.sw_node[0].sepic_switch.dead_time_falling = CSEPIC_PWM_DEAD_TIME_FE;
    csepic.sw_node[0].sepic_switch.leb_period = CSEPIC_LEB_PERIOD;
    csepic.sw_node[0].sepic_switch.trigger_offset = CSEPIC_PWM_ADTR1OFS;
    csepic.sw_node[0].sepic_switch.trigger_scaler = CSEPIC_PWM_ADTR1PS;
    
    return(retval);
    
}

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-private
 * @fn	volatile uint16_t appPowerSupply_GpioInitialize(void)
 * @brief  This function initializes the IO functions of the buck converter device driver instance 
 * @return unsigned integer (0=failure, 1=success)
 *  
 * @details
 *  This function initializes the optional Input/Output functions of the buck
 *  converter device driver instance used to provide external sequencing control,
 *  such as ENABLE Input and Power Good Output. These optional features can be 
 *  individually enabled and mapped to any available device GPIO.
 *********************************************************************************/

volatile uint16_t appPowerSupply_GpioInitialize(void)
{
    volatile uint16_t retval = 1;

    // Initialize additional GPIOs 
    
    // ~~~ EXTERNAL ENABLE INPUT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    csepic.gpio.EnableInput.enabled = false; // this converter doesn't support external enable control
    // ~~~ EXTERNAL ENABLE INPUT END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    // ~~~ POWER GOOD OUTPUT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    csepic.gpio.PowerGood.enabled = false; // This converter supports an additional POWER GOOD output
    // ~~~ POWER GOOD OUTPUT END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    return(retval);
    
}

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-private
 * @fn	volatile uint16_t appPowerSupply_FeedbackInitialize(void)
 * @brief  This function initializes the feedback channels of the buck converter device driver instance 
 * @return unsigned integer (0=failure, 1=success)
 *  
 * @details
 *  This function initializes the supported feedback channels of the buck
 *  converter device driver instance used for system monitoring and control.
 *  A buck converter instance supports the following standard feedback 
 *  channels:
 * 
 * - Input Voltage:    (used for protection and advanced linearization control)
 * - Output Voltage:   (used for output voltage control)
 * - Inductor Current
 * - Temperature
 * 
 *********************************************************************************/

volatile uint16_t appPowerSupply_FeedbackInitialize(void)
{
    volatile uint16_t retval = 1;

    // Initialize Feedback Channels
    
    // ~~~ OUTPUT VOLTAGE FEEDBACK ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    csepic.feedback.ad_vout.enabled = true;   // Use this channel

    csepic.feedback.ad_vout.adc_input = CSEPIC_FB_VOUT_ADCIN;
    csepic.feedback.ad_vout.adc_core = CSEPIC_FB_VOUT_ADCCORE;
    csepic.feedback.ad_vout.adc_buffer = &CSEPIC_FB_VOUT_ADCBUF;
    csepic.feedback.ad_vout.trigger_source = CSEPIC_FB_VOUT_TRGSRC;

    csepic.feedback.ad_vout.differential_input = false;
    csepic.feedback.ad_vout.interrupt_enable = true;
    csepic.feedback.ad_vout.early_interrupt_enable = true;
    csepic.feedback.ad_vout.level_trigger = true;
    csepic.feedback.ad_vout.signed_result = false;
    
    csepic.feedback.ad_vout.scaling.factor = CSEPIC_VOUT_NORM_FACTOR;
    csepic.feedback.ad_vout.scaling.scaler = CSEPIC_VOUT_NORM_SCALER;
    csepic.feedback.ad_vout.scaling.offset = CSEPIC_VOUT_OFFSET;

    CSEPIC_FB_VOUT_ANSEL = csepic.feedback.ad_vout.enabled;
    
    // ~~~ OUTPUT VOLTAGE FEEDBACK END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    // ~~~ INPUT VOLTAGE FEEDBACK ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    csepic.feedback.ad_vin.enabled = true;   // Use this channel

    csepic.feedback.ad_vin.adc_input = CSEPIC_VIN_ADCIN;
    csepic.feedback.ad_vin.adc_core = CSEPIC_VIN_ADCCORE;
    csepic.feedback.ad_vin.adc_buffer = &CSEPIC_VIN_ADCBUF;
    csepic.feedback.ad_vin.trigger_source = CSEPIC_VIN_TRGSRC;

    csepic.feedback.ad_vin.differential_input = false;
    csepic.feedback.ad_vin.interrupt_enable = false;
    csepic.feedback.ad_vin.early_interrupt_enable = false;
    csepic.feedback.ad_vin.level_trigger = false;
    csepic.feedback.ad_vin.signed_result = false;

    csepic.feedback.ad_vin.scaling.factor = CSEPIC_VIN_NORM_FACTOR;
    csepic.feedback.ad_vin.scaling.scaler = CSEPIC_VIN_NORM_SCALER;
    csepic.feedback.ad_vin.scaling.offset = CSEPIC_VIN_OFFSET;

    CSEPIC_VIN_ANSEL = csepic.feedback.ad_vin.enabled;
    
    // ~~~ INPUT VOLTAGE FEEDBACK END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~ OUTPUT CURRENT FEEDBACK ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    csepic.feedback.ad_isns[0].enabled = true;   // Use this channel

    csepic.feedback.ad_isns[0].adc_input = CSEPIC_ISNS_ADCIN;
    csepic.feedback.ad_isns[0].adc_core = CSEPIC_ISNS_ADCCORE;
    csepic.feedback.ad_isns[0].adc_buffer = &CSEPIC_ISNS_ADCBUF;
    csepic.feedback.ad_isns[0].trigger_source = CSEPIC_ISNS_TRGSRC;

    csepic.feedback.ad_isns[0].differential_input = false;
    csepic.feedback.ad_isns[0].interrupt_enable = false;
    csepic.feedback.ad_isns[0].early_interrupt_enable = false;
    csepic.feedback.ad_isns[0].level_trigger = true;
    csepic.feedback.ad_isns[0].signed_result = false;

    csepic.feedback.ad_isns[0].scaling.factor = CSEPIC_ISNS_NORM_FACTOR;
    csepic.feedback.ad_isns[0].scaling.scaler = CSEPIC_ISNS_NORM_SCALER;
    csepic.feedback.ad_isns[0].scaling.offset = CSEPIC_ISNS_FB_OFFSET;

    CSEPIC_ISNS_ANSEL = csepic.feedback.ad_isns[0].enabled;
    
    // ~~~ OUTPUT CURRENT FEEDBACK END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~ TEMPERATURE FEEDBACK ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    csepic.feedback.ad_temp.enabled = false;   // Use this channel
    // ~~~ TEMPERATURE FEEDBACK END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    return(retval);
}

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-private
 * @fn	volatile uint16_t appPowerSupply_StartupInitialize(void)
 * @brief  This function initializes the startup configuration of the buck converter device driver instance 
 * @return unsigned integer (0=failure, 1=success)
 *  
 * @details
 *  This function initializes the startup configuration of the buck converter 
 *  device driver instance. A buck converter instance supports the following 
 *  startup options:
 * 
 * - Power-On Delay:   
 *   User-specified delay before the output voltage is ramping up
 * 
 * - VRamp-Up Period:  
 *   User specified output voltage ramp-up period in which the output voltage 
 *   is ramped up linearly from 0 to nominal output voltage
 * 
 * - IRamp-Up Period:  
 *   User specified output current ramp-up period; This function is only 
 *   available in average current mode control and only if a current limit 
 *   is hit during a voltage ramp-up and the output voltage cannot reach the 
 *   nominal level. under these conditions the state machine will switch over
 *   to state IRamp-Up and linearly increase the current limit up to the 
 *   allowed absolute maximum current. 
 *   This mode has been introduced especially for battery chargers or when
 *   converters are powering up against large capacitive loads.
 * 
 * - Power Good Delay: 
 *   User-specified period during which the output must stand stable before 
 *   the output is considered to be reliable
 * 
 * optional:
 * - Open Loop Startup: 
 *   Specific startup mode in average current mode control, where the PWM 
 *   output is increased manually in open loop while the output is monitored.
 *   This mode was introduced to bridge limited common mode voltage ranges
 *   of certain current sense circuits, which require a certain, minimum 
 *   voltage to be applied across the sense points before they start to 
 *   produce reliable feedback signals.
 * 
 *********************************************************************************/

volatile uint16_t appPowerSupply_StartupInitialize(void)
{
    volatile uint16_t retval = 1;

    // Initialize Startup Settings
    
    csepic.startup.power_on_delay.period = CSEPIC_POD;
    
    csepic.startup.v_ramp.period = CSEPIC_VRAMP_PER;
    csepic.startup.v_ramp.ref_inc_step = CSEPIC_VREF_STEP;
    csepic.startup.v_ramp.ref_minimum = CSEPIC_ISNS_CMOD_LIMIT;
    
    if ((csepic.set_values.control_mode == CSEPIC_CONTROL_MODE_ACMC) || (csepic.set_values.control_mode == CSEPIC_CONTROL_MODE_CCMC))
    {
        csepic.startup.i_ramp.period = CSEPIC_IRAMP_PER;
        csepic.startup.i_ramp.ref_inc_step = CSEPIC_IREF_STEP;
        csepic.startup.i_ramp.ref_start_limit = CSEPIC_ISNS_START_LIMIT;
        
        csepic.startup.open_loop.enabled = CSEPIC_OPEN_LOOP_STARTUP; // Enable/disable open loop startup with average current sense amplifier
        csepic.startup.open_loop.vout_cutoff = CSEPIC_ISNS_CMOD_LIMIT; // Set common mode voltage limit as open loop cut-off voltage level
        
    }
    else
    {
        //csepic.startup.open_loop.enabled = false;
        //csepic.startup.open_loop.vout_cutoff = CSEPIC_VOUT_NOM;
        csepic.startup.open_loop.enabled = CSEPIC_OPEN_LOOP_STARTUP;
        csepic.startup.open_loop.vout_cutoff = CSEPIC_ISNS_CMOD_LIMIT;
    }
    
    csepic.startup.power_good_delay.period = CSEPIC_PGD;
    csepic.startup.power_good_delay.reference = CSEPIC_VOUT_REF;
    
    
    return(retval);
}

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-private
 * @fn	volatile uint16_t appPowerSupply_ControllerInitialize(void)
 * @brief  This function initializes the control system feedback loop objects
 * @return 0=failure
 * @return 1=success
 * 
 * @details
 * This function allows the user to set up and initialize the loop configuration. This 
 * includes the following setup.
 *     - Initialize Default Loop Configuration
 *     - Set Controller Object of Voltage Loop
 *     - Configure Voltage Loop Controller Object
 *     - Configure controller input/output ports
 *     - Data Input/Output Limit Configuration
 *     - ADC Trigger Control Configuration
 *     - Data Provider Configuration
 *     - Cascaded Function Configuration
 *     - Initialize Advanced Control Settings 
 *     - Custom Advanced Control Settings
 *********************************************************************************/

volatile uint16_t appPowerSupply_ControllerInitialize(void)
{
    volatile uint16_t retval = 1;
    
    // ~~~ VOLTAGE LOOP CONFIGURATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    // Initialize Default Loop Configuration
    switch (csepic.set_values.control_mode)
    {
        case CSEPIC_CONTROL_MODE_VMC:
            csepic.v_loop.feedback_offset = CSEPIC_VOUT_OFFSET;
            csepic.v_loop.reference = CSEPIC_VOUT_REF;
            csepic.v_loop.minimum = 0; // Control output range minimum = Duty cycle = 0
            csepic.v_loop.maximum = CSEPIC_PWM_DC_MAX; // Control output range maximum = maximum duty cycle
            csepic.v_loop.trigger_offset = (CSEPIC_PWM_PERIOD >> 1)+ CSEPIC_VOUT_ADC_TRGDLY;    // TSW/2 offset to trig on TOFF/2
            
            // Set Controller Object of Voltage Loop
            csepic.v_loop.controller = &v_loop;
            csepic.v_loop.ctrl_Initialize = &v_loop_Initialize;
            csepic.v_loop.ctrl_Update = &v_loop_Update;
            csepic.v_loop.ctrl_Reset = &v_loop_Reset;
            csepic.v_loop.ctrl_Precharge = &v_loop_Precharge;

            // Configure Voltage Loop Controller Object
            csepic.v_loop.ctrl_Initialize(&v_loop);   // Call Initialization Routine setting histories and scaling

            // Configure controller input ports
            csepic.v_loop.controller->Ports.Source.ptrAddress = &CSEPIC_FB_VOUT_ADCBUF; // Output Voltage is Common Source
            csepic.v_loop.controller->Ports.Source.Offset = csepic.v_loop.feedback_offset; // Output Voltage feedback signal offset 
            csepic.v_loop.controller->Ports.Source.NormScaler = CSEPIC_VOUT_NORM_SCALER; // Output voltage normalization factor bit-shift scaler 
            csepic.v_loop.controller->Ports.Source.NormFactor = CSEPIC_VOUT_NORM_FACTOR; // Output voltage normalization factor fractional

            csepic.v_loop.controller->Ports.AltSource.ptrAddress = &CSEPIC_VIN_ADCBUF; // Input Voltage Is Alternate Source
            csepic.v_loop.controller->Ports.AltSource.Offset = CSEPIC_VIN_OFFSET; // Input Voltage feedback signal offset 
            csepic.v_loop.controller->Ports.AltSource.NormScaler = CSEPIC_VIN_NORM_SCALER; // Input voltage normalization factor bit-shift scaler 
            csepic.v_loop.controller->Ports.AltSource.NormFactor = CSEPIC_VIN_NORM_FACTOR; // Input voltage normalization factor fractional
            
            // Configure controller output ports
            csepic.v_loop.controller->Ports.Target.ptrAddress = &CSEPIC_PWM_PDC; // PWM Duty Cycle is Control Target in VMC
            
            csepic.v_loop.controller->Ports.Target.Offset = 0; // Static primary output value offset

            csepic.v_loop.controller->Ports.Target.NormScaler = 0; // Primary control output normalization factor bit-shift scaler 
            csepic.v_loop.controller->Ports.Target.NormFactor = 0x7FFF; // Primary control output normalization factor fractional 

            csepic.v_loop.controller->Ports.AltTarget.ptrAddress = NULL; // No alternate target used
            csepic.v_loop.controller->Ports.AltTarget.Offset = 0; // Static secondary output value offset
            csepic.v_loop.controller->Ports.AltTarget.NormScaler = 0; // Secondary control output normalization factor bit-shift scaler
            csepic.v_loop.controller->Ports.AltTarget.NormFactor = 0x7FFF; // Secondary control output normalization factor fractional 

            // Configure controller control ports
            csepic.v_loop.controller->Ports.ptrControlReference = &csepic.v_loop.reference; // Set pointer to Reference

            // Data Input/Output Limit Configuration
            csepic.v_loop.controller->Limits.MinOutput = csepic.v_loop.minimum;
            csepic.v_loop.controller->Limits.MaxOutput = csepic.v_loop.maximum;
            csepic.v_loop.controller->Limits.AltMinOutput = 0; // not used
            csepic.v_loop.controller->Limits.AltMaxOutput = 0; // not used
            csepic.status.bits.v_loop_clamped =0; // init flag to voltage loop output is not clamped to maximum limit (Used in LED driver / CCMC mode)

            // ADC Trigger Control Configuration
            csepic.v_loop.controller->ADCTriggerControl.ptrADCTriggerARegister = &CSEPIC_FB_VOUT_ADCTRIG;
            csepic.v_loop.controller->ADCTriggerControl.ADCTriggerAOffset = csepic.v_loop.trigger_offset;
            csepic.v_loop.controller->ADCTriggerControl.ptrADCTriggerBRegister = &CSEPIC_VIN_ADCTRIG;
            csepic.v_loop.controller->ADCTriggerControl.ADCTriggerBOffset = 0; 

            // Data Provider Configuration
            csepic.v_loop.controller->DataProviders.ptrDProvControlInput = &csepic.data.control_input; 
            csepic.v_loop.controller->DataProviders.ptrDProvControlInputCompensated = &csepic.data.v_out; 
            csepic.v_loop.controller->DataProviders.ptrDProvControlError = &csepic.data.control_error; 
            csepic.v_loop.controller->DataProviders.ptrDProvControlOutput = &csepic.data.control_output;

            // User Extension Function Configuration
            /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
             * 
             * PowerSmart DCLD allows users to create and call user extension 
             * functions from specific locations of the main control loop to 
             * cover design-specific requirements and features which are not
             * supported by the main controller by default.
             * 
             * Control Loop User Extension Declaration Example:
             * 
             *  csepic.v_loop.controller->ExtensionHooks.ptrExtHookStartFunction = (uint16_t)&my_function; 
             * 
             * Control Loop User Extension Parameter Declaration Example (optional):
             * 
             *  csepic.v_loop.controller->ExtensionHooks.ExtHookStartFunctionParam = 512;
             * 
             * Please refer to the PowerSmart DCLD User Guide for more details about
             * how to use this feature, its requirements and limitations.
             * 
             * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            */

            csepic.v_loop.controller->ExtensionHooks.ptrExtHookStartFunction = (uint16_t)NULL;
            csepic.v_loop.controller->ExtensionHooks.ExtHookStartFunctionParam = 0;
            csepic.v_loop.controller->ExtensionHooks.ptrExtHookSourceFunction = (uint16_t)NULL;
            csepic.v_loop.controller->ExtensionHooks.ExtHookSourceFunctionParam = 0;
            csepic.v_loop.controller->ExtensionHooks.ptrExtHookPreAntiWindupFunction = (uint16_t)NULL;
            csepic.v_loop.controller->ExtensionHooks.ExtHookPreAntiWindupFunctionParam = 0;
            csepic.v_loop.controller->ExtensionHooks.ptrExtHookPreTargetWriteFunction = (uint16_t)NULL;
            csepic.v_loop.controller->ExtensionHooks.ExtHookPreTargetWriteFunctionParam = 0;
            csepic.v_loop.controller->ExtensionHooks.ptrExtHookExitFunction = (uint16_t)NULL;
            csepic.v_loop.controller->ExtensionHooks.ExtHookExitFunctionParam = 0;
            
            csepic.v_loop.controller->ExtensionHooks.ptrExtHookEndOfLoopFunction = (uint16_t)NULL;
            csepic.v_loop.controller->ExtensionHooks.ExtHookEndOfLoopFunctionParam = 0;
            
            csepic.v_loop.controller->GainControl.AgcFactor = 0x7FFF; // Adaptive Gain Control factor fractional
            csepic.v_loop.controller->GainControl.AgcScaler = 0x0000; // Adaptive Gain Control factor bit-shift scaler
            csepic.v_loop.controller->GainControl.AgcMedian = 0x0000; // Q15 number representing normalized Nominal Operating Point

            // Custom Advanced Control Settings
            csepic.v_loop.controller->Advanced.usrParam0 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam1 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam2 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam3 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam4 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam5 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam6 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam7 = 0; // No additional advanced control options used

            // Reset Controller Status
            csepic.v_loop.controller->status.bits.enabled = false; // Keep controller disabled
            csepic.v_loop.controller->status.bits.swap_source = false; // use SOURCE as major control input
            csepic.v_loop.controller->status.bits.swap_target = false; // use TARGET as major control output
            csepic.v_loop.controller->status.bits.invert_input = false; // Do not invert input value
            csepic.v_loop.controller->status.bits.lower_saturation_event = false; // Reset Anti-Windup Minimum Status bit
            csepic.v_loop.controller->status.bits.upper_saturation_event = false; // Reset Anti-Windup Minimum Status bits
            csepic.v_loop.controller->status.bits.agc_enabled = false;   // Enable Adaptive Gain Modulation by default
            // ~~~ VMC VOLTAGE LOOP CONFIGURATION END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            break;
        
        case CSEPIC_CONTROL_MODE_ACMC:
            csepic.v_loop.feedback_offset = CSEPIC_VOUT_OFFSET;
            csepic.v_loop.reference = CSEPIC_VOUT_REF;
            csepic.v_loop.minimum = CSEPIC_ISNS_MIN; // Control output range minimum = minimum output current
            csepic.v_loop.maximum = CSEPIC_ISNS_OCL; // Control output range maximum = maximum output current
            csepic.v_loop.trigger_offset = CSEPIC_VOUT_ADC_TRGDLY;
            
            // Set Controller Object of Voltage Loop
            csepic.v_loop.controller = &v_loop;
            csepic.v_loop.ctrl_Initialize = &v_loop_Initialize;
            csepic.v_loop.ctrl_Update = &v_loop_Update;
            csepic.v_loop.ctrl_Reset = &v_loop_Reset;
            csepic.v_loop.ctrl_Precharge = &v_loop_Precharge;

            // Configure Voltage Loop Controller Object
            csepic.v_loop.ctrl_Initialize(&v_loop);   // Call Initialization Routine setting histories and scaling

            // Configure controller input ports
            csepic.v_loop.controller->Ports.Source.ptrAddress = &CSEPIC_FB_VOUT_ADCBUF; // Output Voltage is Common Source
            csepic.v_loop.controller->Ports.Source.Offset = csepic.v_loop.feedback_offset; // Output Voltage feedback signal offset 
            csepic.v_loop.controller->Ports.Source.NormScaler = CSEPIC_VOUT_NORM_SCALER; // Output voltage normalization factor bit-shift scaler 
            csepic.v_loop.controller->Ports.Source.NormFactor = CSEPIC_VOUT_NORM_FACTOR; // Output voltage normalization factor fractional

            csepic.v_loop.controller->Ports.AltSource.ptrAddress = &CSEPIC_VIN_ADCBUF; // Input Voltage Is Alternate Source
            csepic.v_loop.controller->Ports.AltSource.Offset = CSEPIC_VIN_OFFSET; // Input Voltage feedback signal offset 
            csepic.v_loop.controller->Ports.AltSource.NormScaler = CSEPIC_VIN_NORM_SCALER; // Input voltage normalization factor bit-shift scaler 
            csepic.v_loop.controller->Ports.AltSource.NormFactor = CSEPIC_VIN_NORM_FACTOR; // Input voltage normalization factor fractional
            
            // Configure controller output ports
            csepic.v_loop.controller->Ports.Target.ptrAddress = &csepic.i_loop[0].reference; // Current loop reference is Control Target in ACMC
            
            csepic.v_loop.controller->Ports.Target.Offset = 0; // Static primary output value offset

            csepic.v_loop.controller->Ports.Target.NormScaler = 0; // Primary control output normalization factor bit-shift scaler 
            csepic.v_loop.controller->Ports.Target.NormFactor = 0x7FFF; // Primary control output normalization factor fractional 

            csepic.v_loop.controller->Ports.AltTarget.ptrAddress = NULL; // No alternate target used
            csepic.v_loop.controller->Ports.AltTarget.Offset = 0; // Static secondary output value offset
            csepic.v_loop.controller->Ports.AltTarget.NormScaler = 0; // Secondary control output normalization factor bit-shift scaler
            csepic.v_loop.controller->Ports.AltTarget.NormFactor = 0x7FFF; // Secondary control output normalization factor fractional 

            // Configure controller control ports
            csepic.v_loop.controller->Ports.ptrControlReference = &csepic.v_loop.reference; // Set pointer to Reference

            // Data Input/Output Limit Configuration
            csepic.v_loop.controller->Limits.MinOutput = csepic.v_loop.minimum;
            csepic.v_loop.controller->Limits.MaxOutput = csepic.v_loop.maximum;
            csepic.v_loop.controller->Limits.AltMinOutput = 0; // not used
            csepic.v_loop.controller->Limits.AltMaxOutput = 0; // not used
            csepic.status.bits.v_loop_clamped =0; // init flag to voltage loop output is not clamped to maximum limit (Used in LED driver / CCMC mode)

            // ADC Trigger Control Configuration
            csepic.v_loop.controller->ADCTriggerControl.ptrADCTriggerARegister = &CSEPIC_FB_VOUT_ADCTRIG;
            csepic.v_loop.controller->ADCTriggerControl.ADCTriggerAOffset = csepic.v_loop.trigger_offset;
            csepic.v_loop.controller->ADCTriggerControl.ptrADCTriggerBRegister = &CSEPIC_ISNS_ADCTRIG;
            csepic.v_loop.controller->ADCTriggerControl.ADCTriggerBOffset = CSEPIC_ISNS_ADC_TRGDLY; 

            // Data Provider Configuration
            csepic.v_loop.controller->DataProviders.ptrDProvControlInput = &csepic.data.control_input; 
            csepic.v_loop.controller->DataProviders.ptrDProvControlInputCompensated = &csepic.data.v_out; 
            csepic.v_loop.controller->DataProviders.ptrDProvControlError = &csepic.data.control_error; 
            csepic.v_loop.controller->DataProviders.ptrDProvControlOutput = &csepic.data.control_output;

            // User Extension Function Configuration
            /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
             * 
             * PowerSmart DCLD allows users to create and call user extension 
             * functions from specific locations of the main control loop to 
             * cover design-specific requirements and features which are not
             * supported by the main controller by default.
             * 
             * Control Loop User Extension Declaration Example:
             * 
             *  csepic.v_loop.controller->ExtensionHooks.ptrExtHookStartFunction = (uint16_t)&my_function; 
             * 
             * Control Loop User Extension Parameter Declaration Example (optional):
             * 
             *  csepic.v_loop.controller->ExtensionHooks.ExtHookStartFunctionParam = 512;
             * 
             * Please refer to the PowerSmart DCLD User Guide for more details about
             * how to use this feature, its requirements and limitations.
             * 
             * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            */

            csepic.v_loop.controller->ExtensionHooks.ptrExtHookStartFunction = (uint16_t)NULL;
            csepic.v_loop.controller->ExtensionHooks.ExtHookStartFunctionParam = 0;
            csepic.v_loop.controller->ExtensionHooks.ptrExtHookSourceFunction = (uint16_t)NULL;
            csepic.v_loop.controller->ExtensionHooks.ExtHookSourceFunctionParam = 0;
            csepic.v_loop.controller->ExtensionHooks.ptrExtHookPreAntiWindupFunction = (uint16_t)NULL;
            csepic.v_loop.controller->ExtensionHooks.ExtHookPreAntiWindupFunctionParam = 0;
            csepic.v_loop.controller->ExtensionHooks.ptrExtHookPreTargetWriteFunction = (uint16_t)NULL;
            csepic.v_loop.controller->ExtensionHooks.ExtHookPreTargetWriteFunctionParam = 0;
            csepic.v_loop.controller->ExtensionHooks.ptrExtHookEndOfLoopFunction = (uint16_t)NULL;
            csepic.v_loop.controller->ExtensionHooks.ExtHookEndOfLoopFunctionParam = 0;
            
            csepic.v_loop.controller->ExtensionHooks.ptrExtHookEndOfLoopFunction = (uint16_t)NULL;
            csepic.v_loop.controller->ExtensionHooks.ExtHookEndOfLoopFunctionParam = 0; 
            
                // Initialize Advanced Control Settings (not used in this code example)
            csepic.v_loop.controller->GainControl.AgcFactor = 0x7FFF; // Adaptive Gain Control factor fractional
            csepic.v_loop.controller->GainControl.AgcScaler = 0x0000; // Adaptive Gain Control factor bit-shift scaler
            csepic.v_loop.controller->GainControl.AgcMedian = 0x0000; // Q15 number representing normalized Nominal Operating Point

            // Custom Advanced Control Settings
            csepic.v_loop.controller->Advanced.usrParam0 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam1 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam2 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam3 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam4 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam5 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam6 = 0; // No additional advanced control options used
            csepic.v_loop.controller->Advanced.usrParam7 = 0; // No additional advanced control options used

            // Reset Controller Status
            csepic.v_loop.controller->status.bits.enabled = false; // Keep controller disabled
            csepic.v_loop.controller->status.bits.swap_source = false; // use SOURCE as major control input
            csepic.v_loop.controller->status.bits.swap_target = false; // use TARGET as major control output
            csepic.v_loop.controller->status.bits.invert_input = false; // Do not invert input value
            csepic.v_loop.controller->status.bits.lower_saturation_event = false; // Reset Anti-Windup Minimum Status bit
            csepic.v_loop.controller->status.bits.upper_saturation_event = false; // Reset Anti-Windup Minimum Status bits
            csepic.v_loop.controller->status.bits.agc_enabled = false;   // Enable Adaptive Gain Modulation by default
            // ~~~ ACMC VOLTAGE LOOP CONFIGURATION END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            
            // ~~~ CURRENT LOOP CONFIGURATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            // Initialize Default Loop Configuration
            csepic.i_loop[0].feedback_offset = CSEPIC_ISNS_FB_OFFSET;
            csepic.i_loop[0].reference = CSEPIC_ISNS_START_LIMIT;
            csepic.i_loop[0].minimum = CSEPIC_PWM_DC_MIN; // Control output range minimum = Duty cycle min
            csepic.i_loop[0].maximum = CSEPIC_PWM_DC_MAX;
            csepic.i_loop[0].trigger_offset = CSEPIC_ISNS_ADC_TRGDLY; // I sense trig at delay

             // Set Controller Object of Voltage Loop
            csepic.i_loop[0].controller = &i_loop;
            csepic.i_loop[0].ctrl_Initialize = &i_loop_Initialize;
            csepic.i_loop[0].ctrl_Update = &i_loop_Update;
            csepic.i_loop[0].ctrl_Reset = &i_loop_Reset;
            csepic.i_loop[0].ctrl_Precharge = &i_loop_Precharge;

            // Configure Current Loop Controller Object
            csepic.i_loop[0].ctrl_Initialize(&i_loop);   // Call Initialization Routine setting histories and scaling

            // Configure controller input ports
            csepic.i_loop[0].controller->Ports.Source.ptrAddress = &CSEPIC_ISNS_ADCBUF; // Output Voltage is Common Source
            csepic.i_loop[0].controller->Ports.Source.Offset = csepic.i_loop[0].feedback_offset; // Output Voltage feedback signal offset 
            csepic.i_loop[0].controller->Ports.Source.NormScaler = CSEPIC_ISNS_NORM_SCALER; // Output voltage normalization factor bit-shift scaler 
            csepic.i_loop[0].controller->Ports.Source.NormFactor = CSEPIC_ISNS_NORM_FACTOR; // Output voltage normalization factor fractional

            csepic.i_loop[0].controller->Ports.AltSource.ptrAddress = &CSEPIC_VIN_ADCBUF; // Input Voltage Is Alternate Source
            csepic.i_loop[0].controller->Ports.AltSource.Offset = CSEPIC_VIN_OFFSET; // Input Voltage feedback signal offset 
            csepic.i_loop[0].controller->Ports.AltSource.NormScaler = CSEPIC_VIN_NORM_SCALER; // Input voltage normalization factor bit-shift scaler 
            csepic.i_loop[0].controller->Ports.AltSource.NormFactor = CSEPIC_VIN_NORM_FACTOR; // Input voltage normalization factor fractional

            // Configure controller output ports
            if (csepic.set_values.control_mode == CSEPIC_CONTROL_MODE_ACMC)
            {
                csepic.i_loop[0].controller->Ports.Target.ptrAddress = &CSEPIC_PWM_PDC; // PWM Duty Cycle is Control Target
            }
            csepic.i_loop[0].controller->Ports.Target.Offset = 0; // Static primary output value offset
            csepic.i_loop[0].controller->Ports.Target.NormScaler = 0; // Primary control output normalization factor bit-shift scaler 
            csepic.i_loop[0].controller->Ports.Target.NormFactor = 0x7FFF; // Primary control output normalization factor fractional 

            csepic.i_loop[0].controller->Ports.AltTarget.ptrAddress = NULL; // No alternate target used
            csepic.i_loop[0].controller->Ports.AltTarget.Offset = 0; // Static secondary output value offset
            csepic.i_loop[0].controller->Ports.AltTarget.NormScaler = 0; // Secondary control output normalization factor bit-shift scaler
            csepic.i_loop[0].controller->Ports.AltTarget.NormFactor = 0x7FFF; // Secondary control output normalization factor fractional 

            // Configure controller control ports
            csepic.i_loop[0].controller->Ports.ptrControlReference = &csepic.i_loop[0].reference; // Set pointer to Reference

            // Data Input/Output Limit Configuration
            csepic.i_loop[0].controller->Limits.MinOutput = csepic.i_loop[0].minimum;
            csepic.i_loop[0].controller->Limits.MaxOutput = csepic.i_loop[0].maximum;
            csepic.i_loop[0].controller->Limits.AltMinOutput = 0; // not used
            csepic.i_loop[0].controller->Limits.AltMaxOutput = 0; // not used

            // ADC Trigger Control Configuration
            csepic.i_loop[0].controller->ADCTriggerControl.ptrADCTriggerARegister = &CSEPIC_FB_VOUT_ADCTRIG;
            csepic.i_loop[0].controller->ADCTriggerControl.ADCTriggerAOffset = csepic.v_loop.trigger_offset;
            csepic.i_loop[0].controller->ADCTriggerControl.ptrADCTriggerBRegister = &CSEPIC_ISNS_ADCTRIG;
            csepic.i_loop[0].controller->ADCTriggerControl.ADCTriggerBOffset = CSEPIC_ISNS_ADC_TRGDLY; 

            // Data Provider Configuration
            csepic.i_loop[0].controller->DataProviders.ptrDProvControlInput = &csepic.data.control_input; 
            csepic.i_loop[0].controller->DataProviders.ptrDProvControlInputCompensated = &csepic.data.i_sns[0]; 
            csepic.i_loop[0].controller->DataProviders.ptrDProvControlError = &csepic.data.control_error; 
            csepic.i_loop[0].controller->DataProviders.ptrDProvControlOutput = &csepic.data.control_output;

            // User Extension Function Configuration
            /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
             * 
             * PowerSmart DCLD allows users to create and call user extension 
             * functions from specific locations of the main control loop to 
             * cover design-specific requirements and features which are not
             * supported by the main controller by default.
             * 
             * Control Loop User Extension Declaration Example:
             * 
             *  buck.v_loop.controller->ExtensionHooks.ptrExtHookStartFunction = (uint16_t)&my_function; 
             * 
             * Control Loop User Extension Parameter Declaration Example (optional):
             * 
             *  buck.v_loop.controller->ExtensionHooks.ExtHookStartFunctionParam = 512;
             * 
             * Please refer to the PowerSmart DCLD User Guide for more details about
             * how to use this feature, its requirements and limitations.
             * 
             * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            */

            csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookStartFunction = (uint16_t)NULL;
            csepic.i_loop[0].controller->ExtensionHooks.ExtHookStartFunctionParam = 0;
            csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookSourceFunction = (uint16_t)NULL;
            csepic.i_loop[0].controller->ExtensionHooks.ExtHookSourceFunctionParam = 0;
            csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookPreAntiWindupFunction = (uint16_t)NULL;
            csepic.i_loop[0].controller->ExtensionHooks.ExtHookPreAntiWindupFunctionParam = 0;
            csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookPreTargetWriteFunction = (uint16_t)NULL;
            csepic.i_loop[0].controller->ExtensionHooks.ExtHookPreTargetWriteFunctionParam = 0;
            if (csepic.set_values.control_mode == CSEPIC_CONTROL_MODE_VMC)
            {
                csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookEndOfLoopFunction = (uint16_t)NULL;
                csepic.i_loop[0].controller->ExtensionHooks.ExtHookEndOfLoopFunctionParam = 0;
            }
            csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookExitFunction = (uint16_t)NULL;
            csepic.i_loop[0].controller->ExtensionHooks.ExtHookExitFunctionParam = 0;

            // Initialize Advanced Control Settings (not used in this code example)
            csepic.i_loop[0].controller->GainControl.AgcFactor = 0x7FFF; // Adaptive Gain Control factor fractional
            csepic.i_loop[0].controller->GainControl.AgcScaler = 0x0000; // Adaptive Gain Control factor bit-shift scaler
            csepic.i_loop[0].controller->GainControl.AgcMedian = 0x0000; // Q15 number representing normalized Nominal Operating Point

            // Custom Advanced Control Settings
            csepic.i_loop[0].controller->Advanced.usrParam0 = 0; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam1 = 0; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam2 = 0; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam3 = 0; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam4 = 0; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam5 = 0; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam6 = 0; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam7 = 0; // No additional advanced control options used

            // Reset Controller Status
            csepic.i_loop[0].controller->status.bits.enabled = false; // Keep controller disabled
            csepic.i_loop[0].controller->status.bits.swap_source = false; // use SOURCE as major control input
            csepic.i_loop[0].controller->status.bits.swap_target = false; // use TARGET as major control output
            csepic.i_loop[0].controller->status.bits.invert_input = false; // Do not invert input value
            csepic.i_loop[0].controller->status.bits.lower_saturation_event = false; // Reset Anti-Windup Minimum Status bit
            csepic.i_loop[0].controller->status.bits.upper_saturation_event = false; // Reset Anti-Windup Minimum Status bits
            csepic.i_loop[0].controller->status.bits.agc_enabled = false;   // Enable Adaptive Gain Modulation by default

            // ~~~ CURRENT LOOP CONFIGURATION END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            break;    
        
        case CSEPIC_CONTROL_MODE_CCMC:
            csepic.i_loop[0].feedback_offset = CSEPIC_VOUT_OFFSET;
            csepic.i_loop[0].reference = CSEPIC_VOUT_REF;
            csepic.i_loop[0].minimum = CSEPIC_PWM_DC_MIN; // Control output range minimum = minimum duty cycle
            csepic.i_loop[0].maximum = CSEPIC_PWM_DC_MAX; // Control output range maximum = maximum duty cycle
            csepic.i_loop[0].trigger_offset = (CSEPIC_PWM_PERIOD >> 1); // Offset of T/2 to trigger at TOFF/2
            //csepic.i_loop[0].trigger_offset = CSEPIC_VOUT_ADC_TRG_DELAY;
              
            // Set Controller Object of Voltage Loop
            csepic.i_loop[0].controller = &i_loop;
            csepic.i_loop[0].ctrl_Initialize = &i_loop_Initialize;
            csepic.i_loop[0].ctrl_Update = &i_loop_Update;
            csepic.i_loop[0].ctrl_Reset = &i_loop_Reset;
            csepic.i_loop[0].ctrl_Precharge = &i_loop_Precharge;

            // Configure Voltage Loop Controller Object
            csepic.i_loop[0].ctrl_Initialize(&i_loop);   // Call Initialization Routine setting histories and scaling

            // Configure controller input ports
            csepic.i_loop[0].controller->Ports.Source.ptrAddress = &CSEPIC_ISNS_ADCBUF; // Output Voltage is Common Source
            csepic.i_loop[0].controller->Ports.Source.Offset = csepic.i_loop[0].feedback_offset; // Output Voltage feedback signal offset 
            csepic.i_loop[0].controller->Ports.Source.NormScaler = CSEPIC_ISNS_NORM_SCALER; // Output voltage normalization factor bit-shift scaler 
            csepic.i_loop[0].controller->Ports.Source.NormFactor = CSEPIC_ISNS_NORM_FACTOR; // Output voltage normalization factor fractional

            csepic.i_loop[0].controller->Ports.AltSource.ptrAddress = &CSEPIC_VIN_ADCBUF; // Input Voltage Is Alternate Source
            csepic.i_loop[0].controller->Ports.AltSource.Offset = CSEPIC_VIN_OFFSET; // Input Voltage feedback signal offset 
            csepic.i_loop[0].controller->Ports.AltSource.NormScaler = CSEPIC_VIN_NORM_SCALER; // Input voltage normalization factor bit-shift scaler 
            csepic.i_loop[0].controller->Ports.AltSource.NormFactor = CSEPIC_VIN_NORM_FACTOR; // Input voltage normalization factor fractional
                
            // Configure controller output ports
            csepic.i_loop[0].controller->Ports.Target.ptrAddress = &CSEPIC_PWM_PDC; // PWM Duty Cycle is Control Target in VMC
            
            csepic.i_loop[0].controller->Ports.Target.Offset = 0; // Static primary output value offset

            csepic.i_loop[0].controller->Ports.Target.NormScaler = 0; // Primary control output normalization factor bit-shift scaler 
            csepic.i_loop[0].controller->Ports.Target.NormFactor = 0x7FFF; // Primary control output normalization factor fractional 

            csepic.i_loop[0].controller->Ports.AltTarget.ptrAddress = NULL; // No alternate target used
            csepic.i_loop[0].controller->Ports.AltTarget.Offset = 0; // Static secondary output value offset
            csepic.i_loop[0].controller->Ports.AltTarget.NormScaler = 0; // Secondary control output normalization factor bit-shift scaler
            csepic.i_loop[0].controller->Ports.AltTarget.NormFactor = 0x7FFF; // Secondary control output normalization factor fractional 

            // Configure controller control ports
            csepic.i_loop[0].controller->Ports.ptrControlReference = &csepic.i_loop[0].reference; // Set pointer to Reference

            // Data Input/Output Limit Configuration
            csepic.i_loop[0].controller->Limits.MinOutput = csepic.i_loop[0].minimum;
            csepic.i_loop[0].controller->Limits.MaxOutput = csepic.i_loop[0].maximum;
            csepic.i_loop[0].controller->Limits.AltMinOutput = 0; // not used
            csepic.i_loop[0].controller->Limits.AltMaxOutput = 0; // not used

            // ADC Trigger Control Configuration
            csepic.i_loop[0].controller->ADCTriggerControl.ptrADCTriggerARegister = &CSEPIC_FB_VOUT_ADCTRIG;
            csepic.i_loop[0].controller->ADCTriggerControl.ADCTriggerAOffset = csepic.i_loop[0].trigger_offset;
            csepic.i_loop[0].controller->ADCTriggerControl.ptrADCTriggerBRegister = &CSEPIC_ISNS_ADCTRIG;
            csepic.i_loop[0].controller->ADCTriggerControl.ADCTriggerBOffset = 0;
            //csepic.i_loop[0].controller->ADCTriggerControl.ADCTriggerBOffset = CSEPIC_ISNS_ADC_TRGDLY; 

            // Data Provider Configuration
            csepic.i_loop[0].controller->DataProviders.ptrDProvControlInput = &csepic.data.control_input; 
            csepic.i_loop[0].controller->DataProviders.ptrDProvControlInputCompensated = &csepic.data.i_sns[0]; 
            csepic.i_loop[0].controller->DataProviders.ptrDProvControlError = &csepic.data.control_error; 
            csepic.i_loop[0].controller->DataProviders.ptrDProvControlOutput = &csepic.data.control_output;

            // User Extension Function Configuration
            /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
             * 
             * PowerSmart DCLD allows users to create and call user extension 
             * functions from specific locations of the main control loop to 
             * cover design-specific requirements and features which are not
             * supported by the main controller by default.
             * 
             * Control Loop User Extension Declaration Example:
             * 
             *  csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookStartFunction = (uint16_t)&my_function; 
             * 
             * Control Loop User Extension Parameter Declaration Example (optional):
             * 
             *  csepic.i_loop[0].controller->ExtensionHooks.ExtHookStartFunctionParam = 512;
             * 
             * Please refer to the PowerSmart DCLD User Guide for more details about
             * how to use this feature, its requirements and limitations.
             * 
             * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            */

            csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookStartFunction = (uint16_t)NULL;
            csepic.i_loop[0].controller->ExtensionHooks.ExtHookStartFunctionParam = 0;
            csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookSourceFunction = (uint16_t)NULL;
            csepic.i_loop[0].controller->ExtensionHooks.ExtHookSourceFunctionParam = 0;
            csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookPreAntiWindupFunction = (uint16_t)NULL;
            csepic.i_loop[0].controller->ExtensionHooks.ExtHookPreAntiWindupFunctionParam = 0;
            csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookPreTargetWriteFunction = (uint16_t)NULL;
            csepic.i_loop[0].controller->ExtensionHooks.ExtHookPreTargetWriteFunctionParam = 0;
            csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookExitFunction = (uint16_t)NULL;
            csepic.i_loop[0].controller->ExtensionHooks.ExtHookExitFunctionParam = 0;
            
            csepic.i_loop[0].controller->ExtensionHooks.ptrExtHookEndOfLoopFunction = (uint16_t)NULL;
            csepic.i_loop[0].controller->ExtensionHooks.ExtHookEndOfLoopFunctionParam = 0;
            
            /////////////////////////////////////////////////////////////
            
            csepic.i_loop[0].controller->GainControl.AgcFactor = 0x7FFF; // Adaptive Gain Control factor fractional
            csepic.i_loop[0].controller->GainControl.AgcScaler = CSEPIC_AGC_NOM_SCALER; // Adaptive Gain Control factor bit-shift scaler
            csepic.i_loop[0].controller->GainControl.AgcMedian = CSEPIC_AGC_MEDIAN; // Q15 number representing normalized Nominal Operating Point
            csepic.i_loop[0].controller->GainControl.ptrAgcObserverFunction = (uint16_t) &i_loop_AGCFactorUpdate;
            
            // Custom Advanced Control Settings
            csepic.i_loop[0].controller->Advanced.usrParam0 = CSEPIC_PWM_PERIOD; // PWM switching period passed as User custom parameter
            csepic.i_loop[0].controller->Advanced.usrParam1 = CSEPIC_AGC_IO_NORM_SCALER; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam2 = CSEPIC_AGC_IO_NORM_FACTOR; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam3 = (uint16_t) &CSEPIC_FB_VOUT_ADCBUF; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam4 = 0; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam5 = 0; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam6 = 0; // No additional advanced control options used
            csepic.i_loop[0].controller->Advanced.usrParam7 = 0; // No additional advanced control options used

            // Reset Controller Status
            csepic.i_loop[0].controller->status.bits.enabled = false; // Keep controller disabled
            csepic.i_loop[0].controller->status.bits.swap_source = false; // use SOURCE as major control input
            csepic.i_loop[0].controller->status.bits.swap_target = false; // use TARGET as major control output
            csepic.i_loop[0].controller->status.bits.invert_input = false; // Do not invert input value
            csepic.i_loop[0].controller->status.bits.lower_saturation_event = false; // Reset Anti-Windup Minimum Status bit
            csepic.i_loop[0].controller->status.bits.upper_saturation_event = false; // Reset Anti-Windup Minimum Status bits
            csepic.i_loop[0].controller->status.bits.agc_enabled = false;   // Diasble Adaptive Gain Modulation by default
            // ~~~ CURRENT LOOP CONFIGURATION END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            break;    
        
        default:
            break;
    }
        
    return(retval);
}

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-private
 * @fn	volatile uint16_t appPowerSupply_PeripheralsInitialize(void)
 * @brief  This function is used to load peripheral configuration templates from the power controller device driver
 * @return 0=failure
 * @return 1=success
 * 
 * @details
 * This function hand over the peripheral configuration to the SEPIC
 * converter device driver
 *********************************************************************************/

volatile uint16_t appPowerSupply_PeripheralsInitialize(void)
{
    volatile uint16_t retval=1;
    
    retval &= dev_csepicConverter_Initialize(&csepic);
    
    return(retval);
}

/*******************************************************************************
 * @ingroup app-layer-power-control-functions-private
 * @fn	volatile uint16_t appPowerSupply_InterruptsInitialize(void)
 * @brief  This function is used to initialize the interrupt service events of the control loop
 * @return 0=failure
 * @return 1=success
 * 
 * @details
 * This function initializes and enables the control loop interrupt(s) of the
 * cycle-by-cycle real-time control. These interrupts are commonly synchronous
 * to the switching process and therefore triggered by ADC conversion or PWM 
 * event interrupts. The interrupt service routines are called on high levels 
 * overriding the recently executed processes to maintain real-time accuracy
 * of the feedback loop response.
 * 
 *********************************************************************************/

volatile uint16_t appPowerSupply_InterruptsInitialize(void)
{
    volatile uint16_t retval=1;

    // Initialize Control Interrupt
    _CSEPIC_LOOP_ISR_IP = CSEPIC_VOUT_ISR_PRIORITY;
    _CSEPIC_LOOP_ISR_IF = 0;
    _CSEPIC_LOOP_ISR_IE = true;
    
    retval &= (_CSEPIC_LOOP_ISR_IE); // Return INTERRUPT_ENABLE flag bit
    
    return(retval);
}


// end of file
