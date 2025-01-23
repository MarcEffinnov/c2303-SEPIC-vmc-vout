/* ***********************************************************************************************
 * File:           ma330048_p33ck_r30_pinmap.h 
 * Author:         M91406                                                                     
 * Comments:       Hardware abstraction layer device pinout descriptor                            
 * Board ID:       DPPIM_P33CK                                                                  
 * Product-No:     MA330048                                                               
 * Device ID:      P33CK                                                                    
 * Board Revision: 30                                                                  
 * Date:           10/20/2020                                                                         
 * Build:          0071                                                                   
 * Build Tool:     1.3                                                                            
 *                                                                                                 
 * Description:                                                                                    
 * This is a header file template adding signal labels for the hardware abstraction layer          
 * In this example user defined signals are directly associated to specific device pins.           
 * These associations have been created using the MS Excel macro-based code generation tool        
 * MyBoard_RXX_pinout.xlsm located in the h/hal/config directory of the project.                   
 *                                                                                                 
 * Note:                                                                                           
 * This file is the junction point between hardware and microcontroller abstraction layer.         
 * To better separate them from each other (e.g. for supporting CPU cards in hardware platforms),  
 * generic signal labels may be used in these declarations, which can be used to associate MCU     
 * device pins in MCAL to signals defined in HAL.                                                  
 *                                                                                     
 * EXAMPLE OF BOTH USE CASES                                                           
 *                                                                                     
 * a) Direct pin assignment using ONE header file in HAL                               
 *                                                                                     
 *  File:       MyBoard_RXX_pinmap.h                                                   
 * -----------------------------------------------------------------------             
 *                                                                                     
 *              #define CLKOUT  _LATB1                                                 
 *                                                                                     
 * Any usage of the label CLKOUT in user code will automatically be mapped to the      
 * specific device pin RB1. Thus board hardware and MCU itself become independent,     
 * exchangeable elements in the firmware and pin-out changes made won't affect         
 * the rest of the firmware.                                                           
 *                                                                                     
 * However, although this assignment simplifies the hardware abstraction, HAL and MCAL 
 * are not clearly separated as MCU specific registers are assigned here.              
 *                                                                                     
 *                                                                                     
 * b) Indirect pin assignment using TWO header files in HAL and MCAL                   
 *          
 *  File:       MyBoard_RXX_pinmap.h            MyController_pinmap.h                  
 * -----------------------------------------------------------------------             
 *          
 *              #define CLKOUT  ECP08            #define TP08    _LATB1                
 *     
 * Any usage of the label CLKOUT in user code will automatically be mapped to the          
 * specific device pin RB1. Thus board hardware, MCU adapter card and MCU itself become    
 * independent, exchangeable elements in the firmware and changes made here won't affect   
 * the rest of the firmware.                                                           
 *                                                                                     
 * This functional assignment scheme clearly separates HAL and MCAL, but adds more complexity  
 * to the structure. This scheme works best when working with CPU adapter cards like   
 * Microchip's Digital Power Plug-In Modules.                                          
 *                                                                                     
 *                                                                                     
 * ***********************************************************************************************/    
// This is a guard condition so that contents of this file are not included
// more than once.
#ifndef __LEAH_P33CK_SecMCU_R10_PINMAP_H__
#define __LEAH_P33CK_SecMCU_R10_PINMAP_H__

#include <xc.h> // include processor files - each processor file is guarded 
#include <stdint.h> // Include standard integer types                       
#include <stdbool.h> // Include standard boolean types                      
#include <stddef.h> // Include standard definition types                    

/* @@Hardware Identifiers
* *************************************************************************************************
 * Summary:
 * Global defines of hardware identifiers
 *
 * Description:
 * This section is used to define hardware specific identifiers which can be used in user firmware
 * to tailor and switch between different versions of a certain hardware. The identifiers provided
 * are using the product number and a board name flag together with the hardware version number.
 *
 * In addition a macro is defined helping to identify the hardware revision as integer number,
 * allowing to use this macro in �compare statements like
 *
 *   #if (__MA330048_VERSION > 10)
 *     #pragma message 'Warning: This code has not been tested for the selected hardware'
 *   #endif
 *
 * *************************************************************************************************/

#ifndef __LEAH_HostMCU_PINMAP_R10__ // hardware indentifier macro using the product number
#define __LEAH_HostMCU_R10_PINMAP__ // hardware version is encoded by R<MAJOR><MINOR> (e.g. revision 2.1 = R21)
#endif

#ifndef __LEAH_HostMCU_PINMAP_VERSION // hardware version as integer number
#define __LEAH_HostMCU_PINMAP_VERSION 10 // is encoded by <MAJOR><MINOR> (e.g. revision 2.1 = R21)
#endif


/* ***********************************************************************************************/

// Generated Content: Generic defines used to map device pins to board signals
#ifndef PINDIR_INPUT
    #define PINDIR_INPUT 1
#endif
#ifndef PINDIR_OUTPUT
    #define PINDIR_OUTPUT 0
#endif

#ifndef PINSTATE_HIGH
    #define PINSTATE_HIGH 1
#endif
#ifndef PINSTATE_LOW
    #define PINSTATE_LOW 0
#endif

#ifndef PINCFG_OPEN_DRAIN
    #define PINCFG_OPEN_DRAIN 1
#endif
#ifndef PINCFG_PUSH_PULL
    #define PINCFG_PUSH_PULL 0
#endif

#ifndef LED_ON
    #define LED_ON 0
#endif
#ifndef LED_OFF
    #define LED_OFF 1
#endif

/**************************************************************************************************
 * @ingroup device-abstraction-pinmap
 * @{
 * @brief User-declaration of global defines for PWM signal generator settings
 * 
 * @details
 * This section defines fundamental PWM settings required for the 4-switch buck-boost converter.
 * These settings are determined by hardware and defined using physical quantities. Pre-compiler 
 * macros are used to convert physical values into binary (integer) numbers to be written to 
 * Special Function Registers (SFR).
 * 
 **************************************************************************************************/

// Common PPS Labels		
#define RPOR_U1TX     	0b000001	// RPn tied to UART1 Transmit
#define RPOR_U1RTS    	0b000010	// RPn tied to UART1 Request-to-Send
#define RPOR_U2TX     	0b000011	// RPn tied to UART2 Transmit
#define RPOR_U2RTS    	0b000100	// RPn tied to UART2 Request-to-Send
#define RPOR_U3TX     	0b011011	// RPn tied to UART3 Transmit
#define RPOR_U3RTS    	0b011100	// RPn tied to UART3 Request-to-Send
#define RPOR_SDO1     	0b000101	// RPn tied to SPI1 Data Output
#define RPOR_SCK1     	0b000110	// RPn tied to SPI1 Clock Output
#define RPOR_SS1      	0b000111	// RPn tied to SPI1 Slave Select
#define RPOR_SDO2     	0b001000	// RPn tied to SPI2 Data Output
#define RPOR_SCK2     	0b001001	// RPn tied to SPI2 Clock Output
#define RPOR_SS2      	0b001010	// RPn tied to SPI2 Slave Select
#define RPOR_SDO3     	0b001011	// RPn tied to SPI3 Data Output
#define RPOR_SCK3     	0b001100	// RPn tied to SPI3 Clock Output
#define RPOR_SS3      	0b001101	// RPn tied to SPI3 Slave Select
#define RPOR_REFCLKO  	0b001110	// RPn tied to Reference Clock Output
#define RPOR_OCM1     	0b001111	// RPn tied to SCCP1 Output
#define RPOR_OCM2     	0b010000	// RPn tied to SCCP2 Output
#define RPOR_OCM3     	0b010001	// RPn tied to SCCP3 Output
#define RPOR_OCM4     	0b010010	// RPn tied to SCCP4 Output
#define RPOR_OCM5     	0b010011	// RPn tied to SCCP5 Output
#define RPOR_OCM6     	0b010100	// RPn tied to SCCP6 Output
#define RPOR_CAN1TX   	0b010101	// RPn tied to CAN1 Transmit
#define RPOR_CMP1     	0b010111	// RPn tied to Comparator 1 Output
#define RPOR_CMP2     	0b011000	// RPn tied to Comparator 2 Output
#define RPOR_CMP3     	0b011001	// RPn tied to Comparator 3 Output
#define RPOR_PWM4H    	0b100010	// RPn tied to PWM4H Output
#define RPOR_PWM4L    	0b100011	// RPn tied to PWM4L Output
#define RPOR_PWMEA    	0b100100	// RPn tied to PWM Event A Output
#define RPOR_PWMEB    	0b100101	// RPn tied to PWM Event B Output
#define RPOR_QEICMP1  	0b100110	// RPn tied to QEI1 Comparator Output
#define RPOR_QEICMP2  	0b100111	// RPn tied to QEI2 Comparator Output
#define RPOR_CLC1OUT  	0b101000	// RPn tied to CLC1 Output
#define RPOR_CLC2OUT  	0b101001	// RPn tied to CLC2 Output
#define RPOR_OCM7     	0b101010	// RPn tied to SCCP7 Output
#define RPOR_OCM8     	0b101011	// RPn tied to SCCP8 Output
#define RPOR_PWMEC    	0b101100	// RPn tied to PWM Event C Output
#define RPOR_PWMED    	0b101101	// RPn tied to PWM Event D Output
#define RPOR_PTGTRG24 	0b101110	// PTG Trigger Output 24
#define RPOR_PTGTRG25 	0b101111	// PTG Trigger Output 25
#define RPOR_SENT1OUT 	0b110000	// RPn tied to SENT1 Output
#define RPOR_SENT2OUT 	0b110001	// RPn tied to SENT2 Output
#define RPOR_MCCP9A   	0b110010	// RPn tied to MCCP9 Output A
#define RPOR_MCCP9B   	0b110011	// RPn tied to MCCP9 Output B
#define RPOR_MCCP9C   	0b110100	// RPn tied to MCCP9 Output C
#define RPOR_MCCP9D   	0b110101	// RPn tied to MCCP9 Output D
#define RPOR_MCCP9E   	0b110110	// RPn tied to MCCP9 Output E
#define RPOR_MCCP9F   	0b110111	// RPn tied to MCCP9 Output F
#define RPOR_CLC3OUT  	0b111011	// RPn tied to CLC4 Output
#define RPOR_CLC4OUT  	0b111100	// RPn tied to CLC4 Output
#define RPOR_U1DTR    	0b111101	// RPn tied to UART1 DTR
#define RPOR_U2DTR    	0b111110	// RPn tied to UART2 DTR
#define RPOR_U3DTR    	0b111111	// RPn tied to UART3 DTR

// Common ADC Trigger Source Labels		
#define TRGSRC_ADTRIG31 	0b11111	// ADTRG31 (PPS input)
#define TRGSRC_PTG      	0b11110	// PTG
#define TRGSRC_CLC2     	0b11101	// CLC2
#define TRGSRC_CLC1     	0b11100	// CLC1
#define TRGSRC_MCCP9    	0b11011	// MCCP9
#define TRGSRC_SCCP7    	0b11010	// SCCP7
#define TRGSRC_SCCP6    	0b11001	// SCCP6
#define TRGSRC_SCCP5    	0b11000	// SCCP5
#define TRGSRC_SCCP4    	0b10111	// SCCP4
#define TRGSRC_SCCP3    	0b10110	// SCCP3
#define TRGSRC_SCCP2    	0b10101	// SCCP2
#define TRGSRC_SCCP1    	0b10100	// SCCP1
#define TRGSRC_PWM8_TRG2	0b10011	// PWM8 Trigger 2
#define TRGSRC_PWM8_TRG1	0b10010	// PWM8 Trigger 1
#define TRGSRC_PWM7_TRG2	0b10001	// PWM7 Trigger 2
#define TRGSRC_PWM7_TRG1	0b10000	// PWM7 Trigger 1
#define TRGSRC_PWM6_TRG2	0b01111	// PWM6 Trigger 2
#define TRGSRC_PWM6_TRG1	0b01110	// PWM6 Trigger 1
#define TRGSRC_PWM5_TRG2	0b01101	// PWM5 Trigger 2
#define TRGSRC_PWM5_TRG1	0b01100	// PWM5 Trigger 1
#define TRGSRC_PWM4_TRG2	0b01011	// PWM4 Trigger 2
#define TRGSRC_PWM4_TRG1	0b01010	// PWM4 Trigger 1
#define TRGSRC_PWM3_TRG2	0b01001	// PWM3 Trigger 2
#define TRGSRC_PWM3_TRG1	0b01000	// PWM3 Trigger 1
#define TRGSRC_PWM2_TRG2	0b00111	// PWM2 Trigger 2
#define TRGSRC_PWM2_TRG1	0b00110	// PWM2 Trigger 1
#define TRGSRC_PWM1_TRG2	0b00101	// PWM1 Trigger 2
#define TRGSRC_PWM1_TRG1	0b00100	// PWM1 Trigger 1
#define TRGSRC_SWLVLTRG 	0b00010	// Level software trigger
#define TRGSRC_SWCOMTRG 	0b00001	// Common software trigger
#define TRGSRC_DISABLED 	0b00000	// No trigger is enabled

