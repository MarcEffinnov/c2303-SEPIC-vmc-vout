/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * @file   LEAH_HostMCU_r10_hwdescr.h
 * Author: M91406
 * @brief  SEPIC Development Board Hardware Descriptor header file
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __LEAH_HostMCU_r10_HARDWARE_DESCRIPTOR_H__
#define	__LEAH_HostMCU_r10_HARDWARE_DESCRIPTOR_H__

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer data types
#include <stdbool.h> // include standard boolean data types
#include <stddef.h> // include standard definition data types
#include <math.h> // include standard math functions library

#include "config/mcal.h"
#include "LEAH_HostMCU_r10_pinmap.h" // include microcontroller abstraction layer header files

/**************************************************************************************************
 * @ingroup hardware-id-macro
 * @{
 * @brief Global macro identifying the hardware version supported by 
 * 
 * @details
 * This global macro is used to identify the hardware version supported by this hardware 
 * abstraction layer header file. 
 * 
 **************************************************************************************************/

#ifndef __LEAH_HostMCU_r10__
  #define __LEAH_HostMCU_r10__
#endif

/** @} */ // end of group hardware-id-macro

/**************************************************************************************************
 * @ingroup special-options
 * @{
 * @brief Global defines used to enable/disable special firmware options
 * 
 * @details
 * This section is used to enable/disable special options useful during development, debugging, 
 * troubleshooting the recent firmware or to tailor special functions of this application. 
 * 
 **************************************************************************************************/

//<editor-fold defaultstate="collapsed" desc="Debug Ressources Settings">
/* CUSTOM RUNTIME OPTIONS */
#define PLANT_MEASUREMENT   false ///< If enabled, replaces the common voltage control loop by a simple P-control loop to perform measurements of the plant transfer function.


// DEBUG PIN1 IS SCL  (RB8)
#define DBGPIN1_ENABLE      true ///< Enables debug pin indicating control loop execution timing
#if DBGPIN1_ENABLE
    #define DBGPIN1_ODC                SCL_ODC
    #define DBGPIN1_CNPU               SCL_CNPU
    #define DBGPIN1_CNPD               SCL_CNPD
    #define DBGPIN1_SetHigh()          SCL_Set()
    #define DBGPIN1_SetLow()           SCL_Clear()
    #define DBGPIN1_Toggle()           SCL_Toggle()
    #define DBGPIN1_GetValue()         SCL_Read()
    #define DBGPIN1_SetDigitalInput()  SCL_InitInput()
    #define DBGPIN1_SetDigitalOutput() SCL_InitOutput()
#endif


// DEBUG PIN2 IS SDA (RB9)
#define DBGPIN2_ENABLE      false ///< Enables debug pin indicating control loop execution timing
#if DBGPIN2_ENABLE
    #define DBGPIN2_SetHigh()          SDA_Set()
    #define DBGPIN2_SetLow()           SDA_Clear()
    #define DBGPIN2_Toggle()           SDA_Toggle()
    #define DBGPIN2_GetValue()         _RC5
    #define DBGPIN2_SetDigitalInput()  SDA_InitInput())
    #define DBGPIN2_SetDigitalOutput() SDA_InitOutput()
#endif

// DBGDAC NOT USABLE ON HOST MCU SIDE!!!!!! ALWAYS False
#define DBGDAC_ENABLE       false ///< Enables debug DAC output pin reproduing control loop output as analog signal

/** @} */ // end of group special-options

/***************************************************************************************************
 * @ingroup circuit-gpio-mcal
 * @{
 * @brief Global abstraction labels of special circuit signal device pin assignments
 * 
 * @details
 * This section is used to define labels of hardware specific signals, which are directly 
 * assigned to specific device pins. These labels will be used throughout the code and remain
 * unchanged even if this firmware is migrated to another device or pin-out changes between
 * hardware revisions.
 * 
 **************************************************************************************************/

// Ref Debugging LED
#define DBGLED_PORT         DBGLED_GPIO_INSTANCE   ///< GPIO port declaration where 0=Port RA, 0=Port RB, 0=Port RC, etc.
#define DBGLED_PIN          DBGLED_GPIO_PORT_PIN   ///< GPIO port pin declaration where 0=Rx0, 1=Rx1, 2=Rx3, etc.
#define DBGLED_Init()       DBGLED_InitOutput()    ///< Initializes the specified GPIO as digital output

// Additional Board I/Os

// (none)

/** @} */ // end of group circuit-gpio-mcal

/**************************************************************************************************
 * @ingroup circuit-peripheral-mcal
 * @{
 * @brief Special Function chip resources declarations
 * 
 * @details
 * Some applications may require additional chip resources, which are not supported by
 * default library modules used in this project. For static configurations, these chip 
 * resources are initialized in function \ref sysUserPeriperhals_Initialize during system 
 * startup. Any specific declarations required for abstracting hardware or microcontroller
 * features is placed in this section
 * 
 **************************************************************************************************/

#define DAC_OUTPUT_INSTANCE     1U ///< Digital-To-Analog Converter instance used for enhanced debugging
//#define DAC_BUFFER_OPA_INSTANCE 0U ///< Operational amplifier instance used to buffer DAC output /// Using DACOUT1 on RA3 instead of original OPA3OUT (3U)
#define DAC_OUTPUT_INIT_VALUE   0U ///< initial value of the Digital-To-Analog Converter debugging output

#if (DAC_OUTPUT_INSTANCE == 1U)
  #define DACOUT_Set(x) { DAC1DATH=x; } ///< Direct SFR Write Access Macro for Digital-To-Analog Converter instance #1
  #define DACOUT_Get()    DAC1DATH      ///< Direct SFR Read Access Macro for Digital-To-Analog Converter instance #1
#elif (DAC_OUTPUT_INSTANCE == 2U)
  #define DACOUT_Set(x) { DAC2DATH=x; } ///< Direct SFR Write Access Macro for Digital-To-Analog Converter instance #2
  #define DACOUT_Get()    DAC2DATH      ///< Direct SFR Read Access Macro for Digital-To-Analog Converter instance #2
#elif (DAC_OUTPUT_INSTANCE == 3U)
  #define DACOUT_Set(x) { DAC3DATH=x; } ///< Direct SFR Write Access Macro for Digital-To-Analog Converter instance #3
  #define DACOUT_Get()    DAC3DATH      ///< Direct SFR Read Access Macro for Digital-To-Analog Converter instance #3
#endif

// LED DRIVER MODE CONSTANTS
#define LED_DRIVER_MODE_ENABLED             false ///< Enable LED String driver mode (voltage loop bypass in CC mode for ACMC regulation mode)
#define NUMBER_OF_LEDS                      6     ///< Number of LEDs in output LED string
#define LED_VF_MAX                          (float) 3.30    ///> Maximum LED forward voltage
#define LED_VF_NOM                          (float) 2.85    ///> Nominal LED forward voltage
#define LED_VF_MIN                          (float) 2.60    ///> Minimum LED forward voltage

#define LED_STRING_VOUT_MAX                 (float) (NUMBER_OF_LEDS * LED_VF_MAX)   ///> Maximum anticipated output voltage to drive LED string
#define LED_STRING_VOUT_NOM                 (float) (NUMBER_OF_LEDS * LED_VF_NOM)   ///> Nominal anticipated output voltage to drive LED string
#define LED_STRING_VOUT_MIN                 (float) (NUMBER_OF_LEDS * LED_VF_MIN)   ///> Minimum anticipated output voltage to drive LED string


/** @} */ // end of group circuit-peripheral-mcal
//</editor-fold>

/**************************************************************************************************
 * @ingroup pwm-settings-sepic
 * @{
 * @brief User-declaration of global defines for PWM signal generator settings
 * 
 * @details
 * This section defines fundamental PWM settings required for the SEPIC converter.
 * These settings are determined by hardware and defined using physical quantities. Pre-compiler 
 * macros are used to convert physical values into binary (integer) numbers to be written to 
 * Special Function Registers (SFR).
 * 
 **************************************************************************************************/
#define CSEPIC_NO_OF_PHASES                 1U ///< Number of power converter phases of this design
#define CSEPIC_SWITCHING_FREQUENCY          (float)  500.0e+3 ///< Fixed Switching frequency in [Hz]

// SMPS SETTINGS
#define CSEPIC_PWM_DUTY_CYCLE_MIN      (float)  0.01  ///< Minimum on/off-time ratio (duty ratio) in [%]
#define CSEPIC_PWM_DUTY_CYCLE_MAX      (float)  0.90  ///< Maximum on/off-time ratio (duty ratio) in [%]
#define CSEPIC_LEADING_EDGE_BLANKING   (float)120.0e-9 ///< Leading Edge Blanking period in [sec]
#define CSEPIC_DEAD_TIME_LEADING_EDGE  (float) 70.0e-9 ///< Leading Edge Dead Time delay in [sec]
#define CSEPIC_DEAD_TIME_FALLING_EDGE  (float) 80.0e-9 ///< Falling Edge Dead Time delay in [sec]

