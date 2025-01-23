/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/**
 * @file   p33SMPS_devices.h
 * @author M91406
 * @brief  List of additional, generalized device identifier filter macros
 * @details
 *  Additional abstraction macros for more flexible device selections 
 *  of device families and derivatives
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef P33_SMPS_DEVICE_DEFINITION_H
#define	P33_SMPS_DEVICE_DEFINITION_H

#include <xc.h> // include processor files - each processor file is guarded.  

/**
 * @def     __P33SMPS__
 * @ingroup p33c-pral-did
 * @brief   Digital Power Supply Digital Signal Controller Device Identification Macros
 * @details
 *  Some peripheral features must be tailored to the specific target 
 *  device selected at design time. 
 * 
 *  The device identification macros provided by this additional header 
 *  file allows detailed filtering:
 *
 *  - identification/ignoring of device family
 *  - identification/ignoring of device pin count
 *  - identification/ignoring of memory size
 * 
 * <b><u>Example</u></b><br>
 *  MPLAB X allows to identify selected target devices by using macros
 *  incorporating the part number of the device selected. The following
 *  example identifies dsPIC33CK32MP105 has been selected. This header
 *  file decodes the part number providing the following, additional
 *  device identification macros:
 * 
 *  - MPLAB X default macro: __dsPIC33CK32MP105__
 *  - XC16-PRAL Device IDs:  
 *     - __P33SMPS__
 *     - __P33SMPS_CK__
 *     - __P33SMPS_CK1__
 *     - __P33SMPS_CK105__
 *     - __P33SMPS_Ara__
 * 
 *  The following statement may be used to filter features tailoring
 *  code sections to the target device in question. Here, a user code
 *  section is tailored for devices of devices families Ara (dsPIC33CKxxMP10x)
 *  and Sagitta without CAN module (dsPIC33CKxxMP20x):
 * 
 *  @code{.c}
 *    #if defined (__P33SMPS_CK1__) || defined (__P33SMPS_CK2__)
 * 
 *      // [ some user code ]
 * 
 *    #endif
 *  @endcode
 * 
 * 
 */
#define __P33SMPS__

#if defined (__dsPIC33FJ06GS101__) || defined (__dsPIC33FJ06GS102__) || \
	defined (__dsPIC33FJ06GS202__) || defined (__dsPIC33FJ16GS402__) || \
	defined (__dsPIC33FJ16GS404__) || defined (__dsPIC33FJ16GS502__) || \
	defined (__dsPIC33FJ16GS504__)
// YGAR family of devices
    
    #define __P33SMPS_FJ__

#elif defined (__dsPIC33FJ32GS406__) || defined (__dsPIC33FJ64GS406__) || \
      defined (__dsPIC33FJ32GS606__) || defined (__dsPIC33FJ64GS606__) || \
      defined (__dsPIC33FJ32GS608__) || defined (__dsPIC33FJ64GS608__) || \
	  defined (__dsPIC33FJ32GS610__) || defined (__dsPIC33FJ64GS610__)
// UEAA family of devices

    #define __P33SMPS_FJC__

#elif defined (__dsPIC33FJ06GS001__) || defined (__dsPIC33FJ06GS101A__) || \
	  defined (__dsPIC33FJ06GS102A__) || defined (__dsPIC33FJ16GS202A__) || \
	  defined (__dsPIC33FJ09GS302__) 
// UEAG family of devices

    #define __P33SMPS_FJA__

#elif defined (__dsPIC33EP16GS202__) || defined (__dsPIC33EP32GS202__)
// TLAL family of devices

    #define __P33SMPS_EP__
    #define __P33SMPS_EP2__

#elif defined (__dsPIC33EP16GS502__) || defined (__dsPIC33EP32GS502__) || defined (__dsPIC33EP64GS502__) || \
      defined (__dsPIC33EP16GS504__) || defined (__dsPIC33EP32GS504__) || defined (__dsPIC33EP64GS504__) || \
      defined (__dsPIC33EP16GS505__) || defined (__dsPIC33EP32GS505__) || defined (__dsPIC33EP64GS505__) || \
      defined (__dsPIC33EP16GS506__) || defined (__dsPIC33EP32GS506__) || defined (__dsPIC33EP64GS506__)
// TLAH family of devices

    #define __P33SMPS_EP__
    #define __P33SMPS_EP5__

