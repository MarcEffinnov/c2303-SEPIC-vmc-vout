/* **************************************************************************************************
* � 2021 Microchip Technology Inc.
*
* FileName:        drv_TrapHandler.h
* Processor:       dsPIC33C
* Compiler:        MPLAB� XC15 v1.36 higher
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all ownership and intellectual property 
* rights in the code accompanying this message and in all derivatives hereto.  You may use this 
* code, and any derivatives created by any person or entity by or on your behalf, exclusively with 
* Microchip's proprietary products.  Your acceptance and/or use of this code constitutes agreement 
* to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER EXPRESS, 
* IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, 
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH 
* MICROCHIP'S PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER IN CONTRACT, 
* WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), STRICT LIABILITY, INDEMNITY, 
* CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE, EXEMPLARY, INCIDENTAL OR 
* CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE CODE, 
* HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
* FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
* IN ANY WAY RELATED TO THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP 
* SPECIFICALLY TO HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and determining its suitability.  
* Microchip has no obligation to modify, test, certify, or support the code.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*	Date		Author				Company	Version	Comments
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* 03/09/2006	D. Settu			MCHP	1.0		First Release
* 10/07/2009	Andreas Reiter		HPC		1.1		added a header file and a default trap handler
*													routine for better integration
* 07/19/2016	Andreas Reiter		MCHP	1.2		Added data structure for trap monitoring
* 06/16/2018	Andreas Reiter		MCHP	1.3		Added support for dsPIC33C and XC16 compiler changes in v1.30
* 10/27/2020	Andreas Reiter		MCHP	1.4		Optimized data structure labels solving parsing issues
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
*
* 1. This file contains trap service routines (handlers) for hardware exceptions generated by 
*	 the dsPIC33F device.
*
* 2. All trap service routines in this file simply ensure that device continuously executes code 
*	 within the trap service routine. Users may modify the basic framework provided here to suit 
*	 to the needs of their application.
*
* **************************************************************************************************/

#ifndef _GLOBAL_TRAPS_H_
#define _GLOBAL_TRAPS_H_

// Device header file
#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer types header file
#include <stdbool.h> // include standard boolean types header file

/**
 * @ingroup lib-layer-fault-properties-public-defines
 * @{ 
 */

/**********************************************************************************
 * @var TRAP_DMA_SUPPORT
 * @brief defining trap-ID for primary and secondary vectors 
 *********************************************************************************/
#if ((__HAS_DMA__) || (__HAS_DMAV2__))
  #define TRAP_DMA_SUPPORT			1		///< Device supports DMA
#else
  #define TRAP_DMA_SUPPORT			0		///< Device does not support DMA
#endif


#define FAULT_OBJECT_CPU_RESET_TRIGGER_BIT_MASK     0b0000000000000001 ///< This define is used to filter the fault object CPU reset trigger
#define CPU_RESET_TRIGGER_LOW_BIT_MASK 0b00000000000000011011101110000000 ///< This define is used to filter on critical fault conditions used to trigger a CPU reset
/**@}*/

// =================================================================================================
//
//	DEFINING TRAP-ID FOR PRIMARY AND SECONDARY EXCEPTION VECTORS
//
// =================================================================================================

/**
 * @ingroup lib-layer-fault-properties-public-data-types
 * @{ 
 */
/**********************************************************************************
 * @enum TRAP_ID_e
 * @brief defining trap-ID for primary and secondary vectors 
 * @extends TRAP_LOGGER_s
 *********************************************************************************/