/** @} */ // end of group pwm-settings ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//<editor-fold defaultstate="collapsed" desc="PWM Assignments">
/** 
 * @ingroup pwm-mcal-sepic
 * @{
 * @brief PWM peripheral output pins, control signals and register assignments of converter phase #1
 * 
 * @details
 * Converter phase #1 uses a simple half-bridge to commutate the switch node. The signal source
 * therefore only requires a single PWM generator instance to be configured in fixed frequency 
 * complementary mode with dead times. Additional PWM peripheral features are used by the firmware
 * to respond to interrupts, trigger ADC conversions, control device output pins during startup 
 * and fault responses and to change timing settings on the fly. 
 * 
 * Please review the device data sheet for details about register names and settings.
 */

#define CSEPIC_PWM_CHANNEL            PWM_SEPIC_PGxCHANNEL ///< PWM Instance Index (e.g. 1=PWM1, 2=PWM2, etc.) /// PWM1 selected for Buck leg
#define CSEPIC_PWM_GPIO_INSTANCE      PWM_SEPIC_GPIO_INSTANCE  ///< Number indicating device port, where 0=Port RA, 0=Port RB, 0=Port RC, etc. /// RB port selected
#define CSEPIC_PWM_GPIO_PORT_PINH     PWM_SEPIC_GPIO_PORT_PIN ///< Port Pin Number
#define CSEPIC_PWM_OUTPUT_SWAP        true ///< false = PWMxH is the leading PWM output, true = PWMxL is the leading PWM output
#define CSEPIC_PWM_PDC                PWM_SEPIC_PGxDC ///< PWM Instance Duty Cycle Register /// PG1DC
#define _CSEPIC_PWM_Interrupt         _PWM_SEPIC_PWMxInterrupt ///< PWM Interrupt Service Routine label
#define CSEPIC_PWM_IF                 PWM_SEPIC_PWMxIF  ///< PWM Interrupt Flag Bit
#define CSEPIC_PWM_IE                 PWM_SEPIC_PWMxIE  ///< PWM Interrupt Enable Bit PWM_SEPIC_PWMxIE
#define CSEPIC_PWM_IP                 PWM_SEPIC_PWMxIP  ///< PWM Interrupt Priority
#define CSEPIC_PWM_TRGSRC_TRG1        PWM_SEPIC_TRGSRC_PWMxTRG1  ///< PWM Trigger #1 Trigger Source of this channel
#define CSEPIC_PWM_TRGSRC_TRG2        PWM_SEPIC_TRGSRC_PWMxTRG2  ///< PWM Trigger #2 Trigger Source of this channel
#define CSEPIC_PWM_PGxTRIGA           PWM_SEPIC_PGxTRIGA ///< PWM trigger register A
#define CSEPIC_PWM_PGxTRIGB           PWM_SEPIC_PGxTRIGB ///< PWM trigger register B
#define CSEPIC_PWM_PGxTRIGC           PWM_SEPIC_PGxTRIGC ///< PWM trigger register C
#define CSEPIC_PWM_ADTR1OFS           0U ///< ADC Trigger 1 Offset:  0...31
#define CSEPIC_PWM_ADTR1PS            0U ///< ADC Trigger 1 Postscaler: 0...31
#define CSEPIC_PWM_UPDREQ             PWM_SEPIC_PGxUPDREQ ///< Update request bit of this channel

/** @} */ // end of group pwm-mcal-sepic ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="PWM Macros using user defined parameters">
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/** 
 * @ingroup pwm-macros-sepic
 * @{
 * @brief Conversion macros for user-declarations of PWM parameters
 * 
 * @details
 * These conversion macros are used to convert user settings defined as physical 
 * quantities into binary (integer) numbers, which will be written to registers and
 * variables and used in calculations throughout the firmware.
 */

#define CSEPIC_SWITCHING_PERIOD         (float)(1.0/CSEPIC_SWITCHING_FREQUENCY)   ///< Switching period in [sec]
#define CSEPIC_PWM_PERIOD               (uint16_t)(float)(CSEPIC_SWITCHING_PERIOD / PWM_CLOCK_PERIOD) ///< This sets the switching period of the converter
#define CSEPIC_PWM_PHASE_SHIFT     (uint16_t)((float)CSEPIC_PWM_PERIOD / (float)CSEPIC_NO_OF_PHASES) ///< This sets the phase shift between phase #1 and #2
#define CSEPIC_PWM_DEAD_TIME_LE    (uint16_t)(CSEPIC_DEAD_TIME_LEADING_EDGE / (float)PWM_CLOCK_PERIOD) ///< Rising edge dead time [tick = 250ps]
#define CSEPIC_PWM_DEAD_TIME_FE    (uint16_t)(CSEPIC_DEAD_TIME_FALLING_EDGE / (float)PWM_CLOCK_PERIOD) ///< Falling edge dead time [tick = 250ps]
#define CSEPIC_PWM_DC_MIN          (uint16_t)(CSEPIC_PWM_DUTY_CYCLE_MIN * (float)CSEPIC_PWM_PERIOD) ///< This sets the minimum duty cycle
#define CSEPIC_PWM_DC_MAX          (uint16_t)(CSEPIC_PWM_DUTY_CYCLE_MAX * (float)CSEPIC_PWM_PERIOD) ///< This sets the maximum duty cycle
#define CSEPIC_LEB_PERIOD          (uint16_t)(CSEPIC_LEADING_EDGE_BLANKING / (float)PWM_CLOCK_PERIOD) ///< Leading Edge Blanking = n x PWM resolution (here: 50 x 2ns = 100ns)

/** @} */ // end of group pwm-macros-sepic ~~~~~~~~~~~~~~~~~
//</editor-fold>

//<editor-fold defaultstate="expanded" desc="Input Voltage VIN USER DEFINED PARAMETERS">
/**************************************************************************************************
 * @ingroup input-voltage-feedback-settings-sepic
 * @{
 * @brief Declaration of input voltage feedback properties
 * 
 * @details
 * In this section the output voltage feedback signal scaling, gain, valid signal limits and nominal
 * operating point is specified. Physical quantities are used to define values. Macros are used to 
 * convert given physical values into binary (integer) number to be written into SFRs and variables.
 * *************************************************************************************************/
#define VIN_MINIMUM            (float) 8.000   ///< Minimum input voltage in [V]
#define VIN_NOMINAL            (float)14.000   ///< Nominal input voltage in [V]
#define VIN_MAXIMUM            (float)36.000   ///< Maximum input voltage in [V]

#define VIN_UNDER_VOLTAGE      (float) 7.500   ///< Under Voltage Lock Out Cut Off in [V]
#define VIN_OVER_VOLTAGE       (float)38.000   ///< Over Voltage Lock Out Cut Off in [V]
#define VIN_HYSTERESIS         (float) 2.000   ///< UVLO/OVLO Hysteresis in [V]
    
#define VIN_R1                 (float)23.200   ///< Upper voltage divider resistor in [kOhm]
#define VIN_R2                 (float) 2.200   ///< Lower voltage divider resistor in [kOhm]
    
#define VIN_FEEDBACK_OFFSET    (float) 0.0000  ///< Physical, static signal offset in [V]
#define VIN_ADC_TRG_DELAY      (float) 20.0e-9 ///< ADC trigger delay in [sec]

/** @} */ // end of group input-voltage-feedback-settings-sepic ~~~~~~~~~~~~~~~~
//</editor-fold>

// Common Peripheral Assignments
#define _VIN_ADCInterrupt  _FB_VIN_ADCANxInterrupt ///< ADC interrupt service routine function call of the input voltage feedback channel /// AN10 on RB8
#define _VIN_ADCISR_IF     FB_VIN_ADCANxIF   ///< ADC interrupt flag bit of the input voltage feedback channel
#define _VIN_ADCISR_IE     FB_VIN_ADCANxIE   ///< ADC interrupt enable bit of the input voltage feedback channel
#define _VIN_ADCISR_IP     FB_VIN_ADCANxIP   ///< ADC interrupt priority bits of the input voltage feedback channel
#define VIN_ANSEL          FB_VIN_ANSEL    ///< GPIO analog function mode enable bit
#define VIN_ADCCORE        FB_VIN_ADCCORE  ///< 0=Dedicated Core #0, 1=Dedicated Core #1, 8=Shared ADC Core
#define VIN_ADCIN          FB_VIN_ADCAN    ///< Analog input number (e.g. '5' for 'AN5')  /// AN10 on RB8
#define VIN_ADCBUF         FB_VIN_ADCBUF   ///< ADC input buffer of this ADC channel
#define VIN_ADCTRIG        CSEPIC_PWM_PGxTRIGB    ///< Register used for trigger placement
#define VIN_TRGSRC         CSEPIC_PWM_TRGSRC_TRG2 ///< PWM Trigger 1 via PGxTRIGy