#elif defined (__dsPIC33EP128GS702__) || defined (__dsPIC33EP128GS704__) || defined (__dsPIC33EP128GS705__) || \
      defined (__dsPIC33EP128GS706__) || defined (__dsPIC33EP64GS708__) || defined (__dsPIC33EP128GS708__) || \
      defined (__dsPIC33EP64GS804__) || defined (__dsPIC33EP128GS804__) || defined (__dsPIC33EP64GS805__) || \
      defined (__dsPIC33EP128GS805__) || defined (__dsPIC33EP64GS806__) || defined (__dsPIC33EP128GS806__) || \
      defined (__dsPIC33EP64GS808__) || defined (__dsPIC33EP128GS808__)
// TLAY family of devices

    #define __P33SMPS_EP__
    #define __P33SMPS_EP7__
    #define __P33SMPS_EP8__

#elif defined (__dsPIC33CH64MP202__) || defined (__dsPIC33CH128MP202__) || \
      defined (__dsPIC33CH64MP202S1__) || defined (__dsPIC33CH128MP202S1__) || \
      defined (__dsPIC33CH64MP203__) || defined (__dsPIC33CH128MP203__) || \
      defined (__dsPIC33CH64MP203S1__) || defined (__dsPIC33CH128MP203S1__) || \
      defined (__dsPIC33CH64MP205__) || defined (__dsPIC33CH128MP205__) || defined (__dsPIC33CH256MP205__) || defined (__dsPIC33CH512MP205__) || \
      defined (__dsPIC33CH64MP205S1__) || defined (__dsPIC33CH128MP205S1__) || defined (__dsPIC33CH256MP205S1__) || defined (__dsPIC33CH512MP205S1__) || \
      defined (__dsPIC33CH64MP206__) || defined (__dsPIC33CH128MP206__) || defined (__dsPIC33CH256MP206__) || defined (__dsPIC33CH512MP206__) || \
      defined (__dsPIC33CH64MP206S1__) || defined (__dsPIC33CH128MP206S1__) || defined (__dsPIC33CH256MP206S1__) || defined (__dsPIC33CH512MP206S1__) || \
      defined (__dsPIC33CH64MP208__) || defined (__dsPIC33CH128MP208__) || defined (__dsPIC33CH256MP208__) || defined (__dsPIC33CH512MP208__) || \
      defined (__dsPIC33CH64MP208S1__) || defined (__dsPIC33CH128MP208S1__) || defined (__dsPIC33CH256MP208S1__) || defined (__dsPIC33CH512MP208S1__)
    // Gemini/Sagittarius family of devices (main and secondary core))

    #define __P33SMPS_CH__
    #define __P33SMPS_CH2__

    #if defined (__dsPIC33CH64MP202S1__) || defined (__dsPIC33CH128MP202S1__) || \
      defined (__dsPIC33CH64MP203S1__) || defined (__dsPIC33CH128MP203S1__) || \
      defined (__dsPIC33CH64MP205S1__) || defined (__dsPIC33CH128MP205S1__) || defined (__dsPIC33CH256MP205S1__) || defined (__dsPIC33CH512MP205S1__) || \
      defined (__dsPIC33CH64MP206S1__) || defined (__dsPIC33CH128MP206S1__) || defined (__dsPIC33CH256MP206S1__) || defined (__dsPIC33CH512MP206S1__) || \
      defined (__dsPIC33CH64MP208S1__) || defined (__dsPIC33CH128MP208S1__) || defined (__dsPIC33CH256MP208S1__) || defined (__dsPIC33CH512MP208S1__)
    // Gemini/Sagittarius family of devices (secondary core)
        #define __P33SMPS_CH_SLV__  //(depreciated)
        #define __P33SMPS_CH_SLV1__ //(depreciated)
        #define __P33SMPS_CHS__
    #else
    // Gemini/Sagittarius family of devices (main core)
        #define __P33SMPS_CH_MSTR__ //(depreciated)
        #define __P33SMPS_CHM__
    #endif