typedef enum TRAP_ID_e
{
	TRAP_OSCILLATOR_FAIL		= 0x0001,	///< Trap ID for primary exception vector
	TRAP_ADDRESS_ERROR			= 0x0002,	///< Trap ID for primary exception vector
	TRAP_STACK_ERROR			= 0x0004,	///< Trap ID for primary exception vector
	TRAP_MATH_ERROR				= 0x0008,	///< Trap ID for primary exception vector
	TRAP_DMA_ERROR				= 0x0010,	///< Trap ID for primary exception vector

    TRAP_SOFT_TRAP_ERROR        = 0x0020,   ///< Trap ID for generic soft trap exception vector
    TRAP_HARD_TRAP_ERROR        = 0x0040,   ///< Trap ID for generic hard trap exception vector
    TRAP_RESERVED_TRAP_5_ERROR  = 0x0080,   ///< Trap ID for generic exception vector
    TRAP_RESERVED_TRAP_7_ERROR  = 0x0080,   ///< Trap ID for generic exception vector

	TRAP_ALT_OSCILLATOR_FAIL	= 0x0100,	///< Trap ID for alternate exception vector
	TRAP_ALT_ADDRESS_ERROR		= 0x0200,	///< Trap ID for alternate exception vector
	TRAP_ALT_STACK_ERROR		= 0x0400,	///< Trap ID for alternate exception vector
	TRAP_ALT_MATH_ERROR			= 0x0800,	///< Trap ID for alternate exception vector
	TRAP_ALT_DMA_ERROR			= 0x1000,	///< Trap ID for alternate exception vector

    TRAP_ALT_SOFT_TRAP_ERROR    = 0x2000,   ///< Trap ID for alternate generic soft trap exception vector
    TRAP_ALT_HARD_TRAP_ERROR    = 0x4000,   ///< Trap ID for alternate generic hard trap exception vector
        
	TRAP_RESET_MSK				= 0x7F1F	///< Bit Mask to filter used bits only

} TRAP_ID_t;

/**********************************************************************************
 * @struct  TRAP_FLAGS_s
 * @brief   Defines the Trap Flag for primary and secondary vectors
 * @extends TRAP_LOGGER_s
 *********************************************************************************/
typedef struct TRAP_FLAGS_s
{
    union {
    struct {

        volatile unsigned OVAERR    :1; ///< Bit #0:  Accumulator A Overflow Trap Flag bit
        volatile unsigned OVBERR    :1; ///< Bit #1:  Accumulator B Overflow Trap Flag bit
        volatile unsigned COVAERR   :1; ///< Bit #2:  Accumulator A Catastrophic Overflow Trap Flag bit
        volatile unsigned COVBERR   :1; ///< Bit #3:  Accumulator B Catastrophic Overflow Trap Flag bit
        volatile unsigned SFTACERR  :1; ///< Bit #4:  Shift Accumulator Error Status bit
        volatile unsigned DIV0ERR   :1; ///< Bit #5:  Divide-by-Zero Error Status bit
        volatile unsigned MATHERR   :1; ///< Bit #6:  Math Error Status bit
        volatile unsigned ADDRERR   :1; ///< Bit #7:  Address Error Trap Status bit
        volatile unsigned STKERR    :1; ///< Bit #8:  Stack Error Trap Status bit
        volatile unsigned OSCFAIL   :1; ///< Bit #9:  Oscillator Failure Trap Status bit
        volatile unsigned SWTRAP    :1; ///< Bit #10: Software Trap Status bit
        volatile unsigned NAE       :1; ///< Bit #11: NVM Address Error Soft Trap Status bit
        volatile unsigned DOOVR     :1; ///< Bit #12: DO Stack Overflow Soft Trap Status bit
        volatile unsigned APLL      :1; ///< Bit #13: Auxiliary PLL Loss of Lock Soft Trap Status bit
        volatile unsigned SGHT      :1; ///< Bit #14: Software Generated Hard Trap Status bit
        volatile unsigned DMACERR   :1; ///< Bit #15: DMA Trap Status bit

        volatile unsigned ECCDBE    :1; ///< Bit #16: ECC Double-Bit Error Trap Status bit
        volatile unsigned CAN       :1; ///< Bit #17: CAN Address Error Soft Trap Status bit
        volatile unsigned CAN2      :1; ///< Bit #18: CAN2 Address Error Soft Trap Status bit
        volatile unsigned           :13; ///< Bit <19:31> (reserved)

    }__attribute__((packed))bits;

    volatile uint32_t value;
    };
    
}TRAP_FLAGS_t;

