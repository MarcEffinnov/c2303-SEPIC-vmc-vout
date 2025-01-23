/**
 *  (c) 2021 Microchip Technology Inc. and its subsidiaries.
 *
 *  Subject to your compliance with these terms, you may use Microchip software
 *  and any derivatives exclusively with Microchip products. You're responsible
 *  for complying with 3rd party license terms applicable to your use of 3rd
 *  party software (including open source software) that may accompany Microchip
 *  software.
 *
 *  SOFTWARE IS "AS IS." NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 *  APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
 *  MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 *  INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 *  WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
 *  HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
 *  THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
 *  CLAIMS RELATED TO THE SOFTWARE WILL NOT EXCEED AMOUNT OF FEES, IF ANY,
 *  YOU PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 *  @file    dev_sepic_typedef.h
 *  @brief   This file contains APIs to for the power control
 *
 *  @note
 *  Microchip Technology Inc. has followed development methods required by
 *  IEC-60730 and performed extensive validation and static testing to ensure
 *  that the code operates as intended. Any modification to the code can
 *  invalidate the results of Microchip's validation and testing.
 *
 */

/* 
 * File:   dev_sepic_typedef.h
 * Author: M91406
 * Comments: Type definitions of single- and multiphase SEPIC Converter data object
 * Revision history: 
 * 1.0  initial release
 * 1.1  restructured phase arrays in data object to optimize code execution and stay with unified API
 *      with regards to other power converter object libraries
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CSEPIC_CONVERTER_TYPE_DEF_H
#define	CSEPIC_CONVERTER_TYPE_DEF_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer number data types
#include <stdbool.h> // include standard boolean data types (true/false)
#include <stddef.h> // include standard definition data types

#include "power_control/drivers/npnz16b.h"
#include "config/hal.h"

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-public-defines
 * @def     CSEPIC_MPHASE_COUNT
 * @brief   Declaration of the number of power train phases of the SEPIC Converter
 **************************************************************************************************** */
#define CSEPIC_MPHASE_COUNT           CSEPIC_NO_OF_PHASES

// Controller Status Bits
/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @enum    CSEPIC_STATUS_FLAGS_e
 * @brief   Enumeration of status and control flags
 * @extends CSEPIC_CONVERTER_CONSTANTS_s
 **************************************************************************************************** */
enum CSEPIC_STATUS_FLAGS_e 
{  
    CSEPIC_STAT_READY                = 0b0000000000000001,
    CSEPIC_STAT_ADC_ACTIVE           = 0b0000000000000010,
    CSEPIC_STAT_PWM_ACTIVE           = 0b0000000000000100,
    CSEPIC_STAT_POWERSOURCE_DETECTED = 0b0000000000001000,
    CSEPIC_STAT_CS_SENSE_READY       = 0b0000000000010000,
    
    CSEPIC_STAT_FORCED_SHUT_DOWN     = 0b0000000010000000,
    CSEPIC_STAT_BUSY                 = 0b0000000100000000,

// Controller Control Bits
    CSEPIC_STAT_GO                   = 0b0010000000000000,
    CSEPIC_STAT_AUTORUN              = 0b0100000000000000,
    CSEPIC_STAT_NO_AUTORUN           = 0b0000000000000000,
    
    CSEPIC_STAT_ENABLED              = 0b1000000000000000,
    CSEPIC_STAT_DISABLED             = 0b0000000000000000
}; ///< Enumeration of all status and control flags of the SEPIC Converter status word
typedef enum CSEPIC_STATUS_FLAGS_e CSEPIC_STATUS_FLAGS_t;

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @enum    CSEPIC_OPSTATES_e
 * @brief   Enumeration of state machine operating states 
 * @extends CSEPIC_STATE_ID_s
 * @extends CSEPIC_CONVERTER_CONSTANTS_s
 **************************************************************************************************** */
enum CSEPIC_OPSTATES_e {  
    
    CSEPIC_OPSTATE_ERROR          = 0x00,  ///< power converter control state #0: in case of an error, state machine will reset to RESET
    CSEPIC_OPSTATE_INITIALIZE     = 0x01,  ///< power converter control state #1: initialize variables and hijack controller reference
    CSEPIC_OPSTATE_RESET          = 0x02,  ///< power converter control state #2: Initializing variable but bypassing delays
    CSEPIC_OPSTATE_STANDBY        = 0x03,  ///< power converter control state #3: power converter control state #2 standing by, ready to launch, waiting for GO (no action)
    CSEPIC_OPSTATE_RAMPUP         = 0x04,  ///< power converter control state #4: Startup handler sub-state machine
    CSEPIC_OPSTATE_ONLINE         = 0x05   ///< power converter control state #5: Output in regulation and power is OK (normal continuous operation)
        
}; ///< Enumeration of state machine operating states 
typedef enum CSEPIC_OPSTATES_e CSEPIC_OPSTATES_t; ///< Enumeration of state machine operating states

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @enum    CSEPIC_SUBSTATES_e
 * @brief   Enumeration of state machine operating sub-states 
 * @extends CSEPIC_STATE_ID_s
 * @extends CSEPIC_CONVERTER_CONSTANTS_s
 **************************************************************************************************** */