#elif defined (__dsPIC33CH64MP502__) || defined (__dsPIC33CH128MP502__) || \
      defined (__dsPIC33CH64MP502S1__) || defined (__dsPIC33CH128MP502S1__) || \
      defined (__dsPIC33CH64MP503__) || defined (__dsPIC33CH128MP503__) || \
      defined (__dsPIC33CH64MP503S1__) || defined (__dsPIC33CH128MP503S1__) || \
      defined (__dsPIC33CH64MP505__) || defined (__dsPIC33CH128MP505__) || defined (__dsPIC33CH256MP505__) || defined (__dsPIC33CH512MP505__) || \
      defined (__dsPIC33CH64MP505S1__) || defined (__dsPIC33CH128MP505S1__) || defined (__dsPIC33CH256MP505S1__) || defined (__dsPIC33CH512MP505S1__) || \
      defined (__dsPIC33CH64MP506__) || defined (__dsPIC33CH128MP506__) || defined (__dsPIC33CH256MP506__) || defined (__dsPIC33CH512MP506__) || \
      defined (__dsPIC33CH64MP506S1__) || defined (__dsPIC33CH128MP506S1__) || defined (__dsPIC33CH256MP506S1__) || defined (__dsPIC33CH512MP506S1__) || \
      defined (__dsPIC33CH64MP508__) || defined (__dsPIC33CH128MP508__) || defined (__dsPIC33CH256MP508__) || defined (__dsPIC33CH512MP508__) || \
      defined (__dsPIC33CH64MP508S1__) || defined (__dsPIC33CH128MP508S1__) || defined (__dsPIC33CH256MP508S1__) || defined (__dsPIC33CH512MP508S1__)
    // Gemini/Sagittarius family of devices with CAN FD (main and secondary core)

    #define __P33SMPS_CH__
    #define __P33SMPS_CH5__

    #if defined (__dsPIC33CH64MP502S1__) || defined (__dsPIC33CH128MP502S1__) || \
      defined (__dsPIC33CH64MP503S1__) || defined (__dsPIC33CH128MP503S1__) || \
      defined (__dsPIC33CH64MP505S1__) || defined (__dsPIC33CH128MP505S1__) || defined (__dsPIC33CH256MP505S1__) || defined (__dsPIC33CH512MP505S1__) || \
      defined (__dsPIC33CH64MP506S1__) || defined (__dsPIC33CH128MP506S1__) || defined (__dsPIC33CH256MP506S1__) || defined (__dsPIC33CH512MP506S1__) || \
      defined (__dsPIC33CH64MP508S1__) || defined (__dsPIC33CH128MP508S1__) || defined (__dsPIC33CH256MP508S1__) || defined (__dsPIC33CH512MP508S1__)
    // Gemini/Sagittarius family of devices with CAN FD (secondary core)
        #define __P33SMPS_CH_SLV__  //(depreciated)
        #define __P33SMPS_CH_SLV1__ //(depreciated)
        #define __P33SMPS_CHS__
    #else
    // Gemini/Sagittarius family of devices (main core)
        #define __P33SMPS_CH_MSTR__ //(depreciated)
        #define __P33SMPS_CHM__
    #endif

#elif defined (__dsPIC33CK32MP102__) || defined (__dsPIC33CK64MP102__) || \
      defined (__dsPIC33CK32MP103__) || defined (__dsPIC33CK64MP103__) || \
      defined (__dsPIC33CK32MP105__) || defined (__dsPIC33CK64MP105__)
// Ara family of devices

    #define __P33SMPS_CK__
    #define __P33SMPS_CK1__

#elif defined (__dsPIC33CK32MP202__) || defined (__dsPIC33CK64MP202__) || defined (__dsPIC33CK128MP202__) || defined (__dsPIC33CK256MP202__) || \
      defined (__dsPIC33CK32MP203__) || defined (__dsPIC33CK64MP203__) || defined (__dsPIC33CK128MP203__) || defined (__dsPIC33CK256MP203__) || \
      defined (__dsPIC33CK32MP205__) || defined (__dsPIC33CK64MP205__) || defined (__dsPIC33CK128MP205__) || defined (__dsPIC33CK256MP205__) || \
      defined (__dsPIC33CK32MP206__) || defined (__dsPIC33CK64MP206__) || defined (__dsPIC33CK128MP206__) || defined (__dsPIC33CK256MP206__) || \
      defined (__dsPIC33CK64MP208__) || defined (__dsPIC33CK128MP208__) || defined (__dsPIC33CK256MP208__)
// Sagitta family of devices without CAN FD

    #define __P33SMPS_CK__
    #define __P33SMPS_CK2__

