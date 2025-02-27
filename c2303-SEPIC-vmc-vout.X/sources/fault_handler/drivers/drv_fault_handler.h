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
 *  @file    drv_fault_handler.h
 *  @brief   This file contains APIs to check current fault status of a user-defined fault object
 *
 *  @note
 *  Microchip Technology Inc. has followed development methods required by
 *  IEC-60730 and performed extensive validation and static testing to ensure
 *  that the code operates as intended. Any modification to the code can
 *  invalidate the results of Microchip's validation and testing.
 *
 */
/* 
 * File:   fault_handler.h
 * Author: M91406
 * Comments: Global, generic fault handler header file
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef FAULT_HANDLER_H
#define	FAULT_HANDLER_H



#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer types 
#include <stdbool.h> // include standard boolean types  
#include <stddef.h> // include standard definitions  

/**
 * @ingroup lib-layer-lib1-properties-public
 * @{
 */
/***********************************************************************************
 * @enum FLT_COMPARE_TYPE_e
 * @brief This data structure is comprised of fault comparison types
 * @extends FLT_OBJECT_STATUS_s
 *********************************************************************************/

typedef enum FLT_COMPARE_TYPE_e {
    
	FLTCMP_NONE				= 0, ///<  No comparison type has been defined (fault object will be ignored)
	FLTCMP_GREATER_THAN		= 1, ///<  Check for condition: SOURCE > trip level
	FLTCMP_LESS_THAN		= 2, ///<  Check for condition: SOURCE < trip level
	FLTCMP_IS_EQUAL			= 3, ///<  Check for condition: SOURCE = trip level
	FLTCMP_IS_NOT_EQUAL		= 4, ///<  Check for condition: SOURCE != trip level
	FLTCMP_BETWEEN			= 5, ///<  Check for condition: (reset_level < SOURCE) && (SOURCE < trip_level)
	FLTCMP_OUTSIDE			= 6  ///<  Check for condition: (SOURCE < reset_level) || (trip_level < SOURCE)
        
} FLT_COMPARE_TYPE_t;


/**********************************************************************************
 * @struct FLT_OBJECT_STATUS_s
 * @brief This data structure defines the fault object status
 * @extends FAULT_OBJECT_s
 *********************************************************************************/

typedef struct FLT_OBJECT_STATUS_s{

    union {
	struct {
		volatile bool FaultStatus : 1;                      ///< Bit 0: Flag bit indicating if FAULT has been tripped
		volatile bool FaultActive : 1;                      ///< Bit 1: Flag bit indicating if fault condition has been detected but FAULT has not been tripped yet
		volatile unsigned : 6;                              ///< Bit <7:2>: (reserved)
		volatile FLT_COMPARE_TYPE_t CompareType: 3;	///< Bit <10:8>: Fault check comparison type control bits
		volatile unsigned : 4;                              ///< Bit 14: (reserved)
		volatile bool Enabled : 1;                          ///< Bit 15: Control bit enabling/disabling monitoring of the fault object
	} __attribute__((packed)) bits;            // Fault object status bit field for single bit access  

	volatile uint16_t value;		// Fault object status word  
    };
    
} FLT_OBJECT_STATUS_t;	// Fault object status


/**********************************************************************************
 * @struct FLT_COMPARE_OBJECT_s
 * @brief This data structure defines the data object which will be monitored by the fault handler
 * @extends FAULT_OBJECT_s
 *********************************************************************************/

typedef struct FLT_COMPARE_OBJECT_s {
    
    volatile uint16_t* ptrObject;   ///< Pointer to register or variable which should be monitored 
    volatile uint16_t bitMask;      ///< Bit mask will be &-ed with source as value (use 0xFFFF for full value comparison)
    
} FLT_COMPARE_OBJECT_t;	// Fault compare object


/**********************************************************************************
 * @struct FLT_EVENT_RESPONSE_s
 * @brief This data structure defines the fault monitor event response object
 * @extends FAULT_OBJECT_s
 *********************************************************************************/

typedef struct FLT_EVENT_RESPONSE_s {
    
    volatile uint16_t compareThreshold;             ///< Signal level at which the fault condition will be detected
    volatile uint16_t eventThreshold;               ///< Bit mask will be &-ed with source as value (use 0xFFFF for full value comparison)
    volatile uint16_t (*ptrResponseFunction)(void); ///< pointer to a user-defined function called when a defined fault monitoring event is detected
    
} FLT_EVENT_RESPONSE_t;	// Fault monitor event response object


/**********************************************************************************
 * @struct FAULT_OBJECT_s
 * @brief This data structure is a collection of data structures for fault handling.
 *********************************************************************************/
struct FAULT_OBJECT_s {

	volatile FLT_OBJECT_STATUS_t  Status;           ///< Status word of this fault object
	volatile uint16_t Counter;                             ///< Fault event counter (controlled by FAULT HANDLER)
	volatile FLT_COMPARE_OBJECT_t SourceObject;     ///< Object which should be monitored
	volatile FLT_COMPARE_OBJECT_t ReferenceObject;  ///< Reference object the source should be compared with
    volatile FLT_EVENT_RESPONSE_t TripResponse;     ///< Settings defining the fault trip event
    volatile FLT_EVENT_RESPONSE_t RecoveryResponse; ///< Settings defining the fault recovery event

}; ///< Generic fault object 
typedef struct FAULT_OBJECT_s FAULT_OBJECT_t; ///< Generic fault object data type

struct FAULT_MONITOR_STATUS_s {
    union {
        struct {
        volatile bool FaultStatus : 1;  ///< Bit 0: Flag bit indicating if a FAULT condition has been tripped
        volatile bool FaultLatch : 1;   ///< Bit 1: Flag bit indicating if a latched FAULT condition has been enforced
		volatile unsigned : 14;         ///< Bit <15:2>: (reserved)
	} __attribute__((packed)) bits;     ///< Fault monitor status bit field for single bit access  
	volatile uint16_t value;            ///< Fault monitor status word  
    };
};
typedef struct FAULT_MONITOR_STATUS_s FAULT_MONITOR_STATUS_t;

/**********************************************************************************
 * @struct FAULT_MONITOR_s
 * @brief Common fault monitor settings
 *********************************************************************************/
struct FAULT_MONITOR_s {
    volatile FAULT_MONITOR_STATUS_t Status;          ///< Status word of the fault monitor
    volatile uint16_t FaultStatusList;                      ///< Status word encoding individual fault object states in order of their list index
    volatile uint16_t FaultRecoveryCounter;                 ///< Most recent number of fault recovery attempts
    volatile uint16_t FaultLatchCount;                      ///< Number of fault recovery attempts after which the system gets locked in a latched fault state
    volatile uint16_t (*FaultRecovery)(void);               ///< Function pointer to the common fault recovery function
};
typedef struct FAULT_MONITOR_s FAULT_MONITOR_t;

/*********************************************************************************
 * @var     FaultMonitor
 * @brief   Global fault monitor object
 * @details
 *  ADD_DESCRIPTION_HERE
 **********************************************************************************/
extern volatile FAULT_MONITOR_t FaultMonitor;        ///< Global fault monitor object

/** @} */ // end of group


// Public Function Prototypes
extern volatile uint16_t drv_FaultHandler_ScanObjects(volatile FAULT_OBJECT_t* fltObjectList[], volatile uint16_t size);
extern volatile uint16_t drv_FaultHandler_Dispose(volatile FAULT_OBJECT_t* fltObjectList[], volatile uint16_t size);

#endif	/* FAULT_HANDLER_H */