enum CSEPIC_SUBSTATES_e {  // Enumeration of state machine operating sub-states

    CSEPIC_OPSTATE_POWER_ON_DELAY = 0x00,  ///< power converter control state #3: power on delay (no action)
    CSEPIC_OPSTATE_PREPARE_V_RAMP = 0x01,  ///< power converter control state #4: turn on PWM outputs and enable controller
    CSEPIC_OPSTATE_V_RAMPUP_START = 0x02,  ///< power converter control state #4: turn on PWM outputs and enable controller
    CSEPIC_OPSTATE_V_RAMP_UP      = 0x03,  ///< power converter control state #5: perform output voltage ramp up based on parameters and system response 
    CSEPIC_OPSTATE_I_RAMP_UP      = 0x04,  ///< power converter control state #6: perform output current ramp up based on parameters and system response (average current mode only)
    CSEPIC_OPSTATE_PWRGOOD_DELAY  = 0x05   ///< power converter control state #7: Output reached regulation point but waits until things have settled
    
}; ///< Enumeration of state machine operating sub-states 
typedef enum CSEPIC_SUBSTATES_e CSEPIC_SUBSTATES_t; ///< Enumeration of state machine operating sub-states data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @enum CSEPIC_OPSTATE_RETURNS_e
 * @brief Enumeration of state machine operating state return values
 * @extends CSEPIC_CONVERTER_CONSTANTS_s
 **************************************************************************************************** */
enum CSEPIC_OPSTATE_RETURNS_e {  // Enumeration of state machine operating state return values
    
    CSEPIC_OPSRET_ERROR           = 0x0000,  ///< power converter state return #0: internal error occurred
    CSEPIC_OPSRET_COMPLETE        = 0x0001,  ///< power converter state return #1: operation state has completed
    CSEPIC_OPSRET_REPEAT          = 0x0002   ///< power converter state return #2: operation state is in progress and needs to be recalled
        
}; // Enumeration of state machine operating state return values
typedef enum CSEPIC_OPSTATE_RETURNS_e CSEPIC_OPSTATE_RETURNS_t; // State Machine Operating State Return Values

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @enum    CSEPIC_CONTROL_MODE_e
 * @brief   Enumeration of the power supply mode control
 * @extends CSEPIC_CONVERTER_SETTINGS_s
 * @extends CSEPIC_CONVERTER_CONSTANTS_s
 **************************************************************************************************** */
enum CSEPIC_CONTROL_MODE_e{
    
    CSEPIC_CONTROL_MODE_VMC = 0,              ///< Voltage Mode Control
//    CSEPIC_CONTROL_MODE_PCMC = 1,           // Peak Current Mode Control (not supported yet)
    CSEPIC_CONTROL_MODE_ACMC = 2,             ///< Average Current Mode Control
    CSEPIC_CONTROL_MODE_CCMC = 3              ///< Constant Current Mode Control (Similar to VMC, using output current feedback Vs output voltage feedback)
        
}; ///< SEPIC Converter Control Modes
typedef enum CSEPIC_CONTROL_MODE_e CSEPIC_CONTROL_MODE_t; ///< SEPIC Converter Control Modes data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-public-data-types
 * @struct  CSEPIC_CONVERTER_CONSTANTS_s
 * @brief   Structure providing all public enumerated lists of constants 
 **************************************************************************************************** */
struct CSEPIC_CONVERTER_CONSTANTS_s
{
    volatile CSEPIC_STATUS_FLAGS_t StatusFlags; ///< List of all status and control flags of the SEPIC Converter status word
    volatile CSEPIC_OPSTATES_t OpStateOpCodes;  ///< List of State Machine Operating State IDs
    volatile CSEPIC_SUBSTATES_t SubStateOpCodes;  ///< List of State Machine Sub-State IDs
    volatile CSEPIC_OPSTATE_RETURNS_t OpStateReturnValues;  ///< List of State Machine Operating State Return Values
    volatile CSEPIC_CONTROL_MODE_t ControlModes;  ///< List of Supported Control Modes
};
typedef struct CSEPIC_CONVERTER_CONSTANTS_s CSEPIC_CONVERTER_CONSTANTS_t;

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-public-variables
 * @var     csepicConverterConstants
 * @brief   Structure providing all public enumerated lists of constants 
 **************************************************************************************************** */
extern volatile struct CSEPIC_CONVERTER_CONSTANTS_s csepicConverterConstants;

/*****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct CSEPIC_CONVERTER_STATUS_s
 * @brief Generic power controller status word
 * @extends CSEPIC_CONVERTER_s
 * 
 * @details
 * The power controller status/control word contains status (low-byte) and control bits (high-byte). 
 * -# Status Bits:
 *      - ADC_ACTIVE: ADC is active and running (read only)
 *      - PWM_STARTED: PWM is active and running generating ADC triggers (read only)
 *      - POWERSOURCE_DETECTED: A valid power source has been detected allowing the converter to run (read only)
 *      - CS_READ: Current sense feedback ready (read only)
 *      - FORCED_SHUT_DOWN: Control(Status bit for external software components forcing the converter to stay off
 *      - BUSY: Converter is currently going through an internal process (e.g. ramp up/down) (read only)
 *      
 * -# Control Bits
 *      - ENABLE: Enables/Disables the power converter
 *      - AUTORUN: When set, the power converter will automatically start up once all status bits are set accordingly
 *      - GO: Control bit to manually start the power converter if (AUTOSTART=0)
 *  
 **************************************************************************************************** */