#elif defined (__dsPIC33CK32MP502__) || defined (__dsPIC33CK64MP502__) || defined (__dsPIC33CK128MP502__) || defined (__dsPIC33CK256MP502__) || \
      defined (__dsPIC33CK32MP503__) || defined (__dsPIC33CK64MP503__) || defined (__dsPIC33CK128MP503__) || defined (__dsPIC33CK256MP503__) || \
      defined (__dsPIC33CK32MP505__) || defined (__dsPIC33CK64MP505__) || defined (__dsPIC33CK128MP505__) || defined (__dsPIC33CK256MP505__) || \
      defined (__dsPIC33CK32MP506__) || defined (__dsPIC33CK64MP506__) || defined (__dsPIC33CK128MP506__) || defined (__dsPIC33CK256MP506__) || \
      defined (__dsPIC33CK64MP508__) || defined (__dsPIC33CK128MP508__) || defined (__dsPIC33CK256MP508__)
// Sagitta family of devices with CAN FD

    #define __P33SMPS_CK__
    #define __P33SMPS_CK5__

#elif defined (__dsPIC33CK256MP305__) || (__dsPIC33CK256MP306__) || (__dsPIC33CK256MP308__) || \
      defined (__dsPIC33CK512MP305__) || (__dsPIC33CK512MP306__) || (__dsPIC33CK512MP308__)
// Sagitta+ family of devices without CAN FD
              
    #define __P33SMPS_CK__
    #define __P33SMPS_CK3__

#elif defined (__dsPIC33CK256MP605__) || (__dsPIC33CK256MP606__) || (__dsPIC33CK256MP608__) || \
      defined (__dsPIC33CK512MP605__) || (__dsPIC33CK512MP606__) || (__dsPIC33CK512MP608__)
// Sagitta+ family of devices with CAN FD
              
    #define __P33SMPS_CK__
    #define __P33SMPS_CK6__

#elif defined (__dsPIC33CK256MP405__) || defined (__dsPIC33CK256MP406__) || defined (__dsPIC33CK256MP408__) || defined (__dsPIC33CK256MP410__) || \
      defined (__dsPIC33CK512MP405__) || defined (__dsPIC33CK512MP406__) || defined (__dsPIC33CK512MP408__) || defined (__dsPIC33CK512MP410__) || \
      defined (__dsPIC33CK1024MP405__) || defined (__dsPIC33CK1024MP406__) || defined (__dsPIC33CK1024MP408__) || defined (__dsPIC33CK1024MP410__)
// Sagitta++ family of devices without CAN FD

    #define __P33SMPS_CK__
    #define __P33SMPS_CK4__

#elif defined (__dsPIC33CK256MP705__) || defined (__dsPIC33CK256MP706__) || defined (__dsPIC33CK256MP708__) || defined (__dsPIC33CK256MP710__) || \
      defined (__dsPIC33CK512MP705__) || defined (__dsPIC33CK512MP706__) || defined (__dsPIC33CK512MP708__) || defined (__dsPIC33CK512MP710__) || \
      defined (__dsPIC33CK1024MP705__) || defined (__dsPIC33CK1024MP706__) || defined (__dsPIC33CK1024MP708__) || defined (__dsPIC33CK1024MP710__)
// Sagitta++ family of devices with CAN FD

    #define __P33SMPS_CK__
    #define __P33SMPS_CK7__

// ----------------------------

#else

    #pragma message "selected device not supported by peripheral driver libraries"

#endif

// ----------------------------
// SINGLE DEVICE IDENTIFIERS
// ----------------------------

// ----------------------------
// YGAR family of devices

#if defined (__dsPIC33FJ06GS101__) 
    #define __P33SMPS_FJ101__
    #define __P33SMPS_YGAR__
#elif defined (__dsPIC33FJ06GS102__) 
    #define __P33SMPS_FJ102__
    #define __P33SMPS_YGAR__
#elif defined (__dsPIC33FJ06GS202__) 
    #define __P33SMPS_FJ202__
    #define __P33SMPS_YGAR__
#elif defined (__dsPIC33FJ16GS402__) 
    #define __P33SMPS_FJ402__
    #define __P33SMPS_YGAR__
#elif defined (__dsPIC33FJ16GS404__) 
    #define __P33SMPS_FJ404__
    #define __P33SMPS_YGAR__
#elif defined (__dsPIC33FJ16GS502__) 
    #define __P33SMPS_FJ502__
    #define __P33SMPS_YGAR__
#elif defined (__dsPIC33FJ16GS504__)
    #define __P33SMPS_FJ504__
    #define __P33SMPS_YGAR__

