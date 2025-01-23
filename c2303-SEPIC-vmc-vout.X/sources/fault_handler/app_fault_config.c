/*
 * File:   app_fault_monitor_config.c
 * Author: M91406
 *
 * Created on July 15, 2021, 4:06 PM
 */


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer data types
#include <stdbool.h> // include standard boolean data types
#include <stddef.h> // include standard definition data types

#include "config/hal.h" // include hardware abstraction layer header file
#include "config/apps.h" // include application layer abstraction layer header file

/********************************************************************
 * @var FAULT_OBJECT_t fltobj_CsepicUVLO  
 * @ingroup app-layer-fault-monitor-properties-public
 * @brief Pre-Initialized Under Voltage Lock Out Fault Object
 * @details
 * This fault object monitors the input voltage of the power supply
 * scanning for conditions violating the minimum required input
 * voltage level for the specified amount of time.
 *******************************************************************/

volatile FAULT_OBJECT_t fltobj_CsepicUVLO = 
{
    .Status.bits.Enabled = true,                            // Enable/disable fault checks
    .Status.bits.FaultActive = true,                        // Set fault condition flag (must be cleared by fault check)
    .Status.bits.FaultStatus = true,                        // Set fault flag (must be cleared by fault check)
    .Status.bits.CompareType = FLTCMP_LESS_THAN,            // Select Compare-Type

    .SourceObject.ptrObject = &csepic.data.v_in,            // Set pointer to variable to monitor
    .SourceObject.bitMask = 0xFFFF,                         // Compare all bits of SOURCE (no bit filter)
    .ReferenceObject.ptrObject = NULL,                      // Clear pointer to "compare against" variable 
    .ReferenceObject.bitMask = 0xFFFF,                      // Clear pointer to "compare against" variable 

    .TripResponse.compareThreshold = CSEPIC_VIN_UVLO_TRIP,  // Set fault trip level
    .TripResponse.eventThreshold = CSEPIC_UVLO_TDLY,         // Set counter level at which a FAULT condition will be tripped
    .TripResponse.ptrResponseFunction = &appPowerSupply_Suspend, // Set pointer to user-function which should be called when a FAULT is tripped

    .RecoveryResponse.compareThreshold = CSEPIC_VIN_UVLO_RELEASE, // Set fault recovery level
    .RecoveryResponse.eventThreshold = CSEPIC_UVLO_RDLY,    // Set counter level at which a FAULT condition will be cleared
    .RecoveryResponse.ptrResponseFunction = NULL            // Clear recovery function pointer
};

/********************************************************************
 * @var FAULT_OBJECT_t fltobj_CsepicOVLO  
 * @ingroup app-layer-fault-monitor-properties-public
 * @brief Pre-Initialized Over Voltage Lock Out Fault Object
 * @details
 * This fault object monitors the input voltage of the power supply
 * scanning for conditions exceeding the maximum allowed input
 * voltage level for the specified amount of time.
 *******************************************************************/
volatile FAULT_OBJECT_t fltobj_CsepicOVLO = {

    .Status.bits.Enabled = true,                            // Enable/disable fault checks
    .Status.bits.FaultActive = true,                        // Set fault condition flag (must be cleared by fault check)
    .Status.bits.FaultStatus = true,                        // Set fault flag (must be cleared by fault check)
    .Status.bits.CompareType = FLTCMP_GREATER_THAN,         // Select Compare-Type

    .SourceObject.ptrObject = &csepic.data.v_in,            // Set pointer to variable to monitor
    .SourceObject.bitMask = 0xFFFF,                         // Compare all bits of SOURCE (no bit filter)
    .ReferenceObject.ptrObject = NULL,                      // Clear pointer to "compare against" variable 
    .ReferenceObject.bitMask = 0xFFFF,                      // Compare all bits of SOURCE (no bit filter)

    .TripResponse.compareThreshold = CSEPIC_VIN_OVLO_TRIP,  // Set fault trip level
    .TripResponse.eventThreshold = CSEPIC_OVLO_TDLY,        // Set counter level at which a FAULT condition will be tripped
    .TripResponse.ptrResponseFunction = &appPowerSupply_Suspend, // Set pointer to user-function which should be called when a FAULT is tripped

    .RecoveryResponse.compareThreshold = CSEPIC_VIN_OVLO_RELEASE,   // Set fault recovery level
    .RecoveryResponse.eventThreshold = CSEPIC_OVLO_RDLY,    // Set counter level at which a FAULT condition will be cleared
    .RecoveryResponse.ptrResponseFunction = NULL            // Clear recovery function pointer

};

