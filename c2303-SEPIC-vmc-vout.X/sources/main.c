/*
 * File:    main.c
 * Author:  M91406
 * Created: 10/01/2020 
 */

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer data types
#include <stdbool.h> // include standard boolean data types
#include <dsp.h>

#include "config/mcal.h" // Include microcontroller abstraction layer
#include "config/hal.h" // Include hardware abstraction layer
#include "config/apps.h" // Include application abstraction layer
#include "config/os.h" // Include operating system configuration header file

#include "config/usercfg.h" // Include header file of user peripheral configuration module

// Declaration of generic, global debugging array
#if __DEBUG
volatile uint16_t ptrDebugArray=0;
volatile uint32_t arrDebugArray[DEBUG_ARR_SIZE];
#endif

/*********************************************************************************
 * @ingroup firmware-flow
 * @fn      int main(void)
 * @brief   Main application function
 * @param   none
 * @return  signed integer int
 * @details
 *   This is the main application function executed after the device came
 *   out of RESET. After the fundamental device configuration and initialization
 *   of all required peripherals and software components, the function enters
 *   the endless main() loop where the device will remain executing the 
 *   application.
 *
 * @code{.c}
 * 
 * @endcode
 *
 *
 **********************************************************************************/

  int main(void) {

    volatile uint16_t retval=1;

    // Fundamental device initialization
    retval &= Boot();       // Set up system oscillator for 100 MIPS operation
                            // Set up Auxiliary PLL for 500 MHz (source clock to PWM module)
                            // Set up DSP for control loop execution
                            // Initialize common device GPIOs
    
    // Load user defined, static peripheral configurations
    retval &= sysUserPeriperhals_Initialize();
    
    // Main program execution
    retval &= rtos_Execute();

    // When the OS is exited, a CPU RESET will be triggered
    // This section of the code should never be reached.
    return (0);
}

// end of file