// ----------------------------
// UEAG family of devices

#elif defined (__dsPIC33FJ06GS001__) 
    #define __P33SMPS_FJA001__
    #define __P33SMPS_UEAG__
#elif defined (__dsPIC33FJ06GS101A__) 
    #define __P33SMPS_FJA101__
    #define __P33SMPS_UEAG__
#elif defined (__dsPIC33FJ06GS102A__)
    #define __P33SMPS_FJA102__
    #define __P33SMPS_UEAG__
#elif defined (__dsPIC33FJ16GS202A__) 
    #define __P33SMPS_FJA202__
    #define __P33SMPS_UEAG__
#elif defined (__dsPIC33FJ09GS302__) 
    #define __P33SMPS_FJA302__
    #define __P33SMPS_UEAG__

// ----------------------------
// UEAA family of devices

#elif defined (__dsPIC33FJ32GS406__) || defined (__dsPIC33FJ64GS406__)
    #define __P33SMPS_FJ406__
    #define __P33SMPS_UEAA__
#elif defined (__dsPIC33FJ32GS606__) || defined (__dsPIC33FJ64GS606__)
    #define __P33SMPS_FJ606__
    #define __P33SMPS_UEAA__
#elif defined (__dsPIC33FJ32GS608__) || defined (__dsPIC33FJ64GS608__)
    #define __P33SMPS_FJ608__
    #define __P33SMPS_UEAA__
#elif defined (__dsPIC33FJ32GS610__) || defined (__dsPIC33FJ64GS610__)
    #define __P33SMPS_FJ610__
    #define __P33SMPS_UEAA__

// ----------------------------
// TLAH family of devices

#elif defined (__dsPIC33EP16GS202__) || defined (__dsPIC33EP32GS202__)
    #define __P33SMPS_EP202__
    #define __P33SMPS_TLAH__
#elif defined (__dsPIC33EP16GS502__) || defined (__dsPIC33EP32GS502__) || defined (__dsPIC33EP64GS502__) 
    #define __P33SMPS_EP502__
    #define __P33SMPS_TLAH__
#elif defined (__dsPIC33EP16GS504__) || defined (__dsPIC33EP32GS504__) || defined (__dsPIC33EP64GS504__) 
    #define __P33SMPS_EP504__
    #define __P33SMPS_TLAH__
#elif defined (__dsPIC33EP16GS505__) || defined (__dsPIC33EP32GS505__) || defined (__dsPIC33EP64GS505__)
    #define __P33SMPS_EP505__
    #define __P33SMPS_TLAH__
#elif defined (__dsPIC33EP16GS506__) || defined (__dsPIC33EP32GS506__) || defined (__dsPIC33EP64GS506__)
    #define __P33SMPS_EP506__
    #define __P33SMPS_TLAH__

// ----------------------------
// TLAY family of devices

#elif defined (__dsPIC33EP128GS702__) 
    #define __P33SMPS_EP702__
    #define __P33SMPS_TLAY__
#elif defined (__dsPIC33EP128GS704__) 
    #define __P33SMPS_EP704__
    #define __P33SMPS_TLAY__
#elif defined (__dsPIC33EP128GS705__) 
    #define __P33SMPS_EP705__
    #define __P33SMPS_TLAY__
#elif defined (__dsPIC33EP128GS706__) 
    #define __P33SMPS_EP706__
    #define __P33SMPS_TLAY__
#elif defined (__dsPIC33EP64GS708__) || defined (__dsPIC33EP128GS708__) 
    #define __P33SMPS_EP708__
    #define __P33SMPS_TLAY__

#elif defined (__dsPIC33EP64GS804__) || defined (__dsPIC33EP128GS804__)
    #define __P33SMPS_EP804__
    #define __P33SMPS_TLAY__
#elif defined (__dsPIC33EP64GS805__) || defined (__dsPIC33EP128GS805__)
    #define __P33SMPS_EP805__
    #define __P33SMPS_TLAY__
#elif defined (__dsPIC33EP64GS806__) || defined (__dsPIC33EP128GS806__)
    #define __P33SMPS_EP806__
    #define __P33SMPS_TLAY__
#elif defined (__dsPIC33EP64GS808__) || defined (__dsPIC33EP128GS808__)
    #define __P33SMPS_EP808__
    #define __P33SMPS_TLAY__

