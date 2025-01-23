#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-c2303_r10.mk)" "nbproject/Makefile-local-c2303_r10.mk"
include nbproject/Makefile-local-c2303_r10.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=c2303_r10
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=sources/fault_handler/app_fault_monitor.c sources/fault_handler/app_fault_config.c sources/fault_handler/drivers/drv_fault_handler.c sources/fault_handler/drivers/drv_trap_handler.c sources/power_control/app_power_control.c sources/power_control/app_power_control_isr.c sources/power_control/app_power_config.c sources/power_control/devices/templates/dev_sepic_ptemp_adc.c sources/power_control/devices/templates/dev_sepic_ptemp_dac.c sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c sources/power_control/devices/dev_sepic_opstates.c sources/power_control/devices/dev_sepic_pconfig.c sources/power_control/devices/dev_sepic_special_functions.c sources/power_control/devices/dev_sepic_substates.c sources/power_control/drivers/i_loop.c sources/power_control/drivers/i_loop_asm.s sources/power_control/drivers/v_loop.c sources/power_control/drivers/v_loop_asm.s sources/power_control/drivers/v_loop_extensions.s sources/power_control/drivers/i_loop_agc.s sources/common/p33c_pral/p33c_pwm.c sources/common/p33c_pral/p33c_gpio.c sources/common/p33c_pral/p33c_dsp.c sources/common/p33c_pral/p33c_osc.c sources/common/p33c_pral/p33c_dac.c sources/common/p33c_pral/p33c_opa.c sources/config/init/init_opa.c sources/config/init/init_dac.c sources/config/init/init_ios.c sources/config/config_bits.c sources/config/apps.c sources/config/usercfg.c sources/os/boot/rtos_dsp.c sources/os/boot/rtos_fosc.c sources/os/boot/rtos_gpio.c sources/os/boot/rtos_pmd.c sources/os/boot/rtos_timer.c sources/os/rtos.c sources/os/boot.c sources/main.c sources/power_control/devices/dev_sepic_converter.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o ${OBJECTDIR}/sources/fault_handler/app_fault_config.o ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o ${OBJECTDIR}/sources/power_control/app_power_control.o ${OBJECTDIR}/sources/power_control/app_power_control_isr.o ${OBJECTDIR}/sources/power_control/app_power_config.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o ${OBJECTDIR}/sources/power_control/drivers/i_loop.o ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o ${OBJECTDIR}/sources/power_control/drivers/v_loop.o ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o ${OBJECTDIR}/sources/config/init/init_opa.o ${OBJECTDIR}/sources/config/init/init_dac.o ${OBJECTDIR}/sources/config/init/init_ios.o ${OBJECTDIR}/sources/config/config_bits.o ${OBJECTDIR}/sources/config/apps.o ${OBJECTDIR}/sources/config/usercfg.o ${OBJECTDIR}/sources/os/boot/rtos_dsp.o ${OBJECTDIR}/sources/os/boot/rtos_fosc.o ${OBJECTDIR}/sources/os/boot/rtos_gpio.o ${OBJECTDIR}/sources/os/boot/rtos_pmd.o ${OBJECTDIR}/sources/os/boot/rtos_timer.o ${OBJECTDIR}/sources/os/rtos.o ${OBJECTDIR}/sources/os/boot.o ${OBJECTDIR}/sources/main.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o
POSSIBLE_DEPFILES=${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d ${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d ${OBJECTDIR}/sources/power_control/app_power_control.o.d ${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d ${OBJECTDIR}/sources/power_control/app_power_config.o.d ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d ${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d ${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d ${OBJECTDIR}/sources/config/init/init_opa.o.d ${OBJECTDIR}/sources/config/init/init_dac.o.d ${OBJECTDIR}/sources/config/init/init_ios.o.d ${OBJECTDIR}/sources/config/config_bits.o.d ${OBJECTDIR}/sources/config/apps.o.d ${OBJECTDIR}/sources/config/usercfg.o.d ${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d ${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d ${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d ${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d ${OBJECTDIR}/sources/os/boot/rtos_timer.o.d ${OBJECTDIR}/sources/os/rtos.o.d ${OBJECTDIR}/sources/os/boot.o.d ${OBJECTDIR}/sources/main.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o ${OBJECTDIR}/sources/fault_handler/app_fault_config.o ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o ${OBJECTDIR}/sources/power_control/app_power_control.o ${OBJECTDIR}/sources/power_control/app_power_control_isr.o ${OBJECTDIR}/sources/power_control/app_power_config.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o ${OBJECTDIR}/sources/power_control/drivers/i_loop.o ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o ${OBJECTDIR}/sources/power_control/drivers/v_loop.o ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o ${OBJECTDIR}/sources/config/init/init_opa.o ${OBJECTDIR}/sources/config/init/init_dac.o ${OBJECTDIR}/sources/config/init/init_ios.o ${OBJECTDIR}/sources/config/config_bits.o ${OBJECTDIR}/sources/config/apps.o ${OBJECTDIR}/sources/config/usercfg.o ${OBJECTDIR}/sources/os/boot/rtos_dsp.o ${OBJECTDIR}/sources/os/boot/rtos_fosc.o ${OBJECTDIR}/sources/os/boot/rtos_gpio.o ${OBJECTDIR}/sources/os/boot/rtos_pmd.o ${OBJECTDIR}/sources/os/boot/rtos_timer.o ${OBJECTDIR}/sources/os/rtos.o ${OBJECTDIR}/sources/os/boot.o ${OBJECTDIR}/sources/main.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o

# Source Files
SOURCEFILES=sources/fault_handler/app_fault_monitor.c sources/fault_handler/app_fault_config.c sources/fault_handler/drivers/drv_fault_handler.c sources/fault_handler/drivers/drv_trap_handler.c sources/power_control/app_power_control.c sources/power_control/app_power_control_isr.c sources/power_control/app_power_config.c sources/power_control/devices/templates/dev_sepic_ptemp_adc.c sources/power_control/devices/templates/dev_sepic_ptemp_dac.c sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c sources/power_control/devices/dev_sepic_opstates.c sources/power_control/devices/dev_sepic_pconfig.c sources/power_control/devices/dev_sepic_special_functions.c sources/power_control/devices/dev_sepic_substates.c sources/power_control/drivers/i_loop.c sources/power_control/drivers/i_loop_asm.s sources/power_control/drivers/v_loop.c sources/power_control/drivers/v_loop_asm.s sources/power_control/drivers/v_loop_extensions.s sources/power_control/drivers/i_loop_agc.s sources/common/p33c_pral/p33c_pwm.c sources/common/p33c_pral/p33c_gpio.c sources/common/p33c_pral/p33c_dsp.c sources/common/p33c_pral/p33c_osc.c sources/common/p33c_pral/p33c_dac.c sources/common/p33c_pral/p33c_opa.c sources/config/init/init_opa.c sources/config/init/init_dac.c sources/config/init/init_ios.c sources/config/config_bits.c sources/config/apps.c sources/config/usercfg.c sources/os/boot/rtos_dsp.c sources/os/boot/rtos_fosc.c sources/os/boot/rtos_gpio.c sources/os/boot/rtos_pmd.c sources/os/boot/rtos_timer.c sources/os/rtos.c sources/os/boot.c sources/main.c sources/power_control/devices/dev_sepic_converter.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-c2303_r10.mk ${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33CK256MP206
MP_LINKER_FILE_OPTION=,--script=p33CK256MP206.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o: sources/fault_handler/app_fault_monitor.c  .generated_files/flags/c2303_r10/a4cb8aece672f18f8f297ecc38857086e9f208c .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/app_fault_monitor.c  -o ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/app_fault_config.o: sources/fault_handler/app_fault_config.c  .generated_files/flags/c2303_r10/dc6b11fa3574a929ef3d5df40e33c7d0b4eac533 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/app_fault_config.c  -o ${OBJECTDIR}/sources/fault_handler/app_fault_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o: sources/fault_handler/drivers/drv_fault_handler.c  .generated_files/flags/c2303_r10/8eba1e6f7ffad83390252c89b31a56d3e764c307 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler/drivers" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/drivers/drv_fault_handler.c  -o ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o: sources/fault_handler/drivers/drv_trap_handler.c  .generated_files/flags/c2303_r10/be753d8892e5e4edb724ba342af879ca1d077095 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler/drivers" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/drivers/drv_trap_handler.c  -o ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_control.o: sources/power_control/app_power_control.c  .generated_files/flags/c2303_r10/34324afb026f20c14e235541cb678e9897ba289b .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_control.c  -o ${OBJECTDIR}/sources/power_control/app_power_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_control.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_control_isr.o: sources/power_control/app_power_control_isr.c  .generated_files/flags/c2303_r10/914547cffa25435b6ba5b3a128439ecce30905bd .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control_isr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_control_isr.c  -o ${OBJECTDIR}/sources/power_control/app_power_control_isr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_config.o: sources/power_control/app_power_config.c  .generated_files/flags/c2303_r10/3dd7af88a941ac0c41285b1915845aa4f484f47f .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_config.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_config.c  -o ${OBJECTDIR}/sources/power_control/app_power_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_config.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o: sources/power_control/devices/templates/dev_sepic_ptemp_adc.c  .generated_files/flags/c2303_r10/4a679bfb08cdd83e48b5b061b9353a9b223f9dd6 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_adc.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o: sources/power_control/devices/templates/dev_sepic_ptemp_dac.c  .generated_files/flags/c2303_r10/36c01ed1e414de3ea0a6a303e5b94cc519d3007d .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_dac.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o: sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c  .generated_files/flags/c2303_r10/f0e77663036d7a4c39ad609919a248039775e8f8 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o: sources/power_control/devices/dev_sepic_opstates.c  .generated_files/flags/c2303_r10/2c6ced0e4e7fef7df8e470665d32e7281516431f .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_opstates.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o: sources/power_control/devices/dev_sepic_pconfig.c  .generated_files/flags/c2303_r10/5458f4a7e38f4c5491277f45b4372e2397b1249b .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_pconfig.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o: sources/power_control/devices/dev_sepic_special_functions.c  .generated_files/flags/c2303_r10/a37a946721fb090c855711f7681c4f3eb87a69c3 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_special_functions.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o: sources/power_control/devices/dev_sepic_substates.c  .generated_files/flags/c2303_r10/60e2f7b7b00678cf34db38b91e239001af67abe1 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_substates.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/i_loop.o: sources/power_control/drivers/i_loop.c  .generated_files/flags/c2303_r10/fd7abb282feb7c571093f9c75e7a93a1318cf68f .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/drivers/i_loop.c  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop.o: sources/power_control/drivers/v_loop.c  .generated_files/flags/c2303_r10/5d7b9c80f2208d214b030c886fd2d2ca2240784 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/drivers/v_loop.c  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o: sources/common/p33c_pral/p33c_pwm.c  .generated_files/flags/c2303_r10/df7f71e69197c35995652ea619411ebd2f98e7f4 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_pwm.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o: sources/common/p33c_pral/p33c_gpio.c  .generated_files/flags/c2303_r10/b818300be9e9327176963bfe61c5edf55dd8a455 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_gpio.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o: sources/common/p33c_pral/p33c_dsp.c  .generated_files/flags/c2303_r10/f1bde05cc306eb2a990f558006c6793a690a8382 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_dsp.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o: sources/common/p33c_pral/p33c_osc.c  .generated_files/flags/c2303_r10/348222272561a0bfcd45674ec3bcb8dee2ae6823 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_osc.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o: sources/common/p33c_pral/p33c_dac.c  .generated_files/flags/c2303_r10/fb6b122c63e147bf257916100951aaf7b3790ee9 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_dac.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o: sources/common/p33c_pral/p33c_opa.c  .generated_files/flags/c2303_r10/dce1407e8dfe897c41e83b1e7b464ffe3628ca23 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_opa.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_opa.o: sources/config/init/init_opa.c  .generated_files/flags/c2303_r10/70f8d94e98d0d21c89c45a9a83c34d58781d89df .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_opa.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_opa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_opa.c  -o ${OBJECTDIR}/sources/config/init/init_opa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_opa.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_dac.o: sources/config/init/init_dac.c  .generated_files/flags/c2303_r10/3072c9a032f5c6247ad5a7d1a15311c4dcfb0d55 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_dac.c  -o ${OBJECTDIR}/sources/config/init/init_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_dac.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_ios.o: sources/config/init/init_ios.c  .generated_files/flags/c2303_r10/85f7d9e0b94989fd545189e0ad1502b52088ad13 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_ios.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_ios.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_ios.c  -o ${OBJECTDIR}/sources/config/init/init_ios.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_ios.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/config_bits.o: sources/config/config_bits.c  .generated_files/flags/c2303_r10/a0bddb6cc057ad95858c8020720301d454382bd2 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/config_bits.o.d 
	@${RM} ${OBJECTDIR}/sources/config/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/config_bits.c  -o ${OBJECTDIR}/sources/config/config_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/config_bits.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/apps.o: sources/config/apps.c  .generated_files/flags/c2303_r10/f3d9d5137f6e1ab4b8843b1dcb5e52030f9162db .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/apps.o.d 
	@${RM} ${OBJECTDIR}/sources/config/apps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/apps.c  -o ${OBJECTDIR}/sources/config/apps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/apps.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/usercfg.o: sources/config/usercfg.c  .generated_files/flags/c2303_r10/31d40a56d9d38e55b6c86f2345df3f61073b00 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/usercfg.o.d 
	@${RM} ${OBJECTDIR}/sources/config/usercfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/usercfg.c  -o ${OBJECTDIR}/sources/config/usercfg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/usercfg.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_dsp.o: sources/os/boot/rtos_dsp.c  .generated_files/flags/c2303_r10/10f2ffdf4de7a647ccee41307c7dc3eea5e22629 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_dsp.c  -o ${OBJECTDIR}/sources/os/boot/rtos_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_fosc.o: sources/os/boot/rtos_fosc.c  .generated_files/flags/c2303_r10/de971384006d0798f740decaaf21642eb7cfcdb .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_fosc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_fosc.c  -o ${OBJECTDIR}/sources/os/boot/rtos_fosc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_gpio.o: sources/os/boot/rtos_gpio.c  .generated_files/flags/c2303_r10/21754d02f1bb2648f90c1e231e00431a2411da63 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_gpio.c  -o ${OBJECTDIR}/sources/os/boot/rtos_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_pmd.o: sources/os/boot/rtos_pmd.c  .generated_files/flags/c2303_r10/af8d9f4623815c02c59d4a0df26190fbcf2b3d8c .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_pmd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_pmd.c  -o ${OBJECTDIR}/sources/os/boot/rtos_pmd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_timer.o: sources/os/boot/rtos_timer.c  .generated_files/flags/c2303_r10/676dcdd6bd9654b7a7805252cc4511c405800736 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_timer.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_timer.c  -o ${OBJECTDIR}/sources/os/boot/rtos_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_timer.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/rtos.o: sources/os/rtos.c  .generated_files/flags/c2303_r10/27584b2ab87f7155d0afc65888f15ad8896f97f2 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os" 
	@${RM} ${OBJECTDIR}/sources/os/rtos.o.d 
	@${RM} ${OBJECTDIR}/sources/os/rtos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/rtos.c  -o ${OBJECTDIR}/sources/os/rtos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/rtos.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot.o: sources/os/boot.c  .generated_files/flags/c2303_r10/85931c4c7d5c320c8e6496294979f77dd66e796b .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os" 
	@${RM} ${OBJECTDIR}/sources/os/boot.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot.c  -o ${OBJECTDIR}/sources/os/boot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/main.o: sources/main.c  .generated_files/flags/c2303_r10/f079944132ed1bff1f1ca020e228fe2f8b0a8102 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/main.o.d 
	@${RM} ${OBJECTDIR}/sources/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/main.c  -o ${OBJECTDIR}/sources/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o: sources/power_control/devices/dev_sepic_converter.c  .generated_files/flags/c2303_r10/3197208cf3fddaa0b4bf694f21b56a6ef9d74661 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_converter.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o: sources/fault_handler/app_fault_monitor.c  .generated_files/flags/c2303_r10/54b761d6b4309a08329f0a17a3cd6c6b356b300d .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/app_fault_monitor.c  -o ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/app_fault_config.o: sources/fault_handler/app_fault_config.c  .generated_files/flags/c2303_r10/aa41f7f50b23331648db39d814d9c5aecdf98cee .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/app_fault_config.c  -o ${OBJECTDIR}/sources/fault_handler/app_fault_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o: sources/fault_handler/drivers/drv_fault_handler.c  .generated_files/flags/c2303_r10/88c7e6cbcbb6a13e65fb843b838d62fb8f0a1dfa .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler/drivers" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/drivers/drv_fault_handler.c  -o ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o: sources/fault_handler/drivers/drv_trap_handler.c  .generated_files/flags/c2303_r10/9f8ff57741143d6c626a3ec17b90654d9fa7a0ce .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler/drivers" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/drivers/drv_trap_handler.c  -o ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_control.o: sources/power_control/app_power_control.c  .generated_files/flags/c2303_r10/ff4e29ed63ecd6f4b1a3494a0da1aa1173e04226 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_control.c  -o ${OBJECTDIR}/sources/power_control/app_power_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_control.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_control_isr.o: sources/power_control/app_power_control_isr.c  .generated_files/flags/c2303_r10/351d3bf6e41212eed7833c43a50f13d582c575be .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control_isr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_control_isr.c  -o ${OBJECTDIR}/sources/power_control/app_power_control_isr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_config.o: sources/power_control/app_power_config.c  .generated_files/flags/c2303_r10/d269b50bac495b7fca4361b889fd6182c73075b7 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_config.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_config.c  -o ${OBJECTDIR}/sources/power_control/app_power_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_config.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o: sources/power_control/devices/templates/dev_sepic_ptemp_adc.c  .generated_files/flags/c2303_r10/d08008751eadbac92fe1dc2707b3f0b076a9e5fd .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_adc.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o: sources/power_control/devices/templates/dev_sepic_ptemp_dac.c  .generated_files/flags/c2303_r10/ca64071a22d54a8457fc3ea62bd67d9dc91585fb .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_dac.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o: sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c  .generated_files/flags/c2303_r10/dd069bf85d29fd2c84cb7b9054c9da6510a9bfe8 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o: sources/power_control/devices/dev_sepic_opstates.c  .generated_files/flags/c2303_r10/29420805ca66feb35af395be8c90468bed1d8ff0 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_opstates.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o: sources/power_control/devices/dev_sepic_pconfig.c  .generated_files/flags/c2303_r10/d1f4649b247ddd4db9c13d27a829a0e72b3348f4 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_pconfig.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o: sources/power_control/devices/dev_sepic_special_functions.c  .generated_files/flags/c2303_r10/d36ed97852f11cb094c3ca8ae57a920a9448e432 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_special_functions.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o: sources/power_control/devices/dev_sepic_substates.c  .generated_files/flags/c2303_r10/c24da568eea5d6096b1b99fff2edccfd51fbb2b4 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_substates.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/i_loop.o: sources/power_control/drivers/i_loop.c  .generated_files/flags/c2303_r10/c736e7fecc02738254fa5024671caa9b167cb7dc .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/drivers/i_loop.c  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop.o: sources/power_control/drivers/v_loop.c  .generated_files/flags/c2303_r10/18d78f0d8f0887f1a3fc5dd33747813971ae78df .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/drivers/v_loop.c  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o: sources/common/p33c_pral/p33c_pwm.c  .generated_files/flags/c2303_r10/699e4af85222ab079a8e5aa8f18d5aa5f8f4e8df .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_pwm.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o: sources/common/p33c_pral/p33c_gpio.c  .generated_files/flags/c2303_r10/cab5b3edb30a78fbd151975250d90f92d1766cdd .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_gpio.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o: sources/common/p33c_pral/p33c_dsp.c  .generated_files/flags/c2303_r10/b5dbe49622de3a6cbe80644a791b212b4aafc37 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_dsp.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o: sources/common/p33c_pral/p33c_osc.c  .generated_files/flags/c2303_r10/a1f5f9ca8cd357fdd639a2eb44c572d32c0eb06a .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_osc.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o: sources/common/p33c_pral/p33c_dac.c  .generated_files/flags/c2303_r10/d14a8db0339e2e31f455a782d9e417e7c68997e9 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_dac.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o: sources/common/p33c_pral/p33c_opa.c  .generated_files/flags/c2303_r10/fe55a1295ade330143fce02c1b649b036023d0be .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_opa.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_opa.o: sources/config/init/init_opa.c  .generated_files/flags/c2303_r10/3854c12efb224a210fb535e7ec35f525bbc7905a .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_opa.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_opa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_opa.c  -o ${OBJECTDIR}/sources/config/init/init_opa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_opa.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_dac.o: sources/config/init/init_dac.c  .generated_files/flags/c2303_r10/8edcadd489b269a7d5e4c6d2dc2085c10e790578 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_dac.c  -o ${OBJECTDIR}/sources/config/init/init_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_dac.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_ios.o: sources/config/init/init_ios.c  .generated_files/flags/c2303_r10/84f2390153bbbb672966d74b53e185cbb43254ce .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_ios.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_ios.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_ios.c  -o ${OBJECTDIR}/sources/config/init/init_ios.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_ios.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/config_bits.o: sources/config/config_bits.c  .generated_files/flags/c2303_r10/6bb47439a8a3ba542c87750736e1d834cfd197f6 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/config_bits.o.d 
	@${RM} ${OBJECTDIR}/sources/config/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/config_bits.c  -o ${OBJECTDIR}/sources/config/config_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/config_bits.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/apps.o: sources/config/apps.c  .generated_files/flags/c2303_r10/53b29651c0449e42f5d86058c309b91d74ece9c2 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/apps.o.d 
	@${RM} ${OBJECTDIR}/sources/config/apps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/apps.c  -o ${OBJECTDIR}/sources/config/apps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/apps.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/usercfg.o: sources/config/usercfg.c  .generated_files/flags/c2303_r10/28d006fd684f9f121c1ade945e2e22629b2616d4 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/usercfg.o.d 
	@${RM} ${OBJECTDIR}/sources/config/usercfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/usercfg.c  -o ${OBJECTDIR}/sources/config/usercfg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/usercfg.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_dsp.o: sources/os/boot/rtos_dsp.c  .generated_files/flags/c2303_r10/4546aa2ed991ab9341b865d3257177855dd26f52 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_dsp.c  -o ${OBJECTDIR}/sources/os/boot/rtos_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_fosc.o: sources/os/boot/rtos_fosc.c  .generated_files/flags/c2303_r10/cb67789763b02776274d25f09dadfecec8ca0b7d .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_fosc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_fosc.c  -o ${OBJECTDIR}/sources/os/boot/rtos_fosc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_gpio.o: sources/os/boot/rtos_gpio.c  .generated_files/flags/c2303_r10/9592e31bdeb80e1a7b8d081190750be209f1d438 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_gpio.c  -o ${OBJECTDIR}/sources/os/boot/rtos_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_pmd.o: sources/os/boot/rtos_pmd.c  .generated_files/flags/c2303_r10/f88d65ed32689a2b517a9169b4899f2cf953fe58 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_pmd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_pmd.c  -o ${OBJECTDIR}/sources/os/boot/rtos_pmd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_timer.o: sources/os/boot/rtos_timer.c  .generated_files/flags/c2303_r10/ea634c5298991b1cd787f3392be905c2ae4032c .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_timer.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_timer.c  -o ${OBJECTDIR}/sources/os/boot/rtos_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_timer.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/rtos.o: sources/os/rtos.c  .generated_files/flags/c2303_r10/283b7d202004e6eb35d0873a057c926079af0097 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os" 
	@${RM} ${OBJECTDIR}/sources/os/rtos.o.d 
	@${RM} ${OBJECTDIR}/sources/os/rtos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/rtos.c  -o ${OBJECTDIR}/sources/os/rtos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/rtos.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot.o: sources/os/boot.c  .generated_files/flags/c2303_r10/902b8e670d8728c47cc7b05b3ca01396687ac822 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os" 
	@${RM} ${OBJECTDIR}/sources/os/boot.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot.c  -o ${OBJECTDIR}/sources/os/boot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/main.o: sources/main.c  .generated_files/flags/c2303_r10/3091f20a191f6387dd56e7621313d0c6567d0248 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/main.o.d 
	@${RM} ${OBJECTDIR}/sources/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/main.c  -o ${OBJECTDIR}/sources/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/main.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o: sources/power_control/devices/dev_sepic_converter.c  .generated_files/flags/c2303_r10/a9c9e9f8f6c8f682d94c8c1c8086d186787309bc .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_converter.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o: sources/power_control/drivers/i_loop_asm.s  .generated_files/flags/c2303_r10/b773561669c0f7509de2d2c6633bc62ffbc78ed5 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/i_loop_asm.s  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o: sources/power_control/drivers/v_loop_asm.s  .generated_files/flags/c2303_r10/80d341b01334c5dc0dfe943e4f54a12c06cdfa4b .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/v_loop_asm.s  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o: sources/power_control/drivers/v_loop_extensions.s  .generated_files/flags/c2303_r10/b8cb3750f307d8d83be1af6bac438719a5f89671 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/v_loop_extensions.s  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o: sources/power_control/drivers/i_loop_agc.s  .generated_files/flags/c2303_r10/1d6f702503477b0957ae6cf0dce9b814ea793440 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/i_loop_agc.s  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o: sources/power_control/drivers/i_loop_asm.s  .generated_files/flags/c2303_r10/f52a111c8d9e91d7a3a9e11c8b401209a4f9c913 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/i_loop_asm.s  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o: sources/power_control/drivers/v_loop_asm.s  .generated_files/flags/c2303_r10/16f13dabd667cb4365f705acb80ec36f51d23019 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/v_loop_asm.s  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o: sources/power_control/drivers/v_loop_extensions.s  .generated_files/flags/c2303_r10/af2780a2caa6aed5285e4085f9a5763630770545 .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/v_loop_extensions.s  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o: sources/power_control/drivers/i_loop_agc.s  .generated_files/flags/c2303_r10/23ac1ddc44c4614a74de59725911fd56a7caf01d .generated_files/flags/c2303_r10/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/i_loop_agc.s  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral"     -Wl,--local-stack,--preserve-all,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -D__c2303_r10__ -DXPRJ_c2303_r10=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -Wl,--local-stack,--preserve-all,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc-dsc-bin2hex ${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