struct CSEPIC_CONVERTER_STATUS_s
{
    union {
    struct{
        volatile bool ready:1;                  ///< Bit #0: status bit, indicating SEPIC converter is initialized and ready to run
        volatile bool adc_active:1;             ///< Bit #1: indicating that ADC has been started and samples are taken
        volatile bool pwm_active:1;             ///< Bit #2: indicating that PWM has been started and ADC triggers are generated
        volatile bool v_loop_clamped:1;         ///< Bit #3: indicating if voltage loop output is clamped to maximum value limit
        volatile bool cs_calib_complete :1;     ///< Bit #4: indicating that current sensor calibration has completed
        volatile bool fault_active :1;          ///< Bit #5: Flag bit indicating system is in enforced shut down mode (usually due to a fault condition)
        volatile bool suspend :1;               ///< Bit #6: Control bit to put the converter in suspend mode (turned off while ENABLE bit is still on)
        volatile bool busy :1;                  ///< Bit #7:  Flag bit indicating that the state machine is executing a process (e.g. startup-ramp)

        volatile bool cs_calib_enable :1;       ///< Bit #8:  Flag bit indicating that current sensors need to calibrated
        volatile unsigned :1;                   ///< Bit #9:  (reserved)
        volatile unsigned :1;                   ///< Bit #10: (reserved)
        volatile unsigned :1;                   ///< Bit #11: (reserved)
        volatile unsigned :1;                   ///< Bit #12: (reserved)
        volatile bool GO :1;                    ///< Bit #13: When set, the GO-bit fires up the power supply
        volatile bool autorun :1;               ///< Bit #14: Control bit determining if charger is starting automatically or on command (using the GO bit)
        volatile bool enabled :1;               ///< Bit #15: Control bit enabling/disabling the charger port
    } __attribute__((packed)) bits;             ///< data structure for single bit addressing operations

	volatile uint16_t value; // buffer for 16-bit word read/write operations
    };
}; // SEPIC Converter Status & Control word
typedef struct CSEPIC_CONVERTER_STATUS_s CSEPIC_CONVERTER_STATUS_t; // SEPIC Converter Status & Control word data type


/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct CSEPIC_STATE_ID_s 
 * @brief data structure for the SEPIC state ID for sub-operating and operating states 
 * @extends CSEPIC_CONVERTER_s
 **************************************************************************************************** */
struct CSEPIC_STATE_ID_s 
{
    union {
    struct { 
        volatile CSEPIC_OPSTATES_t opstate_id;   ///< Most recent operating state of main state machine
        volatile CSEPIC_SUBSTATES_t substate_id; ///< Most recent operating state of active sub state machine
    } bits;
    volatile uint32_t value; // full state ID value access to main and sub-state machine state
    };
}; // SEPIC Converter State Machine operating state ID
typedef struct CSEPIC_STATE_ID_s CSEPIC_STATE_ID_t;  // SEPIC Converter State Machine operating state ID data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct  CSEPIC_STARTUP_PERIOD_HANDLER_s
 * @brief   Generic power controller startup period settings
 * @extends CSEPIC_CONVERTER_STARTUP_s
 * 
 * @details
 * This data structure is used to set the startup settings such as power on delay, power good delay
 * and ramp up time. It further covers private values like startup counters and reference values
 * for voltage and current, which are used internally by the controller (read only) but are still
 * accessible for external code modules for monitoring, diagnostics and fault handling purposes.
 * 
 **************************************************************************************************** */
struct CSEPIC_STARTUP_PERIOD_HANDLER_s {
    
    volatile uint16_t counter;      ///< Soft-Start Execution Counter (read only)
    volatile uint16_t period;       ///< Soft-Start Period (POD, RAMP PERIOD, PGD, etc.)
    volatile uint16_t reference;    ///< Internal dummy reference used to increment/decrement controller reference (read only)
    volatile uint16_t ref_inc_step; ///< Size/value of one reference increment/decrement or this period
    volatile uint16_t ref_minimum;  ///< Minimum starting value of the reference (Commonly =0 but sometimes required to overcome minimum common mode limits)
    volatile uint16_t ref_start_limit;  ///< Specific reference limit during startup if different from common maximum. This setting is only considered in average current mode control loops where the startup current limit might be different from normal operation.
    
}; // Power converter soft-start auxiliary variables
typedef struct CSEPIC_STARTUP_PERIOD_HANDLER_s CSEPIC_STARTUP_PERIOD_HANDLER_t; // Power converter soft-start auxiliary variables data types

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct  CSEPIC_CONVERTER_OLSTARTUP_s
 * @brief   Power Converter Monitored Open Loop Startup Settings
 * @extends CSEPIC_CONVERTER_STARTUP_s
 * 
 * @details
 * This data structure is used to set the monitored open loop startup settings such as the open 
 * loop soft-start increment per execution tick.
 * 
 * *************************************************************************************************** */