// ----------------------------------------------
// Gemini family of devices without CAN FD

#elif defined (__dsPIC33CH64MP202S1__) || defined (__dsPIC33CH128MP202S1__)
    #define __P33SMPS_CH202__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP202__) || defined (__dsPIC33CH128MP202__)
    #define __P33SMPS_CH202__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP203S1__) || defined (__dsPIC33CH128MP203S1__)
    #define __P33SMPS_CH203__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP203__) || defined (__dsPIC33CH128MP203__)
    #define __P33SMPS_CH203__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP205S1__) || defined (__dsPIC33CH128MP205S1__)
    #define __P33SMPS_CH205__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP205__) || defined (__dsPIC33CH128MP205__)
    #define __P33SMPS_CH205__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP206S1__) || defined (__dsPIC33CH128MP206S1__)
    #define __P33SMPS_CH206__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP206__) || defined (__dsPIC33CH128MP206__)
    #define __P33SMPS_CH206__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP208S1__) || defined (__dsPIC33CH128MP208S1__)
    #define __P33SMPS_CH208__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP208__) || defined (__dsPIC33CH128MP208__)
    #define __P33SMPS_CH208__
    #define __P33SMPS_GEMINI__

// ----------------------------------------------
// Gemini family of devices with CAN FD

#elif defined (__dsPIC33CH64MP502S1__) || defined (__dsPIC33CH128MP502S1__)
    #define __P33SMPS_CH502__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP502__) || defined (__dsPIC33CH128MP502__)
    #define __P33SMPS_CH502__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP503S1__) || defined (__dsPIC33CH128MP503S1__)
    #define __P33SMPS_CH503__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP503__) || defined (__dsPIC33CH128MP503__)
    #define __P33SMPS_CH503__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP505S1__) || defined (__dsPIC33CH128MP505S1__)
    #define __P33SMPS_CH505__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP505__) || defined (__dsPIC33CH128MP505__)
    #define __P33SMPS_CH505__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP506S1__) || defined (__dsPIC33CH128MP506S1__)
    #define __P33SMPS_CH506S1__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP506__) || defined (__dsPIC33CH128MP506__)
    #define __P33SMPS_CH506__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP508S1__) || defined (__dsPIC33CH128MP508S1__)
    #define __P33SMPS_CH508__
    #define __P33SMPS_GEMINI__
#elif defined (__dsPIC33CH64MP508__) || defined (__dsPIC33CH128MP508__)
    #define __P33SMPS_CH508__
    #define __P33SMPS_GEMINI__

// ----------------------------------------------
// Sagittarius family of devices without CAN FD

#elif defined (__dsPIC33CH256MP205S1__) || defined (__dsPIC33CH512MP205S1__)
    #define __P33SMPS_CH205__
    #define __P33SMPS_CHE__
    #define __P33SMPS_CHES__
    #define __P33SMPS_SAGITTARIUS__

#elif defined (__dsPIC33CH256MP205__) || defined (__dsPIC33CH512MP205__)
    #define __P33SMPS_CH205__
    #define __P33SMPS_CHE__
    #define __P33SMPS_CHEM__
    #define __P33SMPS_SAGITTARIUS__

#elif defined (__dsPIC33CH256MP206S1__) || defined (__dsPIC33CH512MP206S1__)
    #define __P33SMPS_CH206__
    #define __P33SMPS_CHE__
    #define __P33SMPS_CHES__
   #define __P33SMPS_SAGITTARIUS__

#elif defined (__dsPIC33CH256MP206__) || defined (__dsPIC33CH512MP206__)
    #define __P33SMPS_CH206__
    #define __P33SMPS_CHE__
    #define __P33SMPS_CHEM__
    #define __P33SMPS_SAGITTARIUS__

#elif defined (__dsPIC33CH256MP208S1__) || defined (__dsPIC33CH512MP208S1__)
    #define __P33SMPS_CH208__
    #define __P33SMPS_CHE__
    #define __P33SMPS_CHES__
    #define __P33SMPS_SAGITTARIUS__

#elif defined (__dsPIC33CH256MP208__) || defined (__dsPIC33CH512MP208__)
    #define __P33SMPS_CH208__
    #define __P33SMPS_CHE__
    #define __P33SMPS_CHEM__
    #define __P33SMPS_SAGITTARIUS__

// ----------------------------------------------
// Sagittarius family of devices without CAN FD