// ***************************************************************************************************
// ***************************************************************************************************
// *      PORTA
// ***************************************************************************************************
// ***************************************************************************************************

// Device Pin #5 is RA0 is SEPIC Feedback IOUT (going through OPAMP1 output)
#define FB_IOUT_SEPIC_GPIO_INSTANCE   0 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define FB_IOUT_SEPIC_GPIO_PORT_PIN   0 // Port Pin Number
#define FB_IOUT_SEPIC_Tris(x)         (TRISAbits.TRISA0 = x) // GPIO direction register bit
#define FB_IOUT_SEPIC_Write(x)        (LATAbits.LATA0 = x) // GPIO port latch register bit
#define FB_IOUT_SEPIC_Read()          PORTAbits.RA0 // GPIO port register bit
#define FB_IOUT_SEPIC_ODC             ODCAbits.ODCA0 // GPIO port open drain configuration register bit
#define FB_IOUT_SEPIC_CNPU            CNPUAbits.CNPUA0 // GPIO port pull-up resistor register bit
#define FB_IOUT_SEPIC_CNPD            CNPDAbits.CNPDA0 // GPIO port pull-down resistor register bit
#define FB_IOUT_SEPIC_CNEN0           CNEN0Abits.CNEN0A0 // GPIO port change notification Enable register bit
#define FB_IOUT_SEPIC_CNSTAT          CNSTATAbits.CNSTATA0 // GPIO port change notification Status register bit
#define FB_IOUT_SEPIC_CNEN1           CNEN1Abits.CNEN1A0 // GPIO port change notification Edge Select Enable register bit
#define FB_IOUT_SEPIC_CNF             CNFAbits.CNFA0 // GPIO port change notification flag bit register bit
#define FB_IOUT_SEPIC_Set()           { asm volatile ("bset _LATA, #0 \n"); }
#define FB_IOUT_SEPIC_Clear()         { asm volatile ("bclr _LATA, #0 \n"); }
#define FB_IOUT_SEPIC_Toggle()        { asm volatile ("btg  _LATA, #0 \n"); }
#define FB_IOUT_SEPIC_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define FB_IOUT_SEPIC_ANSEL           _ANSELA0 // analog/digital pin configuration register bit
#define FB_IOUT_SEPIC_ADCCORE         0 // index starts from zero, last index indicated shared adC core
#define FB_IOUT_SEPIC_IS_SHARED_CORE  false // AN input is routed to a dedicated or shared ACD core
#define FB_IOUT_SEPIC_ADCAN           0   // ANx input pin number
#define FB_IOUT_SEPIC_ADCBUF          ADCBUF0 // ADC buffer register for this input
#define FB_IOUT_SEPIC_ADIE_IEx        ADIELbits.IE0
#define FB_IOUT_SEPIC_ADEIE_EIEx      ADEIELbits.EIEN0
#define FB_IOUT_SEPIC_ADCANxIF        _ADCAN0IF // interrupt flag bit
#define FB_IOUT_SEPIC_ADCANxIE        _ADCAN0IE // interrupt enable bit
#define FB_IOUT_SEPIC_ADCANxIP        _ADCAN0IP // interrupt priority for this analog input
#define FB_IOUT_SEPIC_ANxRDY          _AN0RDY // ADC buffer ready bit
#define _FB_IOUT_SEPIC_ADCANxInterrupt _ADCAN0Interrupt
#define FB_IOUT_SEPIC_ANxTRGSRC       _TRGSRC0 // ADC input trigger source register
#define FB_IOUT_SEPIC_InitAnalog()    {FB_IOUT_SEPIC_ANSEL = 1; FB_IOUT_SEPIC_Write(PINSTATE_HIGH); FB_IOUT_SEPIC_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define FB_IOUT_SEPIC_Dispose()       {FB_IOUT_SEPIC_Write(PINSTATE_HIGH); FB_IOUT_SEPIC_Tris(PINDIR_INPUT); FB_IOUT_SEPIC_ANSEL = 0;} // disposing macro for digital input with analog function
#define FB_IOUT_SEPIC_InitOutput()    {FB_IOUT_SEPIC_Write(PINSTATE_LOW); FB_IOUT_SEPIC_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define FB_IOUT_SEPIC_InitInput()     {FB_IOUT_SEPIC_Write(PINSTATE_HIGH); FB_IOUT_SEPIC_Tris(PINDIR_INPUT);} // initialization macro for digital input


// Device Pin #6 is RA1 is OPAMP1 negative input ISN- for IOUT current sense on SEPIC
#define ISNN_GPIO_INSTANCE   0 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define ISNN_GPIO_PORT_PIN   1 // Port Pin Number
#define ISNN_Tris(x)         (TRISAbits.TRISA1 = x) // GPIO direction register bit
#define ISNN_Write(x)        (LATAbits.LATA1 = x) // GPIO port latch register bit
#define ISNN_Read()          PORTAbits.RA1 // GPIO port register bit
#define ISNN_ODC             ODCAbits.ODCA1 // GPIO port open drain configuration register bit
#define ISNN_CNPU            CNPUAbits.CNPUA1 // GPIO port pull-up resistor register bit
#define ISNN_CNPD            CNPDAbits.CNPDA1 // GPIO port pull-down resistor register bit
#define ISNN_CNEN0           CNEN0Abits.CNEN0A1 // GPIO port change notification Enable register bit
#define ISNN_CNSTAT          CNSTATAbits.CNSTATA1 // GPIO port change notification Status register bit
#define ISNN_CNEN1           CNEN1Abits.CNEN1A1 // GPIO port change notification Edge Select Enable register bit
#define ISNN_CNF             CNFAbits.CNFA1 // GPIO port change notification flag bit register bit
#define ISNN_Set()           { asm volatile ("bset _LATA, #1 \n"); }
#define ISNN_Clear()         { asm volatile ("bclr _LATA, #1 \n"); }
#define ISNN_Toggle()        { asm volatile ("btg  _LATA, #1 \n"); }
#define ISNN_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define ISNN_ANSEL           _ANSELA1 // analog/digital pin configuration register bit
#define ISNN_ADCCORE         1 // index starts from zero, last index indicated shared adC core
#define ISNN_IS_SHARED_CORE  false // AN input is routed to a dedicated or shared ACD core
#define ISNN_ADCAN           1   // ANx input pin number
#define ISNN_ADCBUF          ADCBUF1 // ADC buffer register for this input
#define ISNN_ADIE_IEx        ADIELbits.IE1
#define ISNN_ADEIE_EIEx      ADEIELbits.EIEN1
#define ISNN_ADCANxIF        _ADCAN1IF // interrupt flag bit
#define ISNN_ADCANxIE        _ADCAN1IE // interrupt enable bit
#define ISNN_ADCANxIP        _ADCAN1IP // interrupt priority for this analog input
#define ISNN_ANxRDY          _AN1RDY // ADC buffer ready bit
#define _ISNN_ADCANxInterrupt _ADCAN1Interrupt
#define ISNN_ANxTRGSRC       _TRGSRC1 // ADC input trigger source register
#define ISNN_InitAnalog()    {ISNN_ANSEL = 1; ISNN_Write(PINSTATE_HIGH); ISNN_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define ISNN_Dispose()       {ISNN_Write(PINSTATE_HIGH); ISNN_Tris(PINDIR_INPUT); ISNN_ANSEL = 0;} // disposing macro for digital input with analog function
#define ISNN_InitOutput()    {ISNN_Write(PINSTATE_LOW); ISNN_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define ISNN_InitInput()     {ISNN_Write(PINSTATE_HIGH); ISNN_Tris(PINDIR_INPUT);} // initialization macro for digital input


// Device Pin #7 is RA2 is OPAMP1 positive input ISN+ for IOUT current sense on SEPIC
#define ISNP_GPIO_INSTANCE   0 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define ISNP_GPIO_PORT_PIN   2 // Port Pin Number
#define ISNP_Tris(x)         (TRISAbits.TRISA2 = x) // GPIO direction register bit
#define ISNP_Write(x)        (LATAbits.LATA2 = x) // GPIO port latch register bit
#define ISNP_Read()          PORTAbits.RA2 // GPIO port register bit
#define ISNP_ODC             ODCAbits.ODCA2 // GPIO port open drain configuration register bit
#define ISNP_CNPU            CNPUAbits.CNPUA2 // GPIO port pull-up resistor register bit
#define ISNP_CNPD            CNPDAbits.CNPDA2 // GPIO port pull-down resistor register bit
#define ISNP_CNEN0           CNEN0Abits.CNEN0A2 // GPIO port change notification Enable register bit
#define ISNP_CNSTAT          CNSTATAbits.CNSTATA2 // GPIO port change notification Status register bit
#define ISNP_CNEN1           CNEN1Abits.CNEN1A2 // GPIO port change notification Edge Select Enable register bit
#define ISNP_CNF             CNFAbits.CNFA2 // GPIO port change notification flag bit register bit
#define ISNP_Set()           { asm volatile ("bset _LATA, #2 \n"); }
#define ISNP_Clear()         { asm volatile ("bclr _LATA, #2 \n"); }
#define ISNP_Toggle()        { asm volatile ("btg  _LATA, #2 \n"); }
#define ISNP_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define ISNP_ANSEL           _ANSELA2 // analog/digital pin configuration register bit
#define ISNP_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define ISNP_IS_SHARED_CORE  false // AN input is routed to a dedicated or shared ACD core
#define ISNP_ADCAN           9   // ANx input pin number
#define ISNP_ADCBUF          ADCBUF2 // ADC buffer register for this input
#define ISNP_ADIE_IEx        ADIELbits.IE2
#define ISNP_ADEIE_EIEx      ADEIELbits.EIEN2
#define ISNP_ADCANxIF        _ADCAN2IF // interrupt flag bit
#define ISNP_ADCANxIE        _ADCAN2IE // interrupt enable bit
#define ISNP_ADCANxIP        _ADCAN2IP // interrupt priority for this analog input
#define ISNP_ANxRDY          _AN2RDY // ADC buffer ready bit
#define _ISNP_ADCANxInterrupt _ADCAN2Interrupt
#define ISNP_ANxTRGSRC       _TRGSRC2 // ADC input trigger source register
#define ISNP_InitAnalog()    {ISNP_ANSEL = 1; ISNP_Write(PINSTATE_HIGH); ISNP_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define ISNP_Dispose()       {ISNP_Write(PINSTATE_HIGH); ISNP_Tris(PINDIR_INPUT); ISNP_ANSEL = 0;} // disposing macro for digital input with analog function
#define ISNP_InitOutput()    {ISNP_Write(PINSTATE_LOW); ISNP_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define ISNP_InitInput()     {ISNP_Write(PINSTATE_HIGH); ISNP_Tris(PINDIR_INPUT);} // initialization macro for digital input


