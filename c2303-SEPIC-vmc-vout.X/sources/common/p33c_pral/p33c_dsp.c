/*LICENSE *****************************************************************************************
 *
 * Software License Agreement
 *
 * Copyright (R) 2021 Microchip Technology Inc.  All rights reserved. Microchip licenses to you the
 * right to use, modify, copy and distribute Software only when embedded on a Microchip 
 * microcontroller or digital signal controller, which is integrated into your product or third 
 * party product (pursuant to the sublicense terms in the accompanying license agreement).
 *
 * You should refer to the license agreement accompanying this Software for additional information 
 * regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR 
 * IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR 
 * OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT  
 * LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS  
 * OR LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY  
 * THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *
 * ***********************************************************************************************/

// Include Header Files
#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer number data types
#include <stdbool.h> // include standard boolean data types (true/false)

#include "p33c_dsp.h"

/*************************************************************************************************
 * @file p33c_dsp.c
 * @brief Driver file for dsPIC33C DSP Configuration SFRs
 * @details
 * The DSP engine of dsPIC33 offers several options to optimize data processing for integer 
 * and fixed-point algorithmic, which can be defined and enabled using this library.
 ************************************************************************************************/


/******************************************************************************************************
 * @fn 	  uint16_t p33c_Dsp_WriteConfig(volatile P33C_DSP_CONFIG_t dsp_cfg) 
 * @ingroup lib-layer-pral-functions-public-dsp
 * @brief  Initializes the DSP engine in accordance to user settings 
 * @param  dsp_cfg DSP configuration SFR object of type P33C_DSP_CONFIG_t
 * @return unsigned integer (0=failure, 1=success)
 *
 * @details
 * This routine writes a DSP user-configuration into the core configuration register and verifies
 * the data has been written correctly.
 * 
 ******************************************************************************************************/

volatile uint16_t p33c_Dsp_WriteConfig(volatile P33C_DSP_CONFIG_t dsp_cfg)
{
	volatile uint16_t retval = 0;
    volatile P33C_DSP_CONFIG_t* dsp;
	
    dsp = p33c_DspConfig_GetHandle();
    *dsp = dsp_cfg;
	
    return(retval);

} 


/******************************************************************************************************
 * @fn P33C_DSP_CONFIG_t p33c_Dsp_GetConfig(void)
 * @ingroup lib-layer-pral-functions-public-dsp
 * @brief Reads the DSP engine configuration 
 * @return P33C_DSP_CONFIG_t
 *
 * @details
 * This routine writes a DSP user-configuration into the core configuration register and verifies
 * the data has been written correctly.
 * 
 ******************************************************************************************************/

volatile P33C_DSP_CONFIG_t p33c_Dsp_ReadConfig(void)
{
	volatile P33C_DSP_CONFIG_t* dsp;
	
    dsp = p33c_DspConfig_GetHandle();
	
    return(*dsp);

} 

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


// end of file