/**********************************************************************************
 * @struct  CPU_INTTREG_s
 * @brief   defining the CPU interrupt for primary and secondary vectors
 * @extends TRAP_LOGGER_s
 *********************************************************************************/
typedef struct CPU_INTTREG_s
{
    union {
    struct {
        volatile unsigned VECNUM:8;	///< Bit #0-7:  Pending Interrupt Number List
        volatile unsigned ILR	:4;	///< Bit #8-11: New Interrupt Priority Level
        volatile unsigned		:1;	///< Bit #12: Reserved
        volatile unsigned VHOLD :1; ///< Bit #13: Vector Number Capture Enable bit
        volatile unsigned       :1;	///< Bit #14: Reserved
        volatile unsigned       :1;	///< Bit #15: Reserved
    }__attribute__((packed))bits;

	volatile uint16_t value;
    };
    
} CPU_INTTREG_t;

/**********************************************************************************
 * @struct CPU_RCON_s 
 * @brief Data structure for RCON status capturing
 * @extends TRAP_LOGGER_s
 *********************************************************************************/
typedef struct CPU_RCON_s 
{
    union {
    struct {

        volatile unsigned por	:1;	///< Bit #0:  Power-on Reset Flag bit
        volatile unsigned bor	:1;	///< Bit #1:  Brown-out Reset Flag bit
        volatile unsigned idle	:1;	///< Bit #2:  Wake-up from Idle Flag bit
        volatile unsigned sleep	:1;	///< Bit #3:  Wake-up from Sleep Flag bit
        volatile unsigned wdto	:1;	///< Bit #4:  Watchdog Timer Time-out Flag bit
        volatile unsigned swdten:1;	///< Bit #5:  Software Enable/Disable of WDT bit
        volatile unsigned swr	:1;	///< Bit #6:  Software Reset Flag (Instruction) bit
        volatile unsigned extr	:1;	///< Bit #7:  External Reset Pin (MCLR) bit
        volatile unsigned vregs	:1;	///< Bit #8:  Voltage Regulator Standby During Sleep bit
        volatile unsigned cm    :1;	///< Bit #9:  Configuration Mismatch Flag bit
        volatile unsigned		:1;	///< Bit #10: Reserved
        volatile unsigned vregsf:1;	///< Bit #11: Flash Voltage Regulator Standby During Sleep bit
        volatile unsigned		:1;	///< Bit #12: Reserved
        volatile unsigned		:1;	///< Bit #13: Reserved
        volatile unsigned iopuwr:1;	///< Bit #14: Illegal Opcode or Uninitialized W Access Reset Flag bit
        volatile unsigned trapr :1;	///< Bit #15: Trap Reset Flag bit

    }__attribute__((packed))bits;

	volatile uint16_t value;
    };
    
} CPU_RCON_t;

/**********************************************************************************
 * @struct TRAPLOG_STATUS_s
 * @brief Data structure for RCON status capturing
 * @extends TRAP_LOGGER_s
 *********************************************************************************/
typedef struct TRAPLOG_STATUS_s 
{
    union {
    struct {

        // Control bits
        volatile bool cpu_reset_trigger : 1;    // Bit 0: Control bit to trigger software-enforced CPU reset
        volatile unsigned : 1;                  // Bit 1: (reserved)
        volatile unsigned : 1;                  // Bit 2: (reserved)
        volatile unsigned : 1;                  // Bit 3: (reserved)
        volatile unsigned : 1;                  // Bit 4: (reserved)
        volatile unsigned : 1;                  // Bit 5: (reserved)
        volatile unsigned : 1;                  // Bit 6: (reserved)
        volatile unsigned : 1;                  // Bit 7: (reserved)

        // Status bits
        volatile bool sw_reset : 1;             // Bit 8:  Flag indicating CPU was reset by software (read only)
        volatile unsigned : 1;                  // Bit 9:  (reserved)
        volatile unsigned : 1;                  // Bit 10: (reserved)
        volatile unsigned : 1;                  // Bit 11: (reserved)
        volatile unsigned : 1;                  // Bit 12: (reserved)
        volatile unsigned : 1;                  // Bit 13: (reserved)
        volatile unsigned : 1;                  // Bit 14: (reserved)
        volatile unsigned : 1;                  // Bit 15: (reserved)

    }__attribute__((packed)) bits;

	volatile uint16_t value;
    };
    
} TRAPLOG_STATUS_t;