//<editor-fold defaultstate="collapsed" desc="Input Voltage VIN feedback assignments">
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/** 
 * @ingroup input-voltage-feedback-mcal-sepic
 * @{
 * @brief ADC input assignments of input voltage feedback signals
 * 
 * @details
 * In this section the ADC input channels, related ADC result buffers, trigger
 * sources and interrupt vectors are defined. These settings allow the fast 
 * re-assignments of feedback signals in case of hardware changes.
 */

// SEPIC Peripheral Assignments
#define _CSEPIC_VIN_ADCInterrupt  _VIN_ADCInterrupt ///< ADC interrupt service routine function call of the input voltage feedback channel /// AN10 on RB8
#define _CSEPIC_VIN_ADCISR_IF     VIN_ADCISR_IF   ///< ADC interrupt flag bit of the input voltage feedback channel
#define _CSEPIC_VIN_ADCISR_IE     VIN_ADCISR_IE   ///< ADC interrupt enable bit of the input voltage feedback channel
#define _CSEPIC_VIN_ADCISR_IP     VIN_ADCISR_IP   ///< ADC interrupt priority bits of the input voltage feedback channel
#define CSEPIC_VIN_ANSEL          VIN_ANSEL    ///< GPIO analog function mode enable bit
#define CSEPIC_VIN_ADCCORE        VIN_ADCCORE  ///< 0=Dedicated Core #0, 1=Dedicated Core #1, 8=Shared ADC Core
#define CSEPIC_VIN_ADCIN          VIN_ADCIN    ///< Analog input number (e.g. '5' for 'AN5')  /// AN10 on RB8
#define CSEPIC_VIN_ADCBUF         VIN_ADCBUF   ///< ADC input buffer of this ADC channel
#define CSEPIC_VIN_ADCTRIG        VIN_ADCTRIG    ///< Register used for trigger placement
#define CSEPIC_VIN_TRGSRC         VIN_TRGSRC ///< PWM Trigger 1 via PGxTRIGy


/** @} */ // end of group input-voltage-feedback-mcal-sepic ~~~~~~~~~~~~~~~~~~~~
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Input Voltage VIN Macros using user defined parameters">
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/** 
 * @ingroup input-voltage-feedback-macros-sepic
 * @{
 * @brief Conversion macros of input voltage feedback parameters
 * 
 * @details
 * These conversion macros are used to convert user settings defined as physical 
 * quantities into binary (integer) numbers, which will be written to registers and
 * variables and used in calculations throughout the firmware.
 */

// SEPIC Input Voltage VIN Feedback Declarations
#define CSEPIC_VIN_MINIMUM            VIN_MINIMUM   ///< Minimum input voltage in [V]
#define CSEPIC_VIN_NOMINAL            VIN_NOMINAL   ///< Nominal input voltage in [V]
#define CSEPIC_VIN_MAXIMUM            VIN_MAXIMUM   ///< Maximum input voltage in [V]
#define CSEPIC_VIN_UNDER_VOLTAGE      VIN_UNDER_VOLTAGE   ///< Under Voltage Lock Out Cut Off in [V]
#define CSEPIC_VIN_OVER_VOLTAGE       VIN_OVER_VOLTAGE   ///< Over Voltage Lock Out Cut Off in [V]
#define CSEPIC_VIN_HYSTERESIS         VIN_HYSTERESIS   ///< UVLO/OVLO Hysteresis in [V]  
#define CSEPIC_VIN_R1                 VIN_R1   ///< Upper voltage divider resistor in [kOhm]
#define CSEPIC_VIN_R2                 VIN_R2   ///< Lower voltage divider resistor in [kOhm]
#define CSEPIC_VIN_FEEDBACK_OFFSET    VIN_FEEDBACK_OFFSET  ///< Physical, static signal offset in [V]
#define CSEPIC_VIN_ADC_TRG_DELAY      VIN_ADC_TRG_DELAY ///< ADC trigger delay in [sec]

#define CSEPIC_VIN_FEEDBACK_GAIN  (float)((CSEPIC_VIN_R2) / (CSEPIC_VIN_R1 + CSEPIC_VIN_R2)) // DO NOT CHANGE
#define CSEPIC_VIN_MIN            (uint16_t)(CSEPIC_VIN_MINIMUM * CSEPIC_VIN_FEEDBACK_GAIN / ADC_GRANULARITY)   ///< Minimum input voltage
#define CSEPIC_VIN_NOM            (uint16_t)(CSEPIC_VIN_NOMINAL * CSEPIC_VIN_FEEDBACK_GAIN / ADC_GRANULARITY)   ///< Nominal input voltage
#define CSEPIC_VIN_MAX            (uint16_t)(CSEPIC_VIN_MAXIMUM * CSEPIC_VIN_FEEDBACK_GAIN / ADC_GRANULARITY)   ///< Maximum input voltage
#define CSEPIC_VIN_HYST           (uint16_t)(CSEPIC_VIN_HYSTERESIS * CSEPIC_VIN_FEEDBACK_GAIN / ADC_GRANULARITY)  ///< Over Voltage LOck Out voltage    
#define CSEPIC_VIN_UVLO_TRIP      (uint16_t)(CSEPIC_VIN_UNDER_VOLTAGE * CSEPIC_VIN_FEEDBACK_GAIN / ADC_GRANULARITY) ///< Under Voltage LOck Out voltage
#define CSEPIC_VIN_UVLO_RELEASE   (uint16_t)((CSEPIC_VIN_UNDER_VOLTAGE + CSEPIC_VIN_HYSTERESIS) * CSEPIC_VIN_FEEDBACK_GAIN / ADC_GRANULARITY) ///< Under Voltage LOck Out voltage
#define CSEPIC_VIN_OVLO_TRIP      (uint16_t)((CSEPIC_VIN_OVER_VOLTAGE * CSEPIC_VIN_FEEDBACK_GAIN) / ADC_GRANULARITY)  ///< Over Voltage LOck Out voltage
#define CSEPIC_VIN_OVLO_RELEASE   (uint16_t)((CSEPIC_VIN_OVER_VOLTAGE - CSEPIC_VIN_HYSTERESIS) * CSEPIC_VIN_FEEDBACK_GAIN / ADC_GRANULARITY)  ///< Over Voltage LOck Out voltage
#define CSEPIC_VIN_ADC_TRGDLY     (uint16_t)(CSEPIC_VIN_ADC_TRG_DELAY / PWM_CLOCK_PERIOD) ///< Input voltage ADC trigger delay
#define CSEPIC_VIN_OFFSET         (uint16_t)(CSEPIC_VIN_FEEDBACK_OFFSET / ADC_GRANULARITY) ///< Input voltage feedback offset
#define CSEPIC_VIN_NORM_INV_G     (float)(1.0/CSEPIC_VIN_FEEDBACK_GAIN) ///< Inverted feedback gain required for value normalization
#define CSEPIC_VIN_NORM_SCALER    (int16_t)(ceil(log(CSEPIC_VIN_NORM_INV_G)/log(2))) ///< VIN normalization  
#define CSEPIC_VIN_NORM_FACTOR    (int16_t)((CSEPIC_VIN_NORM_INV_G / pow(2.0, CSEPIC_VIN_NORM_SCALER)) * (pow(2.0, 15)-1)) ///< VIN normalization factor scaled in Q15
#define CSEPIC_VIN_RANGE_MAX      (float)(ADC_REFERENCE * CSEPIC_VIN_NORM_INV_G)

/** @} */ // end of group input-voltage-feedback-macros-sepic ~~~~~~~~~~~~~~~~~~
//</editor-fold>

//<editor-fold defaultstate="expanded" desc="Output Voltage VOUT USER DEFINED PARAMETERS">
/**************************************************************************************************
 * @ingroup output-voltage-feedback-settings-sepic
 * @{
 * @brief Declaration of output voltage feedback properties
 * 
 * @details
 * In this section the output voltage feedback signal scaling, gain, valid signal limits and nominal
 * operating point is specified. Physical quantities are used to define values. Macros are used to 
 * convert given physical values into binary (integer) number to be written into SFRs and variables.
 * *************************************************************************************************/

#if (!LED_DRIVER_MODE_ENABLED)
// Feedback Declarations
    #define CSEPIC_VOUT_MINIMUM         (float) 9.000   ///< Absolute minimum output voltage
    #define CSEPIC_VOUT_NOMINAL         (float) 26.000   ///< Nominal output voltage
    #define CSEPIC_VOUT_MAXIMUM         (float) 30.000   ///< Absolute maximum output voltage (Over Voltage Protection)
    #define CSEPIC_VOUT_MAXIMUM_CMP     (float) 28.000   ///< Absolute maximum output voltage (Over Voltage Protection) using Boot leg PWM override (PWM3 FP PCI)