/********************************************************************
 * @var FAULT_OBJECT_t fltobj_CsepicOCP  
 * @ingroup app-layer-fault-monitor-properties-public
 * @brief Pre-Initialized Over Current Protection Fault Object
 * @details
 * This fault object monitors the average output current of the
 * power supply scanning for conditions exceeding the maximum
 * allowed output current level for the specified amount of time.
 *******************************************************************/
volatile FAULT_OBJECT_t fltobj_CsepicOCP = {

    .Status.bits.Enabled = false,                           // Enable/disable fault checks    
    .Status.bits.FaultActive = false,                       // Set fault condition flag (must be cleared by fault check)
    .Status.bits.FaultStatus = false,                       // Set fault flag (must be cleared by fault check)
    .Status.bits.CompareType = FLTCMP_GREATER_THAN,         // Select Compare-Type

    .SourceObject.ptrObject = &csepic.data.i_out,           // Set pointer to variable to monitor
    .SourceObject.bitMask = 0xFFFF,                         // Compare all bits of SOURCE (no bit filter)
    .ReferenceObject.ptrObject = NULL,                      // Clear pointer to "compare against" variable 
    .ReferenceObject.bitMask = 0xFFFF,                      // Compare all bits of SOURCE (no bit filter)

    .TripResponse.compareThreshold = CSEPIC_ISNS_OCL,       // Set fault trip level
    .TripResponse.eventThreshold = CSEPIC_OCP_TDLY,         // Set counter level at which a FAULT condition will be tripped
    .TripResponse.ptrResponseFunction = &appPowerSupply_Suspend, // Set pointer to user-function which should be called when a FAULT is tripped

    .RecoveryResponse.compareThreshold = CSEPIC_ISNS_OCL_RELEASE, // Set fault recovery level
    .RecoveryResponse.eventThreshold = CSEPIC_OCP_RDLY,     // Set counter level at which a FAULT condition will be cleared
    .RecoveryResponse.ptrResponseFunction = NULL            // Clear recovery function pointer

};

/*********************************************************************************
 * @var     FAULT_OBJECT_t fltobj_CsepicOVP  
 * @ingroup app-layer-fault-monitor-properties-public
 * @brief  Pre-Initialized Overvoltage Protection Fault Object
 * @return 0=failure
 * @return 1=success
 * 
 * @details
 * In this function all user-defined fault objects are initialize and set to the 
 * thresholds for overvoltage protection. The ADC channel that monitors the 
 * voltage from the circuit is set in SourceObject while the threshold violation 
 * and recovery are set by TripResponse and RecoveryResponse objects.   
 *********************************************************************************/
volatile FAULT_OBJECT_t fltobj_CsepicOVP = {

    .Status.bits.Enabled = true,                            // Enable/disable fault checks at startup
    .Status.bits.FaultActive = true,                        // Set fault condition flag (must be cleared by fault check)
    .Status.bits.FaultStatus = true,                        // Set fault flag (must be cleared by fault check)
    .Status.bits.CompareType = FLTCMP_GREATER_THAN,         // Select Compare-Type

    .SourceObject.ptrObject = &csepic.data.v_out,           // Set pointer to variable to monitor
    .SourceObject.bitMask = 0xFFFF,                         // Compare all bits of SOURCE (no bit filter)
    .ReferenceObject.ptrObject = NULL,    					// Set pointer to "compare against" variable 
    .ReferenceObject.bitMask = 0xFFFF,                      // Compare all bits of Reference (no bit filter)

    .TripResponse.compareThreshold = CSEPIC_VOUT_OVP_TRIP,  // Set fault trip level
    .TripResponse.eventThreshold = CSEPIC_OVP_TDLY,        	// Set counter level at which a FAULT condition will be tripped
    .TripResponse.ptrResponseFunction = &appPowerSupply_Suspend, // Set pointer to user-function which should be called when a FAULT is tripped

    .RecoveryResponse.compareThreshold = CSEPIC_VOUT_OVP_RELEASE, // Set fault recovery level
    .RecoveryResponse.eventThreshold = CSEPIC_OVP_RDLY,    	// Set counter level at which a FAULT condition will be cleared
    .RecoveryResponse.ptrResponseFunction = NULL            // Clear recovery function pointer

};

