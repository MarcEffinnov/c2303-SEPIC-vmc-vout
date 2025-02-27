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
 *  @file    dev_sepic_substates.h
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
 * File:   dev_sepic_substates.h
 * Author: M91406
 * Comments: SEPIC converter operation states header file
 * Revision history: 
 *   10/28/20   1.0  initial version
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CSEPIC_CONVERTER_OPERATION_SUBSTATES_H
#define	CSEPIC_CONVERTER_OPERATION_SUBSTATES_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer data types
#include <stdbool.h> // include standard boolean data types

/***********************************************************************************
 * @ingroup lib-layer-sepic-state-machine-properties-variables
 * @var volatile uint16_t (*csepicConverterRampUpSubStateMachine[])(volatile CSEPIC_CONVERTER_t *csepicInstance) 
 * @brief   Function pointer array of SEPIC converter startup sub-states
 * @details
 * The function pointer list csepicConverterRampUpSubStateMachine[] is providing 
 * access to a list of state functions. Each function mapped into this array 
 * as function pointer represents a self-contained, independent sub-state. 
 * The main state machine will call functions from this list in order of their
 * index within the array, starting from '0'. While this list is executed, the 
 * calling main state is transparent by passing through the return value of the 
 * most recent sub-state. Once all sub-states have been executed, the calling main 
 * state will return the COMPLETE flag, allowing the main state machine to move on.
 * 
 * Each function needs to be called by handing over a parameter of type
 * 
 * - CSEPIC_CONVERTER_t 
 * 
 * Each function returns of type unsigned integer:
 * 
 * - 0 = CSEPIC_OPSRET_ERROR
 * - 1 = CSEPIC_OPSRET_COMPLETE
 * - 2 = CSEPIC_OPSRET_REPEAT
 * 
 **********************************************************************************/

extern volatile uint16_t (*csepicConverterRampUpSubStateMachine[])
            (volatile CSEPIC_CONVERTER_t *csepicInstance); ///< SEPIC converter state machine function pointer array

/***********************************************************************************
 * @var     volatile uint16_t csepicRampUpSubStateList_size
 * @ingroup lib-layer-sepic-state-machine-properties-variables
 * @brief   SEPIC converter sub-state machine function pointer array size
 **********************************************************************************/

extern volatile uint16_t csepicRampUpSubStateList_size; ///< SEPIC converter state machine function pointer array size

#endif	/* CSEPIC_CONVERTER_OPERATION_SUBSTATES_H */