#else
        // Feedback Declarations IN LED DRIVER MODE
    #define CSEPIC_VOUT_MINIMUM         LED_STRING_VOUT_MIN   ///< Absolute minimum output voltage
    #define CSEPIC_VOUT_NOMINAL         LED_STRING_VOUT_NOM   ///< Nominal output voltage
    #define CSEPIC_VOUT_MAXIMUM         (LED_STRING_VOUT_MAX + CSEPIC_VOUT_HYSTERESIS)   ///< Absolute maximum output voltage (Over Voltage Protection)
    #define CSEPIC_VOUT_MAXIMUM_CMP     LED_STRING_VOUT_MAX   ///< Absolute maximum output voltage (Over Voltage Protection) using Boot leg PWM override (PWM3 FP PCI)
#endif
#define CSEPIC_VOUT_HYSTERESIS          (float) 1.000   ///< Over Voltage Protection Hysteresis
#define CSEPIC_VOUT_TOLERANCE_MAX       (float) 1.000   ///< Output voltage tolerance at nominal operating point [+/-]
#define CSEPIC_VOUT_TOLERANCE_MIN       (float) 1.000   ///< Output voltage tolerance at nominal operating point [+/-]
#define CSEPIC_VOUT_DIV_R1              (float) 130.000  ///< Upper voltage divider resistor in kOhm
#define CSEPIC_VOUT_DIV_R2              (float) 10.000  ///< Lower voltage divider resistor in kOhm
        /// WARNING: if SEPIC_VOUT_FEEDBACK_OFFSET is not 0.000, DataProvider option in DCLD tool must be disabled not to push negative data at startup.
#define CSEPIC_VOUT_FEEDBACK_OFFSET     (float) 0.000  ///< Physical, static signal offset in [V] at feedback pin (after resistive divider)
#define CSEPIC_VOUT_ADC_TRG_DELAY       (float) 20.0e-9 ///< Trigger delay in [sec]
#define CSEPIC_VOUT_SETTING_5V          (float) 5.000 ///< Default output voltage level 0f  5V
#define CSEPIC_VOUT_SETTING_9V          (float) 9.000 ///< Default output voltage level 0f  9V
#define CSEPIC_VOUT_SETTING_12V         (float)12.000 ///< Default output voltage level 0f 12V
#define CSEPIC_VOUT_SETTING_15V         (float)15.000 ///< Default output voltage level 0f 15V
#define CSEPIC_VOUT_SETTING_20V         (float)20.000 ///< Default output voltage level 0f 20V
#define CSEPIC_VOUT_REFERENCE_SLEW_RATE (float)1000.0 ///< Output voltage slew rate during reference transitions in [V/s]


/** @} */ // end of group output-voltage-feedback-settings-sepic ~~~~~~~~~~~~~~~
//</editor-fold>


//<editor-fold defaultstate="collapsed" desc="Output Voltage VOUT feedback assignments">
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/** 
 * @ingroup output-voltage-feedback-mcal-sepic
 * @{
 * @brief ADC input assignments of output voltage feedback signals
 * 
 * @details
 * In this section the ADC input channels, related ADC result buffers, trigger
 * sources and interrupt vectors are defined. These settings allow the fast 
 * re-assignments of feedback signals in case of hardware changes.
 */

// VOUT OVP sense through internal comparator (driving PWM 1/2 Fault PCI)
#define CSEPIC_VOUT_COMP_INSTANCE    3U         // Using CMP3/DAC3 module
#define CSEPIC_VOUT_COMP_IN_SEL      FB_VOUT_SEPIC_COMP3_IN_SEL         // Comparator input select
#define CSEPIC_VOUT_COMP_HYS_SEL     0b11       // Input Hysteresis = 45mV
#define CSEPIC_VOUT_COMP_HYS_POL     1          // Input Hysteresis applied to input falling edge
#define CSEPIC_VOUT_COMP_LATCH_EN    0          // Comparator output latch.
#if (CSEPIC_VOUT_COMP_INSTANCE == 1U)
  #define CSEPIC_VOUT_CMP_Threshold_Set(x) { DAC1DATH=x; } ///< Direct SFR Write Access Macro for Digital-To-Analog Converter instance #1
  #define CSEPIC_VOUT_CMP_Threshold_Get()    DAC1DATH      ///< Direct SFR Read Access Macro for Digital-To-Analog Converter instance #1
#elif (CSEPIC_VOUT_COMP_INSTANCE == 2U)
  #define CSEPIC_VOUT_CMP_Threshold_Set(x) { DAC2DATH=x; } ///< Direct SFR Write Access Macro for Digital-To-Analog Converter instance #2
  #define CSEPIC_VOUT_CMP_Threshold_Get()    DAC2DATH      ///< Direct SFR Read Access Macro for Digital-To-Analog Converter instance #2
#elif (CSEPIC_VOUT_COMP_INSTANCE == 3U)
  #define CSEPIC_VOUT_CMP_Threshold_Set(x) { DAC3DATH=x; } ///< Direct SFR Write Access Macro for Digital-To-Analog Converter instance #3
  #define CSEPIC_VOUT_CMP_Threshold_Get()    DAC3DATH      ///< Direct SFR Read Access Macro for Digital-To-Analog Converter instance #3
#endif
#define CSEPIC_VOUT_COMP_OUT         _SCL_RPxR
#if (!DBGPIN1_ENABLE)
#define CSEPIC_VOUT_COMP_OUT_SEL     0b011001  // CMP3 output routed to PPS setting
#else
#define CSEPIC_VOUT_COMP_OUT_SEL     0b000000  // CMP3 output not routed to PIM DBG pin RD12 (RP76)), set as default IO
#endif

// ADC Peripheral Assignments
#define _CSEPIC_FB_VOUT_ADCInterrupt   _FB_VOUT_SEPIC_ADCANxInterrupt ///< ADC interrupt service routine function call of the input voltage feedback channel
#define _CSEPIC_FB_VOUT_ADCISR_IF      FB_VOUT_SEPIC_ADCANxIF   ///< ADC interrupt flag bit of the input voltage feedback channel
#define _CSEPIC_FB_VOUT_ADCISR_IE      FB_VOUT_SEPIC_ADCANxIE   ///< ADC interrupt enable bit of the input voltage feedback channel
#define _CSEPIC_FB_VOUT_ADCISR_IP      FB_VOUT_SEPIC_ADCANxIP   ///< ADC interrupt priority bits of the input voltage feedback channel
#define CSEPIC_FB_VOUT_ANSEL           FB_VOUT_SEPIC_ANSEL ///< GPIO analog function mode enable bit
#define CSEPIC_FB_VOUT_ADCCORE         FB_VOUT_SEPIC_ADCCORE ///< 0=Dedicated Core #0, 1=Dedicated Core #1, 8=Shared ADC Core
#define CSEPIC_FB_VOUT_ADCIN           FB_VOUT_SEPIC_ADCAN ///< Analog input number (e.g. '5' for 'AN5')
#define CSEPIC_FB_VOUT_ADCBUF          FB_VOUT_SEPIC_ADCBUF ///< ADC input buffer of this ADC channel
#define CSEPIC_FB_VOUT_ADCTRIG         CSEPIC_PWM_PGxTRIGA    ///< Register used for trigger placement
#define CSEPIC_FB_VOUT_TRGSRC          CSEPIC_PWM_TRGSRC_TRG1 ///< PWM Trigger 1 via PGxTRIGy

// FB_VOUT OVP sense through internal comparator (driving PWM 1/2 Fault PCI)
#define CSEPIC_FB_VOUT_COMP_INSTANCE    3U         // Using CMP1/DAC1 module
#define CSEPIC_FB_VOUT_COMP_IN_SEL      FB_VOUT_SEPIC_COMP3_IN_SEL         // Comparator input select
#define CSEPIC_FB_VOUT_COMP_HYS_SEL     0b11       // Input Hysteresis = 45mV
#define CSEPIC_FB_VOUT_COMP_HYS_POL     1          // Input Hysteresis applied to input falling edge
#define CSEPIC_FB_VOUT_COMP_LATCH_EN    0          // Comparator output latch.
#if (CSEPIC_FB_VOUT_COMP_INSTANCE == 1U)
  #define SEPIC_FB_VOUT_CMP_Threshold_Set(x) { DAC1DATH=x; } ///< Direct SFR Write Access Macro for Digital-To-Analog Converter instance #1
  #define SEPIC_FB_VOUT_CMP_Threshold_Get()    DAC1DATH      ///< Direct SFR Read Access Macro for Digital-To-Analog Converter instance #1
#elif (CSEPIC_FB_VOUT_COMP_INSTANCE == 2U)
  #define SEPIC_FB_VOUT_CMP_Threshold_Set(x) { DAC2DATH=x; } ///< Direct SFR Write Access Macro for Digital-To-Analog Converter instance #2
  #define SEPIC_FB_VOUT_CMP_Threshold_Get()    DAC2DATH      ///< Direct SFR Read Access Macro for Digital-To-Analog Converter instance #2