// Device Pin #8 is RA3 is LS switch current sense (for PCMC or ACMC regulation) for SEPIC
#define IL_SENSE_GPIO_INSTANCE   0 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define IL_SENSE_GPIO_PORT_PIN   3 // Port Pin Number
#define IL_SENSE_Tris(x)         (TRISAbits.TRISA3 = x) // GPIO direction register bit
#define IL_SENSE_Write(x)        (LATAbits.LATA3 = x) // GPIO port latch register bit
#define IL_SENSE_Read()          PORTAbits.RA3 // GPIO port register bit
#define IL_SENSE_ODC             ODCAbits.ODCA3 // GPIO port open drain configuration register bit
#define IL_SENSE_CNPU            CNPUAbits.CNPUA3 // GPIO port pull-up resistor register bit
#define IL_SENSE_CNPD            CNPDAbits.CNPDA3 // GPIO port pull-down resistor register bit
#define IL_SENSE_CNEN0           CNEN0Abits.CNEN0A3 // GPIO port change notification Enable register bit
#define IL_SENSE_CNSTAT          CNSTATAbits.CNSTATA3 // GPIO port change notification Status register bit
#define IL_SENSE_CNEN1           CNEN1Abits.CNEN1A3 // GPIO port change notification Edge Select Enable register bit
#define IL_SENSE_CNF             CNFAbits.CNFA3 // GPIO port change notification flag bit register bit
#define IL_SENSE_Set()           { asm volatile ("bset _LATA, #3 \n"); }
#define IL_SENSE_Clear()         { asm volatile ("bclr _LATA, #3 \n"); }
#define IL_SENSE_Toggle()        { asm volatile ("btg  _LATA, #3 \n"); }
#define IL_SENSE_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define IL_SENSE_ANSEL           _ANSELA3 // analog/digital pin configuration register bit
#define IL_SENSE_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define IL_SENSE_IS_SHARED_CORE  false // AN input is routed to a dedicated or shared ACD core
#define IL_SENSE_ADCAN           3   // ANx input pin number
#define IL_SENSE_ADCBUF          ADCBUF3 // ADC buffer register for this input
#define IL_SENSE_ADIE_IEx        ADIELbits.IE3
#define IL_SENSE_ADEIE_EIEx      ADEIELbits.EIEN3
#define IL_SENSE_ADCANxIF        _ADCAN3IF // interrupt flag bit
#define IL_SENSE_ADCANxIE        _ADCAN3IE // interrupt enable bit
#define IL_SENSE_ADCANxIP        _ADCAN3IP // interrupt priority for this analog input
#define IL_SENSE_ANxRDY          _AN3RDY // ADC buffer ready bit
#define _IL_SENSE_ADCANxInterrupt _ADCAN3Interrupt
#define IL_SENSE_ANxTRGSRC       _TRGSRC3 // ADC input trigger source register
#define IL_SENSE_InitAnalog()    {IL_SENSE_ANSEL = 1; IL_SENSE_Write(PINSTATE_HIGH); IL_SENSE_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define IL_SENSE_Dispose()       {IL_SENSE_Write(PINSTATE_HIGH); IL_SENSE_Tris(PINDIR_INPUT); IL_SENSE_ANSEL = 0;} // disposing macro for digital input with analog function
#define IL_SENSE_InitOutput()    {IL_SENSE_Write(PINSTATE_LOW); IL_SENSE_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define IL_SENSE_InitInput()     {IL_SENSE_Write(PINSTATE_HIGH); IL_SENSE_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #9 is RA4 (Feedback VOUT for SEPIC)
#define FB_VOUT_SEPIC_GPIO_INSTANCE   0 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define FB_VOUT_SEPIC_GPIO_PORT_PIN   4 // Port Pin Number
#define FB_VOUT_SEPIC_Tris(x)         (TRISAbits.TRISA4 = x) // GPIO direction register bit
#define FB_VOUT_SEPIC_Write(x)        (LATAbits.LATA4 = x) // GPIO port latch register bit
#define FB_VOUT_SEPIC_Read()          PORTAbits.RA4 // GPIO port register bit
#define FB_VOUT_SEPIC_ODC             ODCAbits.ODCA4 // GPIO port open drain configuration register bit
#define FB_VOUT_SEPIC_CNPU            CNPUAbits.CNPUA4 // GPIO port pull-up resistor register bit
#define FB_VOUT_SEPIC_CNPD            CNPDAbits.CNPDA4 // GPIO port pull-down resistor register bit
#define FB_VOUT_SEPIC_CNEN0           CNEN0Abits.CNEN0A4 // GPIO port change notification Enable register bit
#define FB_VOUT_SEPIC_CNSTAT          CNSTATAbits.CNSTATA4 // GPIO port change notification Status register bit
#define FB_VOUT_SEPIC_CNEN1           CNEN1Abits.CNEN1A4 // GPIO port change notification Edge Select Enable register bit
#define FB_VOUT_SEPIC_CNF             CNFAbits.CNFA4 // GPIO port change notification flag bit register bit
#define FB_VOUT_SEPIC_Set()           { asm volatile ("bset _LATA, #4 \n"); }
#define FB_VOUT_SEPIC_Clear()         { asm volatile ("bclr _LATA, #4 \n"); }
#define FB_VOUT_SEPIC_Toggle()        { asm volatile ("btg  _LATA, #4 \n"); }
#define FB_VOUT_SEPIC_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define FB_VOUT_SEPIC_ANSEL           _ANSELA4 // analog/digital pin configuration register bit
#define FB_VOUT_SEPIC_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define FB_VOUT_SEPIC_IS_SHARED_CORE  false // AN input is routed to a dedicated or shared ACD core
#define FB_VOUT_SEPIC_ADCAN           4   // ANx input pin number
#define FB_VOUT_SEPIC_ADCBUF          ADCBUF4 // ADC buffer register for this input
#define FB_VOUT_SEPIC_ADIE_IEx        ADIELbits.IE4
#define FB_VOUT_SEPIC_ADEIE_EIEx      ADEIELbits.EIEN4
#define FB_VOUT_SEPIC_ADCANxIF        _ADCAN4IF // interrupt flag bit
#define FB_VOUT_SEPIC_ADCANxIE        _ADCAN4IE // interrupt enable bit
#define FB_VOUT_SEPIC_ADCANxIP        _ADCAN4IP // interrupt priority for this analog input
#define FB_VOUT_SEPIC_ANxRDY          _AN4RDY // ADC buffer ready bit
#define _FB_VOUT_SEPIC_ADCANxInterrupt _ADCAN4Interrupt
#define FB_VOUT_SEPIC_ANxTRGSRC       _TRGSRC4 // ADC input trigger source register
#define FB_VOUT_SEPIC_InitAnalog()    {FB_VOUT_SEPIC_ANSEL = 1; FB_VOUT_SEPIC_Write(PINSTATE_HIGH); FB_VOUT_SEPIC_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define FB_VOUT_SEPIC_Dispose()       {FB_VOUT_SEPIC_Write(PINSTATE_HIGH); FB_VOUT_SEPIC_Tris(PINDIR_INPUT); FB_VOUT_SEPIC_ANSEL = 0;} // disposing macro for digital input with analog function
#define FB_VOUT_SEPIC_InitOutput()    {FB_VOUT_SEPIC_Write(PINSTATE_LOW); FB_VOUT_SEPIC_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define FB_VOUT_SEPIC_InitInput()     {FB_VOUT_SEPIC_Write(PINSTATE_HIGH); FB_VOUT_SEPIC_Tris(PINDIR_INPUT);} // initialization macro for digital input
#define FB_VOUT_SEPIC_COMP3_IN_SEL    1U         // A input=0, B input=1 .... D input=3 / RB2 is CMP1D

// ***************************************************************************************************
// ***************************************************************************************************
// *      PORTB
// ***************************************************************************************************
// ***************************************************************************************************