#elif defined (__dsPIC33CH256MP505S1__) || defined (__dsPIC33CH512MP505S1__)
    #define __P33SMPS_CH505__
    #define __P33SMPS_CHE__
    #define __P33SMPS_CHES__
    #define __P33SMPS_SAGITTARIUS__

#elif defined (__dsPIC33CH256MP505__) || defined (__dsPIC33CH512MP505__)
    #define __P33SMPS_CH505__
    #define __P33SMPS_CHE__
    #define __P33SMPS_CHEM__
    #define __P33SMPS_SAGITTARIUS__

#elif defined (__dsPIC33CH256MP506S1__) || defined (__dsPIC33CH512MP506S1__)
    #define __P33SMPS_CH506S1__
    #define __P33SMPS_CHE__
    #define __P33SMPS_CHES__
    #define __P33SMPS_SAGITTARIUS__

#elif defined (__dsPIC33CH256MP506__) || defined (__dsPIC33CH512MP506__)
    #define __P33SMPS_CH506__
    #define __P33SMPS_CHE__
    #define __P33SMPS_CHEM__
    #define __P33SMPS_SAGITTARIUS__

#elif defined (__dsPIC33CH256MP508S1__) || defined (__dsPIC33CH512MP508S1__)
    #define __P33SMPS_CH508__
    #define __P33SMPS_CHE__
    #define __P33SMPS_CHES__
    #define __P33SMPS_SAGITTARIUS__

#elif defined (__dsPIC33CH256MP508__) || defined (__dsPIC33CH512MP508__)
    #define __P33SMPS_CH508__
    #define __P33SMPS_CHE__
    #define __P33SMPS_CHEM__
    #define __P33SMPS_SAGITTARIUS__

// ----------------------------
// Ara family of devices

#elif defined (__dsPIC33CK32MP102__) || defined (__dsPIC33CK64MP102__)
    #define __P33SMPS_CK102__
    #define __P33SMPS_ARA__
#elif defined (__dsPIC33CK32MP103__) || defined (__dsPIC33CK64MP103__)
    #define __P33SMPS_CK103__
    #define __P33SMPS_ARA__
#elif defined (__dsPIC33CK32MP105__) || defined (__dsPIC33CK64MP105__)
    #define __P33SMPS_CK105__
    #define __P33SMPS_ARA__

// ----------------------------
// Sagitta family of devices without CAN FD

#elif defined (__dsPIC33CK32MP202__) || defined (__dsPIC33CK64MP202__) || defined (__dsPIC33CK128MP202__) || defined (__dsPIC33CK256MP202__)
    #define __P33SMPS_CK202__
    #define __P33SMPS_SAGITTA__
#elif defined (__dsPIC33CK32MP203__) || defined (__dsPIC33CK64MP203__) || defined (__dsPIC33CK128MP203__) || defined (__dsPIC33CK256MP203__)
    #define __P33SMPS_CK203__
    #define __P33SMPS_SAGITTA__
#elif defined (__dsPIC33CK32MP205__) || defined (__dsPIC33CK64MP205__) || defined (__dsPIC33CK128MP205__) || defined (__dsPIC33CK256MP205__)
    #define __P33SMPS_CK205__
    #define __P33SMPS_SAGITTA__
#elif defined (__dsPIC33CK32MP206__) || defined (__dsPIC33CK64MP206__) || defined (__dsPIC33CK128MP206__) || defined (__dsPIC33CK256MP206__)
    #define __P33SMPS_CK206__
    #define __P33SMPS_SAGITTA__
#elif defined (__dsPIC33CK64MP208__) || defined (__dsPIC33CK128MP208__) || defined (__dsPIC33CK256MP208__)
    #define __P33SMPS_CK208__
    #define __P33SMPS_SAGITTA__

// ----------------------------
// Sagitta family of devices with CAN FD

#elif defined (__dsPIC33CK32MP502__) || defined (__dsPIC33CK64MP502__) || defined (__dsPIC33CK128MP502__) || defined (__dsPIC33CK256MP502__)
    #define __P33SMPS_CK502__
    #define __P33SMPS_SAGITTA__
#elif defined (__dsPIC33CK32MP503__) || defined (__dsPIC33CK64MP503__) || defined (__dsPIC33CK128MP503__) || defined (__dsPIC33CK256MP503__)
    #define __P33SMPS_CK503__
    #define __P33SMPS_SAGITTA__