#elif (CSEPIC_FB_VOUT_COMP_INSTANCE == 3U)
  #define SEPIC_FB_VOUT_CMP_Threshold_Set(x) { DAC3DATH=x; } ///< Direct SFR Write Access Macro for Digital-To-Analog Converter instance #3
  #define SEPIC_FB_VOUT_CMP_Threshold_Get()    DAC3DATH      ///< Direct SFR Read Access Macro for Digital-To-Analog Converter instance #3
#endif
#define CSEPIC_FB_VOUT_COMP_OUT         _SCA_RPxR
#if (!DBGPIN2_ENABLE)
#define CSEPIC_FB_VOUT_COMP_OUT_SEL     0b011001  // CMP3 output routed to PPS setting
#else
#define SEPIC_FB_VOUT_COMP_OUT_SEL     0b000000  // CMP3 output not routed to PIM DBG
#endif

/** @} */ // end of group output-voltage-feedback-mcal-sepic ~~~~~~~~~~~~~~~~~~~
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Output Voltage VOUT Macros using user defined parameters">
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/** 
 * @ingroup output-voltage-feedback-macros-sepic
 * @{
 * @brief Conversion macros of output voltage feedback parameters
 * 
 * @details
 * These conversion macros are used to convert user settings defined as physical 
 * quantities into binary (integer) numbers, which will be written to registers and
 * variables and used in calculations throughout the firmware.
 */

#define CSEPIC_VOUT_FEEDBACK_GAIN (float)((CSEPIC_VOUT_DIV_R2) / (CSEPIC_VOUT_DIV_R1 + CSEPIC_VOUT_DIV_R2)) ///< Feedback gain required for value normalization
#define CSEPIC_VOUT_REF           (uint16_t)((CSEPIC_VOUT_NOMINAL * CSEPIC_VOUT_FEEDBACK_GAIN) / ADC_GRANULARITY) ///< Macro calculating the integer number equivalent of the output voltage reference given above in [V]
#define CSEPIC_VOUT_NOM           (uint16_t) CSEPIC_VOUT_REF ///< Alias macro of the integer number equivalent of the nominal output voltage given above in [V]
#define CSEPIC_VOUT_DEV_TRIP      (uint16_t)((CSEPIC_VOUT_TOLERANCE_MAX * CSEPIC_VOUT_FEEDBACK_GAIN) / ADC_GRANULARITY) ///< Macro calculating the integer number equivalent of the maximum allowed output voltage deviation given above in [V], which will lead to a converter shut down when exceeded.
#define CSEPIC_VOUT_DEV_RELEASE   (uint16_t)((CSEPIC_VOUT_TOLERANCE_MIN * CSEPIC_VOUT_FEEDBACK_GAIN) / ADC_GRANULARITY) ///< Macro calculating the integer number equivalent of the maximum allowed output voltage deviation given above in [V], which needs to be underrun before a shut-down converter can recover
#define CSEPIC_VOUT_OVP_TRIP      (uint16_t)((CSEPIC_VOUT_MAXIMUM * CSEPIC_VOUT_FEEDBACK_GAIN) / ADC_GRANULARITY)  ///< Over Voltage Protection voltage trip signal level
#define CSEPIC_VOUT_OVP_RELEASE   (uint16_t)(((CSEPIC_VOUT_MAXIMUM - CSEPIC_VOUT_HYSTERESIS) * CSEPIC_VOUT_FEEDBACK_GAIN) / ADC_GRANULARITY)  ///< Over Voltage Protection voltage recovery signal level
#define CSEPIC_VOUT_OVP_TRIP_CMP  (uint16_t)((CSEPIC_VOUT_MAXIMUM_CMP * CSEPIC_VOUT_FEEDBACK_GAIN) / ADC_GRANULARITY)  ///< Over Voltage Protection voltage trip signal level
#define CSEPIC_VOUT_OFFSET        (uint16_t)(CSEPIC_VOUT_FEEDBACK_OFFSET / ADC_GRANULARITY) ///< Macro calculating the integer number equivalent of the physical, static signal offset of this feedback channel
#define CSEPIC_VOUT_ADC_TRGDLY    (uint16_t)(CSEPIC_VOUT_ADC_TRG_DELAY / PWM_CLOCK_PERIOD) ///< Macro calculating the integer number equivalent of the signal chain time delay between internal PWM timebase and effective switching edge of the leading FET
#define CSEPIC_VOUT_NORM_INV_G    (float)(1.0/CSEPIC_VOUT_FEEDBACK_GAIN) ///< Inverted feedback gain required for value normalization
#define CSEPIC_VOUT_NORM_SCALER   (int16_t)(ceil(log(CSEPIC_VOUT_NORM_INV_G)/log(2))) ///< VOUT normalization bit-shift scaler  
#define CSEPIC_VOUT_NORM_FACTOR   (int16_t)((CSEPIC_VOUT_NORM_INV_G / pow(2.0, CSEPIC_VOUT_NORM_SCALER)) * (pow(2.0, 15)-1)) ///< VOUT normalization factor scaled in Q15
#define CSEPIC_VOUT_RANGE_MAX     (float)(ADC_REFERENCE * CSEPIC_VOUT_NORM_INV_G) ///< Macro calculating the integer number equivalent of the total output voltage range defined by the settings given above in [V]] 
#define CSEPIC_VOUT_REFERENCE_5V  (uint16_t)(CSEPIC_VOUT_SETTING_5V * CSEPIC_VOUT_FEEDBACK_GAIN / ADC_GRANULARITY) ///< Default output voltage level 0f 5V
#define CSEPIC_VOUT_REFERENCE_9V  (uint16_t)(CSEPIC_VOUT_SETTING_9V * CSEPIC_VOUT_FEEDBACK_GAIN / ADC_GRANULARITY) ///< Default output voltage level 0f 5V
#define CSEPIC_VOUT_REFERENCE_12V (uint16_t)(CSEPIC_VOUT_SETTING_12V * CSEPIC_VOUT_FEEDBACK_GAIN / ADC_GRANULARITY) ///< Default output voltage level 0f 5V
#define CSEPIC_VOUT_REFERENCE_15V (uint16_t)(CSEPIC_VOUT_SETTING_15V * CSEPIC_VOUT_FEEDBACK_GAIN / ADC_GRANULARITY) ///< Default output voltage level 0f 5V
#define CSEPIC_VOUT_REFERENCE_20V (uint16_t)(CSEPIC_VOUT_SETTING_20V * CSEPIC_VOUT_FEEDBACK_GAIN / ADC_GRANULARITY) ///< Default output voltage level 0f 5V
#define CSEPIC_VOUT_REF_SLEWRATE  (uint16_t)(float)((CSEPIC_VOUT_REFERENCE_SLEW_RATE * CSEPIC_VOUT_FEEDBACK_GAIN / ADC_GRANULARITY) * MAIN_EXECUTION_PERIOD) // Incremental step applied during online reference transition ramps



/** @} */ // end of group output-voltage-feedback-macros-sepic ~~~~~~~~~~~~~~~~~
//</editor-fold>


//<editor-fold defaultstate="expanded" desc="Current Sense ISNS USER DEFINED PARAMETERS">
/**************************************************************************************************
 * @ingroup phase-current-feedback-settings-sepic
 * @{
 * @brief Declaration of phase-current feedback properties
 * 
 * @details
 * In this section the phase-current feedback signal scaling, gain, valid signal limits and nominal
 * operating point is specified. Physical quantities are used to define parameter values to ease
 * the system configuration. 
 * 
 * As DPSK3 supports two different current sense devices (current sense transformers and shunt
 * amplifier devices) users can select which one should be used for regulating the output current.
 * Based on the selection made, the appropriate feedback channels and signal scaling values will be
 * used by the firmware.
 * 
 * Macros are used to convert given physical values into binary (integer) number to be written
 * into SFRs and variables and being used in runtime calculations.  
 * (see \ref phase-current-feedback-macros-sepic for details)
 * *************************************************************************************************/

