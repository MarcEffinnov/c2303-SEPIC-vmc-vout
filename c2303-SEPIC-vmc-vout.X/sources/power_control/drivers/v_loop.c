/* *********************************************************************************
 * PowerSmart Digital Control Library Designer, Version 1.9.15.709
 * *********************************************************************************
 * 3p3z controller function declarations and compensation filter coefficients
 * derived for following operating conditions:
 * *********************************************************************************
 *
 *  Controller Type:    3P3Z - Basic Voltage Mode Compensator
 *  Sampling Frequency: 250000 Hz
 *  Fixed Point Format: Q15
 *  Scaling Mode:       3 - Dual Bit-Shift Scaling
 *  Input Gain:         0.0714285714285714
 *
 * *********************************************************************************
 * CGS Version:         3.0.11
 * CGS Date:            01/06/2022
 * *********************************************************************************
 * User:                M24683
 * Date/Time:           02/29/2024 19:31:07
 * ********************************************************************************/

#include "v_loop.h"

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
 * through extern declarations in header file v_loop.h
 * ********************************************************************************/

volatile struct V_LOOP_CONTROL_LOOP_COEFFICIENTS_s __attribute__((space(xmemory), near)) v_loop_coefficients; // A/B-Coefficients
volatile uint16_t v_loop_ACoefficients_size = (sizeof(v_loop_coefficients.ACoefficients)/sizeof(v_loop_coefficients.ACoefficients[0])); // A-coefficient array size
volatile uint16_t v_loop_BCoefficients_size = (sizeof(v_loop_coefficients.BCoefficients)/sizeof(v_loop_coefficients.BCoefficients[0])); // B-coefficient array size

volatile struct V_LOOP_CONTROL_LOOP_HISTORIES_s __attribute__((space(ymemory), far)) v_loop_histories; // Control/Error Histories
volatile uint16_t v_loop_ControlHistory_size = (sizeof(v_loop_histories.ControlHistory)/sizeof(v_loop_histories.ControlHistory[0])); // Control history array size
volatile uint16_t v_loop_ErrorHistory_size = (sizeof(v_loop_histories.ErrorHistory)/sizeof(v_loop_histories.ErrorHistory[0])); // Error history array size

/* *********************************************************************************
 * Pole&Zero Placement:
 * *********************************************************************************
 *
 *    fP0:    150 Hz
 *    fP1:    240000 Hz
 *    fP2:    250000 Hz
 *    fZ1:    2000 Hz
 *    fZ2:    200000 Hz
 *
 * *********************************************************************************
 * Filter Coefficients and Parameters:
 * ********************************************************************************/

volatile int32_t v_loop_ACoefficients [3] =
{
    0x0000FD8F, // Coefficient A1 will be multiplied with controller output u(n-1)
    0x00006138, // Coefficient A2 will be multiplied with controller output u(n-2)
    0x0000213A  // Coefficient A3 will be multiplied with controller output u(n-3)
};

volatile int32_t v_loop_BCoefficients [4] =
{
    0x00006DBE, // Coefficient B0 will be multiplied with error input e(n-0)
    0x000034A7, // Coefficient B1 will be multiplied with error input e(n-1)
    0x000099F6, // Coefficient B2 will be multiplied with error input e(n-2)
    0x0000D30D  // Coefficient B3 will be multiplied with error input e(n-3)
};

// Coefficient normalization factors
volatile int16_t v_loop_pre_shift = 3;            // Bit-shift value used to perform input value normalization
volatile int16_t v_loop_post_shift_A = 0;         // Bit-shift value A used to perform control output value backward normalization
volatile int16_t v_loop_post_shift_B = 0;         // Bit-shift value B used to perform control output value backward normalization
volatile fractional v_loop_post_scaler = 0x0000;  // Q15 fractional factor used to perform control output value backward normalization


// User-defined NPNZ16b_s controller data object
volatile struct NPNZ16b_s v_loop;                 // user-controller data object

/* ********************************************************************************/

/* *********************************************************************************
 * Controller Initialization:
 * ==========================
  *
 * Public controller initialization function loading known default settings
 * into the NPNZ16b data structure.
 *
 * ********************************************************************************/

volatile uint16_t v_loop_Initialize(volatile struct NPNZ16b_s* controller)
{
    volatile uint16_t i=0;

    // Initialize controller data structure at runtime with pre-defined default values
    controller->status.value = NPNZ_STATUS_CLEAR; // clear all status flag bits (will turn off execution))

    controller->Filter.ptrACoefficients = &v_loop_coefficients.ACoefficients[0]; // initialize pointer to A-coefficients array
    controller->Filter.ptrBCoefficients = &v_loop_coefficients.BCoefficients[0]; // initialize pointer to B-coefficients array
    controller->Filter.ptrControlHistory = &v_loop_histories.ControlHistory[0]; // initialize pointer to control history array
    controller->Filter.ptrErrorHistory = &v_loop_histories.ErrorHistory[0]; // initialize pointer to error history array
    controller->Filter.normPostShiftA = v_loop_post_shift_A; // initialize A-coefficients/single bit-shift scaler
    controller->Filter.normPostShiftB = v_loop_post_shift_B; // initialize B-coefficients/dual/post scale factor bit-shift scaler
    controller->Filter.normPostScaler = v_loop_post_scaler; // initialize control output value normalization scaling factor
    controller->Filter.normPreShift = v_loop_pre_shift; // initialize A-coefficients/single bit-shift scaler
    
    controller->Filter.ACoefficientsArraySize = v_loop_ACoefficients_size; // initialize A-coefficients array size
    controller->Filter.BCoefficientsArraySize = v_loop_BCoefficients_size; // initialize B-coefficients array size
    controller->Filter.ControlHistoryArraySize = v_loop_ControlHistory_size; // initialize control history array size
    controller->Filter.ErrorHistoryArraySize = v_loop_ErrorHistory_size; // initialize error history array size

    // Load default set of A-coefficients from user RAM into controller A-array located in X-Space
    for(i=0; i<controller->Filter.ACoefficientsArraySize; i++)
    {
        v_loop_coefficients.ACoefficients[i] = v_loop_ACoefficients[i]; // Load coefficient A(n) value into v_loop coefficient(i) data space
    }

    // Load default set of B-coefficients from user RAM into controller B-array located in X-Space
    for(i=0; i<controller->Filter.BCoefficientsArraySize; i++)
    {
        v_loop_coefficients.BCoefficients[i] = v_loop_BCoefficients[i]; // Load coefficient B(n) value into v_loop coefficient(i) data space
    }

    // Clear error and control histories of the 3P3Z controller
    v_loop_Reset(&v_loop);
    
    return(1);
}


//**********************************************************************************
// Download latest version of this tool here:
//      https://www.microchip.com/powersmart
//**********************************************************************************

