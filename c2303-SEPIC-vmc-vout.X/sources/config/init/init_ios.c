/*
 * File:   init_ios.c
 * Author: M24683
 *
 * Created on April 07, 2022, 10:25 AM
 */


#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#include "config/mcal.h"
#include "config/hal.h"
#include "init_ios.h"

/**
 * @ingroup I/Os-initialization
 * @{
 */
/***********************************************************************************
 * @fn uint16_t sysIOs_Initialize(void) 
 * @brief  Initializes the on-chip I/Os
 * @return unsigned integer
 * @return 0=failure
 * @return 1=success
 * 
 * @details
 *
 * 
 **********************************************************************************/

volatile uint16_t sysIOs_Initialize(void) 
{
    volatile uint16_t retval=1;
        // Init I/Os
    
    return (retval);
}


/** @}*/ // end of group op-amp-initialization

// end of file