// Feedback Declarations
#define CSEPIC_ISNS_CT     0                   ///< Use current sense transformer as main current feedback source
#define CSEPIC_ISNS_AMP    1                   ///< Use shunt amplifier as main current feedback source   
#define CSEPIC_RSENSE      2                   ///< Use shunt on low-side load with Op Amp
#define CSEPIC_ISNS_OPTION    CSEPIC_RSENSE    ///< Select one of the available current sense feedback options
// Settings based on the selection made above
#if (SEPIC_ISNS_OPTION == SEPIC_RSENSE)
/// 0.1R current sense between load - node and ground using OPA1 as x30 gain
    #define CSEPIC_ISNS_FEEDBACK_GAIN       (float) 3.000   ///< Current Gain in V/A
    #define CSEPIC_ISNS_MINIMUM             (float) -0.500   ///< absolute total minimum output current (average)
    #define CSEPIC_ISNS_MAXIMUM             (float) 0.200   ///< absolute total maximum output current (average)
    #define CSEPIC_ISNS_RELEASE             (float) 0.200   ///< current reset level after over current event
    #define CSEPIC_ISNS_STARTUP_LIMIT       (float) 0.000   ///< output current reference (average)
    #define CSEPIC_ISNS_COMMON_MODE_LIMIT   (float) 0.000   ///< phase current sense common mode voltage minimum 
    #define CSEPIC_OPEN_LOOP_STARTUP        false            ///< Flag indicating if minium common mode voltage range needs to be secured before regulation can be trusted
    #define CSEPIC_ISNS_ADC_TRG_DELAY       (float) 240.0e-9 ///< ADC trigger delay for current sense in [sec]
    #define CSEPIC_ISNS_FEEDBACK_OFFSET     (float) 0.000   ///< current sense feedback offset (average)
    #define CSEPIC_ISNS_OFFSET_CALIBRATION_ENABLE   false     ///< Current Sense Offset Calibration is disabled 
    #define CSEPIC_SYNCCTL_ON_THRESHOLD     (float) 0.250   ///< Phase Current above which the synchronous rectifier will be turned on
    #define CSEPIC_SYNCCTL_OFF_THRESHOLD    (float) 0.200   ///< Phase Current below which the synchronous rectifier will be turned off
    
    #define CSEPIC_FB_IOUT_OPA_INSTANCE     1U              ///< OPA1 is used for current feedback amplification
    #define CSEPIC_FB_IOUT_OPA_INN_EN       ISNN_ANSEL      ///< OPA1 INN Analog Input Enable
    #define CSEPIC_FB_IOUT_OPA_INP_EN       ISNP_ANSEL      ///< OPA1 INP Analog Input Enable
#endif
#define CSEPIC_ISNS_REFERENCE_SLEW_RATE     (float) 50.0    ///< Phase current slew rate during reference transitions in [A/s]



/** @} */ // end of group phase-current-feedback-settings-sepic ~~~~~~~~~~~~~~~~
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Current Sense ISNS Macros using user defined parameters">
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/** 
 * @ingroup phase-current-feedback-macros-sepic
 * @{
 * @brief Conversion macros of phase current feedback parameters
 * 
 * @details
 * These conversion macros are used to convert user settings defined as physical 
 * quantities into binary (integer) numbers, which will be written to registers and
 * variables and used in calculations throughout the firmware.
 */

// Phase Current Feedback Settings Conversion Macros
#define CSEPIC_ISNS_MIN           (uint16_t)(int16_t)((CSEPIC_ISNS_MINIMUM * CSEPIC_ISNS_FEEDBACK_GAIN) / ADC_GRANULARITY)  ///< Minimum Current Limit including Feedback Offset
#define CSEPIC_ISNS_OCL           (uint16_t)((CSEPIC_ISNS_MAXIMUM * CSEPIC_ISNS_FEEDBACK_GAIN) / ADC_GRANULARITY)  ///< Over Current Limit including Feedback Offset
#define CSEPIC_ISNS_OCL_RELEASE   (uint16_t)((CSEPIC_ISNS_RELEASE* CSEPIC_ISNS_FEEDBACK_GAIN) / ADC_GRANULARITY)  ///< Over Current Release Level including Feedback Offset

#define CSEPIC_ISNS_START_LIMIT   (uint16_t)((CSEPIC_ISNS_STARTUP_LIMIT * CSEPIC_ISNS_FEEDBACK_GAIN) / ADC_GRANULARITY)  ///< Output Current Reference
#define CSEPIC_ISNS_CMOD_LIMIT    (uint16_t)(CSEPIC_ISNS_COMMON_MODE_LIMIT * CSEPIC_VOUT_FEEDBACK_GAIN / ADC_GRANULARITY) ///< Common Mode Voltage Limit specifies the minimum output voltage required before the current sense feedback becomes reliable
#define CSEPIC_ISNS_FB_OFFSET     (uint16_t)(CSEPIC_ISNS_FEEDBACK_OFFSET / ADC_GRANULARITY)
#define CSEPIC_ISNS_ADC_TRGDLY    (uint16_t)(CSEPIC_ISNS_ADC_TRG_DELAY / PWM_CLOCK_PERIOD)

#define CSEPIC_ISNS_NORM_INV_G    (float)(1.0/CSEPIC_ISNS_FEEDBACK_GAIN) ///< Inverted feedback gain required for value normalization
#define CSEPIC_ISNS_NORM_SCALER   (int16_t)(ceil(log(CSEPIC_ISNS_NORM_INV_G * CSEPIC_ISNS_NORM_INV_G)/log(2))) ///< ISNS normalization  
#define CSEPIC_ISNS_NORM_FACTOR   (int16_t)((CSEPIC_ISNS_NORM_INV_G / pow(2.0, CSEPIC_ISNS_NORM_SCALER)) * (pow(2.0, 15)-1)) ///< ISNS normalization factor scaled in Q15

#define CSEPIC_ISNS_REF_SLEWRATE  (uint16_t)(float)((CSEPIC_ISNS_REFERENCE_SLEW_RATE * CSEPIC_ISNS_FEEDBACK_GAIN / ADC_GRANULARITY) * MAIN_EXECUTION_PERIOD) // Incremental step applied during online reference transition ramps


/** @} */ // end of group phase-current-feedback-macros ~~~~~~~~~~~~~~~~~~~~~~~
//</editor-fold>


//<editor-fold defaultstate="collapsed" desc="Current Sense ISNS feedback assignments">
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/** 
 * @ingroup phase-current-feedback-mcal-sepic
 * @{
 * @brief ADC input assignments of phase current feedback signals
 * 
 * @details
 * In this section the ADC input channels, related ADC result buffers, trigger
 * sources and interrupt vectors are defined. These settings allow the fast 
 * re-assignments of feedback signals in case of hardware changes.
 */

// Peripheral Assignments OPA1 Output
#if (SEPIC_ISNS_OPTION == SEPIC_RSENSE)
    #define _CSEPIC_ISNS_ADCInterrupt     _FB_IOUT_SEPIC_ADCANxInterrupt ///< Interrupt Service Routine function name
    #define _CSEPIC_ISNS_ADCISR_IF        FB_IOUT_SEPIC_ADCANxIF   ///< Interrupt Service Routine Flag Bit
    #define _CSEPIC_ISNS_ADCISR_IE        FB_IOUT_SEPIC_ADCANxIE   ///< Interrupt Service Routine Enable Bit
    #define _CSEPIC_ISNS_ADCISR_IP        FB_IOUT_SEPIC_ADCANxIP   ///< Interrupt Service Routine Priority Selection

    #define CSEPIC_ISNS_ANSEL             FB_IOUT_SEPIC_ANSEL   ///< GPIO analog function mode enable bit
    #define CSEPIC_ISNS_ADCCORE           FB_IOUT_SEPIC_ADCCORE ///< 0=Dedicated Core #0, 1=Dedicated Core #1, 7=Shared ADC Core
    #define CSEPIC_ISNS_ADCIN             FB_IOUT_SEPIC_ADCAN   ///< Analog input number (e.g. '5' for 'AN5')
    #define CSEPIC_ISNS_ADCBUF            FB_IOUT_SEPIC_ADCBUF  ///< ADC input buffer of this ADC channel
    #define CSEPIC_ISNS_ADCTRIG           CSEPIC_PWM_PGxTRIGB    ///< Register used for trigger placement
    #define CSEPIC_ISNS_TRGSRC            CSEPIC_PWM_TRGSRC_TRG2 ///< PWM1 (=PG1) Trigger 2 via PGxTRIGB
#else
    #pragma message "hardware abstraction layer warning: no current sense feedback selected."
#endif

/** @} */ // end of group phase-current-feedback-mcal-sepic ~~~~~~~~~~~~~~~~~~~~
//</editor-fold>


/**************************************************************************************************
 * @ingroup adaptive-gain-control-settings-sepic
 * @{
 * @brief Declaration of additional hardware-specific defines required for adaptive gain control
 * 
 * @details
 * In this section additional macros are defined to calculate constant parameters for the
 * adaptive gain modulation algorithm using user defined settings declared in their respective
 * sections. Any change of these parameters will also result in a change of the values of the 
 * gain modulation parameters of this section.
 * *************************************************************************************************/

#define CSEPIC_AGC_EXECUTION_DELAY     (float)(370.0e-9) ///< AGC Observer Algorithm Execution Time in [sec]

/** @} */ // end of group adaptive-gain-control-settings-sepic ~~~~~~~~~~~~~~~~~
//</editor-fold>


//<editor-fold defaultstate="collapsed" desc="Automatic Gain Control AGC Macros using user defined parameters">
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/** 
 * @ingroup adaptive-gain-control-macros-sepic
 * @{
 * @brief Conversion macros of phase current feedback parameters
 * 
 * @details
 * These conversion macros are used to convert user settings defined as physical 
 * quantities into binary (integer) numbers, which will be written to registers and
 * variables and used in calculations throughout the firmware.
 */