struct CSEPIC_CONVERTER_OLSTARTUP_s {
    
    volatile bool enabled;  ///< User option enabling the open loop startup feature, which will increment the control output until the output voltage is above the specified minimum cut-off voltage
    volatile uint16_t vout_cutoff; ///< Monitored open loop startup cut-off voltage, at which the state machine will switch over into closed loop output ramp-up mode
    volatile uint16_t output_increment; ///< Value increment per execution step during monitored open loop startup. This value will be determined by the state machine during startup and is 'read only'.
    
}; // Power converter start-up settings and variables
typedef struct CSEPIC_CONVERTER_OLSTARTUP_s CSEPIC_CONVERTER_OLSTARTUP_t; // Power converter open-loop start-up settings and variables data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct  CSEPIC_CONVERTER_STARTUP_s
 * @brief   Power Converter Startup Timing Settings
 * @extends CSEPIC_CONVERTER_s
 * *************************************************************************************************** */
 struct CSEPIC_CONVERTER_STARTUP_s {
    
    volatile CSEPIC_STARTUP_PERIOD_HANDLER_t power_on_delay; ///< Declaration of Power On Delay period and timeout
    volatile CSEPIC_STARTUP_PERIOD_HANDLER_t power_good_delay; ///< Declaration of Power Good period and timeout
    volatile CSEPIC_STARTUP_PERIOD_HANDLER_t i_ramp;  ///< Declaration of output current ramp reference increment step size and period
    volatile CSEPIC_STARTUP_PERIOD_HANDLER_t v_ramp;  ///< Declaration of output voltage ramp reference increment step size and period
    volatile CSEPIC_CONVERTER_OLSTARTUP_t open_loop;  ///< Monitored Open Loop Startup Settings
    
}; // Power converter start-up settings and variables
typedef struct CSEPIC_CONVERTER_STARTUP_s  CSEPIC_CONVERTER_STARTUP_t; // Power converter start-up settings and variables data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct  CSEPIC_CONVERTER_DATA_s
 * @brief   Publicly accessible data buffer of most recent runtime data values
 * @extends CSEPIC_CONVERTER_s
 * 
 **************************************************************************************************** */
struct CSEPIC_CONVERTER_DATA_s {
    
    volatile uint16_t i_sns[CSEPIC_MPHASE_COUNT];   ///< SEPIC output current per phase ADC value
    volatile float    i_sns_in_A[CSEPIC_MPHASE_COUNT];   ///< SEPIC output current per phase in A
    volatile uint16_t i_out;                        ///< SEPIC common output current
    volatile uint16_t v_in;                         ///< SEPIC input voltage ADC value
    volatile float    v_in_in_V;                    ///< SEPIC input voltage in V
    volatile uint16_t v_out;                        ///< SEPIC output voltage ADC value
    volatile float    v_out_in_V;                    ///< SEPIC output voltage in V
    volatile uint16_t temp;                         ///< SEPIC board temperature
    
    volatile uint16_t control_input;                ///< SEPIC most recent control input value (raw input)
    volatile uint16_t control_error;                ///< SEPIC most recent control error value
    volatile uint16_t control_output;               ///< SEPIC most recent control output value
    
}; // SEPIC runtime data buffer
typedef struct CSEPIC_CONVERTER_DATA_s CSEPIC_CONVERTER_DATA_t; // SEPIC runtime data buffer data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct CSEPIC_CONVERTER_SETTINGS_s
 * @brief Generic power controller control settings
 * @extends CSEPIC_CONVERTER_s
 * 
 * @details
 * This data structure is used to set the overall settings to allow external software instances 
 * to control the power control object, such as voltage and current references.
 *  
 **************************************************************************************************** */
struct CSEPIC_CONVERTER_SETTINGS_s {
    
    volatile enum CSEPIC_CONTROL_MODE_e control_mode;  ///< Fundamental control mode 
    volatile uint16_t no_of_phases;             ///< number of converter phases
    volatile uint16_t v_ref;                    ///< User reference setting used to control the power converter controller
    volatile uint16_t v_ref_previous;
    volatile uint16_t v_slew_rate;              ///< slew rate of output voltage applied during output voltage reference transitions
    volatile uint16_t i_ref;                    ///< User reference setting used to control the power converter controller
    volatile uint16_t i_slew_rate;              ///< slew rate of output current applied during output current reference transitions
    volatile bool led_driver_mode_enabled;      ///< flag used to enable voltage loop bypass in ISR if running in constant current mode for LED string driving.
    volatile uint16_t led_driver_mode_switch_debounce; ///< Debounce (in # of ISR cycles) before voltage loop is bypassed in CC mode
    volatile uint16_t led_driver_mode_switch_debounce_counter; ///< Debounce (in # of ISR cycles) before voltage loop is bypassed in CC mode  
};  ///> SEPIC converter main settings
typedef struct CSEPIC_CONVERTER_SETTINGS_s CSEPIC_CONVERTER_SETTINGS_t;  ///> SEPIC converter main settings

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct  CSEPIC_LOOP_SETTINGS_s
 * @brief   Generic power control loop settings
 * @extends CSEPIC_CONVERTER_s
 * 
 * @details
 * This data structure is used to set the control loop settings such as pointers to controller 
 * objects and its function calls as well as basic user settings such as reference, feedback
 * signal offsets, trigger delays and minimum/maximum output clamping values.
 * 
 * *************************************************************************************************** */