/**********************************************************************************
 * @struct  TASK_INFO_s
 * @brief   Provides information for executed task, fault event and operating mode ID of task manager 
 * @extends TRAP_LOGGER_s
 *********************************************************************************/

typedef struct TASK_INFO_s 
{
    volatile uint16_t task_id; // Task ID of last executed task
    volatile uint16_t fault_id; // Fault ID causing a catastrophic fault event
    volatile uint16_t op_mode; // Operating Mode ID of task manager

} TASK_INFO_t;

// =================================================================================================
//
//	GLOBAL DATA STRUCTURE - TRAP LOGGER OBJECT
//
// =================================================================================================
/**********************************************************************************
 * @struct TRAP_LOGGER_s
 * @brief Global data structure for trap event capturing
 *********************************************************************************/
typedef struct TRAP_LOGGER_s 
{
    volatile TRAPLOG_STATUS_t status;    ///< Status word of the Trap Logger object
    volatile uint16_t reset_count;              ///< Counter of CPU RESET events (read/write)
	volatile TRAP_ID_t trap_id;            ///< Trap-ID of the captured incident
	volatile uint16_t trap_count;               ///< Counter tracking the number of occurrences
    volatile TRAP_FLAGS_t trap_flags;    ///< Complete list of trap flags (showing all trap flags)
	volatile CPU_RCON_t rcon_reg;        ///< Captures the RESET CONTROL register
    volatile CPU_INTTREG_t inttreg;      ///< Interrupt Vector and Priority register capture
    volatile TASK_INFO_t task_capture;   ///< Information of last task executed
    
} TRAP_LOGGER_t; // Global data structure for trap event capturing

/**@}*/

// Global data structure used as buffer for trap monitoring
extern volatile __attribute__((__persistent__)) TRAP_LOGGER_t traplog; 

// =================================================================================================
//
//	PROTOTYPES
//
// =================================================================================================

extern volatile uint16_t drv_TrapHandler_SoftTrapsInitialize(
                bool accumulator_a_overflow_trap_enable, 
                bool accumulator_b_overflow_trap_enable, 
                bool accumulator_catastrophic_overflow_trap_enable);

extern void __attribute__((__interrupt__)) _HardTrapError(void);
extern void __attribute__((__interrupt__)) _SoftTrapError(void);

extern void __attribute__((__interrupt__)) _OscillatorFail(void);
extern void __attribute__((__interrupt__)) _AddressError(void);
extern void __attribute__((__interrupt__)) _StackError(void);
extern void __attribute__((__interrupt__)) _MathError(void);

/**
 * @ingroup lib-layer-fault-properties-public-defines
 * @{ 
 */
#if (TRAP_DMA_SUPPORT == 1)
  #if defined (_DMACError)
    extern void __attribute__((__interrupt__)) _DMACError(void);
  #endif
#endif

 
#if __XC16_VERSION__ < 1030
// Compile switch dealing with the changed support of alternate interrupt vectors between
// versions v.1.29 and 1.30  
  
extern void __attribute__((interrupt, no_auto_psv)) _AltHardTrapError(void);
extern void __attribute__((interrupt, no_auto_psv)) _AltSoftTrapError(void);

extern void __attribute__((__interrupt__)) _AltOscillatorFail(void);
extern void __attribute__((__interrupt__)) _AltAddressError(void);
extern void __attribute__((__interrupt__)) _AltStackError(void);
extern void __attribute__((__interrupt__)) _AltMathError(void);

#if (TRAP_DMA_SUPPORT == 1)
  extern void __attribute__((__interrupt__)) _AltDMACError(void);
#endif

#endif
  
#endif
  
/**@}*/  