#define CSEPIC_VL_MINIMUM         (float)(abs(CSEPIC_VIN_UNDER_VOLTAGE + CSEPIC_VOUT_MINIMUM)) ///< Minimum input voltage - maximum output voltage
#define CSEPIC_VL_NOMINAL         (float)(abs(CSEPIC_VIN_NOMINAL       + CSEPIC_VOUT_NOMINAL)) ///< Nominal input voltage - nominal output voltage
#define CSEPIC_VL_MAXIMUM         (float)(CSEPIC_VIN_RANGE_MAX     + CSEPIC_VOUT_MAXIMUM) ///< Maximum input voltage - output voltage = 0V

// To calculate the voltage across the inductor, input and output voltage ADC results need to be normalized. The normalization factor is determined here
// Each input voltage sample has to be multiplied with this scaling factor to allow the calculation of the instantaneous voltage across the inductor
#define CSEPIC_VIN_NORM_FCT       (float)(CSEPIC_VOUT_FEEDBACK_GAIN / CSEPIC_VIN_FEEDBACK_GAIN)   ///< VIN-2-VOUT Normalization Factor
#define CSEPIC_AGC_IO_NORM_SCALER (int16_t)(ceil(log(CSEPIC_VIN_NORM_FCT)/log(2))) ///< Nominal VL Q15 scaler  
#define CSEPIC_AGC_IO_NORM_FACTOR (int16_t)((CSEPIC_VIN_NORM_FCT / pow(2.0, CSEPIC_AGC_IO_NORM_SCALER)) * (pow(2.0, 15)-1)) ///< Nominal VL Q15 factor 

// The AGC compare value is defined at nominal input voltage and output voltage 
// The maximum modulation factor is normalized to fractional '1' to prevent number overruns
#define CSEPIC_AGC_FACTOR_MAX     (float)(CSEPIC_VL_MAXIMUM / CSEPIC_VL_MINIMUM) ///< Floating point number of the maximumm limit of the adaptive gain modulation factor (float)
#define CSEPIC_AGC_NOM_SCALER     (uint16_t)(ceil(log(CSEPIC_AGC_FACTOR_MAX)/log(2))) ///< Bit-shift scaler of the floating point number of the maimum limit of the adaptive gain modulation factor
#define CSEPIC_AGC_NOM_FACTOR     (uint16_t)(0x7FFF >> CSEPIC_AGC_NOM_SCALER) ///< Fractional of the floating point number of the maimum limit of the adaptive gain modulation factor
#define CSEPIC_AGC_MEDIAN         (int16_t)(((int16_t)(((float)CSEPIC_VIN_NOM * CSEPIC_VIN_NORM_FCT) + CSEPIC_VOUT_NOM))>>CSEPIC_AGC_NOM_SCALER) ///< Adaptive gain modulation factor at nominal operating point

// Additional execution time calculation to be considered in trigger delay and overall control timing
#define CSEPIC_AGC_EXEC_DLY       (uint16_t)(CSEPIC_AGC_EXECUTION_DELAY / PWM_CLOCK_PERIOD) ///< Macro calculating the integer number equivalent of the AGC algorithm computation time


/** @} */ // end of group adaptive-gain-control-macros-sepic ~~~~~~~~~~~~~~~~~~~
//</editor-fold>


/**************************************************************************************************
 * @ingroup isr-settings-sepic
 * @{
 * @brief Control loop Interrupt Vector Settings
 * 
 * @details
 * Control loops are called in dedicated interrupt service routines of PWM events, ADC events
 * or triggered by timers. This section allows users to set and modify the interrupt service 
 * routine triggers and their priority to set up and optimize the control system interrupt 
 * structure.
 * 
 * *************************************************************************************************/
    
#define CSEPIC_VOUT_TRIG_PWM  0   ///< SEPIC VOUT control loop is called in PWM interrupt
#define CSEPIC_VOUT_TRIG_ADC  1   ///< SEPIC VOUT control loop is called in ADC interrupt

#define CSEPIC_VOUT_TRIGGER_MODE  CSEPIC_VOUT_TRIG_PWM ///< Currently selected voltage loop interrupt vector
#define CSEPIC_VOUT_ISR_PRIORITY  5 ///< Voltage loop interrupt vector priority (valid settings between 0...6 with 6 being the highest priority)

#if (CSEPIC_VOUT_TRIGGER_MODE == CSEPIC_VOUT_TRIG_ADC)    

  #define _CSEPIC_LOOP_Interrupt     _CSEPIC_FB_VOUT_ADCInterrupt ///< Interrupt vector function call label
  #define _CSEPIC_LOOP_ISR_IP        _CSEPIC_FB_VOUT_ADCISR_IP ///< Interupt vector priority register bits
  #define _CSEPIC_LOOP_ISR_IF        _CSEPIC_FB_VOUT_ADCISR_IF ///< Interupt vector flag bit register bit
  #define _CSEPIC_LOOP_ISR_IE        _CSEPIC_FB_VOUT_ADCISR_IE ///< Interupt vector enable bit register bit

#elif (CSEPIC_VOUT_TRIGGER_MODE == CSEPIC_VOUT_TRIG_PWM)

  #define _CSEPIC_LOOP_Interrupt     _CSEPIC_PWM_Interrupt ///< Interrupt vector function call label
  #define _CSEPIC_LOOP_ISR_IP        CSEPIC_PWM_IP ///< Interupt vector priority register
  #define _CSEPIC_LOOP_ISR_IF        CSEPIC_PWM_IF ///< Interupt vector flag bit register bit
  #define _CSEPIC_LOOP_ISR_IE        CSEPIC_PWM_IE ///< Interupt vector enable bit register bit

#endif

/** @} */ // end of group isr-settings-sepic ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//</editor-fold>

/**************************************************************************************************
 * @ingroup startup-timing-settings-sepic
 * @{
 * @brief Global defines for soft-start specific parameters
 * 
 * @details
 * This section is used to define power supply startup timing settings. The soft-start sequence 
 * is part of the power controller. It allows to program specific timings for 
 *   - Power On Delay
 *   - Ramp Period 
 *   - Power Good Delay
 * 
 * After the startup has passed these three timing periods, the power supply is ending up in 
 * "normal" operation, continuously regulating the output until a fault is detected or the 
 * operating state is changed for any other reason. When the output voltage reference is changed, 
 * the power control state machine will use the voltage ramp slope defined here to tune from the 
 * recent voltage reference to the new reference value. During this period the BUSY-bit of the 
 * power controller (status word, bit #7) will be set. This status bit will be cleared automatically
 * by the power controller state machine once the new reference value has been applied and the 
 * converter is back in constant regulation mode.
 * 
 * Pre-compiler macros are used to translate physical values into binary (integer) numbers to 
 * be written to SFRs and variables.  
 * (see \ref startup-timing-macros-sepic for details)
 * 
 * @note
 * On DPSK3 it takes roughly 500 ms until the auxiliary power has been started, the 
 * PIC24 housekeeping controller on the bottom side of the board resets the protection
 * logic and allows the dsPIC to run. After this period the dsPIC controller starts to 
 * execute its firmware.
 *  
 * This additional startup delay of ~500 ms is not considered in the settings below and 
 * needs to be taken into account when adjusting startup timing. Use an independent debugging
 * pin toggle at the beginning of the firmware to verify the specified startup timing is 
 * applied as desired.
 **************************************************************************************************/

#define CSEPIC_POWER_ON_DELAY          (float) 200e-3 ///< power on delay in [sec]
#define CSEPIC_VRAMP_PERIOD            (float) 100e-3 ///< voltage ramp-up period in [sec]
#define CSEPIC_IRAMP_PERIOD            (float) 100e-3 ///< output current ramp-up period in [sec]
#define CSEPIC_POWER_GOOD_DELAY        (float) 200e-3 ///< power good delay in [sec]
/** @} */ // end of group startup-timing-settings ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//</editor-fold>


//<editor-fold defaultstate="collapsed" desc="Startup Macros using user defined parameters">
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/** 
 * @ingroup startup-timing-macros-sepic
 * @{
 * @brief Conversion Macros of Startup Timing Settings
 * 
 * @details
 * These conversion macros are used to convert user settings defined as physical 
 * quantities into binary (integer) numbers, which will be written to registers and
 * variables and used in calculations throughout the firmware.
 */

#define CSEPIC_POD       (uint16_t)(((float)CSEPIC_POWER_ON_DELAY / (float)MAIN_EXECUTION_PERIOD)-1.0)
#define CSEPIC_VRAMP_PER (uint16_t)(((float)CSEPIC_VRAMP_PERIOD / (float)MAIN_EXECUTION_PERIOD)-1.0)
#define CSEPIC_VREF_STEP (uint16_t)((float)CSEPIC_VOUT_REF / (float)(CSEPIC_VRAMP_PER + 1.0))
#define CSEPIC_IRAMP_PER (uint16_t)(((float)CSEPIC_IRAMP_PERIOD / (float)MAIN_EXECUTION_PERIOD)-1.0)
#define CSEPIC_IREF_STEP (uint16_t)((float)CSEPIC_ISNS_START_LIMIT / (float)(CSEPIC_VRAMP_PER + 1.0))
#define CSEPIC_PGD       (uint16_t)(((float)CSEPIC_POWER_GOOD_DELAY / (float)MAIN_EXECUTION_PERIOD)-1.0)