// Device Pin #17 is RB0 is oscillator clock input @ 8MHz
#define CLKI_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define CLKI_GPIO_PORT_PIN   0 // Port Pin Number
#define CLKI_Tris(x)         (TRISBbits.TRISB0 = x) // GPIO direction register bit
#define CLKI_Write(x)        (LATBbits.LATB0 = x) // GPIO port latch register bit
#define CLKI_Read()          PORTBbits.RB0 // GPIO port register bit
#define CLKI_ODC             ODCBbits.ODCB0 // GPIO port open drain configuration register bit
#define CLKI_CNPU            CNPUBbits.CNPUB0 // GPIO port pull-up resistor register bit
#define CLKI_CNPD            CNPDBbits.CNPDB0 // GPIO port pull-down resistor register bit
#define CLKI_CNEN0           CNEN0Bbits.CNEN0B0 // GPIO port change notification Enable register bit
#define CLKI_CNSTAT          CNSTATBbits.CNSTATB0 // GPIO port change notification Status register bit
#define CLKI_CNEN1           CNEN1Bbits.CNEN1B0 // GPIO port change notification Edge Select Enable register bit
#define CLKI_CNF             CNFBbits.CNFB0 // GPIO port change notification flag bit register bit
#define CLKI_RP              32 // Number of Remappable Pin
#define _CLKI_RPxR           _RP32R // Remappable Pin Register
#define CLKI_Set()           { asm volatile ("bset _LATB, #0 \n"); }
#define CLKI_Clear()         { asm volatile ("bclr _LATB, #0 \n"); }
#define CLKI_Toggle()        { asm volatile ("btg  _LATB, #0 \n"); }
#define CLKI_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define CLKI_ANSEL           _ANSELB0 // analog/digital pin configuration register bit
#define CLKI_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define CLKI_IS_SHARED_CORE  false // AN input is routed to a dedicated or shared ACD core
#define CLKI_ADCAN           5   // ANx input pin number
#define CLKI_ADCBUF          ADCBUF5 // ADC buffer register for this input
#define CLKI_ADIE_IEx        ADIELbits.IE5
#define CLKI_ADEIE_EIEx      ADEIELbits.EIEN5
#define CLKI_ADCANxIF        _ADCAN5IF // interrupt flag bit
#define CLKI_ADCANxIE        _ADCAN5IE // interrupt enable bit
#define CLKI_ADCANxIP        _ADCAN5IP // interrupt priority for this analog input
#define CLKI_ANxRDY          _AN5RDY // ADC buffer ready bit
#define _CLKI_ADCANxInterrupt _ADCAN5Interrupt
#define CLKI_ANxTRGSRC       _TRGSRC5 // ADC input trigger source register
#define CLKI_InitAnalog()    {CLKI_ANSEL = 1; CLKI_Write(PINSTATE_HIGH); CLKI_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define CLKI_Dispose()       {CLKI_Write(PINSTATE_HIGH); CLKI_Tris(PINDIR_INPUT); CLKI_ANSEL = 0;} // disposing macro for digital input with analog function
#define CLKI_InitOutput()    {CLKI_Write(PINSTATE_LOW); CLKI_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define CLKI_InitInput()     {CLKI_Write(PINSTATE_HIGH); CLKI_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #18 is RB1 is VIN/VDD sense feedback
#define FB_VIN_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define FB_VIN_GPIO_PORT_PIN   1 // Port Pin Number
#define FB_VIN_Tris(x)         (TRISBbits.TRISB1 = x) // GPIO direction register bit
#define FB_VIN_Write(x)        (LATBbits.LATB1 = x) // GPIO port latch register bit
#define FB_VIN_Read()          PORTBbits.RB1 // GPIO port register bit
#define FB_VIN_ODC             ODCBbits.ODCB1 // GPIO port open drain configuration register bit
#define FB_VIN_CNPU            CNPUBbits.CNPUB1 // GPIO port pull-up resistor register bit
#define FB_VIN_CNPD            CNPDBbits.CNPDB1 // GPIO port pull-down resistor register bit
#define FB_VIN_CNEN0           CNEN0Bbits.CNEN0B1 // GPIO port change notification Enable register bit
#define FB_VIN_CNSTAT          CNSTATBbits.CNSTATB1 // GPIO port change notification Status register bit
#define FB_VIN_CNEN1           CNEN1Bbits.CNEN1B1 // GPIO port change notification Edge Select Enable register bit
#define FB_VIN_CNF             CNFBbits.CNFB1 // GPIO port change notification flag bit register bit
#define FB_VIN_RP              33 // Number of Remappable Pin
#define _FB_VIN_RPxR           _RP33R // Remappable Pin Register
#define FB_VIN_Set()           { asm volatile ("bset _LATB, #1 \n"); }
#define FB_VIN_Clear()         { asm volatile ("bclr _LATB, #1 \n"); }
#define FB_VIN_Toggle()        { asm volatile ("btg  _LATB, #1 \n"); }
#define FB_VIN_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define FB_VIN_ANSEL           _ANSELB1 // analog/digital pin configuration register bit
#define FB_VIN_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define FB_VIN_IS_SHARED_CORE  false // AN input is routed to a dedicated or shared ACD core
#define FB_VIN_ADCAN           6   // ANx input pin number
#define FB_VIN_ADCBUF          ADCBUF6 // ADC buffer register for this input
#define FB_VIN_ADIE_IEx        ADIELbits.IE6
#define FB_VIN_ADEIE_EIEx      ADEIELbits.EIEN6
#define FB_VIN_ADCANxIF        _ADCAN6IF // interrupt flag bit
#define FB_VIN_ADCANxIE        _ADCAN6IE // interrupt enable bit
#define FB_VIN_ADCANxIP        _ADCAN6IP // interrupt priority for this analog input
#define FB_VIN_ANxRDY          _AN6RDY // ADC buffer ready bit
#define _FB_VIN_ADCANxInterrupt _ADCAN6Interrupt
#define FB_VIN_ANxTRGSRC       _TRGSRC6 // ADC input trigger source register
#define FB_VIN_InitAnalog()    {FB_VIN_ANSEL = 1; FB_VIN_Write(PINSTATE_HIGH); FB_VIN_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define FB_VIN_Dispose()       {FB_VIN_Write(PINSTATE_HIGH); FB_VIN_Tris(PINDIR_INPUT); FB_VIN_ANSEL = 0;} // disposing macro for digital input with analog function
#define FB_VIN_InitOutput()    {FB_VIN_Write(PINSTATE_LOW); FB_VIN_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define FB_VIN_InitInput()     {FB_VIN_Write(PINSTATE_HIGH); FB_VIN_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #19 is RB2 is 4SWBB VOUT sense feedback FB_Vout_4SWBB
#define FB_VOUT_4SWBB_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define FB_VOUT_4SWBB_GPIO_PORT_PIN   2 // Port Pin Number
#define FB_VOUT_4SWBB_Tris(x)         (TRISBbits.TRISB2 = x) // GPIO direction register bit
#define FB_VOUT_4SWBB_Write(x)        (LATBbits.LATB2 = x) // GPIO port latch register bit
#define FB_VOUT_4SWBB_Read()          PORTBbits.RB2 // GPIO port register bit
#define FB_VOUT_4SWBB_ODC             ODCBbits.ODCB2 // GPIO port open drain configuration register bit
#define FB_VOUT_4SWBB_CNPU            CNPUBbits.CNPUB2 // GPIO port pull-up resistor register bit
#define FB_VOUT_4SWBB_CNPD            CNPDBbits.CNPDB2 // GPIO port pull-down resistor register bit
#define FB_VOUT_4SWBB_CNEN0           CNEN0Bbits.CNEN0B2 // GPIO port change notification Enable register bit
#define FB_VOUT_4SWBB_CNSTAT          CNSTATBbits.CNSTATB2 // GPIO port change notification Status register bit
#define FB_VOUT_4SWBB_CNEN1           CNEN1Bbits.CNEN1B2 // GPIO port change notification Edge Select Enable register bit
#define FB_VOUT_4SWBB_CNF             CNFBbits.CNFB2 // GPIO port change notification flag bit register bit
#define FB_VOUT_4SWBB_RP              34 // Number of Remappable Pin
#define _FB_VOUT_4SWBB_RPxR           _RP34R // Remappable Pin Register
#define FB_VOUT_4SWBB_Set()           { asm volatile ("bset _LATB, #2 \n"); }
#define FB_VOUT_4SWBB_Clear()         { asm volatile ("bclr _LATB, #2 \n"); }
#define FB_VOUT_4SWBB_Toggle()        { asm volatile ("btg  _LATB, #2 \n"); }
#define FB_VOUT_4SWBB_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define FB_VOUT_4SWBB_ANSEL           _ANSELB2 // analog/digital pin configuration register bit
#define FB_VOUT_4SWBB_ADCCORE         1 // index starts from zero, last index indicated shared adC core
#define FB_VOUT_4SWBB_IS_SHARED_CORE  false // AN input is routed to a dedicated or shared ACD core
#define FB_VOUT_4SWBB_ADCAN           0   // ANx input pin number
#define FB_VOUT_4SWBB_ADCBUF          ADCBUF1 // ADC buffer register for this input
#define FB_VOUT_4SWBB_ADIE_IEx        ADIELbits.IE1
#define FB_VOUT_4SWBB_ADEIE_EIEx      ADEIELbits.EIEN1
#define FB_VOUT_4SWBB_ADCANxIF        _ADCAN1IF // interrupt flag bit
#define FB_VOUT_4SWBB_ADCANxIE        _ADCAN1IE // interrupt enable bit
#define FB_VOUT_4SWBB_ADCANxIP        _ADCAN1IP // interrupt priority for this analog input
#define FB_VOUT_4SWBB_ANxRDY          _AN1RDY // ADC buffer ready bit
#define _FB_VOUT_4SWBB_ADCANxInterrupt _ADCAN1Interrupt
#define FB_VOUT_4SWBB_ANxTRGSRC       _TRGSRC1 // ADC input trigger source register
#define FB_VOUT_4SWBB_InitAnalog()    {FB_VOUT_4SWBB_ANSEL = 1; FB_VOUT_4SWBB_Write(PINSTATE_HIGH); FB_VOUT_4SWBB_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define FB_VOUT_4SWBB_Dispose()       {FB_VOUT_4SWBB_Write(PINSTATE_HIGH); FB_VOUT_4SWBB_Tris(PINDIR_INPUT); FB_VOUT_4SWBB_ANSEL = 0;} // disposing macro for digital input with analog function
#define FB_VOUT_4SWBB_InitOutput()    {FB_VOUT_4SWBB_Write(PINSTATE_LOW); FB_VOUT_4SWBB_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define FB_VOUT_4SWBB_InitInput()     {FB_VOUT_4SWBB_Write(PINSTATE_HIGH); FB_VOUT_4SWBB_Tris(PINDIR_INPUT);} // initialization macro for digital input
#define FB_VOUT_4SWBB_COMP1_IN_SEL    3U         // A input=0, B input=1 .... D input=3 / RB2 is CMP1D
#define FB_VOUT_4SWBB_COMP2_IN_SEL    3U         // A input=0, B input=1 .... D input=3 / RB2 is CMP2D