struct CSEPIC_LOOP_SETTINGS_s {
    
    // Properties (user settings)
    volatile uint16_t reference;            ///< Control loop reference variable
    volatile uint16_t feedback_offset;      ///< Feedback offset value for calibration or bi-direction feedback signals
    volatile uint16_t trigger_offset;       ///< ADC trigger offset value for trigger fine-tuning
    volatile uint16_t minimum;              ///< output clamping value (minimum)
    volatile uint16_t maximum;              ///< output clamping value (maximum)
    // Control Loop Object
    volatile struct NPNZ16b_s* controller;  ///< pointer to control loop object data structure
    // Function pointers
    volatile uint16_t (*ctrl_Initialize)(volatile struct NPNZ16b_s*); ///< Function pointer to INIT routine
    void (*ctrl_Reset)(volatile struct NPNZ16b_s*); ///< Function pointer to RESET routine
    void (*ctrl_Update)(volatile struct NPNZ16b_s*); ///< Function pointer to UPDATE routine
    void (*ctrl_Precharge)(volatile struct NPNZ16b_s*, volatile fractional, volatile fractional); ///< Function pointer to PRECHARGE routine
    
}; ///< User defined settings for control loops; 
typedef struct CSEPIC_LOOP_SETTINGS_s CSEPIC_LOOP_SETTINGS_t; ///< User defined settings for control loops data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct  CSEPIC_SWITCH_NODE_INSTANCE_s
 * @brief   Generic power converter single switch-node specifications
 * @extends CSEPIC_SWITCH_NODE_SETTINGS_s
 * 
 * @details
 * This data structure is used to set the converter switch-node specifications declaring which
 * PWM channel is used as well as its switching frequency, phase-shift, dead times and duty ratio
 * limits. 
 * 
 * @note
 * All declarations made refer to one, individual switch node, such as the buck-leg half bridge 
 * drive or the boost-leg half bridge drive. The definition of the complete switch node interface 
 * is merged into the CSEPIC_SWITCH_NODE_SETTINGS_s data structure.
 * 
 * *************************************************************************************************** */
struct CSEPIC_SWITCH_NODE_INSTANCE_s 
{
    volatile uint16_t pwm_instance;         ///< number of the PWM channel used
    volatile uint16_t gpio_instance;        ///< GPIO instance of the selected PWM generator
    //volatile uint16_t gpio_high;            ///< GPIO port pin-number of PWMxH of the selected PWM generator
    volatile uint16_t gpio_low;             ///< GPIO port pin-number of PWMxL of the selected PWM generator
    volatile bool     swap_outputs;         ///< Selecting if PWMxH (default) or PWMxL should be the leading PWM output
    volatile bool     sync_drive;           ///< Selecting if switch node is driven in synchronous or asnchronous mode
    volatile uint16_t phase;                ///< Switching signal phase-shift
    volatile uint16_t duty_ratio_init;      ///< Initial duty cycle when the PWM module is being turned on
    volatile uint16_t duty_ratio_min;       ///< Absolute duty cycle minimum during normal operation
    volatile uint16_t duty_ratio_max;       ///< Absolute duty cycle maximum during normal operation
    volatile uint16_t dead_time_rising;     ///< Dead time setting at rising edge of a half-bridge drive
    volatile uint16_t dead_time_falling;    ///< Dead time setting at falling edge of a half-bridge drive
    volatile uint16_t leb_period;           ///< Leading-Edge Blanking period
    volatile uint16_t trigger_scaler;       ///< PWM triggers for ADC will be generated every n-th cycle
    volatile uint16_t trigger_offset;       ///< PWM triggers for ADC will be offset by n cycles
    
}; ///< Switching signal timing settings
typedef struct CSEPIC_SWITCH_NODE_INSTANCE_s  CSEPIC_SWITCH_NODE_INSTANCE_t; ///< Switching signal timing settings data type


/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct  CSEPIC_PWM_DISTRIBUTION_STATUS_s
 * @brief   Generic power converter switch-node control interface
 * @extends CSEPIC_PWM_DISTRIBUTION_s
 * 
 * @details
 * This data structure is the status word of the PWM distribution module, which is part
 * of the switch node interface of the SEPIC converter data object and 
 * main control output interface distributing a single, linear feedback loop output onto
 * the two switch nodes of this type of power supply.
 * 
 * The bits of this status word are used for status monitoring any control access allowing
 * micro-management of PWM timing related operations.
 * 
 *****************************************************************************************************/