/** @} */ // end of group startup-timing-macros-sepic ~~~~~~~~~~~~~~~~~~~~~~~~~~
//</editor-fold>


/**************************************************************************************************
 * @ingroup fault-response-settings-sepic
 * @{
 * @brief Global defines for fault-monitor related parameters
 * 
 * @details
 * This section is used to define power supply fault object timing settings. The fault monitor 
 * is continuously monitoring declared data objects at the high-priority task frequency defined by 
 * \ref MAIN_EXECUTION_PERIOD. Based on this known interval, filtering delays for fault trip and 
 * fault recovery events to allow users to adjust the fault detection sensitivity.
 * 
 * - Fault Trip Event Delay   
 * This setting defines for how long a fault condition has to be continuously active before the 
 * effective fault trip status/event will be triggered.
 * 
 * - Fault Recovery Event Delay   
 * This setting defines for how long a fault condition has to be continuously cleared before the 
 * effective fault recovery status/event will be triggered.
 * 
 * - Restart Cycle Limit
 * In case of a persistent fault condition (e.g continuous short circuit or unstable feedback loop)
 * the fault monitor will limit the number of restart attempts specified by FAULT_RESTART_CYCLES.
 * When this threshold is exceeded, the power supply will latch in save state (off) and a CPU or 
 * power cycle is required to start-up the power supply again.
 * 
 *************************************************************************************************/

#define CSEPIC_UVLO_TRIP_DELAY          (float) 5e-3   ///< under voltage lock out trip delay in [sec]
#define CSEPIC_UVLO_RECOVERY_DELAY      (float) 500e-3 ///< under voltage lock out recovery delay in [sec]
#define CSEPIC_OVLO_TRIP_DELAY          (float) 5e-3   ///< over voltage lock out trip delay in [sec]
#define CSEPIC_OVLO_RECOVERY_DELAY      (float) 500e-3 ///< over voltage lock out recovery delay in [sec]
#define CSEPIC_REGERR_TRIP_DELAY        (float) 25e-3  ///< regulation error trip delay in [sec]
#define CSEPIC_REGERR_RECOVERY_DELAY    (float) 2000e-3 ///< regulation error recovery delay in [sec]
#define CSEPIC_OCP_TRIP_DELAY           (float) 2e-3   ///< over current proection trip delay in [sec]
#define CSEPIC_OCP_RECOVERY_DELAY       (float) 2000e-3 ///< over current proection recovery delay in [sec]
#define CSEPIC_OVP_TRIP_DELAY           (float) 5e-3   ///< over voltage proection trip delay in [sec]
#define CSEPIC_OVP_RECOVERY_DELAY       (float) 1000e-3 ///< over voltage proection recovery delay in [sec]

#define CSEPIC_FAULT_RESTART_CYCLES     10U  ///< Maximum number of restart cycles: Fault state will be latched until CPU reset or power cycle


/** @} */ // end of group fault-response-settings-sepic ~~~~~~~~~~~~~~~~~~~~~~~~
//</editor-fold>


//<editor-fold defaultstate="collapsed" desc="Faults Macros using user defined parameters">
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/** 
 * @ingroup fault-response-macros-sepic
 * @{
 * @brief Conversion Macros of Fault Response Timing Settings
 * 
 * @details
 * These conversion macros are used to convert user settings defined as physical 
 * quantities into binary (integer) numbers, which will be written to registers and
 * variables and used in calculations throughout the firmware.
 */

#define CSEPIC_UVLO_TDLY   (uint16_t)(((float)      CSEPIC_UVLO_TRIP_DELAY / (float)MAIN_EXECUTION_PERIOD)-1.0) ///< under voltage lock out trip delay conversion nacro
#define CSEPIC_UVLO_RDLY   (uint16_t)(((float)  CSEPIC_UVLO_RECOVERY_DELAY / (float)MAIN_EXECUTION_PERIOD)-1.0) ///< under voltage lock out recovery delay conversion nacro
#define CSEPIC_OVLO_TDLY   (uint16_t)(((float)      CSEPIC_OVLO_TRIP_DELAY / (float)MAIN_EXECUTION_PERIOD)-1.0) ///< over voltage lock out trip delay conversion nacro
#define CSEPIC_OVLO_RDLY   (uint16_t)(((float)  CSEPIC_OVLO_RECOVERY_DELAY / (float)MAIN_EXECUTION_PERIOD)-1.0) ///< over voltage lock out recovery delay conversion nacro
#define CSEPIC_REGERR_TDLY (uint16_t)(((float)    CSEPIC_REGERR_TRIP_DELAY / (float)MAIN_EXECUTION_PERIOD)-1.0) ///< regulation error trip delay conversion macro
#define CSEPIC_REGERR_RDLY (uint16_t)(((float)CSEPIC_REGERR_RECOVERY_DELAY / (float)MAIN_EXECUTION_PERIOD)-1.0) ///< regulation error recovery delay conversion macro
#define CSEPIC_OCP_TDLY    (uint16_t)(((float)       CSEPIC_OCP_TRIP_DELAY / (float)MAIN_EXECUTION_PERIOD)-1.0) ///< over current protection trip Delay conversion macro
#define CSEPIC_OCP_RDLY    (uint16_t)(((float)   CSEPIC_OCP_RECOVERY_DELAY / (float)MAIN_EXECUTION_PERIOD)-1.0) ///< over current protection recovery delay conversion nacro
#define CSEPIC_OVP_TDLY    (uint16_t)(((float)       CSEPIC_OVP_TRIP_DELAY / (float)MAIN_EXECUTION_PERIOD)-1.0) ///< over voltage protection trip Delay conversion macro
#define CSEPIC_OVP_RDLY    (uint16_t)(((float)   CSEPIC_OVP_RECOVERY_DELAY / (float)MAIN_EXECUTION_PERIOD)-1.0) ///< over voltage protection recovery delay conversion nacro

// PCI Register settings
#define PCI_PGxIOCONL_FLTDAT_PWMH       0b10  ///< when PCI fault occus, PWMH is driven high, PWML is driven low
#define PCI_PGxIOCONL_FLTDAT_PWML       0b01  ///< when PCI fault occus, PWMH is driven low, PWML is driven high
#define PCI_PGxIOCONL_FLTDAT_NO_PWM     0b00  ///< when PCI fault occus, PWMH is driven low, PWML is driven low

#define PCI_PGxFPCIL_TERM_MANUAL        0b000 ///< PCI FAULT manual termination by SWTERM bit write
#define PCI_PGxFPCIL_TERM_AUTO          0b001 ///< PCI FAULT auto termination when source goes inactive
#define PCI_PGxFPCIL_TERM_TRIGA         0b010 ///< PCI FAULT auto termination when source PWM TRIGA occurs
#define PCI_PGxFPCIL_TERM_TRIGB         0b011 ///< PCI FAULT auto termination when source PWM TRIGB occurs
#define PCI_PGxFPCIL_TERM_TRIGC         0b100 ///< PCI FAULT auto termination when source PWM TRIGC occurs

#define PCI_PGxFPCIL_AQSS_NOTHING       0b000 ///< PCI FAULT acceptance, no qualifier is used
#define PCI_PGxFPCIL_AQSS_DC_ACTIVE     0b001 ///< PCI FAULT acceptance when duty cycle is active

#define PCI_PGxFPCIL_PSS_CMP1_OUT       0b11011 ///< PCI source is Comparator 1 output
#define PCI_PGxFPCIL_PSS_CMP2_OUT       0b11100 ///< PCI source is Comparator 2 output
#define PCI_PGxFPCIL_PSS_CMP3_OUT       0b11101 ///< PCI source is Comparator 3 output

// CSEPIC PCI Settings
#define CSEPIC_PCI_PGxIOCONL_FLTDAT    PCI_PGxIOCONL_FLTDAT_NO_PWM
#define CSEPIC_PCI_PGxFPCIL_TERM       PCI_PGxFPCIL_TERM_AUTO
#define CSEPIC_PCI_PGxFPCIL_AQSS       PCI_PGxFPCIL_AQSS_NOTHING
#define CSEPIC_PCI_PGxFPCIL_PSS        PCI_PGxFPCIL_PSS_CMP3_OUT


/** @} */ // end of group fault-response-macros-sepic ~~~~~~~~~~~~~~~~~~~~~~~~~~
//</editor-fold>

#endif	/* __LEAH_HostMCU_r10_HARDWARE_DESCRIPTOR_H__ */

// end of file
