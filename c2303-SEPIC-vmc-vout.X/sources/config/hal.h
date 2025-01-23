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
 * File:   hal.h
 * Author: M91406
 * Comments: Hardware Abstraction Layer (HAL) main header file
 * Revision history: 
 *   1.0    initial release
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APPLICATION_HARDWARE_ABSTRACTION_LAYER_H
#define	APPLICATION_HARDWARE_ABSTRACTION_LAYER_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer data types
#include <stdbool.h> // include standard boolean data types
#include <stddef.h> // include standard definition data types

// HARDWARE ABSTRACTION LAYER HEADER FILES

#if defined (__LEAH_HostMCU_r10__)
  #include "config/hal/LEAH_HostMCU_r10_hwdescr.h" // include hardware description declarations of 4-Switch BUck/Boost LEAH Board R0.1
  #include "config/hal/LEAH_HostMCU_r10_pinmap.h" // include hardware description declarations of dsPIC33CK used as Client MCU on LEAH board R0.1
#endif

#if defined (__c2303_r10__)
  #include "config/hal/c2303_r10_hwdescr.h" // include hardware description declarations of 4-Switch BUck/Boost LEAH Board R0.1
  #include "config/hal/c2303_r10_pinmap.h" // include hardware description declarations of dsPIC33CK used as Client MCU on LEAH board R0.1
#endif


#endif	/* APPLICATION_HARDWARE_ABSTRACTION_LAYER_H */