struct CSEPIC_PWM_DISTRIBUTION_STATUS_s
{
    union {
    struct{
        volatile bool buck_async_mode :1;       ///< Bit #0:  Control bit suspending the synchronous rectifier switch PWM channel of the buck leg
        volatile bool boost_async_mode :1;      ///< Bit #1:  Control bit suspending the synchronous rectifier switch PWM channel of the boost leg
        volatile unsigned :1;                   ///< Bit #2:  (reserved)
        volatile unsigned :1;                   ///< Bit #3:  (reserved)
        volatile unsigned :1;                   ///< Bit #4:  (reserved)
        volatile unsigned :1;                   ///< Bit #5:  (reserved)
        volatile unsigned :1;                   ///< Bit #6:  (reserved)
        volatile unsigned :1;                   ///< Bit #7:  (reserved)

        volatile unsigned :1;                   ///< Bit #8:  (reserved)
        volatile unsigned :1;                   ///< Bit #9:  (reserved)
        volatile unsigned :1;                   ///< Bit #10: (reserved)
        volatile unsigned :1;                   ///< Bit #11: (reserved)
        volatile unsigned :1;                   ///< Bit #12: (reserved)
        volatile unsigned :1;                   ///< Bit #13: (reserved)
        volatile bool AdcTriggerBEnable :1;     ///< Bit #14: Control bit enabling/disabling ADC Trigger B Auto-Placement 
        volatile bool AdcTriggerAEnable :1;     ///< Bit #15: Control bit enabling/disabling ADC Trigger A Auto-Placement 
    } __attribute__((packed)) bits;             ///< data structure for single bit addressing operations

	volatile uint16_t value; // buffer for 16-bit word read/write operations
    };
}; // SEPIC Converter PWM Distribution Status & Control word
typedef struct CSEPIC_PWM_DISTRIBUTION_STATUS_s CSEPIC_PWM_DISTRIBUTION_STATUS_t; // SEPIC Converter PWM Distribution Status & Control word data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct  CSEPIC_PWM_DISTRIBUTION_s
 * @brief   Generic power converter switch-node control interface
 * @extends CSEPIC_SWITCH_NODE_SETTINGS_s
 * 
 * @details
 * This data structure is the data buffer for parameters required by the PWM distribution 
 * module of the SEPIC converter device driver.
 * 
 * @note
 * The PWM distribution module always needs to be called after and together with the feedback 
 * loop, where the most recent feedback loop output needs to be written to data field 
 * 'ControlOutput' before execution.
 * 
 *****************************************************************************************************/
struct CSEPIC_PWM_DISTRIBUTION_s 
{
    // Status & Control Word
    volatile struct CSEPIC_PWM_DISTRIBUTION_STATUS_s Status; ///< PWM Distribution Status and Control word
    
    // Control Output Distribution Settings
    volatile uint16_t  ControlOutput;       ///< Controller output target
    
	volatile uint16_t* ptrBuckLeg;          ///< Pointer to target register of buck leg
	volatile uint16_t* ptrBoostLeg;         ///< Pointer to target register of boost leg
	volatile uint16_t  MinLimitBuck;        ///< minimum value of target A
	volatile uint16_t  MaxLimitBuck;        ///< maximum value of target A
	volatile uint16_t  MinLimitBoost;       ///< minimum value of target B
	volatile uint16_t  MaxLimitBoost;       ///< maximum value of target B
    
    // Buck/Boost Leg Phase Shift
    volatile uint16_t* ptrBoostLegPhaseShiftReg; ///< Pointer to buck vs. boost leg phase shift register
    volatile uint16_t  BoostLegPhaseShift;  ///< Value of phase shift between buck and boost leg in [PWM ticks]
    
    // Voltage/Average Current Mode Control Trigger handling
    volatile uint16_t* ptrAdcTriggerA;      ///< Pointer to ADC trigger A register (e.g. PG1TRIGA)
    volatile uint16_t  OffsetAdcTriggerA;   ///< ADC trigger offset of trigger A to compensate propagation delays 
    volatile uint16_t* ptrAdcTriggerB;      ///< Pointer to ADC trigger B register (e.g. PG1TRIGB)
    volatile uint16_t  OffsetAdcTriggerB;   ///< ADC trigger offset of trigger B to compensate propagation delays 

} __attribute__((packed)); 
typedef struct CSEPIC_PWM_DISTRIBUTION_s CSEPIC_PWM_DISTRIBUTION_t;

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct  CSEPIC_SWITCH_NODE_SETTINGS_s
 * @brief   Generic power converter switch-node specifications
 * @extends CSEPIC_CONVERTER_s
 * 
 * @details
 * This data structure is used to set the converter switch-node specifications declaring individual
 * switch nodes, their PWM channel used as well as its switching frequency, phase-shift, dead times 
 * and duty ratio limits. Each switch node interface is listed individually for buck- and boost leg.
 * 
 * This data structure also includes the configuration and control interface of the PWM distribution 
 * module, which is responsible of distributing a single, linear control output onto both half-bridge
 * drives of buck- and boost-leg. It further supports automatic trigger placement of up to two 
 * individual ADC triggers and the capability to phase-shift the boost-leg vs. the buck-leg PWM output.
 * 
 *****************************************************************************************************/
