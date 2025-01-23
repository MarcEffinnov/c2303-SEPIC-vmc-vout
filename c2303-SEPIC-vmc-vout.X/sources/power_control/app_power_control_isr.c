/*
 * File:   app_power_control_isr.c
 * Author: M91406
 *
 * Created on May 26, 2020, 7:32 PM
 */


#include "config/hal.h"
#include "app_power_control.h"
#include "drivers/v_loop.h"

/*********************************************************************************
 * @fn      void _CSEPIC_LOOP_Interrupt(void)
 * @ingroup app-layer-power-control-events
 * @brief   Main Control Interrupt
 * @param   void
 * @return  void
 *   
 * @details
 * The control interrupt is calling the control loop. The point in time where
 * this interrupt is thrown is determined by selecting the CSEPIC_VOUT_TRIGGER_MODE
 * option. 
 * 
 *********************************************************************************/

void __attribute__((__interrupt__, auto_psv, context))_CSEPIC_LOOP_Interrupt(void)
{
   
    // Set flag bit indication ADC interrupt activity
    csepic.status.bits.adc_active = true;
    // Call feedback loop
    #if (PLANT_MEASUREMENT == false)

    #if (DBGPIN1_ENABLE)
    DBGPIN1_SetHigh();
    #endif
    ///// CCMC /////
    // CURENT LOOP in CCMC
    //csepic.i_loop[0].ctrl_Update(csepic.i_loop[0].controller);
    
    ///// VMC /////
    // VOLTAGE LOOP in CCMC
    csepic.v_loop.ctrl_Update(csepic.v_loop.controller);
    
    #if (DBGPIN1_ENABLE)
    DBGPIN1_SetLow();
    #endif
    
    #else
    v_loop_PTermUpdate(&v_loop);
    #endif

    // Copy most recent control output to DAC output for debugging
    #if (DBGDAC_ENABLE)
    DACOUT_Set(csepic.data.control_output);
    #endif
    
    // Clear the interrupt flag bit allowing the next interrupt to trip
    _CSEPIC_LOOP_ISR_IF = 0;
    
}

// end of file