// Device Pin #20 is RB3  is is 4SWBB Feedback IOUT (FB_Iout_4SWBB)
#define FB_IOUT_4SWBB_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define FB_IOUT_4SWBB_GPIO_PORT_PIN   3 // Port Pin Number
#define FB_IOUT_4SWBB_Tris(x)         (TRISBbits.TRISB3 = x) // GPIO direction register bit
#define FB_IOUT_4SWBB_Write(x)        (LATBbits.LATB3 = x) // GPIO port latch register bit
#define FB_IOUT_4SWBB_Read()          PORTBbits.RB3 // GPIO port register bit
#define FB_IOUT_4SWBB_ODC             ODCBbits.ODCB3 // GPIO port open drain configuration register bit
#define FB_IOUT_4SWBB_CNPU            CNPUBbits.CNPUB3 // GPIO port pull-up resistor register bit
#define FB_IOUT_4SWBB_CNPD            CNPDBbits.CNPDB3 // GPIO port pull-down resistor register bit
#define FB_IOUT_4SWBB_CNEN0           CNEN0Bbits.CNEN0B3 // GPIO port change notification Enable register bit
#define FB_IOUT_4SWBB_CNSTAT          CNSTATBbits.CNSTATB3 // GPIO port change notification Status register bit
#define FB_IOUT_4SWBB_CNEN1           CNEN1Bbits.CNEN1B3 // GPIO port change notification Edge Select Enable register bit
#define FB_IOUT_4SWBB_CNF             CNFBbits.CNFB3 // GPIO port change notification flag bit register bit
#define FB_IOUT_4SWBB_RP              35 // Number of Remappable Pin
#define _FB_IOUT_4SWBB_RPxR           _RP35R // Remappable Pin Register
#define FB_IOUT_4SWBB_Set()           { asm volatile ("bset _LATB, #3 \n"); }
#define FB_IOUT_4SWBB_Clear()         { asm volatile ("bclr _LATB, #3 \n"); }
#define FB_IOUT_4SWBB_Toggle()        { asm volatile ("btg  _LATB, #3 \n"); }
#define FB_IOUT_4SWBB_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define FB_IOUT_4SWBB_ANSEL           _ANSELB3 // analog/digital pin configuration register bit
#define FB_IOUT_4SWBB_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define FB_IOUT_4SWBB_IS_SHARED_CORE  false // AN input is routed to a dedicated or shared ACD core
#define FB_IOUT_4SWBB_ADCAN           8   // ANx input pin number
#define FB_IOUT_4SWBB_ADCBUF          ADCBUF8 // ADC buffer register for this input
#define FB_IOUT_4SWBB_ADIE_IEx        ADIELbits.IE8
#define FB_IOUT_4SWBB_ADEIE_EIEx      ADEIELbits.EIEN8
#define FB_IOUT_4SWBB_ADCANxIF        _ADCAN8IF // interrupt flag bit
#define FB_IOUT_4SWBB_ADCANxIE        _ADCAN8IE // interrupt enable bit
#define FB_IOUT_4SWBB_ADCANxIP        _ADCAN8IP // interrupt priority for this analog input
#define FB_IOUT_4SWBB_ANxRDY          _AN8RDY // ADC buffer ready bit
#define _FB_IOUT_4SWBB_ADCANxInterrupt _ADCAN8Interrupt
#define FB_IOUT_4SWBB_ANxTRGSRC       _TRGSRC8 // ADC input trigger source register
#define FB_IOUT_4SWBB_InitAnalog()    {FB_IOUT_4SWBB_ANSEL = 1; FB_IOUT_4SWBB_Write(PINSTATE_HIGH); FB_IOUT_4SWBB_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define FB_IOUT_4SWBB_Dispose()       {FB_IOUT_4SWBB_Write(PINSTATE_HIGH); FB_IOUT_4SWBB_Tris(PINDIR_INPUT); FB_IOUT_4SWBB_ANSEL = 0;} // disposing macro for digital input with analog function
#define FB_IOUT_4SWBB_InitOutput()    {FB_IOUT_4SWBB_Write(PINSTATE_LOW); FB_IOUT_4SWBB_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define FB_IOUT_4SWBB_InitInput()     {FB_IOUT_4SWBB_Write(PINSTATE_HIGH); FB_IOUT_4SWBB_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #21 is RB4 is HB LED String Enable signal
#define HIGH_BEAM_EN_GPIO_INSTANCE   1U // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define HIGH_BEAM_EN_GPIO_PORT_PIN   4U // Port Pin Number
#define HIGH_BEAM_EN_Tris(x)         (TRISBbits.TRISB4 = x) // GPIO direction register bit
#define HIGH_BEAM_EN_Write(x)        (LATBbits.LATB4 = x) // GPIO port latch register bit
#define HIGH_BEAM_EN_Read()          PORTBbits.RB4 // GPIO port register bit
#define HIGH_BEAM_EN_TRIS            TRISBbits.TRISB4 // GPIO direction register bit
#define HIGH_BEAM_EN_WR              LATBbits.LATB4 // GPIO port latch register bit
#define HIGH_BEAM_EN_RD              PORTBbits.RB4 // GPIO port register bit
#define HIGH_BEAM_EN_ODC             ODCBbits.ODCB4 // GPIO port open drain configuration register bit
#define HIGH_BEAM_EN_CNPU            CNPUBbits.CNPUB4 // GPIO port pull-up resistor register bit
#define HIGH_BEAM_EN_CNPD            CNPDBbits.CNPDB4 // GPIO port pull-down resistor register bit
#define HIGH_BEAM_EN_CNEN0           CNEN0Bbits.CNEN0B4 // GPIO port change notification Enable register bit
#define HIGH_BEAM_EN_CNSTAT          CNSTATBbits.CNSTATB4 // GPIO port change notification Status register bit
#define HIGH_BEAM_EN_CNEN1           CNEN1Bbits.CNEN1B4 // GPIO port change notification Edge Select Enable register bit
#define HIGH_BEAM_EN_CNF             CNFBbits.CNFB4 // GPIO port change notification flag bit register bit
#define HIGH_BEAM_EN_RP              (uint8_t)36 // Number of Remappable Pin
#define _HIGH_BEAM_EN_RPxR           _RP36R // Remappable Pin Register
#define HIGH_BEAM_EN_Get()           PORTBbits.RB4
#define HIGH_BEAM_EN_Set()           { asm volatile ("bset _LATB, #4 \n"); }
#define HIGH_BEAM_EN_Clear()         { asm volatile ("bclr _LATB, #4 \n"); }
#define HIGH_BEAM_EN_Toggle()        { asm volatile ("btg  _LATB, #4 \n"); }
#define HIGH_BEAM_EN_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define HIGH_BEAM_EN_Dispose()       {HIGH_BEAM_EN_Write(PINSTATE_HIGH); HIGH_BEAM_EN_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define HIGH_BEAM_EN_InitOutput()    {HIGH_BEAM_EN_Write(PINSTATE_LOW); HIGH_BEAM_EN_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define HIGH_BEAM_EN_InitInput()     {HIGH_BEAM_EN_Write(PINSTATE_HIGH); HIGH_BEAM_EN_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #24 is RB5 OK
#define RB5_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define RB5_GPIO_PORT_PIN   5 // Port Pin Number
#define RB5_Tris(x)         (TRISBbits.TRISB5 = x) // GPIO direction register bit
#define RB5_Write(x)        (LATBbits.LATB5 = x) // GPIO port latch register bit
#define RB5_Read()          PORTBbits.RB5 // GPIO port register bit
#define RB5_ODC             ODCBbits.ODCB5 // GPIO port open drain configuration register bit
#define RB5_CNPU            CNPUBbits.CNPUB5 // GPIO port pull-up resistor register bit
#define RB5_CNPD            CNPDBbits.CNPDB5 // GPIO port pull-down resistor register bit
#define RB5_CNEN0           CNEN0Bbits.CNEN0B5 // GPIO port change notification Enable register bit
#define RB5_CNSTAT          CNSTATBbits.CNSTATB5 // GPIO port change notification Status register bit
#define RB5_CNEN1           CNEN1Bbits.CNEN1B5 // GPIO port change notification Edge Select Enable register bit
#define RB5_CNF             CNFBbits.CNFB5 // GPIO port change notification flag bit register bit
#define RB5_RP              37 // Number of Remappable Pin
#define _RB5_RPxR           _RP37R // Remappable Pin Register
#define RB5_Set()           { asm volatile ("bset _LATB, #5 \n"); }
#define RB5_Clear()         { asm volatile ("bclr _LATB, #5 \n"); }
#define RB5_Toggle()        { asm volatile ("btg  _LATB, #5 \n"); }
#define RB5_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define RB5_Dispose()       {RB5_Write(PINSTATE_HIGH); RB5_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define RB5_InitOutput()    {RB5_Write(PINSTATE_LOW); RB5_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define RB5_InitInput()     {RB5_Write(PINSTATE_HIGH); RB5_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #25 is RB6 OK
#define RB6_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define RB6_GPIO_PORT_PIN   6 // Port Pin Number
#define RB6_Tris(x)         (TRISBbits.TRISB6 = x) // GPIO direction register bit
#define RB6_Write(x)        (LATBbits.LATB6 = x) // GPIO port latch register bit
#define RB6_Read()          PORTBbits.RB6 // GPIO port register bit
#define RB6_ODC             ODCBbits.ODCB6 // GPIO port open drain configuration register bit
#define RB6_CNPU            CNPUBbits.CNPUB6 // GPIO port pull-up resistor register bit
#define RB6_CNPD            CNPDBbits.CNPDB6 // GPIO port pull-down resistor register bit
#define RB6_CNEN0           CNEN0Bbits.CNEN0B6 // GPIO port change notification Enable register bit
#define RB6_CNSTAT          CNSTATBbits.CNSTATB6 // GPIO port change notification Status register bit
#define RB6_CNEN1           CNEN1Bbits.CNEN1B6 // GPIO port change notification Edge Select Enable register bit
#define RB6_CNF             CNFBbits.CNFB6 // GPIO port change notification flag bit register bit
#define RB6_RP              38 // Number of Remappable Pin
#define _RB6_RPxR           _RP38R // Remappable Pin Register
#define RB6_Set()           { asm volatile ("bset _LATB, #6 \n"); }
#define RB6_Clear()         { asm volatile ("bclr _LATB, #6 \n"); }
#define RB6_Toggle()        { asm volatile ("btg  _LATB, #6 \n"); }
#define RB6_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define RB6_Dispose()       {RB6_Write(PINSTATE_HIGH); RB6_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define RB6_InitOutput()    {RB6_Write(PINSTATE_LOW); RB6_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define RB6_InitInput()     {RB6_Write(PINSTATE_HIGH); RB6_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #26 is RB7 is LOAD_REG_EN signal
#define LOAD_REG_EN_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define LOAD_REG_EN_GPIO_PORT_PIN   7 // Port Pin Number
#define LOAD_REG_EN_Tris(x)         (TRISBbits.TRISB7 = x) // GPIO direction register bit
#define LOAD_REG_EN_Write(x)        (LATBbits.LATB7 = x) // GPIO port latch register bit
#define LOAD_REG_EN_Read()          PORTBbits.RB7 // GPIO port register bit
#define LOAD_REG_EN_ODC             ODCBbits.ODCB7 // GPIO port open drain configuration register bit
#define LOAD_REG_EN_CNPU            CNPUBbits.CNPUB7 // GPIO port pull-up resistor register bit
#define LOAD_REG_EN_CNPD            CNPDBbits.CNPDB7 // GPIO port pull-down resistor register bit
#define LOAD_REG_EN_CNEN0           CNEN0Bbits.CNEN0B7 // GPIO port change notification Enable register bit
#define LOAD_REG_EN_CNSTAT          CNSTATBbits.CNSTATB7 // GPIO port change notification Status register bit
#define LOAD_REG_EN_CNEN1           CNEN1Bbits.CNEN1B7 // GPIO port change notification Edge Select Enable register bit
#define LOAD_REG_EN_CNF             CNFBbits.CNFB7 // GPIO port change notification flag bit register bit
#define LOAD_REG_EN_RP              39 // Number of Remappable Pin
#define _LOAD_REG_EN_RPxR           _RP39R // Remappable Pin Register
#define LOAD_REG_EN_Get()           PORTBbits.RB7
#define LOAD_REG_EN_Set()           { asm volatile ("bset _LATB, #7 \n"); }
#define LOAD_REG_EN_Clear()         { asm volatile ("bclr _LATB, #7 \n"); }
#define LOAD_REG_EN_Toggle()        { asm volatile ("btg  _LATB, #7 \n"); }
#define LOAD_REG_EN_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define LOAD_REG_EN_Dispose()       {LOAD_REG_EN_Write(PINSTATE_HIGH); LOAD_REG_EN_Tris(PINDIR_INPUT);} // disposing macro for digital input with analog function
#define LOAD_REG_EN_InitOutput()    {LOAD_REG_EN_Write(PINSTATE_LOW); LOAD_REG_EN_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define LOAD_REG_EN_InitInput()     {LOAD_REG_EN_Write(PINSTATE_HIGH); LOAD_REG_EN_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #27 is RB8 is I2C SCL
#define SCL_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define SCL_GPIO_PORT_PIN   8 // Port Pin Number
#define SCL_Tris(x)         (TRISBbits.TRISB8 = x) // GPIO direction register bit
#define SCL_Write(x)        (LATBbits.LATB8 = x) // GPIO port latch register bit
#define SCL_Read()          PORTBbits.RB8 // GPIO port register bit
#define SCL_ODC             ODCBbits.ODCB8 // GPIO port open drain configuration register bit
#define SCL_CNPU            CNPUBbits.CNPUB8 // GPIO port pull-up resistor register bit
#define SCL_CNPD            CNPDBbits.CNPDB8 // GPIO port pull-down resistor register bit
#define SCL_CNEN0           CNEN0Bbits.CNEN0B8 // GPIO port change notification Enable register bit
#define SCL_CNSTAT          CNSTATBbits.CNSTATB8 // GPIO port change notification Status register bit
#define SCL_CNEN1           CNEN1Bbits.CNEN1B8 // GPIO port change notification Edge Select Enable register bit
#define SCL_CNF             CNFBbits.CNFB8 // GPIO port change notification flag bit register bit
#define SCL_RP              40 // Number of Remappable Pin
#define _SCL_RPxR           _RP40R // Remappable Pin Register
#define SCL_Set()           { asm volatile ("bset _LATB, #8 \n"); }
#define SCL_Clear()         { asm volatile ("bclr _LATB, #8 \n"); }
#define SCL_Toggle()        { asm volatile ("btg  _LATB, #8 \n"); }
#define SCL_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define SCL_Dispose()       {SCL_Write(PINSTATE_HIGH); SCL_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define SCL_InitOutput()    {SCL_Write(PINSTATE_LOW); SCL_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define SCL_InitInput()     {SCL_Write(PINSTATE_HIGH); SCL_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #28 is RB9 is I2C SDA
#define SDA_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define SDA_GPIO_PORT_PIN   9 // Port Pin Number
#define SDA_Tris(x)         (TRISBbits.TRISB9 = x) // GPIO direction register bit
#define SDA_Write(x)        (LATBbits.LATB9 = x) // GPIO port latch register bit
#define SDA_Read()          PORTBbits.RB9 // GPIO port register bit
#define SDA_ODC             ODCBbits.ODCB9 // GPIO port open drain configuration register bit
#define SDA_CNPU            CNPUBbits.CNPUB9 // GPIO port pull-up resistor register bit
#define SDA_CNPD            CNPDBbits.CNPDB9 // GPIO port pull-down resistor register bit
#define SDA_CNEN0           CNEN0Bbits.CNEN0B9 // GPIO port change notification Enable register bit
#define SDA_CNSTAT          CNSTATBbits.CNSTATB9 // GPIO port change notification Status register bit
#define SDA_CNEN1           CNEN1Bbits.CNEN1B9 // GPIO port change notification Edge Select Enable register bit
#define SDA_CNF             CNFBbits.CNFB9 // GPIO port change notification flag bit register bit
#define SDA_RP              41 // Number of Remappable Pin
#define _SDA_RPxR           _RP41R // Remappable Pin Register
#define SDA_Set()           { asm volatile ("bset _LATB, #9 \n"); }
#define SDA_Clear()         { asm volatile ("bclr _LATB, #9 \n"); }
#define SDA_Toggle()        { asm volatile ("btg  _LATB, #9 \n"); }
#define SDA_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define SDA_Dispose()       {SDA_Write(PINSTATE_HIGH); SDA_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define SDA_InitOutput()    {SDA_Write(PINSTATE_LOW); SDA_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define SDA_InitInput()     {SDA_Write(PINSTATE_HIGH); SDA_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #33 is RB10 is Turn-Indicator Enable
#define TIEN_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define TIEN_GPIO_PORT_PIN   10 // Port Pin Number
#define TIEN_Tris(x)         (TRISBbits.TRISB10 = x) // GPIO direction register bit
#define TIEN_Write(x)        (LATBbits.LATB10 = x) // GPIO port latch register bit
#define TIEN_Read()          PORTBbits.RB10 // GPIO port register bit
#define TIEN_ODC             ODCBbits.ODCB10 // GPIO port open drain configuration register bit
#define TIEN_CNPU            CNPUBbits.CNPUB10 // GPIO port pull-up resistor register bit
#define TIEN_CNPD            CNPDBbits.CNPDB10 // GPIO port pull-down resistor register bit
#define TIEN_CNEN0           CNEN0Bbits.CNEN0B10 // GPIO port change notification Enable register bit
#define TIEN_CNSTAT          CNSTATBbits.CNSTATB10 // GPIO port change notification Status register bit
#define TIEN_CNEN1           CNEN1Bbits.CNEN1B10 // GPIO port change notification Edge Select Enable register bit
#define TIEN_CNF             CNFBbits.CNFB10 // GPIO port change notification flag bit register bit
#define TIEN_RP              42 // Number of Remappable Pin
#define _TIEN_RPxR           _RP42R // Remappable Pin Register
#define TIEN_Set()           { asm volatile ("bset _LATB, #10 \n"); }
#define TIEN_Clear()         { asm volatile ("bclr _LATB, #10 \n"); }
#define TIEN_Toggle()        { asm volatile ("btg  _LATB, #10 \n"); }
#define TIEN_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define TIEN_Dispose()       {TIEN_Write(PINSTATE_HIGH); TIEN_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define TIEN_InitOutput()    {TIEN_Write(PINSTATE_LOW); TIEN_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define TIEN_InitInput()     {TIEN_Write(PINSTATE_HIGH); TIEN_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #34 is RB11 OK
#define PWM_SEPIC_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define PWM_SEPIC_GPIO_PORT_PIN   11 // Port Pin Number
#define PWM_SEPIC_Tris(x)         (TRISBbits.TRISB11 = x) // GPIO direction register bit
#define PWM_SEPIC_Write(x)        (LATBbits.LATB11 = x) // GPIO port latch register bit
#define PWM_SEPIC_Read()          PORTBbits.RB11 // GPIO port register bit
#define PWM_SEPIC_ODC             ODCBbits.ODCB11 // GPIO port open drain configuration register bit
#define PWM_SEPIC_CNPU            CNPUBbits.CNPUB11 // GPIO port pull-up resistor register bit
#define PWM_SEPIC_CNPD            CNPDBbits.CNPDB11 // GPIO port pull-down resistor register bit
#define PWM_SEPIC_CNEN0           CNEN0Bbits.CNEN0B11 // GPIO port change notification Enable register bit
#define PWM_SEPIC_CNSTAT          CNSTATBbits.CNSTATB11 // GPIO port change notification Status register bit
#define PWM_SEPIC_CNEN1           CNEN1Bbits.CNEN1B11 // GPIO port change notification Edge Select Enable register bit
#define PWM_SEPIC_CNF             CNFBbits.CNFB11 // GPIO port change notification flag bit register bit
#define PWM_SEPIC_RP              43 // Number of Remappable Pin
#define _PWM_SEPIC_RPxR           _RP43R // Remappable Pin Register
#define PWM_SEPIC_Set()           { asm volatile ("bset _LATB, #11 \n"); }
#define PWM_SEPIC_Clear()         { asm volatile ("bclr _LATB, #11 \n"); }
#define PWM_SEPIC_Toggle()        { asm volatile ("btg  _LATB, #11 \n"); }
#define PWM_SEPIC_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define PWM_SEPIC_Dispose()       {PWM_SEPIC_Write(PINSTATE_HIGH); PWM_SEPIC_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define PWM_SEPIC_InitOutput()    {PWM_SEPIC_Write(PINSTATE_LOW); PWM_SEPIC_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define PWM_SEPIC_InitInput()     {PWM_SEPIC_Write(PINSTATE_HIGH); PWM_SEPIC_Tris(PINDIR_INPUT);} // initialization macro for digital input
#define PWM_SEPIC_PGxCHANNEL      3 // PWM channel index
#define PWM_SEPIC_PGxPER          PG3PER // PWM channel period register
#define PWM_SEPIC_PGxPHASE        PG3PHASE // PWM channel phase register
#define PWM_SEPIC_PGxDC           PG3DC // PWM channel duty cycle register
#define PWM_SEPIC_PGxDCA          PG3DCA// PWM channel duty cycle A register
#define PWM_SEPIC_PGxDTH          PG3DTH // PWM channel rising edge dead time register
#define PWM_SEPIC_PGxDTL          PG3DTL // PWM channel falling edge dead time register
#define PWM_SEPIC_PGx_OVRENL      PG3IOCONLbits.OVRENL // PWM channel IO config register override low control bit
#define PWM_SEPIC_PGx_PENL        PG3IOCONLbits.PENL // PWM channel IO config register pin enable low control bit
#define PWM_SEPIC_PGxUPDREQ       PG3STATbits.UPDREQ // PWM channel ADC trigger A register
#define PWM_SEPIC_PGxTRIGA        PG3TRIGA // PWM channel ADC trigger A register
#define PWM_SEPIC_PGxTRIGB        PG3TRIGB // PWM channel ADC trigger A register
#define PWM_SEPIC_PGxTRIGC        PG3TRIGC // PWM channel ADC trigger A register
#define PWM_SEPIC_ADTR1OFS        PG3EVTHbits.ADTR1OFS // PWM channel ADC trigger #1 offset setting in PGxEVTH register
#define PWM_SEPIC_ADTR1PS         PG3EVTLbits.ADTR1PS  // PWM channel ADC trigger #1 post scaler setting in PGxEVTL register
#define PWM_SEPIC_PWMxIF          _PWM3IF // interrupt flag bit
#define PWM_SEPIC_PWMxIE          _PWM3IE // interrupt enable bit
#define PWM_SEPIC_PWMxIP          _PWM3IP // interrupt priority for this analog input
#define _PWM_SEPIC_PWMxInterrupt  _PWM3Interrupt // Interrupt Service Routine name declaration
#define PWM_SEPIC_TRGSRC_PWMxTRG1 TRGSRC_PWM3_TRG1 // PWM channel trigger 1
#define PWM_SEPIC_TRGSRC_PWMxTRG2 TRGSRC_PWM3_TRG2 // PWM channel trigger 2

