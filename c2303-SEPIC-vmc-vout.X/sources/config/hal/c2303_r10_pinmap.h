/* ***********************************************************************************************
 * File:           c2303_r10_pinmap.h 
 * Author:         M24683                                                                     
 * Comments:       Hardware abstraction layer device pinout descriptor                            
 * Board ID:       C2303 Board                                                                  
 * Product-No:     N/A                                                               
 * Device ID:      P33CK                                                                    
 * Board Revision: 10                                                                  
 * Date:           25/02/2024                                                                                                                                              
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
#ifndef __c2303_R10_PINMAP_H__
#define __c2303_R10_PINMAP_H__

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

#ifndef __c2303_PINMAP_R10__ // hardware indentifier macro using the product number
#define __c2303_R10_PINMAP__ // hardware version is encoded by R<MAJOR><MINOR> (e.g. revision 2.1 = R21)
#endif

#ifndef __c2303_PINMAP_VERSION // hardware version as integer number
#define __c2303_PINMAP_VERSION 10 // is encoded by <MAJOR><MINOR> (e.g. revision 2.1 = R21)
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

// Device Pin #14 is RA0 is SEPIC Feedback IOUT (going through OPAMP1 output) / Primary inductor current sense
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
#define FB_IOUT_SEPIC_COMP1_IN_SEL    0U         // A input=0, B input=1 .... D input=3 / RA0 is CMP1A

// Device Pin #15 is RA1 is OPAMP1 negative input ISN- for IOUT current sense on SEPIC
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


// Device Pin #16 is RA2 is OPAMP1 positive input ISN+ for IOUT current sense on SEPIC
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
#define ISNP_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
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


// Device Pin #17 is RA3 is EOL_VOLTAGEB
#define EOL_VOLTAGEB_GPIO_INSTANCE   0 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define EOL_VOLTAGEB_GPIO_PORT_PIN   3 // Port Pin Number
#define EOL_VOLTAGEB_Tris(x)         (TRISAbits.TRISA3 = x) // GPIO direction register bit
#define EOL_VOLTAGEB_Write(x)        (LATAbits.LATA3 = x) // GPIO port latch register bit
#define EOL_VOLTAGEB_Read()          PORTAbits.RA3 // GPIO port register bit
#define EOL_VOLTAGEB_ODC             ODCAbits.ODCA3 // GPIO port open drain configuration register bit
#define EOL_VOLTAGEB_CNPU            CNPUAbits.CNPUA3 // GPIO port pull-up resistor register bit
#define EOL_VOLTAGEB_CNPD            CNPDAbits.CNPDA3 // GPIO port pull-down resistor register bit
#define EOL_VOLTAGEB_CNEN0           CNEN0Abits.CNEN0A3 // GPIO port change notification Enable register bit
#define EOL_VOLTAGEB_CNSTAT          CNSTATAbits.CNSTATA3 // GPIO port change notification Status register bit
#define EOL_VOLTAGEB_CNEN1           CNEN1Abits.CNEN1A3 // GPIO port change notification Edge Select Enable register bit
#define EOL_VOLTAGEB_CNF             CNFAbits.CNFA3 // GPIO port change notification flag bit register bit
#define EOL_VOLTAGEB_Set()           { asm volatile ("bset _LATA, #3 \n"); }
#define EOL_VOLTAGEB_Clear()         { asm volatile ("bclr _LATA, #3 \n"); }
#define EOL_VOLTAGEB_Toggle()        { asm volatile ("btg  _LATA, #3 \n"); }
#define EOL_VOLTAGEB_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define EOL_VOLTAGEB_ANSEL           _ANSELA3 // analog/digital pin configuration register bit
#define EOL_VOLTAGEB_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define EOL_VOLTAGEB_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
#define EOL_VOLTAGEB_ADCAN           3   // ANx input pin number
#define EOL_VOLTAGEB_ADCBUF          ADCBUF3 // ADC buffer register for this input
#define EOL_VOLTAGEB_ADIE_IEx        ADIELbits.IE3
#define EOL_VOLTAGEB_ADEIE_EIEx      ADEIELbits.EIEN3
#define EOL_VOLTAGEB_ADCANxIF        _ADCAN3IF // interrupt flag bit
#define EOL_VOLTAGEB_ADCANxIE        _ADCAN3IE // interrupt enable bit
#define EOL_VOLTAGEB_ADCANxIP        _ADCAN3IP // interrupt priority for this analog input
#define EOL_VOLTAGEB_ANxRDY          _AN3RDY // ADC buffer ready bit
#define _EOL_VOLTAGEB_ADCANxInterrupt _ADCAN3Interrupt
#define EOL_VOLTAGEB_ANxTRGSRC       _TRGSRC3 // ADC input trigger source register
#define EOL_VOLTAGEB_InitAnalog()    {EOL_VOLTAGEB_ANSEL = 1; EOL_VOLTAGEB_Write(PINSTATE_HIGH); EOL_VOLTAGEB_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define EOL_VOLTAGEB_Dispose()       {EOL_VOLTAGEB_Write(PINSTATE_HIGH); EOL_VOLTAGEB_Tris(PINDIR_INPUT); EOL_VOLTAGEB_ANSEL = 0;} // disposing macro for digital input with analog function
#define EOL_VOLTAGEB_InitOutput()    {EOL_VOLTAGEB_Write(PINSTATE_LOW); EOL_VOLTAGEB_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define EOL_VOLTAGEB_InitInput()     {EOL_VOLTAGEB_Write(PINSTATE_HIGH); EOL_VOLTAGEB_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #18 is RA4 (VIN sense for SEPIC)
#define FB_VIN_GPIO_INSTANCE   0 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define FB_VIN_GPIO_PORT_PIN   4 // Port Pin Number
#define FB_VIN_Tris(x)         (TRISAbits.TRISA4 = x) // GPIO direction register bit
#define FB_VIN_Write(x)        (LATAbits.LATA4 = x) // GPIO port latch register bit
#define FB_VIN_Read()          PORTAbits.RA4 // GPIO port register bit
#define FB_VIN_ODC             ODCAbits.ODCA4 // GPIO port open drain configuration register bit
#define FB_VIN_CNPU            CNPUAbits.CNPUA4 // GPIO port pull-up resistor register bit
#define FB_VIN_CNPD            CNPDAbits.CNPDA4 // GPIO port pull-down resistor register bit
#define FB_VIN_CNEN0           CNEN0Abits.CNEN0A4 // GPIO port change notification Enable register bit
#define FB_VIN_CNSTAT          CNSTATAbits.CNSTATA4 // GPIO port change notification Status register bit
#define FB_VIN_CNEN1           CNEN1Abits.CNEN1A4 // GPIO port change notification Edge Select Enable register bit
#define FB_VIN_CNF             CNFAbits.CNFA4 // GPIO port change notification flag bit register bit
#define FB_VIN_Set()           { asm volatile ("bset _LATA, #4 \n"); }
#define FB_VIN_Clear()         { asm volatile ("bclr _LATA, #4 \n"); }
#define FB_VIN_Toggle()        { asm volatile ("btg  _LATA, #4 \n"); }
#define FB_VIN_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define FB_VIN_ANSEL           _ANSELA4 // analog/digital pin configuration register bit
#define FB_VIN_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define FB_VIN_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
#define FB_VIN_ADCAN           4   // ANx input pin number
#define FB_VIN_ADCBUF          ADCBUF4 // ADC buffer register for this input
#define FB_VIN_ADIE_IEx        ADIELbits.IE4
#define FB_VIN_ADEIE_EIEx      ADEIELbits.EIEN4
#define FB_VIN_ADCANxIF        _ADCAN4IF // interrupt flag bit
#define FB_VIN_ADCANxIE        _ADCAN4IE // interrupt enable bit
#define FB_VIN_ADCANxIP        _ADCAN4IP // interrupt priority for this analog input
#define FB_VIN_ANxRDY          _AN4RDY // ADC buffer ready bit
#define _FB_VIN_ADCANxInterrupt _ADCAN4Interrupt
#define FB_VIN_ANxTRGSRC       _TRGSRC4 // ADC input trigger source register
#define FB_VIN_InitAnalog()    {FB_VIN_ANSEL = 1; FB_VIN_Write(PINSTATE_HIGH); FB_VIN_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define FB_VIN_Dispose()       {FB_VIN_Write(PINSTATE_HIGH); FB_VIN_Tris(PINDIR_INPUT); FB_VIN_ANSEL = 0;} // disposing macro for digital input with analog function
#define FB_VIN_InitOutput()    {FB_VIN_Write(PINSTATE_LOW); FB_VIN_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define FB_VIN_InitInput()     {FB_VIN_Write(PINSTATE_HIGH); FB_VIN_Tris(PINDIR_INPUT);} // initialization macro for digital input
#define FB_VIN_COMP3_IN_SEL    1U         // A input=0, B input=1 .... D input=3 / RB2 is CMP3B

// ***************************************************************************************************
// ***************************************************************************************************
// *      PORTB
// ***************************************************************************************************
// ***************************************************************************************************

// Device Pin #28 is RB0 is Average Current 1
#define AVG_CURRENT1_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define AVG_CURRENT1_GPIO_PORT_PIN   0 // Port Pin Number
#define AVG_CURRENT1_Tris(x)         (TRISBbits.TRISB0 = x) // GPIO direction register bit
#define AVG_CURRENT1_Write(x)        (LATBbits.LATB0 = x) // GPIO port latch register bit
#define AVG_CURRENT1_Read()          PORTBbits.RB0 // GPIO port register bit
#define AVG_CURRENT1_ODC             ODCBbits.ODCB0 // GPIO port open drain configuration register bit
#define AVG_CURRENT1_CNPU            CNPUBbits.CNPUB0 // GPIO port pull-up resistor register bit
#define AVG_CURRENT1_CNPD            CNPDBbits.CNPDB0 // GPIO port pull-down resistor register bit
#define AVG_CURRENT1_CNEN0           CNEN0Bbits.CNEN0B0 // GPIO port change notification Enable register bit
#define AVG_CURRENT1_CNSTAT          CNSTATBbits.CNSTATB0 // GPIO port change notification Status register bit
#define AVG_CURRENT1_CNEN1           CNEN1Bbits.CNEN1B0 // GPIO port change notification Edge Select Enable register bit
#define AVG_CURRENT1_CNF             CNFBbits.CNFB0 // GPIO port change notification flag bit register bit
#define AVG_CURRENT1_RP              32 // Number of Remappable Pin
#define _AVG_CURRENT1_RPxR           _RP32R // Remappable Pin Register
#define AVG_CURRENT1_Set()           { asm volatile ("bset _LATB, #0 \n"); }
#define AVG_CURRENT1_Clear()         { asm volatile ("bclr _LATB, #0 \n"); }
#define AVG_CURRENT1_Toggle()        { asm volatile ("btg  _LATB, #0 \n"); }
#define AVG_CURRENT1_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define AVG_CURRENT1_ANSEL           _ANSELB0 // analog/digital pin configuration register bit
#define AVG_CURRENT1_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define AVG_CURRENT1_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
#define AVG_CURRENT1_ADCAN           5   // ANx input pin number
#define AVG_CURRENT1_ADCBUF          ADCBUF5 // ADC buffer register for this input
#define AVG_CURRENT1_ADIE_IEx        ADIELbits.IE5
#define AVG_CURRENT1_ADEIE_EIEx      ADEIELbits.EIEN5
#define AVG_CURRENT1_ADCANxIF        _ADCAN5IF // interrupt flag bit
#define AVG_CURRENT1_ADCANxIE        _ADCAN5IE // interrupt enable bit
#define AVG_CURRENT1_ADCANxIP        _ADCAN5IP // interrupt priority for this analog input
#define AVG_CURRENT1_ANxRDY          _AN5RDY // ADC buffer ready bit
#define _AVG_CURRENT1_ADCANxInterrupt _ADCAN5Interrupt
#define AVG_CURRENT1_ANxTRGSRC       _TRGSRC5 // ADC input trigger source register
#define AVG_CURRENT1_InitAnalog()    {AVG_CURRENT1_ANSEL = 1; AVG_CURRENT1_Write(PINSTATE_HIGH); AVG_CURRENT1_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define AVG_CURRENT1_Dispose()       {AVG_CURRENT1_Write(PINSTATE_HIGH); AVG_CURRENT1_Tris(PINDIR_INPUT); AVG_CURRENT1_ANSEL = 0;} // disposing macro for digital input with analog function
#define AVG_CURRENT1_InitOutput()    {AVG_CURRENT1_Write(PINSTATE_LOW); AVG_CURRENT1_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define AVG_CURRENT1_InitInput()     {AVG_CURRENT1_Write(PINSTATE_HIGH); AVG_CURRENT1_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #29 is RB1 is Average Current 2
#define AVG_CURRENT2_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define AVG_CURRENT2_GPIO_PORT_PIN   1 // Port Pin Number
#define AVG_CURRENT2_Tris(x)         (TRISBbits.TRISB1 = x) // GPIO direction register bit
#define AVG_CURRENT2_Write(x)        (LATBbits.LATB1 = x) // GPIO port latch register bit
#define AVG_CURRENT2_Read()          PORTBbits.RB1 // GPIO port register bit
#define AVG_CURRENT2_ODC             ODCBbits.ODCB1 // GPIO port open drain configuration register bit
#define AVG_CURRENT2_CNPU            CNPUBbits.CNPUB1 // GPIO port pull-up resistor register bit
#define AVG_CURRENT2_CNPD            CNPDBbits.CNPDB1 // GPIO port pull-down resistor register bit
#define AVG_CURRENT2_CNEN0           CNEN0Bbits.CNEN0B1 // GPIO port change notification Enable register bit
#define AVG_CURRENT2_CNSTAT          CNSTATBbits.CNSTATB1 // GPIO port change notification Status register bit
#define AVG_CURRENT2_CNEN1           CNEN1Bbits.CNEN1B1 // GPIO port change notification Edge Select Enable register bit
#define AVG_CURRENT2_CNF             CNFBbits.CNFB1 // GPIO port change notification flag bit register bit
#define AVG_CURRENT2_RP              33 // Number of Remappable Pin
#define _AVG_CURRENT2_RPxR           _RP33R // Remappable Pin Register
#define AVG_CURRENT2_Set()           { asm volatile ("bset _LATB, #1 \n"); }
#define AVG_CURRENT2_Clear()         { asm volatile ("bclr _LATB, #1 \n"); }
#define AVG_CURRENT2_Toggle()        { asm volatile ("btg  _LATB, #1 \n"); }
#define AVG_CURRENT2_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define AVG_CURRENT2_ANSEL           _ANSELB1 // analog/digital pin configuration register bit
#define AVG_CURRENT2_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define AVG_CURRENT2_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
#define AVG_CURRENT2_ADCAN           6   // ANx input pin number
#define AVG_CURRENT2_ADCBUF          ADCBUF6 // ADC buffer register for this input
#define AVG_CURRENT2_ADIE_IEx        ADIELbits.IE6
#define AVG_CURRENT2_ADEIE_EIEx      ADEIELbits.EIEN6
#define AVG_CURRENT2_ADCANxIF        _ADCAN6IF // interrupt flag bit
#define AVG_CURRENT2_ADCANxIE        _ADCAN6IE // interrupt enable bit
#define AVG_CURRENT2_ADCANxIP        _ADCAN6IP // interrupt priority for this analog input
#define AVG_CURRENT2_ANxRDY          _AN6RDY // ADC buffer ready bit
#define _AVG_CURRENT2_ADCANxInterrupt _ADCAN6Interrupt
#define AVG_CURRENT2_ANxTRGSRC       _TRGSRC6 // ADC input trigger source register
#define AVG_CURRENT2_InitAnalog()    {AVG_CURRENT2_ANSEL = 1; AVG_CURRENT2_Write(PINSTATE_HIGH); AVG_CURRENT2_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define AVG_CURRENT2_Dispose()       {AVG_CURRENT2_Write(PINSTATE_HIGH); AVG_CURRENT2_Tris(PINDIR_INPUT); AVG_CURRENT2_ANSEL = 0;} // disposing macro for digital input with analog function
#define AVG_CURRENT2_InitOutput()    {AVG_CURRENT2_Write(PINSTATE_LOW); AVG_CURRENT2_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define AVG_CURRENT2_InitInput()     {AVG_CURRENT2_Write(PINSTATE_HIGH); AVG_CURRENT2_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #33 is RB2 is SEPIC VOUT sense feedback
#define FB_VOUT_SEPIC_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define FB_VOUT_SEPIC_GPIO_PORT_PIN   2 // Port Pin Number
#define FB_VOUT_SEPIC_Tris(x)         (TRISBbits.TRISB2 = x) // GPIO direction register bit
#define FB_VOUT_SEPIC_Write(x)        (LATBbits.LATB2 = x) // GPIO port latch register bit
#define FB_VOUT_SEPIC_Read()          PORTBbits.RB2 // GPIO port register bit
#define FB_VOUT_SEPIC_ODC             ODCBbits.ODCB2 // GPIO port open drain configuration register bit
#define FB_VOUT_SEPIC_CNPU            CNPUBbits.CNPUB2 // GPIO port pull-up resistor register bit
#define FB_VOUT_SEPIC_CNPD            CNPDBbits.CNPDB2 // GPIO port pull-down resistor register bit
#define FB_VOUT_SEPIC_CNEN0           CNEN0Bbits.CNEN0B2 // GPIO port change notification Enable register bit
#define FB_VOUT_SEPIC_CNSTAT          CNSTATBbits.CNSTATB2 // GPIO port change notification Status register bit
#define FB_VOUT_SEPIC_CNEN1           CNEN1Bbits.CNEN1B2 // GPIO port change notification Edge Select Enable register bit
#define FB_VOUT_SEPIC_CNF             CNFBbits.CNFB2 // GPIO port change notification flag bit register bit
#define FB_VOUT_SEPIC_RP              34 // Number of Remappable Pin
#define _FB_VOUT_SEPIC_RPxR           _RP34R // Remappable Pin Register
#define FB_VOUT_SEPIC_Set()           { asm volatile ("bset _LATB, #2 \n"); }
#define FB_VOUT_SEPIC_Clear()         { asm volatile ("bclr _LATB, #2 \n"); }
#define FB_VOUT_SEPIC_Toggle()        { asm volatile ("btg  _LATB, #2 \n"); }
#define FB_VOUT_SEPIC_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define FB_VOUT_SEPIC_ANSEL           _ANSELB2 // analog/digital pin configuration register bit
#define FB_VOUT_SEPIC_ADCCORE         1 // index starts from zero, last index indicated shared adC core
#define FB_VOUT_SEPIC_IS_SHARED_CORE  false // AN input is routed to a dedicated or shared ACD core
#define FB_VOUT_SEPIC_ADCAN           1   // ANx input pin number
#define FB_VOUT_SEPIC_ADCBUF          ADCBUF1 // ADC buffer register for this input
#define FB_VOUT_SEPIC_ADIE_IEx        ADIELbits.IE1
#define FB_VOUT_SEPIC_ADEIE_EIEx      ADEIELbits.EIEN1
#define FB_VOUT_SEPIC_ADCANxIF        _ADCAN1IF // interrupt flag bit
#define FB_VOUT_SEPIC_ADCANxIE        _ADCAN1IE // interrupt enable bit
#define FB_VOUT_SEPIC_ADCANxIP        _ADCAN1IP // interrupt priority for this analog input
#define FB_VOUT_SEPIC_ANxRDY          _AN1RDY // ADC buffer ready bit
#define _FB_VOUT_SEPIC_ADCANxInterrupt _ADCAN1Interrupt
#define FB_VOUT_SEPIC_ANxTRGSRC       _TRGSRC1 // ADC input trigger source register
#define FB_VOUT_SEPIC_InitAnalog()    {FB_VOUT_SEPIC_ANSEL = 1; FB_VOUT_SEPIC_Write(PINSTATE_HIGH); FB_VOUT_SEPIC_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define FB_VOUT_SEPIC_Dispose()       {FB_VOUT_SEPIC_Write(PINSTATE_HIGH); FB_VOUT_SEPIC_Tris(PINDIR_INPUT); FB_VOUT_SEPIC_ANSEL = 0;} // disposing macro for digital input with analog function
#define FB_VOUT_SEPIC_InitOutput()    {FB_VOUT_SEPIC_Write(PINSTATE_LOW); FB_VOUT_SEPIC_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define FB_VOUT_SEPIC_InitInput()     {FB_VOUT_SEPIC_Write(PINSTATE_HIGH); FB_VOUT_SEPIC_Tris(PINDIR_INPUT);} // initialization macro for digital input
#define FB_VOUT_SEPIC_COMP1_IN_SEL    3U         // A input=0, B input=1 .... D input=3 / RB2 is CMP1D
#define FB_VOUT_SEPIC_COMP2_IN_SEL    3U         // A input=0, B input=1 .... D input=3 / RB2 is CMP2D
#define FB_VOUT_SEPIC_COMP3_IN_SEL    3U         // A input=0, B input=1 .... D input=3 / RB2 is CMP3D


// Device Pin #34 is RB3  is DC Offset 3
#define DC_OFFSET3_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define DC_OFFSET3_GPIO_PORT_PIN   3 // Port Pin Number
#define DC_OFFSET3_Tris(x)         (TRISBbits.TRISB3 = x) // GPIO direction register bit
#define DC_OFFSET3_Write(x)        (LATBbits.LATB3 = x) // GPIO port latch register bit
#define DC_OFFSET3_Read()          PORTBbits.RB3 // GPIO port register bit
#define DC_OFFSET3_ODC             ODCBbits.ODCB3 // GPIO port open drain configuration register bit
#define DC_OFFSET3_CNPU            CNPUBbits.CNPUB3 // GPIO port pull-up resistor register bit
#define DC_OFFSET3_CNPD            CNPDBbits.CNPDB3 // GPIO port pull-down resistor register bit
#define DC_OFFSET3_CNEN0           CNEN0Bbits.CNEN0B3 // GPIO port change notification Enable register bit
#define DC_OFFSET3_CNSTAT          CNSTATBbits.CNSTATB3 // GPIO port change notification Status register bit
#define DC_OFFSET3_CNEN1           CNEN1Bbits.CNEN1B3 // GPIO port change notification Edge Select Enable register bit
#define DC_OFFSET3_CNF             CNFBbits.CNFB3 // GPIO port change notification flag bit register bit
#define DC_OFFSET3_RP              35 // Number of Remappable Pin
#define _DC_OFFSET3_RPxR           _RP35R // Remappable Pin Register
#define DC_OFFSET3_Set()           { asm volatile ("bset _LATB, #3 \n"); }
#define DC_OFFSET3_Clear()         { asm volatile ("bclr _LATB, #3 \n"); }
#define DC_OFFSET3_Toggle()        { asm volatile ("btg  _LATB, #3 \n"); }
#define DC_OFFSET3_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define DC_OFFSET3_ANSEL           _ANSELB3 // analog/digital pin configuration register bit
#define DC_OFFSET3_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define DC_OFFSET3_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
#define DC_OFFSET3_ADCAN           8   // ANx input pin number
#define DC_OFFSET3_ADCBUF          ADCBUF8 // ADC buffer register for this input
#define DC_OFFSET3_ADIE_IEx        ADIELbits.IE8
#define DC_OFFSET3_ADEIE_EIEx      ADEIELbits.EIEN8
#define DC_OFFSET3_ADCANxIF        _ADCAN8IF // interrupt flag bit
#define DC_OFFSET3_ADCANxIE        _ADCAN8IE // interrupt enable bit
#define DC_OFFSET3_ADCANxIP        _ADCAN8IP // interrupt priority for this analog input
#define DC_OFFSET3_ANxRDY          _AN8RDY // ADC buffer ready bit
#define _DC_OFFSET3_ADCANxInterrupt _ADCAN8Interrupt
#define DC_OFFSET3_ANxTRGSRC       _TRGSRC8 // ADC input trigger source register
#define DC_OFFSET3_InitAnalog()    {DC_OFFSET3_ANSEL = 1; DC_OFFSET3_Write(PINSTATE_HIGH); DC_OFFSET3_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define DC_OFFSET3_Dispose()       {DC_OFFSET3_Write(PINSTATE_HIGH); DC_OFFSET3_Tris(PINDIR_INPUT); DC_OFFSET3_ANSEL = 0;} // disposing macro for digital input with analog function
#define DC_OFFSET3_InitOutput()    {DC_OFFSET3_Write(PINSTATE_LOW); DC_OFFSET3_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define DC_OFFSET3_InitInput()     {DC_OFFSET3_Write(PINSTATE_HIGH); DC_OFFSET3_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #35 is RB4 is Spare signal available on TP26
#define SPARE1_GPIO_INSTANCE   1U // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define SPARE1_GPIO_PORT_PIN   4U // Port Pin Number
#define SPARE1_Tris(x)         (TRISBbits.TRISB4 = x) // GPIO direction register bit
#define SPARE1_Write(x)        (LATBbits.LATB4 = x) // GPIO port latch register bit
#define SPARE1_Read()          PORTBbits.RB4 // GPIO port register bit
#define SPARE1_TRIS            TRISBbits.TRISB4 // GPIO direction register bit
#define SPARE1_WR              LATBbits.LATB4 // GPIO port latch register bit
#define SPARE1_RD              PORTBbits.RB4 // GPIO port register bit
#define SPARE1_ODC             ODCBbits.ODCB4 // GPIO port open drain configuration register bit
#define SPARE1_CNPU            CNPUBbits.CNPUB4 // GPIO port pull-up resistor register bit
#define SPARE1_CNPD            CNPDBbits.CNPDB4 // GPIO port pull-down resistor register bit
#define SPARE1_CNEN0           CNEN0Bbits.CNEN0B4 // GPIO port change notification Enable register bit
#define SPARE1_CNSTAT          CNSTATBbits.CNSTATB4 // GPIO port change notification Status register bit
#define SPARE1_CNEN1           CNEN1Bbits.CNEN1B4 // GPIO port change notification Edge Select Enable register bit
#define SPARE1_CNF             CNFBbits.CNFB4 // GPIO port change notification flag bit register bit
#define SPARE1_RP              (uint8_t)36 // Number of Remappable Pin
#define _SPARE1_RPxR           _RP36R // Remappable Pin Register
#define SPARE1_Get()           PORTBbits.RB4
#define SPARE1_Set()           { asm volatile ("bset _LATB, #4 \n"); }
#define SPARE1_Clear()         { asm volatile ("bclr _LATB, #4 \n"); }
#define SPARE1_Toggle()        { asm volatile ("btg  _LATB, #4 \n"); }
#define SPARE1_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define SPARE1_Dispose()       {SPARE1_Write(PINSTATE_HIGH); SPARE1_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define SPARE1_InitOutput()    {SPARE1_Write(PINSTATE_LOW); SPARE1_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define SPARE1_InitInput()     {SPARE1_Write(PINSTATE_HIGH); SPARE1_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #45 is RB5 (ICD)
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

// Device Pin #46 is RB6 (ICD)
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

// Device Pin #47 is RB7 is EOL_VOLTAGEA signal (AN2)
#define EOL_VOLTAGEA_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define EOL_VOLTAGEA_GPIO_PORT_PIN   7 // Port Pin Number
#define EOL_VOLTAGEA_Tris(x)         (TRISBbits.TRISB7 = x) // GPIO direction register bit
#define EOL_VOLTAGEA_Write(x)        (LATBbits.LATB7 = x) // GPIO port latch register bit
#define EOL_VOLTAGEA_Read()          PORTBbits.RB7 // GPIO port register bit
#define EOL_VOLTAGEA_ODC             ODCBbits.ODCB7 // GPIO port open drain configuration register bit
#define EOL_VOLTAGEA_CNPU            CNPUBbits.CNPUB7 // GPIO port pull-up resistor register bit
#define EOL_VOLTAGEA_CNPD            CNPDBbits.CNPDB7 // GPIO port pull-down resistor register bit
#define EOL_VOLTAGEA_CNEN0           CNEN0Bbits.CNEN0B7 // GPIO port change notification Enable register bit
#define EOL_VOLTAGEA_CNSTAT          CNSTATBbits.CNSTATB7 // GPIO port change notification Status register bit
#define EOL_VOLTAGEA_CNEN1           CNEN1Bbits.CNEN1B7 // GPIO port change notification Edge Select Enable register bit
#define EOL_VOLTAGEA_CNF             CNFBbits.CNFB7 // GPIO port change notification flag bit register bit
#define EOL_VOLTAGEA_RP              39 // Number of Remappable Pin
#define _EOL_VOLTAGEA_RPxR           _RP39R // Remappable Pin Register
#define EOL_VOLTAGEA_Get()           PORTBbits.RB7
#define EOL_VOLTAGEA_Set()           { asm volatile ("bset _LATB, #7 \n"); }
#define EOL_VOLTAGEA_Clear()         { asm volatile ("bclr _LATB, #7 \n"); }
#define EOL_VOLTAGEA_Toggle()        { asm volatile ("btg  _LATB, #7 \n"); }
#define EOL_VOLTAGEA_IS_ANALOG_INPUT true // Pin is/is not analog input
#define EOL_VOLTAGEA_ANSEL           _ANSELB7 // analog/digital pin configuration register bit
#define EOL_VOLTAGEA_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define EOL_VOLTAGEA_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
#define EOL_VOLTAGEA_ADCAN           2   // ANx input pin number
#define EOL_VOLTAGEA_ADCBUF          ADCBUF2 // ADC buffer register for this input
#define EOL_VOLTAGEA_ADIE_IEx        ADIELbits.IE2
#define EOL_VOLTAGEA_ADEIE_EIEx      ADEIELbits.EIEN2
#define EOL_VOLTAGEA_ADCANxIF        _ADCAN2IF // interrupt flag bit
#define EOL_VOLTAGEA_ADCANxIE        _ADCAN2IE // interrupt enable bit
#define EOL_VOLTAGEA_ADCANxIP        _ADCAN2IP // interrupt priority for this analog input
#define EOL_VOLTAGEA_ANxRDY          _AN2RDY // ADC buffer ready bit
#define _EOL_VOLTAGEA_ADCANxInterrupt _ADCAN2Interrupt
#define EOL_VOLTAGEA_ANxTRGSRC       _TRGSRC2 // ADC input trigger source register
#define EOL_VOLTAGEA_InitAnalog()    {EOL_VOLTAGEA_ANSEL = 1; EOL_VOLTAGEA_Write(PINSTATE_HIGH); EOL_VOLTAGEA_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define EOL_VOLTAGEA_Dispose()       {EOL_VOLTAGEA_Write(PINSTATE_HIGH); EOL_VOLTAGEA_Tris(PINDIR_INPUT);} // disposing macro for digital input with analog function
#define EOL_VOLTAGEA_InitOutput()    {EOL_VOLTAGEA_Write(PINSTATE_LOW); EOL_VOLTAGEA_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define EOL_VOLTAGEA_InitInput()     {EOL_VOLTAGEA_Write(PINSTATE_HIGH); EOL_VOLTAGEA_Tris(PINDIR_INPUT);} // initialization macro for digital input



// Device Pin #48 is RB8 is DC_OFFSET1 (AN10)
#define DC_OFFSET1_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define DC_OFFSET1_GPIO_PORT_PIN   8 // Port Pin Number
#define DC_OFFSET1_Tris(x)         (TRISBbits.TRISB8 = x) // GPIO direction register bit
#define DC_OFFSET1_Write(x)        (LATBbits.LATB8 = x) // GPIO port latch register bit
#define DC_OFFSET1_Read()          PORTBbits.RB8 // GPIO port register bit
#define DC_OFFSET1_ODC             ODCBbits.ODCB8 // GPIO port open drain configuration register bit
#define DC_OFFSET1_CNPU            CNPUBbits.CNPUB8 // GPIO port pull-up resistor register bit
#define DC_OFFSET1_CNPD            CNPDBbits.CNPDB8 // GPIO port pull-down resistor register bit
#define DC_OFFSET1_CNEN0           CNEN0Bbits.CNEN0B8 // GPIO port change notification Enable register bit
#define DC_OFFSET1_CNSTAT          CNSTATBbits.CNSTATB8 // GPIO port change notification Status register bit
#define DC_OFFSET1_CNEN1           CNEN1Bbits.CNEN1B8 // GPIO port change notification Edge Select Enable register bit
#define DC_OFFSET1_CNF             CNFBbits.CNFB8 // GPIO port change notification flag bit register bit
#define DC_OFFSET1_RP              40 // Number of Remappable Pin
#define _DC_OFFSET1_RPxR           _RP40R // Remappable Pin Register
#define DC_OFFSET1_Set()           { asm volatile ("bset _LATB, #8 \n"); }
#define DC_OFFSET1_Clear()         { asm volatile ("bclr _LATB, #8 \n"); }
#define DC_OFFSET1_Toggle()        { asm volatile ("btg  _LATB, #8 \n"); }
#define DC_OFFSET1_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define DC_OFFSET1_ANSEL           _ANSELB8 // analog/digital pin configuration register bit
#define DC_OFFSET1_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define DC_OFFSET1_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
#define DC_OFFSET1_ADCAN           10   // ANx input pin number
#define DC_OFFSET1_ADCBUF          ADCBUF10 // ADC buffer register for this input
#define DC_OFFSET1_ADIE_IEx        ADIELbits.IE10
#define DC_OFFSET1_ADEIE_EIEx      ADEIELbits.EIEN10
#define DC_OFFSET1_ADCANxIF        _ADCAN10IF // interrupt flag bit
#define DC_OFFSET1_ADCANxIE        _ADCAN10IE // interrupt enable bit
#define DC_OFFSET1_ADCANxIP        _ADCAN10IP // interrupt priority for this analog input
#define DC_OFFSET1_ANxRDY          _AN10RDY // ADC buffer ready bit
#define _DC_OFFSET1_ADCANxInterrupt _ADCAN10Interrupt
#define DC_OFFSET1_ANxTRGSRC       _TRGSRC10 // ADC input trigger source register
#define DC_OFFSET1_InitAnalog()    {DC_OFFSET1_ANSEL = 1; DC_OFFSET1_Write(PINSTATE_HIGH); DC_OFFSET1_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define DC_OFFSET1_Dispose()       {DC_OFFSET1_Write(PINSTATE_HIGH); DC_OFFSET1_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define DC_OFFSET1_InitOutput()    {DC_OFFSET1_Write(PINSTATE_LOW); DC_OFFSET1_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define DC_OFFSET1_InitInput()     {DC_OFFSET1_Write(PINSTATE_HIGH); DC_OFFSET1_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #49 is RB9 is DC_OFFSET2 (AN11)
#define DC_OFFSET2_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define DC_OFFSET2_GPIO_PORT_PIN   9 // Port Pin Number
#define DC_OFFSET2_Tris(x)         (TRISBbits.TRISB9 = x) // GPIO direction register bit
#define DC_OFFSET2_Write(x)        (LATBbits.LATB9 = x) // GPIO port latch register bit
#define DC_OFFSET2_Read()          PORTBbits.RB9 // GPIO port register bit
#define DC_OFFSET2_ODC             ODCBbits.ODCB9 // GPIO port open drain configuration register bit
#define DC_OFFSET2_CNPU            CNPUBbits.CNPUB9 // GPIO port pull-up resistor register bit
#define DC_OFFSET2_CNPD            CNPDBbits.CNPDB9 // GPIO port pull-down resistor register bit
#define DC_OFFSET2_CNEN0           CNEN0Bbits.CNEN0B9 // GPIO port change notification Enable register bit
#define DC_OFFSET2_CNSTAT          CNSTATBbits.CNSTATB9 // GPIO port change notification Status register bit
#define DC_OFFSET2_CNEN1           CNEN1Bbits.CNEN1B9 // GPIO port change notification Edge Select Enable register bit
#define DC_OFFSET2_CNF             CNFBbits.CNFB9 // GPIO port change notification flag bit register bit
#define DC_OFFSET2_RP              41 // Number of Remappable Pin
#define _DC_OFFSET2_RPxR           _RP41R // Remappable Pin Register
#define DC_OFFSET2_Set()           { asm volatile ("bset _LATB, #9 \n"); }
#define DC_OFFSET2_Clear()         { asm volatile ("bclr _LATB, #9 \n"); }
#define DC_OFFSET2_Toggle()        { asm volatile ("btg  _LATB, #9 \n"); }
#define DC_OFFSET2_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define DC_OFFSET2_ANSEL           _ANSELB9 // analog/digital pin configuration register bit
#define DC_OFFSET2_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define DC_OFFSET2_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
#define DC_OFFSET2_ADCAN           11   // ANx input pin number
#define DC_OFFSET2_ADCBUF          ADCBUF11 // ADC buffer register for this input
#define DC_OFFSET2_ADIE_IEx        ADIELbits.IE11
#define DC_OFFSET2_ADEIE_EIEx      ADEIELbits.EIEN11
#define DC_OFFSET2_ADCANxIF        _ADCAN11IF // interrupt flag bit
#define DC_OFFSET2_ADCANxIE        _ADCAN11IE // interrupt enable bit
#define DC_OFFSET2_ADCANxIP        _ADCAN11IP // interrupt priority for this analog input
#define DC_OFFSET2_ANxRDY          _AN11RDY // ADC buffer ready bit
#define _DC_OFFSET2_ADCANxInterrupt _ADCAN11Interrupt
#define DC_OFFSET2_ANxTRGSRC       _TRGSRC11 // ADC input trigger source register
#define DC_OFFSET2_InitAnalog()    {DC_OFFSET2_ANSEL = 1; DC_OFFSET2_Write(PINSTATE_HIGH); DC_OFFSET2_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define DC_OFFSET2_Dispose()       {DC_OFFSET2_Write(PINSTATE_HIGH); DC_OFFSET2_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define DC_OFFSET2_InitOutput()    {DC_OFFSET2_Write(PINSTATE_LOW); DC_OFFSET2_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define DC_OFFSET2_InitInput()     {DC_OFFSET2_Write(PINSTATE_HIGH); DC_OFFSET2_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #61 is RB10 is ISO_1B_MINUS
#define ISO_1B_MINUS_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define ISO_1B_MINUS_GPIO_PORT_PIN   10 // Port Pin Number
#define ISO_1B_MINUS_Tris(x)         (TRISBbits.TRISB10 = x) // GPIO direction register bit
#define ISO_1B_MINUS_Write(x)        (LATBbits.LATB10 = x) // GPIO port latch register bit
#define ISO_1B_MINUS_Read()          PORTBbits.RB10 // GPIO port register bit
#define ISO_1B_MINUS_ODC             ODCBbits.ODCB10 // GPIO port open drain configuration register bit
#define ISO_1B_MINUS_CNPU            CNPUBbits.CNPUB10 // GPIO port pull-up resistor register bit
#define ISO_1B_MINUS_CNPD            CNPDBbits.CNPDB10 // GPIO port pull-down resistor register bit
#define ISO_1B_MINUS_CNEN0           CNEN0Bbits.CNEN0B10 // GPIO port change notification Enable register bit
#define ISO_1B_MINUS_CNSTAT          CNSTATBbits.CNSTATB10 // GPIO port change notification Status register bit
#define ISO_1B_MINUS_CNEN1           CNEN1Bbits.CNEN1B10 // GPIO port change notification Edge Select Enable register bit
#define ISO_1B_MINUS_CNF             CNFBbits.CNFB10 // GPIO port change notification flag bit register bit
#define ISO_1B_MINUS_RP              42 // Number of Remappable Pin
#define _ISO_1B_MINUS_RPxR           _RP42R // Remappable Pin Register
#define ISO_1B_MINUS_Set()           { asm volatile ("bset _LATB, #10 \n"); }
#define ISO_1B_MINUS_Clear()         { asm volatile ("bclr _LATB, #10 \n"); }
#define ISO_1B_MINUS_Toggle()        { asm volatile ("btg  _LATB, #10 \n"); }
#define ISO_1B_MINUS_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define ISO_1B_MINUS_Dispose()       {ISO_1B_MINUS_Write(PINSTATE_HIGH); ISO_1B_MINUS_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define ISO_1B_MINUS_InitOutput()    {ISO_1B_MINUS_Write(PINSTATE_LOW); ISO_1B_MINUS_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define ISO_1B_MINUS_InitInput()     {ISO_1B_MINUS_Write(PINSTATE_HIGH); ISO_1B_MINUS_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #62 is RB11 is PWM_SEPIC
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

// Device Pin #63 is RB12 is TX2
#define TX2_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define TX2_GPIO_PORT_PIN   12 // Port Pin Number
#define TX2_Tris(x)         (TRISBbits.TRISB12 = x) // GPIO direction register bit
#define TX2_Write(x)        (LATBbits.LATB12 = x) // GPIO port latch register bit
#define TX2_Read()          PORTBbits.RB12 // GPIO port register bit
#define TX2_ODC             ODCBbits.ODCB12 // GPIO port open drain configuration register bit
#define TX2_CNPU            CNPUBbits.CNPUB12 // GPIO port pull-up resistor register bit
#define TX2_CNPD            CNPDBbits.CNPDB12 // GPIO port pull-down resistor register bit
#define TX2_CNEN0           CNEN0Bbits.CNEN0B12 // GPIO port change notification Enable register bit
#define TX2_CNSTAT          CNSTATBbits.CNSTATB12 // GPIO port change notification Status register bit
#define TX2_CNEN1           CNEN1Bbits.CNEN1B12 // GPIO port change notification Edge Select Enable register bit
#define TX2_CNF             CNFBbits.CNFB12 // GPIO port change notification flag bit register bit
#define TX2_RP              44 // Number of Remappable Pin
#define _TX2_RPxR           _RP44R // Remappable Pin Register
#define TX2_Set()           { asm volatile ("bset _LATB, #12 \n"); }
#define TX2_Clear()         { asm volatile ("bclr _LATB, #12 \n"); }
#define TX2_Toggle()        { asm volatile ("btg  _LATB, #12 \n"); }
#define TX2_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define TX2_Dispose()       {TX2_Write(PINSTATE_HIGH); TX2_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define TX2_InitOutput()    {TX2_Write(PINSTATE_LOW); TX2_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define TX2_InitInput()     {TX2_Write(PINSTATE_HIGH); TX2_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #64 is RB13 is RXD2
#define RXD2_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define RXD2_GPIO_PORT_PIN   13 // Port Pin Number
#define RXD2_Tris(x)         (TRISBbits.TRISB13 = x) // GPIO direction register bit
#define RXD2_Write(x)        (LATBbits.LATB13 = x) // GPIO port latch register bit
#define RXD2_Read()          PORTBbits.RB13 // GPIO port register bit
#define RXD2_ODC             ODCBbits.ODCB13 // GPIO port open drain configuration register bit
#define RXD2_CNPU            CNPUBbits.CNPUB13 // GPIO port pull-up resistor register bit
#define RXD2_CNPD            CNPDBbits.CNPDB13 // GPIO port pull-down resistor register bit
#define RXD2_CNEN0           CNEN0Bbits.CNEN0B13 // GPIO port change notification Enable register bit
#define RXD2_CNSTAT          CNSTATBbits.CNSTATB13 // GPIO port change notification Status register bit
#define RXD2_CNEN1           CNEN1Bbits.CNEN1B13 // GPIO port change notification Edge Select Enable register bit
#define RXD2_CNF             CNFBbits.CNFB13 // GPIO port change notification flag bit register bit
#define RXD2_RP              45 // Number of Remappable Pin
#define _RXD2_RPxR           _RP45R // Remappable Pin Register
#define RXD2_Set()           { asm volatile ("bset _LATB, #13 \n"); }
#define RXD2_Clear()         { asm volatile ("bclr _LATB, #13 \n"); }
#define RXD2_Toggle()        { asm volatile ("btg  _LATB, #13 \n"); }
#define RXD2_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define RXD2_Dispose()       {RXD2_Write(PINSTATE_HIGH); RXD2_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define RXD2_InitOutput()    {RXD2_Write(PINSTATE_LOW); RXD2_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define RXD2_InitInput()     {RXD2_Write(PINSTATE_HIGH); RXD2_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #1 is RB14 is TX1
#define TX1_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define TX1_GPIO_PORT_PIN   14 // Port Pin Number
#define TX1_Tris(x)         (TRISBbits.TRISB14 = x) // GPIO direction register bit
#define TX1_Write(x)        (LATBbits.LATB14 = x) // GPIO port latch register bit
#define TX1_Read()          PORTBbits.RB14 // GPIO port register bit
#define TX1_ODC             ODCBbits.ODCB14 // GPIO port open drain configuration register bit
#define TX1_CNPU            CNPUBbits.CNPUB14 // GPIO port pull-up resistor register bit
#define TX1_CNPD            CNPDBbits.CNPDB14 // GPIO port pull-down resistor register bit
#define TX1_CNEN0           CNEN0Bbits.CNEN0B14 // GPIO port change notification Enable register bit
#define TX1_CNSTAT          CNSTATBbits.CNSTATB14 // GPIO port change notification Status register bit
#define TX1_CNEN1           CNEN1Bbits.CNEN1B14 // GPIO port change notification Edge Select Enable register bit
#define TX1_CNF             CNFBbits.CNFB14 // GPIO port change notification flag bit register bit
#define TX1_RP              46 // Number of Remappable Pin
#define _TX1_RPxR           _RP46R // Remappable Pin Register
#define TX1_Set()           { asm volatile ("bset _LATB, #14 \n"); }
#define TX1_Clear()         { asm volatile ("bclr _LATB, #14 \n"); }
#define TX1_Toggle()        { asm volatile ("btg  _LATB, #14 \n"); }
#define TX1_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define TX1_Dispose()       {TX1_Write(PINSTATE_HIGH); TX1_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define TX1_InitOutput()    {TX1_Write(PINSTATE_LOW); TX1_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define TX1_InitInput()     {TX1_Write(PINSTATE_HIGH); TX1_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #2 is RB15 is RXD1
#define RXD1_GPIO_INSTANCE   1 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define RXD1_GPIO_PORT_PIN   15 // Port Pin Number
#define RXD1_Tris(x)         (TRISBbits.TRISB15 = x) // GPIO direction register bit
#define RXD1_Write(x)        (LATBbits.LATB15 = x) // GPIO port latch register bit
#define RXD1_Read()          PORTBbits.RB15 // GPIO port register bit
#define RXD1_ODC             ODCBbits.ODCB15 // GPIO port open drain configuration register bit
#define RXD1_CNPU            CNPUBbits.CNPUB15 // GPIO port pull-up resistor register bit
#define RXD1_CNPD            CNPDBbits.CNPDB15 // GPIO port pull-down resistor register bit
#define RXD1_CNEN0           CNEN0Bbits.CNEN0B15 // GPIO port change notification Enable register bit
#define RXD1_CNSTAT          CNSTATBbits.CNSTATB15 // GPIO port change notification Status register bit
#define RXD1_CNEN1           CNEN1Bbits.CNEN1B15 // GPIO port change notification Edge Select Enable register bit
#define RXD1_CNF             CNFBbits.CNFB15 // GPIO port change notification flag bit register bit
#define RXD1_RP              47 // Number of Remappable Pin
#define _RXD1_RPxR           _RP47R // Remappable Pin Register
#define RXD1_Set()           { asm volatile ("bset _LATB, #15 \n"); }
#define RXD1_Clear()         { asm volatile ("bclr _LATB, #15 \n"); }
#define RXD1_Toggle()        { asm volatile ("btg  _LATB, #15 \n"); }
#define RXD1_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define RXD1_Dispose()       {RXD1_Write(PINSTATE_HIGH); RXD1_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define RXD1_InitOutput()    {RXD1_Write(PINSTATE_LOW); RXD1_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define RXD1_InitInput()     {RXD1_Write(PINSTATE_HIGH); RXD1_Tris(PINDIR_INPUT);} // initialization macro for digital input

// ***************************************************************************************************
// ***************************************************************************************************
// *      PORTC
// ***************************************************************************************************
// ***************************************************************************************************

// Device Pin #13 is RC0 is RXA1(AN12)
#define RXA1_GPIO_INSTANCE   2 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define RXA1_GPIO_PORT_PIN   0 // Port Pin Number
#define RXA1_Tris(x)         (TRISCbits.TRISC0 = x) // GPIO direction register bit
#define RXA1_Write(x)        (LATCbits.LATC0 = x) // GPIO port latch register bit
#define RXA1_Read()          PORTCbits.RC0 // GPIO port register bit
#define RXA1_ODC             ODCCbits.ODCC0 // GPIO port open drain configuration register bit
#define RXA1_CNPU            CNPUCbits.CNPUC0 // GPIO port pull-up resistor register bit
#define RXA1_CNPD            CNPDCbits.CNPDC0 // GPIO port pull-down resistor register bit
#define RXA1_CNEN0           CNEN0Cbits.CNEN0C0 // GPIO port change notification Enable register bit
#define RXA1_CNSTAT          CNSTATCbits.CNSTATC0 // GPIO port change notification Status register bit
#define RXA1_CNEN1           CNEN1Cbits.CNEN1C0 // GPIO port change notification Edge Select Enable register bit
#define RXA1_CNF             CNFCbits.CNFC0 // GPIO port change notification flag bit register bit
#define RXA1_RP              48 // Number of Remappable Pin
#define _RXA1_RPxR           _RP48R // Remappable Pin Register
#define RXA1_Set()           { asm volatile ("bset _LATC, #0 \n"); }
#define RXA1_Clear()         { asm volatile ("bclr _LATC, #0 \n"); }
#define RXA1_Toggle()        { asm volatile ("btg  _LATC, #0 \n"); }
#define RXA1_IS_ANALOG_INPUT true // Pin is/is not analog input
#define RXA1_ANSEL           _ANSELC0 // analog/digital pin configuration register bit
#define RXA1_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define RXA1_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
#define RXA1_ADCAN           12   // ANx input pin number
#define RXA1_ADCBUF          ADCBUF12 // ADC buffer register for this input
#define RXA1_ADIE_IEx        ADIELbits.IE12
#define RXA1_ADEIE_EIEx      ADEIELbits.EIEN12
#define RXA1_ADCANxIF        _ADCAN12IF // interrupt flag bit
#define RXA1_ADCANxIE        _ADCAN12IE // interrupt enable bit
#define RXA1_ADCANxIP        _ADCAN12IP // interrupt priority for this analog input
#define RXA1_ANxRDY          _AN12RDY // ADC buffer ready bit
#define _RXA1_ADCANxInterrupt _ADCAN12Interrupt
#define RXA1_ANxTRGSRC       _TRGSRC12 // ADC input trigger source register
#define RXA1_InitAnalog()    {RXA1_ANSEL = 1; RXA1_Write(PINSTATE_HIGH); RXA1_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define RXA1_Dispose()       {RXA1_Write(PINSTATE_HIGH); RXA1_Tris(PINDIR_INPUT);} // disposing macro for digital input with analog function
#define RXA1_InitOutput()    {RXA1_Write(PINSTATE_LOW); RXA1_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define RXA1_InitInput()     {RXA1_Write(PINSTATE_HIGH); RXA1_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #22 is RC1 RXA2 (AN13)
#define RXA2_GPIO_INSTANCE   2 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define RXA2_GPIO_PORT_PIN   1 // Port Pin Number
#define RXA2_Tris(x)         (TRISCbits.TRISC1 = x) // GPIO direction register bit
#define RXA2_Write(x)        (LATCbits.LATC1 = x) // GPIO port latch register bit
#define RXA2_Read()          PORTCbits.RC1 // GPIO port register bit
#define RXA2_ODC             ODCCbits.ODCC1 // GPIO port open drain configuration register bit
#define RXA2_CNPU            CNPUCbits.CNPUC1 // GPIO port pull-up resistor register bit
#define RXA2_CNPD            CNPDCbits.CNPDC1 // GPIO port pull-down resistor register bit
#define RXA2_CNEN0           CNEN0Cbits.CNEN0C1 // GPIO port change notification Enable register bit
#define RXA2_CNSTAT          CNSTATCbits.CNSTATC1 // GPIO port change notification Status register bit
#define RXA2_CNEN1           CNEN1Cbits.CNEN1C1 // GPIO port change notification Edge Select Enable register bit
#define RXA2_CNF             CNFCbits.CNFC1 // GPIO port change notification flag bit register bit
#define RXA2_RP              49 // Number of Remappable Pin
#define _RXA2_RPxR           _RP49R // Remappable Pin Register
#define RXA2_Set()           { asm volatile ("bset _LATC, #1 \n"); }
#define RXA2_Clear()         { asm volatile ("bclr _LATC, #1 \n"); }
#define RXA2_Toggle()        { asm volatile ("btg  _LATC, #1 \n"); }
#define RXA2_IS_ANALOG_INPUT true // Pin is/is not analog input
#define RXA2_ANSEL           _ANSELC1 // analog/digital pin configuration register bit
#define RXA2_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define RXA2_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
#define RXA2_ADCAN           13   // ANx input pin number
#define RXA2_ADCBUF          ADCBUF13 // ADC buffer register for this input
#define RXA2_ADIE_IEx        ADIELbits.IE13
#define RXA2_ADEIE_EIEx      ADEIELbits.EIEN13
#define RXA2_ADCANxIF        _ADCAN13IF // interrupt flag bit
#define RXA2_ADCANxIE        _ADCAN13IE // interrupt enable bit
#define RXA2_ADCANxIP        _ADCAN13IP // interrupt priority for this analog input
#define RXA2_ANxRDY          _AN13RDY // ADC buffer ready bit
#define _RXA2_ADCANxInterrupt _ADCAN13Interrupt
#define RXA2_ANxTRGSRC       _TRGSRC13 // ADC input trigger source register
#define RXA2_InitAnalog()    {RXA2_ANSEL = 1; RXA2_Write(PINSTATE_HIGH); RXA2_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define RXA2_Dispose()       {RXA2_Write(PINSTATE_HIGH); RXA2_Tris(PINDIR_INPUT);} // disposing macro for digital input with analog function
#define RXA2_InitOutput()    {RXA2_Write(PINSTATE_LOW); RXA2_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define RXA2_InitInput()     {RXA2_Write(PINSTATE_HIGH); RXA2_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #23 is RC2 is RXA3 (AN14)
#define RXA3_GPIO_INSTANCE   2 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define RXA3_GPIO_PORT_PIN   2 // Port Pin Number
#define RXA3_Tris(x)         (TRISCbits.TRISC2 = x) // GPIO direction register bit
#define RXA3_Write(x)        (LATCbits.LATC2 = x) // GPIO port latch register bit
#define RXA3_Read()          PORTCbits.RC2 // GPIO port register bit
#define RXA3_ODC             ODCCbits.ODCC2 // GPIO port open drain configuration register bit
#define RXA3_CNPU            CNPUCbits.CNPUC2 // GPIO port pull-up resistor register bit
#define RXA3_CNPD            CNPDCbits.CNPDC2 // GPIO port pull-down resistor register bit
#define RXA3_CNEN0           CNEN0Cbits.CNEN0C2 // GPIO port change notification Enable register bit
#define RXA3_CNSTAT          CNSTATCbits.CNSTATC2 // GPIO port change notification Status register bit
#define RXA3_CNEN1           CNEN1Cbits.CNEN1C2 // GPIO port change notification Edge Select Enable register bit
#define RXA3_CNF             CNFCbits.CNFC2 // GPIO port change notification flag bit register bit
#define RXA3_RP              50 // Number of Remappable Pin
#define _RXA3_RPxR           _RP50R // Remappable Pin Register
#define RXA3_Set()           { asm volatile ("bset _LATC, #2 \n"); }
#define RXA3_Clear()         { asm volatile ("bclr _LATC, #2 \n"); }
#define RXA3_Toggle()        { asm volatile ("btg  _LATC, #2 \n"); }
#define RXA3_IS_ANALOG_INPUT true // Pin is/is not analog input 
#define RXA3_ANSEL           _ANSELC2 // analog/digital pin configuration register bit
#define RXA3_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define RXA3_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
#define RXA3_ADCAN           14   // ANx input pin number
#define RXA3_ADCBUF          ADCBUF14 // ADC buffer register for this input
#define RXA3_ADIE_IEx        ADIELbits.IE14
#define RXA3_ADEIE_EIEx      ADEIELbits.EIEN14
#define RXA3_ADCANxIF        _ADCAN14IF // interrupt flag bit
#define RXA3_ADCANxIE        _ADCAN14IE // interrupt enable bit
#define RXA3_ADCANxIP        _ADCAN14IP // interrupt priority for this analog input
#define RXA3_ANxRDY          _AN14RDY // ADC buffer ready bit
#define _RXA3_ADCANxInterrupt _ADCAN14Interrupt
#define RXA3_ANxTRGSRC       _TRGSRC14 // ADC input trigger source register
#define RXA3_InitAnalog()    {RXA3_ANSEL = 1; RXA3_Write(PINSTATE_HIGH); RXA3_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define RXA3_Dispose()       {RXA3_Write(PINSTATE_HIGH); RXA3_Tris(PINDIR_INPUT);} // disposing macro for digital input with analog function
#define RXA3_InitOutput()    {RXA3_Write(PINSTATE_LOW); RXA3_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define RXA3_InitInput()     {RXA3_Write(PINSTATE_HIGH); RXA3_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #27 is RC3 is RXA4 (AN15)
#define RXA4_GPIO_INSTANCE   2 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define RXA4_GPIO_PORT_PIN   3 // Port Pin Number
#define RXA4_Tris(x)         (TRISCbits.TRISC3 = x) // GPIO direction register bit
#define RXA4_Write(x)        (LATCbits.LATC3 = x) // GPIO port latch register bit
#define RXA4_Read()          PORTCbits.RC3 // GPIO port register bit
#define RXA4_ODC             ODCCbits.ODCC3 // GPIO port open drain configuration register bit
#define RXA4_CNPU            CNPUCbits.CNPUC3 // GPIO port pull-up resistor register bit
#define RXA4_CNPD            CNPDCbits.CNPDC3 // GPIO port pull-down resistor register bit
#define RXA4_CNEN0           CNEN0Cbits.CNEN0C3 // GPIO port change notification Enable register bit
#define RXA4_CNSTAT          CNSTATCbits.CNSTATC3 // GPIO port change notification Status register bit
#define RXA4_CNEN1           CNEN1Cbits.CNEN1C3 // GPIO port change notification Edge Select Enable register bit
#define RXA4_CNF             CNFCbits.CNFC3 // GPIO port change notification flag bit register bit
#define RXA4_RP              51 // Number of Remappable Pin
#define _RXA4_RPxR           _RP51R // Remappable Pin Register
#define RXA4_Set()           { asm volatile ("bset _LATC, #3 \n"); }
#define RXA4_Clear()         { asm volatile ("bclr _LATC, #3 \n"); }
#define RXA4_Toggle()        { asm volatile ("btg  _LATC, #3 \n"); }
#define RXA4_IS_ANALOG_INPUT true // Pin is/is not analog input
#define RXA4_ANSEL           _ANSELC3 // analog/digital pin configuration register bit
#define RXA4_ADCCORE         8 // index starts from zero, last index indicated shared adC core
#define RXA4_IS_SHARED_CORE  true // AN input is routed to a dedicated or shared ACD core
#define RXA4_ADCAN           15   // ANx input pin number
#define RXA4_ADCBUF          ADCBUF15 // ADC buffer register for this input
#define RXA4_ADIE_IEx        ADIELbits.IE15
#define RXA4_ADEIE_EIEx      ADEIELbits.EIEN15
#define RXA4_ADCANxIF        _ADCAN15IF // interrupt flag bit
#define RXA4_ADCANxIE        _ADCAN15IE // interrupt enable bit
#define RXA4_ADCANxIP        _ADCAN15IP // interrupt priority for this analog input
#define RXA4_ANxRDY          _AN15RDY // ADC buffer ready bit
#define _RXA4_ADCANxInterrupt _ADCAN15Interrupt
#define RXA4_ANxTRGSRC       _TRGSRC15 // ADC input trigger source register
#define RXA4_InitAnalog()    {RXA4_ANSEL = 1; RXA4_Write(PINSTATE_HIGH); RXA4_Tris(PINDIR_INPUT);} // initialization macro for analog input
#define RXA4_Dispose()       {RXA4_Write(PINSTATE_HIGH); RXA4_Tris(PINDIR_INPUT);} // disposing macro for digital input with analog function
#define RXA4_InitOutput()    {RXA4_Write(PINSTATE_LOW); RXA4_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define RXA4_InitInput()     {RXA4_Write(PINSTATE_HIGH); RXA4_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #50 is RC4 is TEST3
#define TEST3_GPIO_INSTANCE   2 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define TEST3_GPIO_PORT_PIN   4 // Port Pin Number
#define TEST3_Tris(x)         (TRISCbits.TRISC4 = x) // GPIO direction register bit
#define TEST3_Write(x)        (LATCbits.LATC4 = x) // GPIO port latch register bit
#define TEST3_Read()          PORTCbits.RC4 // GPIO port register bit
#define TEST3_ODC             ODCCbits.ODCC4 // GPIO port open drain configuration register bit
#define TEST3_CNPU            CNPUCbits.CNPUC4 // GPIO port pull-up resistor register bit
#define TEST3_CNPD            CNPDCbits.CNPDC4 // GPIO port pull-down resistor register bit
#define TEST3_CNEN0           CNEN0Cbits.CNEN0C4 // GPIO port change notification Enable register bit
#define TEST3_CNSTAT          CNSTATCbits.CNSTATC4 // GPIO port change notification Status register bit
#define TEST3_CNEN1           CNEN1Cbits.CNEN1C4 // GPIO port change notification Edge Select Enable register bit
#define TEST3_CNF             CNFCbits.CNFC4 // GPIO port change notification flag bit register bit
#define TEST3_RP              52 // Number of Remappable Pin
#define _TEST3_RPxR           _RP52R // Remappable Pin Register
#define TEST3_Set()           { asm volatile ("bset _LATC, #4 \n"); }
#define TEST3_Clear()         { asm volatile ("bclr _LATC, #4 \n"); }
#define TEST3_Toggle()        { asm volatile ("btg  _LATC, #4 \n"); }
#define TEST3_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define TEST3_Dispose()       {TEST3_Write(PINSTATE_HIGH); TEST3_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define TEST3_InitOutput()    {TEST3_Write(PINSTATE_LOW); TEST3_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define TEST3_InitInput()     {TEST3_Write(PINSTATE_HIGH); TEST3_Tris(PINDIR_INPUT);} // initialization macro for digital input

// Device Pin #51 is RC5 is TEST4
#define TEST4_GPIO_INSTANCE   2 // Number indicating device port, where 0=A, 1=B, 2=C, etc.
#define TEST4_GPIO_PORT_PIN   5 // Port Pin Number
#define TEST4_Tris(x)         (TRISCbits.TRISC5 = x) // GPIO direction register bit
#define TEST4_Write(x)        (LATCbits.LATC5 = x) // GPIO port latch register bit
#define TEST4_Read()          PORTCbits.RC5 // GPIO port register bit
#define TEST4_ODC             ODCCbits.ODCC5 // GPIO port open drain configuration register bit
#define TEST4_CNPU            CNPUCbits.CNPUC5 // GPIO port pull-up resistor register bit
#define TEST4_CNPD            CNPDCbits.CNPDC5 // GPIO port pull-down resistor register bit
#define TEST4_CNEN0           CNEN0Cbits.CNEN0C5 // GPIO port change notification Enable register bit
#define TEST4_CNSTAT          CNSTATCbits.CNSTATC5 // GPIO port change notification Status register bit
#define TEST4_CNEN1           CNEN1Cbits.CNEN1C5 // GPIO port change notification Edge Select Enable register bit
#define TEST4_CNF             CNFCbits.CNFC5 // GPIO port change notification flag bit register bit
#define TEST4_RP              53 // Number of Remappable Pin
#define _TEST4_RPxR           _RP53R // Remappable Pin Register
#define TEST4_Set()           { asm volatile ("bset _LATC, #5 \n"); }
#define TEST4_Clear()         { asm volatile ("bclr _LATC, #5 \n"); }
#define TEST4_Toggle()        { asm volatile ("btg  _LATC, #5 \n"); }
#define TEST4_IS_ANALOG_INPUT false // Pin is/is not analog input 
#define TEST4_Dispose()       {TEST4_Write(PINSTATE_HIGH); TEST4_Tris(PINDIR_INPUT);} // disposing macro for digital input
#define TEST4_InitOutput()    {TEST4_Write(PINSTATE_LOW); TEST4_Tris(PINDIR_OUTPUT);} // initialization macro for digital output
#define TEST4_InitInput()     {TEST4_Write(PINSTATE_HIGH); TEST4_Tris(PINDIR_INPUT);} // initialization macro for digital input

/** @} */ // end of group device-abstraction-pinmap

#endif	/* __LEAH_P33CK_HostMCU_R10_PINMAP_H__ */
