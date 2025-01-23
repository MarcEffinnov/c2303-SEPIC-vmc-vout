/* *********************************************************************************
 * PowerSmart Digital Control Library Designer, Version 1.9.15.709
 * *********************************************************************************
 * 2p2z controller function declarations and compensation filter coefficients
 * derived for following operating conditions:
 * *********************************************************************************
 *
 *  Controller Type:    2P2Z - Basic Current Mode Compensator
 *  Sampling Frequency: 500000 Hz
 *  Fixed Point Format: Q15
 *  Scaling Mode:       3 - Dual Bit-Shift Scaling
 *  Input Gain:         3
 *
 * *********************************************************************************
 * CGS Version:         3.0.11
 * CGS Date:            01/06/2022
 * *********************************************************************************
 * User:                M24683
 * Date/Time:           01/04/2024 16:52:29
 * ********************************************************************************/

#include "i_loop.h"

/* *********************************************************************************
 * Data Arrays:
 * ============
 *
 * This source file declares the default parameters of the z-domain compensation
 * filter. The NPNZ16b_s data structure contains two pointers to A- and B-
 * coefficient arrays and two pointers to control and error history arrays.
 *
 * For optimized data processing during DSP computations, these arrays must be
 * located in specific memory locations (X-space for coefficient arrays and
 * Y-space for control and error history arrays).
 *
 * The following declarations are used to define the array data contents, their
 * length and memory location. These declarations are made publicly accessible
 * through extern declarations in header file i_loop.h
 * ********************************************************************************/

volatile struct I_LOOP_CONTROL_LOOP_COEFFICIENTS_s __attribute__((space(xmemory), near)) i_loop_coefficients; // A/B-Coefficients
volatile uint16_t i_loop_ACoefficients_size = (sizeof(i_loop_coefficients.ACoefficients)/sizeof(i_loop_coefficients.ACoefficients[0])); // A-coefficient array size
volatile uint16_t i_loop_BCoefficients_size = (sizeof(i_loop_coefficients.BCoefficients)/sizeof(i_loop_coefficients.BCoefficients[0])); // B-coefficient array size

volatile struct I_LOOP_CONTROL_LOOP_HISTORIES_s __attribute__((space(ymemory), far)) i_loop_histories; // Control/Error Histories
volatile uint16_t i_loop_ControlHistory_size = (sizeof(i_loop_histories.ControlHistory)/sizeof(i_loop_histories.ControlHistory[0])); // Control history array size
volatile uint16_t i_loop_ErrorHistory_size = (sizeof(i_loop_histories.ErrorHistory)/sizeof(i_loop_histories.ErrorHistory[0])); // Error history array size

/* *********************************************************************************
 * Pole&Zero Placement:
 * *********************************************************************************
 *
 *    fP0:    100 Hz
 *    fP1:    200000 Hz
 *    fZ1:    3000 Hz
 *
 * *********************************************************************************
 * Filter Coefficients and Parameters:
 * ********************************************************************************/

volatile int32_t i_loop_ACoefficients [2] =
{
    0x00007172, // Coefficient A1 will be multiplied with controller output u(n-1)
    0x00000E8F  // Coefficient A2 will be multiplied with controller output u(n-2)
};

volatile int32_t i_loop_BCoefficients [3] =
{
    0x0000674F, // Coefficient B0 will be multiplied with error input e(n-0)
    0x000003D3, // Coefficient B1 will be multiplied with error input e(n-1)
    0x00009C85  // Coefficient B2 will be multiplied with error input e(n-2)
};

// Coefficient normalization factors
volatile int16_t i_loop_pre_shift = 3;            // Bit-shift value used to perform input value normalization
volatile int16_t i_loop_post_shift_A = 0;         // Bit-shift value A used to perform control output value backward normalization
volatile int16_t i_loop_post_shift_B = 7;         // Bit-shift value B used to perform control output value backward normalization
volatile fractional i_loop_post_scaler = 0x0000;  // Q15 fractional factor used to perform control output value backward normalization


// User-defined NPNZ16b_s controller data object
volatile struct NPNZ16b_s i_loop;                 // user-controller data object

/* ********************************************************************************/

/* *********************************************************************************
 * Controller Initialization:
 * ==========================
  *
 * Public controller initialization function loading known default settings
 * into the NPNZ16b data structure.
 *
 * ********************************************************************************/

volatile uint16_t i_loop_Initialize(volatile struct NPNZ16b_s* controller)
{
    volatile uint16_t i=0;

    // Initialize controller data structure at runtime with pre-defined default values
    controller->status.value = NPNZ_STATUS_CLEAR; // clear all status flag bits (will turn off execution))

    controller->Filter.ptrACoefficients = &i_loop_coefficients.ACoefficients[0]; // initialize pointer to A-coefficients array
    controller->Filter.ptrBCoefficients = &i_loop_coefficients.BCoefficients[0]; // initialize pointer to B-coefficients array
    controller->Filter.ptrControlHistory = &i_loop_histories.ControlHistory[0]; // initialize pointer to control history array
    controller->Filter.ptrErrorHistory = &i_loop_histories.ErrorHistory[0]; // initialize pointer to error history array
    controller->Filter.normPostShiftA = i_loop_post_shift_A; // initialize A-coefficients/single bit-shift scaler
    controller->Filter.normPostShiftB = i_loop_post_shift_B; // initialize B-coefficients/dual/post scale factor bit-shift scaler
    controller->Filter.normPostScaler = i_loop_post_scaler; // initialize control output value normalization scaling factor
    controller->Filter.normPreShift = i_loop_pre_shift; // initialize A-coefficients/single bit-shift scaler
    
    controller->Filter.ACoefficientsArraySize = i_loop_ACoefficients_size; // initialize A-coefficients array size
    controller->Filter.BCoefficientsArraySize = i_loop_BCoefficients_size; // initialize B-coefficients array size
    controller->Filter.ControlHistoryArraySize = i_loop_ControlHistory_size; // initialize control history array size
    controller->Filter.ErrorHistoryArraySize = i_loop_ErrorHistory_size; // initialize error history array size

    // Load default set of A-coefficients from user RAM into controller A-array located in X-Space
    for(i=0; i<controller->Filter.ACoefficientsArraySize; i++)
    {
        i_loop_coefficients.ACoefficients[i] = i_loop_ACoefficients[i]; // Load coefficient A(n) value into i_loop coefficient(i) data space
    }

    // Load default set of B-coefficients from user RAM into controller B-array located in X-Space
    for(i=0; i<controller->Filter.BCoefficientsArraySize; i++)
    {
        i_loop_coefficients.BCoefficients[i] = i_loop_BCoefficients[i]; // Load coefficient B(n) value into i_loop coefficient(i) data space
    }

    // Clear error and control histories of the 2P2Z controller
    i_loop_Reset(&i_loop);
    
    return(1);
}


//**********************************************************************************
// Download latest version of this tool here:
//      https://www.microchip.com/powersmart
//**********************************************************************************