#elif defined (__dsPIC33CK32MP505__) || defined (__dsPIC33CK64MP505__) || defined (__dsPIC33CK128MP505__) || defined (__dsPIC33CK256MP505__)
    #define __P33SMPS_CK505__
    #define __P33SMPS_SAGITTA__
#elif defined (__dsPIC33CK32MP506__) || defined (__dsPIC33CK64MP506__) || defined (__dsPIC33CK128MP506__) || defined (__dsPIC33CK256MP506__)
    #define __P33SMPS_CK506__
    #define __P33SMPS_SAGITTA__
#elif defined (__dsPIC33CK64MP508__) || defined (__dsPIC33CK128MP508__) || defined (__dsPIC33CK256MP508__)
    #define __P33SMPS_CK508__
    #define __P33SMPS_SAGITTA__

// ----------------------------
// Sagitta+ family of devices without CAN FD

#elif defined (__dsPIC33CK256MP305__) || defined (__dsPIC33CK512MP305__)
    #define __P33SMPS_CK305__
    #define __P33SMPS_SAGITTAP__
#elif defined (__dsPIC33CK256MP306__) || defined (__dsPIC33CK512MP306__)
    #define __P33SMPS_CK306__
    #define __P33SMPS_SAGITTAP__
#elif defined (__dsPIC33CK256MP308__) || defined (__dsPIC33CK512MP308__)
    #define __P33SMPS_CK308__
    #define __P33SMPS_SAGITTAP__

// ----------------------------
// Sagitta+ family of devices with CAN FD

#elif defined (__dsPIC33CK256MP605__) || defined (__dsPIC33CK512MP605__)
    #define __P33SMPS_CK605__
    #define __P33SMPS_SAGITTAP__
#elif defined (__dsPIC33CK256MP606__) || defined (__dsPIC33CK512MP606__)
    #define __P33SMPS_CK606__
    #define __P33SMPS_SAGITTAP__
#elif defined (__dsPIC33CK256MP608__) || defined (__dsPIC33CK512MP608__)
    #define __P33SMPS_CK608__
    #define __P33SMPS_SAGITTAP__

// ----------------------------
// Sagitta++ family of devices without CAN FD

#elif defined (__dsPIC33CK256MP405__) || defined (__dsPIC33CK512MP405__) || defined (__dsPIC33CK1024MP405__)
    #define __P33SMPS_CK405__
    #define __P33SMPS_SAGITTAPP__
#elif defined (__dsPIC33CK256MP406__) || defined (__dsPIC33CK512MP406__) || defined (__dsPIC33CK1024MP406__)
    #define __P33SMPS_CK406__
    #define __P33SMPS_SAGITTAPP__
#elif defined (__dsPIC33CK256MP408__) || defined (__dsPIC33CK512MP408__) || defined (__dsPIC33CK1024MP408__)
    #define __P33SMPS_CK408__
    #define __P33SMPS_SAGITTAPP__
#elif defined (__dsPIC33CK256MP410__) || defined (__dsPIC33CK512MP410__) || defined (__dsPIC33CK1024MP410__)
    #define __P33SMPS_CK410__
    #define __P33SMPS_SAGITTAPP__

// ----------------------------
// Sagitta++ family of devices with CAN FD

#elif defined (__dsPIC33CK256MP705__) || defined (__dsPIC33CK512MP705__) || defined (__dsPIC33CK1024MP705__)
    #define __P33SMPS_CK705__
    #define __P33SMPS_SAGITTAPP__
#elif defined (__dsPIC33CK256MP706__) || defined (__dsPIC33CK512MP706__) || defined (__dsPIC33CK1024MP706__)
    #define __P33SMPS_CK706__
    #define __P33SMPS_SAGITTAPP__
#elif defined (__dsPIC33CK256MP708__) || defined (__dsPIC33CK512MP708__) || defined (__dsPIC33CK1024MP708__)
    #define __P33SMPS_CK708__
    #define __P33SMPS_SAGITTAPP__
#elif defined (__dsPIC33CK256MP710__) || defined (__dsPIC33CK512MP710__) || defined (__dsPIC33CK1024MP710__)
    #define __P33SMPS_CK710__
    #define __P33SMPS_SAGITTAPP__

// ----------------------------

#else
    #pragma message "selected device not supported by peripheral register abstraction driver libraries"
#endif


#endif	/* P33_SMPS_DEVICE_DEFINITION_H */

