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
 * File:   dev_sepic_pconfig.h
 * Author: M91406
 * Comments: Peripheral configuration template header file for generic SEPIC converter driver
 * Revision history: 
 * 1.0  initial release
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CSEPIC_CONVERTER_PERIPHERAL_CONFIGURATION_H
#define	CSEPIC_CONVERTER_PERIPHERAL_CONFIGURATION_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer data types
#include <stdbool.h> // include standard boolean data types
#include <stddef.h> // include standard definition data types

#include "dev_sepic_typedef.h"

/* ********************************************************************************
 * DEVICE GPIO INSTANCE CONFIGURATION
 * *******************************************************************************/
extern volatile uint16_t csepicGPIO_Initialize(volatile CSEPIC_CONVERTER_t* csepicInstance);
extern volatile uint16_t csepicGPIO_Set(volatile CSEPIC_GPIO_INSTANCE_t* csepicGPIOInstance);
extern volatile uint16_t csepicGPIO_Clear(volatile CSEPIC_GPIO_INSTANCE_t* csepicGPIOInstance);
extern volatile bool     csepicGPIO_GetPinState(volatile CSEPIC_GPIO_INSTANCE_t* csepicGPIOInstance);

/* ********************************************************************************
 * HIGH SPEED PWM MODULE CONFIGURATION
 * *******************************************************************************/
    
extern volatile uint16_t csepicPWM_ModuleInitialize(volatile CSEPIC_CONVERTER_t* csepicInstance);
extern volatile uint16_t csepicPWM_ChannelInitialize(volatile CSEPIC_CONVERTER_t* csepicInstance);
extern volatile uint16_t csepicPWM_Start(volatile CSEPIC_CONVERTER_t* csepicInstance);
extern volatile uint16_t csepicPWM_Stop(volatile CSEPIC_CONVERTER_t* csepicInstance);
extern volatile uint16_t csepicPWM_Suspend(volatile CSEPIC_CONVERTER_t* csepicInstance);
extern volatile uint16_t csepicPWM_Resume(volatile CSEPIC_CONVERTER_t* csepicInstance);
extern volatile uint16_t csepicPWM_Update(volatile CSEPIC_CONVERTER_t* csepicInstance);

extern volatile P33C_PWM_MODULE_t csepicPwmModuleConfig;
extern volatile P33C_PWM_GENERATOR_t csepicPwmGeneratorConfig;

/* ********************************************************************************
 * HIGH SPEED ADC MODULE CONFIGURATION
 * *******************************************************************************/

extern volatile uint16_t csepicADC_ModuleInitialize(void);
extern volatile uint16_t csepicADC_ChannelInitialize(volatile CSEPIC_ADC_INPUT_SETTINGS_t* adcInstance);
extern volatile uint16_t csepicADC_Start(void);

/* ********************************************************************************
 * ANALOG COMPARATOR INSTANCE CONFIGURATION
 * *******************************************************************************/

// (not supported yet)

#endif	/* CSEPIC_CONVERTER_PERIPHERAL_CONFIGURATION_H */