// Device Pin #35 is RB12 is 4SWBB PWM_BOOSTH
#define PWM_BOOSTH_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define PWM_BOOSTH_GPIO_PORT_PIN   12 // Port Pin Number
#define PWM_BOOSTH_Tris(x)         (TRISBbits.TRISB12 = x) // GPIO direction register bit
#define PWM_BOOSTH_Write(x)        (LATBbits.LATB12 = x) // GPIO port latch register bit
#define PWM_BOOSTH_Read()          PORTBbits.RB12 // GPIO port register bit
#define PWM_BOOSTH_ODC             ODCBbits.ODCB12 // GPIO port open drain configuration register bit
#define PWM_BOOSTH_CNPU            CNPUBbits.CNPUB12 // GPIO port pull-up resistor register bit
#define PWM_BOOSTH_CNPD            CNPDBbits.CNPDB12 // GPIO port pull-down resistor register bit
#define PWM_BOOSTH_CNEN0           CNEN0Bbits.CNEN0B12 // GPIO port change notification Enable register bit
#define PWM_BOOSTH_CNSTAT          CNSTATBbits.CNSTATB12 // GPIO port change notification Status register bit
#define PWM_BOOSTH_CNEN1           CNEN1Bbits.CNEN1B12 // GPIO port change notification Edge Select Enable register bit
#define PWM_BOOSTH_CNF             CNFBbits.CNFB12 // GPIO port change notification flag bit register bit
#define PWM_BOOSTH_RP              44 // Number of Remappable Pin
#define _PWM_BOOSTH_RPxR           _RP44R // Remappable Pin Register
#define PWM_BOOSTH_Set()           { asm volatile ("bset _LATB, #12 \n"); }
#define PWM_BOOSTH_Clear()         { asm volatile ("bclr _LATB, #12 \n"); }
#define PWM_BOOSTH_Toggle()        { asm volatile ("btg  _LATB, #12 \n"); }
#define PWM_BOOSTH_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define PWM_BOOSTH_Dispose()       {PWM_BOOSTH_Write(PINSTATE_HIGH); PWM_BOOSTH_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define PWM_BOOSTH_InitOutput()    {PWM_BOOSTH_Write(PINSTATE_LOW); PWM_BOOSTH_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define PWM_BOOSTH_InitInput()     {PWM_BOOSTH_Write(PINSTATE_HIGH); PWM_BOOSTH_Tris(PINDIR_INPUT);} // initialization macro for digital input
#define PWM_BOOSTH_PGxCHANNEL      2 // PWM channel index
#define PWM_BOOSTH_PGxPER          PG2PER // PWM channel period register
#define PWM_BOOSTH_PGxPHASE        PG2PHASE // PWM channel phase register
#define PWM_BOOSTH_PGxDC           PG2DC // PWM channel duty cycle register
#define PWM_BOOSTH_PGxDCA          PG2DCA// PWM channel duty cycle A register
#define PWM_BOOSTH_PGxDTH          PG2DTH // PWM channel rising edge dead time register
#define PWM_BOOSTH_PGxDTL          PG2DTL // PWM channel falling edge dead time register
#define PWM_BOOSTH_PGx_OVRENH      PG2IOCONLbits.OVRENH // PWM channel IO config register override high control bit
#define PWM_BOOSTH_PGx_PENH        PG2IOCONLbits.PENH // PWM channel IO config register pin enable high control bit
#define PWM_BOOSTH_PGxUPDREQ       PG2STATbits.UPDREQ // PWM channel ADC trigger A register
#define PWM_BOOSTH_PGxTRIGA        PG2TRIGA // PWM channel ADC trigger A register
#define PWM_BOOSTH_PGxTRIGB        PG2TRIGB // PWM channel ADC trigger A register
#define PWM_BOOSTH_PGxTRIGC        PG2TRIGC // PWM channel ADC trigger A register
#define PWM_BOOSTH_ADTR1OFS        PG2EVTHbits.ADTR1OFS // PWM channel ADC trigger #1 offset setting in PGxEVTH register
#define PWM_BOOSTH_ADTR1PS         PG2EVTLbits.ADTR1PS  // PWM channel ADC trigger #1 post scaler setting in PGxEVTL register
#define PWM_BOOSTH_PWMxIF          _PWM2IF // interrupt flag bit
#define PWM_BOOSTH_PWMxIE          _PWM2IE // interrupt enable bit
#define PWM_BOOSTH_PWMxIP          _PWM2IP // interrupt priority for this analog input
#define _PWM_BOOSTH_PWMxInterrupt  _PWM2Interrupt // Interrupt Service Routine name declaration
#define PWM_BOOSTH_TRGSRC_PWMxTRG1 TRGSRC_PWM2_TRG1 // PWM channel trigger 1
#define PWM_BOOSTH_TRGSRC_PWMxTRG2 TRGSRC_PWM2_TRG2 // PWM channel trigger 2

// Device Pin #36 is RB13 is 4SWBB PWM_BOOSTL
#define PWM_BOOSTL_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define PWM_BOOSTL_GPIO_PORT_PIN   13 // Port Pin Number
#define PWM_BOOSTL_Tris(x)         (TRISBbits.TRISB13 = x) // GPIO direction register bit
#define PWM_BOOSTL_Write(x)        (LATBbits.LATB13 = x) // GPIO port latch register bit
#define PWM_BOOSTL_Read()          PORTBbits.RB13 // GPIO port register bit
#define PWM_BOOSTL_ODC             ODCBbits.ODCB13 // GPIO port open drain configuration register bit
#define PWM_BOOSTL_CNPU            CNPUBbits.CNPUB13 // GPIO port pull-up resistor register bit
#define PWM_BOOSTL_CNPD            CNPDBbits.CNPDB13 // GPIO port pull-down resistor register bit
#define PWM_BOOSTL_CNEN0           CNEN0Bbits.CNEN0B13 // GPIO port change notification Enable register bit
#define PWM_BOOSTL_CNSTAT          CNSTATBbits.CNSTATB13 // GPIO port change notification Status register bit
#define PWM_BOOSTL_CNEN1           CNEN1Bbits.CNEN1B13 // GPIO port change notification Edge Select Enable register bit
#define PWM_BOOSTL_CNF             CNFBbits.CNFB13 // GPIO port change notification flag bit register bit
#define PWM_BOOSTL_RP              45 // Number of Remappable Pin
#define _PWM_BOOSTL_RPxR           _RP45R // Remappable Pin Register
#define PWM_BOOSTL_Set()           { asm volatile ("bset _LATB, #13 \n"); }
#define PWM_BOOSTL_Clear()         { asm volatile ("bclr _LATB, #13 \n"); }
#define PWM_BOOSTL_Toggle()        { asm volatile ("btg  _LATB, #13 \n"); }
#define PWM_BOOSTL_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define PWM_BOOSTL_Dispose()       {PWM_BOOSTL_Write(PINSTATE_HIGH); PWM_BOOSTL_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define PWM_BOOSTL_InitOutput()    {PWM_BOOSTL_Write(PINSTATE_LOW); PWM_BOOSTL_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define PWM_BOOSTL_InitInput()     {PWM_BOOSTL_Write(PINSTATE_HIGH); PWM_BOOSTL_Tris(PINDIR_INPUT);} // initialization macro for digital input
#define PWM_BOOSTL_PGxCHANNEL      2 // PWM channel index
#define PWM_BOOSTL_PGxPER          PG2PER // PWM channel period register
#define PWM_BOOSTL_PGxPHASE        PG2PHASE // PWM channel phase register
#define PWM_BOOSTL_PGxDC           PG2DC // PWM channel duty cycle register
#define PWM_BOOSTL_PGxDCA          PG2DCA// PWM channel duty cycle A register
#define PWM_BOOSTL_PGxDTH          PG2DTH // PWM channel rising edge dead time register
#define PWM_BOOSTL_PGxDTL          PG2DTL // PWM channel falling edge dead time register
#define PWM_BOOSTL_PGx_OVRENL      PG2IOCONLbits.OVRENL // PWM channel IO config register override low control bit
#define PWM_BOOSTL_PGx_PENL        PG2IOCONLbits.PENL // PWM channel IO config register pin enable low control bit
#define PWM_BOOSTL_PGxUPDREQ       PG2STATbits.UPDREQ // PWM channel ADC trigger A register
#define PWM_BOOSTL_PGxTRIGA        PG2TRIGA // PWM channel ADC trigger A register
#define PWM_BOOSTL_PGxTRIGB        PG2TRIGB // PWM channel ADC trigger A register
#define PWM_BOOSTL_PGxTRIGC        PG2TRIGC // PWM channel ADC trigger A register
#define PWM_BOOSTL_ADTR1OFS        PG2EVTHbits.ADTR1OFS // PWM channel ADC trigger #1 offset setting in PGxEVTH register
#define PWM_BOOSTL_ADTR1PS         PG2EVTLbits.ADTR1PS  // PWM channel ADC trigger #1 post scaler setting in PGxEVTL register