struct CSEPIC_SWITCH_NODE_SETTINGS_s 
{
    volatile uint16_t period;                   ///< Switching period
    volatile bool     high_resolution_enable;   ///< Selecting if PWM module should use high-resolution mode 
    
//    volatile struct CSEPIC_SWITCH_NODE_INSTANCE_s buck_leg;     // SEPIC converter buck leg configuration
//    volatile struct CSEPIC_SWITCH_NODE_INSTANCE_s boost_leg;    // SEPIC converter boost leg configuration
//    volatile struct CSEPIC_PWM_DISTRIBUTION_s pwm_distribution; // SEPIC converter buck/boost leg control output distribution configuration
  
// VG_   
    volatile struct CSEPIC_SWITCH_NODE_INSTANCE_s sepic_switch;    // Sepic converter leg configuration
    volatile struct CSEPIC_PWM_DISTRIBUTION_s pwm_distribution; // SEPIC converter buck/boost leg control output distribution configuration
    
    
}; ///< Switching signal timing settings
typedef struct CSEPIC_SWITCH_NODE_SETTINGS_s  CSEPIC_SWITCH_NODE_SETTINGS_t; ///< Switching signal timing settings data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct  CSEPIC_ADC_INPUT_SCALING_s 
 * @brief   Generic power converter feedback specifications
 * @extends CSEPIC_ADC_INPUT_SETTINGS_s
 * @details
 * This data structure is used to set the converter feedback specifications declaring which
 * ADC channels are used including the individual AD input configuration such as trigger mode,
 * input mode, result format and value normalization.
 * 
 * *************************************************************************************************** */
struct CSEPIC_ADC_INPUT_SCALING_s {
    
    volatile int16_t factor; ///< Fractional scaling factor (range -1 ... 0.99969)
    volatile int16_t scaler; ///< Feedback bit-shift scaler used for number normalization
    volatile int16_t offset; ///< Signal offset as signed integer to be subtracted from ADC input

}; ///< ADC input signal scaling = (ADCBUF - <offset>) * <factor> >> 2^<scaler>
typedef struct CSEPIC_ADC_INPUT_SCALING_s CSEPIC_ADC_INPUT_SCALING_t; ///< ADC input signal scaling data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct  CSEPIC_ADC_INPUT_SETTINGS_s
 * @brief   Generic power converter ADC input channel configuration
 * @extends CSEPIC_FEEDBACK_SETTINGS_s
 * *************************************************************************************************** */
struct CSEPIC_ADC_INPUT_SETTINGS_s {
    
    volatile bool enabled;                  ///< input channel enable bit
    volatile uint16_t* adc_buffer;          ///< pointer to ADC result buffer
    volatile uint16_t gpio_instance;        ///< GPIO instance of the selected PWM generator
    volatile uint8_t adc_input;             ///< number of the ADC input channel used
    volatile uint8_t adc_core;              ///< number of the ADC core connected to the selected channel
    volatile uint8_t trigger_source;        ///< input channel trigger source
    volatile bool interrupt_enable;         ///< input channel interrupt enable bit
    volatile bool early_interrupt_enable;   ///< input channel early interrupt enable bit
    volatile bool differential_input;       ///< input channel differential mode enable bit
    volatile bool signed_result;            ///< input channel singed result mode enable bit
    volatile bool level_trigger;            ///< input channel level trigger mode enable bit
    volatile struct CSEPIC_ADC_INPUT_SCALING_s scaling; ///< normalization scaling settings

}; ///< ADC input channel configuration
typedef struct CSEPIC_ADC_INPUT_SETTINGS_s CSEPIC_ADC_INPUT_SETTINGS_t; ///< ADC input channel configuration data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct  CSEPIC_FEEDBACK_SETTINGS_s
 * @brief   Power converter feedback input channel declarations
 * @extends CSEPIC_CONVERTER_s
 * *************************************************************************************************** */
struct CSEPIC_FEEDBACK_SETTINGS_s {
    
    volatile CSEPIC_ADC_INPUT_SETTINGS_t ad_vin;                       ///< ADC input sampling input voltage
    volatile CSEPIC_ADC_INPUT_SETTINGS_t ad_vout;                      ///< ADC input sampling output voltage
    volatile CSEPIC_ADC_INPUT_SETTINGS_t ad_isns[CSEPIC_MPHASE_COUNT];   ///< ADC input sampling phase current
    volatile CSEPIC_ADC_INPUT_SETTINGS_t ad_temp;                      ///< ADC input sampling temperature
    
}; ///< SEPIC converter feedback declarations
typedef struct CSEPIC_FEEDBACK_SETTINGS_s CSEPIC_FEEDBACK_SETTINGS_t; ///< SEPIC converter feedback declarations data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct CSEPIC_GPIO_INSTANCE_s
 * @brief Generic power converter GPIO specifications
 * @extends CSEPIC_GPIO_SETTINGS_s
 * 
 * @details
 * This data structure is used to set the converter GPIO specifications declaring which
 * if and which additional GPIOs are used by the converter controller, such as POWER_GOOD.
 * 
 * *************************************************************************************************** */