/********************************************************************
 * @var FAULT_OBJECT_t fltobj_CsepicRegErr  
 * @ingroup app-layer-fault-monitor-properties-public
 * @brief Pre-Initialized Regulation Error Fault Object
 * @details
 * This fault object monitors the deviation between voltage reference
 * and most recent output voltage of the power supply scanning for
 * conditions where a maximum allowed deviation is exceeded for the
 * specified amount of time.
 *******************************************************************/ 
volatile FAULT_OBJECT_t fltobj_CsepicRegErr = {

    .Status.bits.Enabled = false,                           // Enable/disable fault checks at startup
    .Status.bits.FaultActive = true,                        // Set fault condition flag (must be cleared by fault check)
    .Status.bits.FaultStatus = true,                        // Set fault flag (must be cleared by fault check)
    .Status.bits.CompareType = FLTCMP_GREATER_THAN,         // Select Compare-Type

    .SourceObject.ptrObject = &csepic.data.v_out,           // Set pointer to variable to monitor
    .SourceObject.bitMask = 0xFFFF,                         // Compare all bits of SOURCE (no bit filter)
    .ReferenceObject.ptrObject = &csepic.set_values.v_ref,  // Set pointer to "compare against" variable 
    .ReferenceObject.bitMask = 0xFFFF,                      // Compare all bits of Reference (no bit filter)

    .TripResponse.compareThreshold = CSEPIC_VOUT_DEV_TRIP,  // Set fault trip level
    .TripResponse.eventThreshold = CSEPIC_REGERR_TDLY,      // Set counter level at which a FAULT condition will be tripped
    .TripResponse.ptrResponseFunction = &appPowerSupply_Suspend, // Set pointer to user-function which should be called when a FAULT is tripped

    .RecoveryResponse.compareThreshold = CSEPIC_VOUT_DEV_RELEASE, // Set fault recovery level
    .RecoveryResponse.eventThreshold = CSEPIC_REGERR_RDLY,  // Set counter level at which a FAULT condition will be cleared
    .RecoveryResponse.ptrResponseFunction = NULL            // Clear recovery function pointer

};


/*********************************************************************************
 * @ingroup app-layer-fault-monitor-properties-public
 * @var     FaultObjectList
 * @brief   Fault object list
 * @details
 *  This list is grouping all user defined fault objects in one list, which
 *  is used by the fault handler for initialization, disposal and scan for 
 *  fault conditions.
 **********************************************************************************/

volatile FAULT_OBJECT_t* FaultObjectList[] = {
    &fltobj_CsepicUVLO,     // Fault Object #0
    &fltobj_CsepicOVLO,     // Fault Object #1
    &fltobj_CsepicOCP,      // Fault Object #2
	&fltobj_CsepicOVP,      // Fault Object #3
    &fltobj_CsepicRegErr    // Fault Object #4
};

/*********************************************************************************
 * @ingroup app-layer-fault-monitor-properties-public
 * @var     FaultObjectList_size
 * @brief   Fault object list size
 * @details
 *  This variable is used to determine the number of user specified fault objects.
 *  The size of the fault object list is required for all fault monitor function 
 *  calls.
 **********************************************************************************/

volatile uint16_t FaultObjectList_size = (sizeof(FaultObjectList)/sizeof(FaultObjectList[0]));


// end of file