// Device Pin #1 is RB14 is PWM_BUCKH
#define PWM_BUCKH_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define PWM_BUCKH_GPIO_PORT_PIN   14 // Port Pin Number
#define PWM_BUCKH_Tris(x)         (TRISBbits.TRISB14 = x) // GPIO direction register bit
#define PWM_BUCKH_Write(x)        (LATBbits.LATB14 = x) // GPIO port latch register bit
#define PWM_BUCKH_Read()          PORTBbits.RB14 // GPIO port register bit
#define PWM_BUCKH_ODC             ODCBbits.ODCB14 // GPIO port open drain configuration register bit
#define PWM_BUCKH_CNPU            CNPUBbits.CNPUB14 // GPIO port pull-up resistor register bit
#define PWM_BUCKH_CNPD            CNPDBbits.CNPDB14 // GPIO port pull-down resistor register bit
#define PWM_BUCKH_CNEN0           CNEN0Bbits.CNEN0B14 // GPIO port change notification Enable register bit
#define PWM_BUCKH_CNSTAT          CNSTATBbits.CNSTATB14 // GPIO port change notification Status register bit
#define PWM_BUCKH_CNEN1           CNEN1Bbits.CNEN1B14 // GPIO port change notification Edge Select Enable register bit
#define PWM_BUCKH_CNF             CNFBbits.CNFB14 // GPIO port change notification flag bit register bit
#define PWM_BUCKH_RP              46 // Number of Remappable Pin
#define _PWM_BUCKH_RPxR           _RP46R // Remappable Pin Register
#define PWM_BUCKH_Set()           { asm volatile ("bset _LATB, #14 \n"); }
#define PWM_BUCKH_Clear()         { asm volatile ("bclr _LATB, #14 \n"); }
#define PWM_BUCKH_Toggle()        { asm volatile ("btg  _LATB, #14 \n"); }
#define PWM_BUCKH_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define PWM_BUCKH_Dispose()       {PWM_BUCKH_Write(PINSTATE_HIGH); PWM_BUCKH_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define PWM_BUCKH_InitOutput()    {PWM_BUCKH_Write(PINSTATE_LOW); PWM_BUCKH_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define PWM_BUCKH_InitInput()     {PWM_BUCKH_Write(PINSTATE_HIGH); PWM_BUCKH_Tris(PINDIR_INPUT);} // initialization macro for digital input
#define PWM_BUCKH_PGxCHANNEL      1 // PWM channel index
#define PWM_BUCKH_PGxPER          PG1PER // PWM channel period register
#define PWM_BUCKH_PGxPHASE        PG1PHASE // PWM channel phase register
#define PWM_BUCKH_PGxDC           PG1DC // PWM channel duty cycle register
#define PWM_BUCKH_PGxDCA          PG1DCA// PWM channel duty cycle A register
#define PWM_BUCKH_PGxDTH          PG1DTH // PWM channel rising edge dead time register
#define PWM_BUCKH_PGxDTL          PG1DTL // PWM channel falling edge dead time register
#define PWM_BUCKH_PGx_OVRENH      PG1IOCONLbits.OVRENH // PWM channel IO config register override high control bit
#define PWM_BUCKH_PGx_PENH        PG1IOCONLbits.PENH // PWM channel IO config register pin enable high control bit
#define PWM_BUCKH_PGxUPDREQ       PG1STATbits.UPDREQ // PWM channel ADC trigger A register
#define PWM_BUCKH_PGxTRIGA        PG1TRIGA // PWM channel ADC trigger A register
#define PWM_BUCKH_PGxTRIGB        PG1TRIGB // PWM channel ADC trigger A register
#define PWM_BUCKH_PGxTRIGC        PG1TRIGC // PWM channel ADC trigger A register
#define PWM_BUCKH_ADTR1OFS        PG1EVTHbits.ADTR1OFS // PWM channel ADC trigger #1 offset setting in PGxEVTH register
#define PWM_BUCKH_ADTR1PS         PG1EVTLbits.ADTR1PS  // PWM channel ADC trigger #1 post scaler setting in PGxEVTL register
#define PWM_BUCKH_PWMxIF          _PWM1IF // interrupt flag bit
#define PWM_BUCKH_PWMxIE          _PWM1IE // interrupt enable bit
#define PWM_BUCKH_PWMxIP          _PWM1IP // interrupt priority for this analog input
#define _PWM_BUCKH_PWMxInterrupt  _PWM1Interrupt // Interrupt Service Routine name declaration
#define PWM_BUCKH_TRGSRC_PWMxTRG1 TRGSRC_PWM1_TRG1 // PWM channel trigger 1
#define PWM_BUCKH_TRGSRC_PWMxTRG2 TRGSRC_PWM1_TRG2 // PWM channel trigger 2

// Device Pin #2 is RB15 is 4SWBB PWM_BUCKL
#define PWM_BUCKL_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define PWM_BUCKL_GPIO_PORT_PIN   15 // Port Pin Number
#define PWM_BUCKL_Tris(x)         (TRISBbits.TRISB15 = x) // GPIO direction register bit
#define PWM_BUCKL_Write(x)        (LATBbits.LATB15 = x) // GPIO port latch register bit
#define PWM_BUCKL_Read()          PORTBbits.RB15 // GPIO port register bit
#define PWM_BUCKL_ODC             ODCBbits.ODCB15 // GPIO port open drain configuration register bit
#define PWM_BUCKL_CNPU            CNPUBbits.CNPUB15 // GPIO port pull-up resistor register bit
#define PWM_BUCKL_CNPD            CNPDBbits.CNPDB15 // GPIO port pull-down resistor register bit
#define PWM_BUCKL_CNEN0           CNEN0Bbits.CNEN0B15 // GPIO port change notification Enable register bit
#define PWM_BUCKL_CNSTAT          CNSTATBbits.CNSTATB15 // GPIO port change notification Status register bit
#define PWM_BUCKL_CNEN1           CNEN1Bbits.CNEN1B15 // GPIO port change notification Edge Select Enable register bit
#define PWM_BUCKL_CNF             CNFBbits.CNFB15 // GPIO port change notification flag bit register bit
#define PWM_BUCKL_RP              47 // Number of Remappable Pin
#define _PWM_BUCKL_RPxR           _RP47R // Remappable Pin Register
#define PWM_BUCKL_Set()           { asm volatile ("bset _LATB, #15 \n"); }
#define PWM_BUCKL_Clear()         { asm volatile ("bclr _LATB, #15 \n"); }
#define PWM_BUCKL_Toggle()        { asm volatile ("btg  _LATB, #15 \n"); }
#define PWM_BUCKL_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define PWM_BUCKL_Dispose()       {PWM_BUCKL_Write(PINSTATE_HIGH); PWM_BUCKL_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define PWM_BUCKL_InitOutput()    {PWM_BUCKL_Write(PINSTATE_LOW); PWM_BUCKL_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define PWM_BUCKL_InitInput()     {PWM_BUCKL_Write(PINSTATE_HIGH); PWM_BUCKL_Tris(PINDIR_INPUT);} // initialization macro for digital input
#define PWM_BUCKL_PGxCHANNEL      1 // PWM channel index
#define PWM_BUCKL_PGxPER          PG1PER // PWM channel period register
#define PWM_BUCKL_PGxPHASE        PG1PHASE // PWM channel phase register
#define PWM_BUCKL_PGxDC           PG1DC // PWM channel duty cycle register
#define PWM_BUCKL_PGxDCA          PG1DCA// PWM channel duty cycle A register
#define PWM_BUCKL_PGxDTH          PG1DTH // PWM channel rising edge dead time register
#define PWM_BUCKL_PGxDTL          PG1DTL // PWM channel falling edge dead time register
#define PWM_BUCKL_PGx_OVRENL      PG1IOCONLbits.OVRENL // PWM channel IO config register override low control bit
#define PWM_BUCKL_PGx_PENL        PG1IOCONLbits.PENL // PWM channel IO config register pin enable low control bit
#define PWM_BUCKL_PGxUPDREQ       PG1STATbits.UPDREQ // PWM channel ADC trigger A register
#define PWM_BUCKL_PGxTRIGA        PG1TRIGA // PWM channel ADC trigger A register
#define PWM_BUCKL_PGxTRIGB        PG1TRIGB // PWM channel ADC trigger A register
#define PWM_BUCKL_PGxTRIGC        PG1TRIGC // PWM channel ADC trigger A register
#define PWM_BUCKL_ADTR1OFS        PG1EVTHbits.ADTR1OFS // PWM channel ADC trigger #1 offset setting in PGxEVTH register
#define PWM_BUCKL_ADTR1PS         PG1EVTLbits.ADTR1PS  // PWM channel ADC trigger #1 post scaler setting in PGxEVTL register