struct CSEPIC_GPIO_INSTANCE_s {
    
    volatile bool enabled;      ///< Specifies, if this IO is used or not
    volatile uint16_t port;     ///< GPIO port instance number (0=Port RA, 0=Port RB, 0=Port RC, etc.)
    volatile uint16_t pin;      ///< GPIO port pin number
    volatile uint16_t polarity; ///< Output polarity, where 0=ACTIVE HIGH, 1=ACTIVE_LOW
    volatile uint16_t io_type;  ///< Input/Output definition (0=push-pull output, 1=input, 2=open-drain output)

}; ///< GPIO instance of the converter control GPIO
typedef struct CSEPIC_GPIO_INSTANCE_s CSEPIC_GPIO_INSTANCE_t; ///< GPIO instance of the converter control GPIO data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-private-data-types
 * @struct CSEPIC_GPIO_SETTINGS_s
 * @brief Generic power converter GPIO specifications
 * @extends CSEPIC_CONVERTER_s
 * *************************************************************************************************** */
struct CSEPIC_GPIO_SETTINGS_s {
    
    volatile CSEPIC_GPIO_INSTANCE_t EnableInput; ///< External ENABLE input
    volatile CSEPIC_GPIO_INSTANCE_t PowerGood; ///< Power Good Output

}; ///< GPIO instance of the converter control GPIO
typedef struct CSEPIC_GPIO_SETTINGS_s CSEPIC_GPIO_SETTINGS_t; ///< GPIO instance of the converter control GPIO data type

/****************************************************************************************************
 * @ingroup lib-layer-sepic-converter-properties-public-data-types
 * @struct  CSEPIC_CONVERTER_s
 * @brief   SEPIC Converter data object
 *****************************************************************************************************/
struct CSEPIC_CONVERTER_s 
{
    volatile CSEPIC_CONVERTER_STATUS_t status;     ///< SEPIC operation status bits 
    volatile CSEPIC_STATE_ID_t state_id;           ///< SEPIC state machine operating state ID
    volatile CSEPIC_CONVERTER_STARTUP_t startup;   ///< SEPIC startup timing settings 
    volatile CSEPIC_CONVERTER_SETTINGS_t set_values;///< Control field for global access to references
    volatile CSEPIC_CONVERTER_DATA_t data;         ///< SEPIC runtime data
    volatile CSEPIC_FEEDBACK_SETTINGS_t feedback;  ///< SEPIC converter feedback settings

    volatile CSEPIC_SWITCH_NODE_SETTINGS_t sw_node[CSEPIC_MPHASE_COUNT]; ///< SEPIC converter switch node settings
    volatile CSEPIC_GPIO_SETTINGS_t gpio;          ///< SEPIC converter additional GPIO specification
    
    volatile CSEPIC_LOOP_SETTINGS_t v_loop;        ///< SEPIC voltage control loop object
    volatile CSEPIC_LOOP_SETTINGS_t i_loop[CSEPIC_MPHASE_COUNT]; ///< SEPIC Current control loop objects
    
}; ///< SEPIC control & monitoring data structure
typedef struct CSEPIC_CONVERTER_s CSEPIC_CONVERTER_t; ///< SEPIC control & monitoring data structure data type

// Function Prototypes
/*********************************************************************************
 * @fn volatile uint16_t v_loop_Initialize(volatile struct NPNZ16b_s* controller)
 * @ingroup lib-layer-sepic-converter-functions-public
 * @brief Distributes a linear control output onto 
 * @param dirstribution_node: Pointer to SEPIC PWM distribution node data object of type struct CSEPIC_PWM_DISTRIBUTION_s
 *
 * @details
 * This function needs to be called from the end of a feedback loop when the most
 * recent control output has been computed. The linear feedback output covers 
 * the range from minimum output voltage in pure buck mode up to maximum output 
 * in pure boost mode. The lower 50% of this control range is written to the buck
 * leg duty cycle while the upper 50% of the control output is written to the boost 
 * leg duty cycle. The range limits (minimum and maximum duty cycle allowed for each 
 * leg) are considered and the distribution of the values is shifted accordingly.
 * 
 * To achieve good dynamic response of the feedback loop, it is recommended to keep 
 * some tension between buck and boost leg duty cycles by limiting the buck leg maximum
 * duty cycle below 100%. However, this will also limit the maximum achievable efficiency
 * as both legs will continuously operate and therefore create switching losses.
 * 
 * When highest efficiency is paramount over dynamic response, a bypass mode is
 * required allowing buck and/or boost leg drop into 100% on-time. In this condition
 * the bootstrap capacitors will not get recharged and the gate voltage of high-side
 * switches may drop below the threshold, eventually opening the high side FETs.
 * This can be solved by either using FET drivers with integrated charge pump allowing
 * continuous 100% on-time operating or to occasionally inject a duty cycle limit
 * to get the bootstrap capacitors recharged.
 *
 ********************************************************************************/

//#else
//    #pragma message "Warning: dev_sepic_typedef.h inclusion bypassed"

#endif	/* CSEPIC_CONVERTER_TYPE_DEF_H */
