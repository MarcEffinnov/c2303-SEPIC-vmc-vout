/*
 * File:   system_initialize.c
 * Author: M91406
 *
 * Created on November 12, 2020, 10:33 AM
 */

#include "apps.h"
#include "mcal.h"
#include "hal.h"
#include "usercfg.h"

/***********************************************************************************
 * @fn uint16_t sysUserPeriperhals_Initialize(void)
 * @ingroup user-peripherals-initialization
 * @brief  Initializes the user-defined chip resources
 * @return unsigned integer (0=failure, 1=success)
 * 
 * @details
 * The Digital Power Starter Kit 3 supports a Test Point allowing to observe
 * the DAC output of the dsPIC33C device. Using this feature requires the 
 * configuration of further on-chip resources. This configuration is static
 * and not related to any other task or function of the application and therefore
 * needs to be added and placed manually. 
 * For this kind of Special Features, The startup procedure offers the following 
 * default function call allowing to place proprietary user code for individual
 * device configurations beyond the default setup. 
 **********************************************************************************/
volatile uint16_t sysUserPeriperhals_Initialize(void) {

    volatile uint16_t retval=1;
    // I/Os init
    retval &= sysIOs_Initialize();
    
    // Reset the operation amplifier module to a disabled default state.
    retval &= sysOpAmp_ModuleReset();
    
    // Initialize op-amp for SEPIC Current sense
    retval &= sysOpAmp_Initialize(CSEPIC_FB_IOUT_OPA_INSTANCE, false); // Initialize op-amp #1 used to sense SEPIC output current
    ISNN_ANSEL = 0b1;
    ISNP_ANSEL = 0b1;
    
    // Initialize DAC
    retval &= sysDacModule_Initialize();  // Initialize DAC module
    // DISABLE DACOUT1 being used for current sense reference
    //retval &= sysDacOutput_Initialize(DAC_OUTPUT_INSTANCE, DAC_OUTPUT_INIT_VALUE); // Initialize DAC #1 used to generate the reference voltage for current sense amplifiers
    //retval &= sysDacOutput_Enable(DAC_OUTPUT_INSTANCE); // Enable DAC providing reference to current sense amplifiers

    // Enable op-amp
    retval &= sysOpAmp_ModuleEnable(); // Enable the operational amplifier module
    
    // Initialize debugging Pins
    #if DBGPIN1_ENABLE
    DBGPIN1_CNPD = 0b0;
    DBGPIN1_CNPU = 0b0;
    DBGPIN1_ODC = 0b0;
    DBGPIN1_SetDigitalOutput(); ///< Device pin #1  (not routed)
    DBGPIN1_SetLow(); // Clear debug pin #1
    #endif
    
	return(retval);

}

// end of file