// Device Pin #4 is RC0 OK
#define USERSW_GPIO_INSTANCE   2 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define USERSW_GPIO_PORT_PIN   0 // Port Pin Number
#define USERSW_Tris(x)         (TRISCbits.TRISC0 = x) // GPIO direction register bit
#define USERSW_Write(x)        (LATCbits.LATC0 = x) // GPIO port latch register bit
#define USERSW_Read()          PORTCbits.RC0 // GPIO port register bit
#define USERSW_ODC             ODCCbits.ODCC0 // GPIO port open drain configuration register bit
#define USERSW_CNPU            CNPUCbits.CNPUC0 // GPIO port pull-up resistor register bit
#define USERSW_CNPD            CNPDCbits.CNPDC0 // GPIO port pull-down resistor register bit
#define USERSW_CNEN0           CNEN0Cbits.CNEN0C0 // GPIO port change notification Enable register bit
#define USERSW_CNSTAT          CNSTATCbits.CNSTATC0 // GPIO port change notification Status register bit
#define USERSW_CNEN1           CNEN1Cbits.CNEN1C0 // GPIO port change notification Edge Select Enable register bit
#define USERSW_CNF             CNFCbits.CNFC0 // GPIO port change notification flag bit register bit
#define USERSW_RP              48 // Number of Remappable Pin
#define _USERSW_RPxR           _RP48R // Remappable Pin Register
#define USERSW_Set()           { asm volatile ("bset _LATC, #0 \n"); }
#define USERSW_Clear()         { asm volatile ("bclr _LATC, #0 \n"); }
#define USERSW_Toggle()        { asm volatile ("btg  _LATC, #0 \n"); }
#define USERSW_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define USERSW_Dispose()       {USERSW_Write(PINSTATE_HIGH); USERSW_Tris(PINDIR_INPUT);} // disposing macro for digital input with analog function
#define USERSW_InitOutput()    {USERSW_Write(PINSTATE_LOW); USERSW_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define USERSW_InitInput()     {USERSW_Write(PINSTATE_HIGH); USERSW_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #12 is RC1 OK
#define CANRX_GPIO_INSTANCE   2 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define CANRX_GPIO_PORT_PIN   1 // Port Pin Number
#define CANRX_Tris(x)         (TRISCbits.TRISC1 = x) // GPIO direction register bit
#define CANRX_Write(x)        (LATCbits.LATC1 = x) // GPIO port latch register bit
#define CANRX_Read()          PORTCbits.RC1 // GPIO port register bit
#define CANRX_ODC             ODCCbits.ODCC1 // GPIO port open drain configuration register bit
#define CANRX_CNPU            CNPUCbits.CNPUC1 // GPIO port pull-up resistor register bit
#define CANRX_CNPD            CNPDCbits.CNPDC1 // GPIO port pull-down resistor register bit
#define CANRX_CNEN0           CNEN0Cbits.CNEN0C1 // GPIO port change notification Enable register bit
#define CANRX_CNSTAT          CNSTATCbits.CNSTATC1 // GPIO port change notification Status register bit
#define CANRX_CNEN1           CNEN1Cbits.CNEN1C1 // GPIO port change notification Edge Select Enable register bit
#define CANRX_CNF             CNFCbits.CNFC1 // GPIO port change notification flag bit register bit
#define CANRX_RP              49 // Number of Remappable Pin
#define _CANRX_RPxR           _RP49R // Remappable Pin Register
#define CANRX_Set()           { asm volatile ("bset _LATC, #1 \n"); }
#define CANRX_Clear()         { asm volatile ("bclr _LATC, #1 \n"); }
#define CANRX_Toggle()        { asm volatile ("btg  _LATC, #1 \n"); }
#define CANRX_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define CANRX_Dispose()       {CANRX_Write(PINSTATE_HIGH); CANRX_Tris(PINDIR_INPUT);} // disposing macro for digital input with analog function
#define CANRX_InitOutput()    {CANRX_Write(PINSTATE_LOW); CANRX_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define CANRX_InitInput()     {CANRX_Write(PINSTATE_HIGH); CANRX_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #13 is RC2 OK
#define CANTX_GPIO_INSTANCE   2 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define CANTX_GPIO_PORT_PIN   2 // Port Pin Number
#define CANTX_Tris(x)         (TRISCbits.TRISC2 = x) // GPIO direction register bit
#define CANTX_Write(x)        (LATCbits.LATC2 = x) // GPIO port latch register bit
#define CANTX_Read()          PORTCbits.RC2 // GPIO port register bit
#define CANTX_ODC             ODCCbits.ODCC2 // GPIO port open drain configuration register bit
#define CANTX_CNPU            CNPUCbits.CNPUC2 // GPIO port pull-up resistor register bit
#define CANTX_CNPD            CNPDCbits.CNPDC2 // GPIO port pull-down resistor register bit
#define CANTX_CNEN0           CNEN0Cbits.CNEN0C2 // GPIO port change notification Enable register bit
#define CANTX_CNSTAT          CNSTATCbits.CNSTATC2 // GPIO port change notification Status register bit
#define CANTX_CNEN1           CNEN1Cbits.CNEN1C2 // GPIO port change notification Edge Select Enable register bit
#define CANTX_CNF             CNFCbits.CNFC2 // GPIO port change notification flag bit register bit
#define CANTX_RP              50 // Number of Remappable Pin
#define _CANTX_RPxR           _RP50R // Remappable Pin Register
#define CANTX_Set()           { asm volatile ("bset _LATC, #2 \n"); }
#define CANTX_Clear()         { asm volatile ("bclr _LATC, #2 \n"); }
#define CANTX_Toggle()        { asm volatile ("btg  _LATC, #2 \n"); }
#define CANTX_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define CANTX_Dispose()       {CANTX_Write(PINSTATE_HIGH); CANTX_Tris(PINDIR_INPUT);} // disposing macro for digital input with analog function
#define CANTX_InitOutput()    {CANTX_Write(PINSTATE_LOW); CANTX_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define CANTX_InitInput()     {CANTX_Write(PINSTATE_HIGH); CANTX_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #16 is RC3 OK
#define ENCAN_GPIO_INSTANCE   2 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define ENCAN_GPIO_PORT_PIN   3 // Port Pin Number
#define ENCAN_Tris(x)         (TRISCbits.TRISC3 = x) // GPIO direction register bit
#define ENCAN_Write(x)        (LATCbits.LATC3 = x) // GPIO port latch register bit
#define ENCAN_Read()          PORTCbits.RC3 // GPIO port register bit
#define ENCAN_ODC             ODCCbits.ODCC3 // GPIO port open drain configuration register bit
#define ENCAN_CNPU            CNPUCbits.CNPUC3 // GPIO port pull-up resistor register bit
#define ENCAN_CNPD            CNPDCbits.CNPDC3 // GPIO port pull-down resistor register bit
#define ENCAN_CNEN0           CNEN0Cbits.CNEN0C3 // GPIO port change notification Enable register bit
#define ENCAN_CNSTAT          CNSTATCbits.CNSTATC3 // GPIO port change notification Status register bit
#define ENCAN_CNEN1           CNEN1Cbits.CNEN1C3 // GPIO port change notification Edge Select Enable register bit
#define ENCAN_CNF             CNFCbits.CNFC3 // GPIO port change notification flag bit register bit
#define ENCAN_RP              51 // Number of Remappable Pin
#define _ENCAN_RPxR           _RP51R // Remappable Pin Register
#define ENCAN_Set()           { asm volatile ("bset _LATC, #3 \n"); }
#define ENCAN_Clear()         { asm volatile ("bclr _LATC, #3 \n"); }
#define ENCAN_Toggle()        { asm volatile ("btg  _LATC, #3 \n"); }
#define ENCAN_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define ENCAN_Dispose()       {ENCAN_Write(PINSTATE_HIGH); ENCAN_Tris(PINDIR_INPUT);} // disposing macro for digital input with analog function
#define ENCAN_InitOutput()    {ENCAN_Write(PINSTATE_LOW); ENCAN_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define ENCAN_InitInput()     {ENCAN_Write(PINSTATE_HIGH); ENCAN_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #29 is RC4 OK
#define DRLEN_GPIO_INSTANCE   2 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define DRLEN_GPIO_PORT_PIN   4 // Port Pin Number
#define DRLEN_Tris(x)         (TRISCbits.TRISC4 = x) // GPIO direction register bit
#define DRLEN_Write(x)        (LATCbits.LATC4 = x) // GPIO port latch register bit
#define DRLEN_Read()          PORTCbits.RC4 // GPIO port register bit
#define DRLEN_ODC             ODCCbits.ODCC4 // GPIO port open drain configuration register bit
#define DRLEN_CNPU            CNPUCbits.CNPUC4 // GPIO port pull-up resistor register bit
#define DRLEN_CNPD            CNPDCbits.CNPDC4 // GPIO port pull-down resistor register bit
#define DRLEN_CNEN0           CNEN0Cbits.CNEN0C4 // GPIO port change notification Enable register bit
#define DRLEN_CNSTAT          CNSTATCbits.CNSTATC4 // GPIO port change notification Status register bit
#define DRLEN_CNEN1           CNEN1Cbits.CNEN1C4 // GPIO port change notification Edge Select Enable register bit
#define DRLEN_CNF             CNFCbits.CNFC4 // GPIO port change notification flag bit register bit
#define DRLEN_RP              52 // Number of Remappable Pin
#define _DRLEN_RPxR           _RP52R // Remappable Pin Register
#define DRLEN_Set()           { asm volatile ("bset _LATC, #4 \n"); }
#define DRLEN_Clear()         { asm volatile ("bclr _LATC, #4 \n"); }
#define DRLEN_Toggle()        { asm volatile ("btg  _LATC, #4 \n"); }
#define DRLEN_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define DRLEN_Dispose()       {DRLEN_Write(PINSTATE_HIGH); DRLEN_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define DRLEN_InitOutput()    {DRLEN_Write(PINSTATE_LOW); DRLEN_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define DRLEN_InitInput()     {DRLEN_Write(PINSTATE_HIGH); DRLEN_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #30 is RC5 is debug red LED output
#define DBGLED_GPIO_INSTANCE   2 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define DBGLED_GPIO_PORT_PIN   5 // Port Pin Number
#define DBGLED_Tris(x)         (TRISCbits.TRISC5 = x) // GPIO direction register bit
#define DBGLED_Write(x)        (LATCbits.LATC5 = x) // GPIO port latch register bit
#define DBGLED_Read()          PORTCbits.RC5 // GPIO port register bit
#define DBGLED_ODC             ODCCbits.ODCC5 // GPIO port open drain configuration register bit
#define DBGLED_CNPU            CNPUCbits.CNPUC5 // GPIO port pull-up resistor register bit
#define DBGLED_CNPD            CNPDCbits.CNPDC5 // GPIO port pull-down resistor register bit
#define DBGLED_CNEN0           CNEN0Cbits.CNEN0C5 // GPIO port change notification Enable register bit
#define DBGLED_CNSTAT          CNSTATCbits.CNSTATC5 // GPIO port change notification Status register bit
#define DBGLED_CNEN1           CNEN1Cbits.CNEN1C5 // GPIO port change notification Edge Select Enable register bit
#define DBGLED_CNF             CNFCbits.CNFC5 // GPIO port change notification flag bit register bit
#define DBGLED_RP              53 // Number of Remappable Pin
#define _DBGLED_RPxR           _RP53R // Remappable Pin Register
#define DBGLED_Set()           { asm volatile ("bset _LATC, #5 \n"); }
#define DBGLED_Clear()         { asm volatile ("bclr _LATC, #5 \n"); }
#define DBGLED_Toggle()        { asm volatile ("btg  _LATC, #5 \n"); }
#define DBGLED_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define DBGLED_Dispose()       {DBGLED_Write(PINSTATE_HIGH); DBGLED_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define DBGLED_InitOutput()    {DBGLED_Write(PINSTATE_LOW); DBGLED_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define DBGLED_InitInput()     {DBGLED_Write(PINSTATE_HIGH); DBGLED_Tris(PINDIR_INPUT);} // initialization macro for digital input
#define DBGLED_PGxCHANNEL      5 // PWM channel index
#define DBGLED_PGxPER          PG5PER // PWM channel period register
#define DBGLED_PGxPHASE        PG5PHASE // PWM channel phase register
#define DBGLED_PGxDC           PG5DC // PWM channel duty cycle register
#define DBGLED_PGxDCA          PG5DCA// PWM channel duty cycle A register
#define DBGLED_PGxDTH          PG5DTH // PWM channel rising edge dead time register
#define DBGLED_PGxDTL          PG5DTL // PWM channel falling edge dead time register
#define DBGLED_PGx_OVRENH      PG5IOCONLbits.OVRENH // PWM channel IO config register override high control bit
#define DBGLED_PGx_PENH        PG5IOCONLbits.PENH // PWM channel IO config register pin enable high control bit
#define DBGLED_PGxUPDREQ       PG5STATbits.UPDREQ // PWM channel ADC trigger A register
#define DBGLED_PGxTRIGA        PG5TRIGA // PWM channel ADC trigger A register
#define DBGLED_PGxTRIGB        PG5TRIGB // PWM channel ADC trigger A register
#define DBGLED_PGxTRIGC        PG5TRIGC // PWM channel ADC trigger A register
#define DBGLED_ADTR1OFS        PG5EVTHbits.ADTR1OFS // PWM channel ADC trigger #1 offset setting in PGxEVTH register
#define DBGLED_ADTR1PS         PG5EVTLbits.ADTR1PS  // PWM channel ADC trigger #1 post scaler setting in PGxEVTL register
#define DBGLED_PWMxIF          _PWM5IF // interrupt flag bit
#define DBGLED_PWMxIE          _PWM5IE // interrupt enable bit
#define DBGLED_PWMxIP          _PWM5IP // interrupt priority for this analog input
#define _DBGLED_PWMxInterrupt  _PWM5Interrupt // Interrupt Service Routine name declaration
#define DBGLED_TRGSRC_PWMxTRG1 TRGSRC_PWM5_TRG1 // PWM channel trigger 1
#define DBGLED_TRGSRC_PWMxTRG2 TRGSRC_PWM5_TRG2 // PWM channel trigger 2

/** @} */ // end of group device-abstraction-pinmap

#endif	/* __LEAH_P33CK_HostMCU_R10_PINMAP_H__ */
