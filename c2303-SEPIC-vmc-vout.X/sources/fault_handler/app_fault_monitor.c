/* 
 * @file   app_fault_monitor.c
 * Author: M91406
 * @brief  Fault monitor application layer source file
 * Revision history: 
 */

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer data types
#include <stdbool.h> // include standard boolean data types
#include <stddef.h> // include standard definition data types

#include "config/hal.h" // include hardware abstraction layer header file
#include "config/apps.h" // include application layer abstraction layer header file

// User fault object declarations
extern volatile FAULT_OBJECT_t* FaultObjectList[];
extern volatile uint16_t FaultObjectList_size;

/*********************************************************************************
 * @fn     volatile uint16_t appFaultMonitor_Execute(void)  
 * @ingroup app-layer-fault-handler-functions-public
 * @brief  Application wide fault object monitoring routine
 * @return 0=failure 
 * @return 1=success
 * 
 * @details
 *   In this function all user-defined fault objects are monitored for 
 *   threshold violations. While fault responses are triggered by each 
 *   fault object individually, system recovery from a fault condition is 
 *   only allowed when all fault conditions have been cleared. Hence, 
 *   individual fault status bits are combined into a common fault bit, 
 *   which needs to be cleared to allow the power supply to start-up again.
 * 
 *********************************************************************************/

volatile uint16_t appFaultMonitor_Execute(void) 
{
    volatile uint16_t retval=1;
    
    // Scan all declared fault objects
    drv_FaultHandler_ScanObjects(FaultObjectList, FaultObjectList_size);
    
    // Push global fault state to buck converter device driver status
    csepic.status.bits.fault_active = FaultMonitor.Status.bits.FaultStatus;
    
    // If power supply controller passes POWER GOOD and reaches state ONLINE,
    // reset restart cycle counter
    if (csepic.state_id.bits.opstate_id == CSEPIC_OPSTATE_ONLINE)
        FaultMonitor.FaultRecoveryCounter = 0;

    
    return (retval);
}

/*********************************************************************************
 * @fn     volatile uint16_t appFaultMonitor_Initialize(void)
 * @ingroup app-layer-fault-handler-functions-public
 * @brief  Initialization of user-defined fault objects
 * @return 0=failure 
 * @return 1=success
 * 
 * @details
 * This function initializes the fault monitor data object user settings
 * and the CPU soft traps. All user defined fault objetcs are pre-initialized
 * in app_fault_config.c and do not need further initialization.
 *********************************************************************************/

volatile uint16_t appFaultMonitor_Initialize(void) 
{
    volatile uint16_t retval=1;
    
    // Initialize soft traps
    retval &= drv_TrapHandler_SoftTrapsInitialize(false, false, false); // Do not use DSP saturation traps
    
    // Initialize fault monitor recovery parameters
    FaultMonitor.FaultRecovery = &appPowerSupply_Resume;
    FaultMonitor.FaultLatchCount = CSEPIC_FAULT_RESTART_CYCLES;
    FaultMonitor.FaultRecoveryCounter = 0;
    
    return(retval);
}

/*********************************************************************************
 * @fn     volatile uint16_t appFaultMonitor_Start(void) 
 * @ingroup app-layer-fault-handler-functions-public
 * @brief  Function starting all pre-configured fault checks
 * @return 0=failure 
 * @return 1=success
 * 
 * @details
 *   This function is used to set the fault status of all fault objects 
 *   to ACTIVE, enforcing the system monitor to clear them one-by-one as 
 *   default startup self-test procedure. Once cleared, the respective 
 *   recovery procedures will turn on the respective user-tasks being
 *   kept on-hold while faults have been active.
 * 
 *   Users can set the initial state of each fault object in accordance
 *   to their inclusion in the self-test period at firmware startup.
 * 
 *********************************************************************************/

volatile uint16_t appFaultMonitor_Start(void) 
{
    fltobj_CsepicUVLO.Status.bits.FaultStatus = true; // Set Under Voltage Lock Out fault
    fltobj_CsepicUVLO.Status.bits.FaultActive = true; // Set Under Voltage Lock Out fault condition indicator
    fltobj_CsepicUVLO.Status.bits.Enabled = true; // Enable Under Voltage Lock Out object

    fltobj_CsepicOVLO.Status.bits.FaultStatus = true; // Set Over Voltage Lock Out fault
    fltobj_CsepicOVLO.Status.bits.FaultActive = true; // Set Over Voltage Lock Out fault condition indicator
    fltobj_CsepicOVLO.Status.bits.Enabled = true; // Enable Over Voltage Lock Out object

    fltobj_CsepicOCP.Status.bits.FaultStatus = false; // Clear Over Current Protection fault
    fltobj_CsepicOCP.Status.bits.FaultActive = false; // Clear Over Current Protection fault condition indicator
    fltobj_CsepicOCP.Status.bits.Enabled = false; // Disable Over Current Protection object (will be enabled by power supply state machine)

    fltobj_CsepicOVP.Status.bits.FaultStatus = false; // Clear Output Over Voltage Protection fault
    fltobj_CsepicOVP.Status.bits.FaultActive = false; // Clear Output Over Voltage Protection fault condition indicator
    fltobj_CsepicOVP.Status.bits.Enabled = true; // Disable Output Over Voltage Protection object 

    fltobj_CsepicRegErr.Status.bits.FaultStatus = false; // Clear Regulation Error fault
    fltobj_CsepicRegErr.Status.bits.FaultActive = false; // Clear Regulation Error fault condition indicator
    fltobj_CsepicRegErr.Status.bits.Enabled = false; // Disable Regulation Error object (will be enabled by power supply state machine)
    
    return(1);
}

/*********************************************************************************
 * @fn     volatile uint16_t appFaultMonitor_Dispose(void) 
 * @ingroup app-layer-fault-handler-functions-public
 * @brief  Function clearing all fault object settings
 * @return 0=failure 
 * @return 1=success
 * 
 * @details
 *   This function is used to clear all fault objects settings. Once cleared,
 *   the fault objects are detached from memory addresses and cannot be used
 *   for fault monitoring anymore until they have been re-initialized.
 * 
 *********************************************************************************/

volatile uint16_t appFaultMonitor_Dispose(void) {
    
    // Clear all user defined fault objects
    drv_FaultHandler_Dispose(FaultObjectList, FaultObjectList_size);
    
    return(1);
}

// end of file
