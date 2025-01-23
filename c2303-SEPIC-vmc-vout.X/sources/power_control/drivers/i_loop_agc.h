
#ifndef __SPECIAL_FUNCTION_LAYER_I_LOOP_AGC_H__
#define __SPECIAL_FUNCTION_LAYER_I_LOOP_AGC_H__

#include <xc.h>                                   // include processor files - each processor file is guarded
#include <dsp.h>                                  // include DSP data types (e.g. fractional)
#include <stdint.h>                               // include standard integer number data types
#include <stdbool.h>                              // include standard boolean data types (true/false)

#include "./power_control/drivers/npnz16b.h"        // include NPNZ library header file


// ADVANCED CONTROL FUNCTION DECLARATIONS

extern void __attribute__((near)) i_loop_AGCFactorUpdate(volatile NPNZ16b_t* controller); ///< Pointer to nPnZ data type object
                                                // Calls the AGC Factor Modulation Function (Assembly)


#endif	/* __SPECIAL_FUNCTION_LAYER_I_LOOP_AGC_H__ */

