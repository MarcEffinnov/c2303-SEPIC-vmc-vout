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
ifeq "$(wildcard nbproject/Makefile-local-210.mk)" "nbproject/Makefile-local-210.mk"
include nbproject/Makefile-local-210.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=210
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
SOURCEFILES_QUOTED_IF_SPACED=sources/fault_handler/app_fault_monitor.c sources/fault_handler/app_fault_config.c sources/fault_handler/drivers/drv_fault_handler.c sources/fault_handler/drivers/drv_trap_handler.c sources/power_control/app_power_control.c sources/power_control/app_power_control_isr.c sources/power_control/app_power_config.c sources/power_control/devices/templates/dev_sepic_ptemp_adc.c sources/power_control/devices/templates/dev_sepic_ptemp_dac.c sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c sources/power_control/devices/dev_sepic_opstates.c sources/power_control/devices/dev_sepic_pconfig.c sources/power_control/devices/dev_sepic_special_functions.c sources/power_control/devices/dev_sepic_substates.c sources/power_control/drivers/i_loop.c sources/power_control/drivers/i_loop_asm.s sources/power_control/drivers/v_loop.c sources/power_control/drivers/v_loop_asm.s sources/power_control/drivers/v_loop_extensions.s sources/power_control/drivers/i_loop_agc.s sources/common/p33c_pral/p33c_pwm.c sources/common/p33c_pral/p33c_gpio.c sources/common/p33c_pral/p33c_dsp.c sources/common/p33c_pral/p33c_osc.c sources/common/p33c_pral/p33c_dac.c sources/common/p33c_pral/p33c_opa.c sources/config/init/init_opa.c sources/config/init/init_dac.c sources/config/init/init_ios.c sources/config/config_bits.c sources/config/apps.c sources/config/usercfg.c sources/os/boot/rtos_dsp.c sources/os/boot/rtos_fosc.c sources/os/boot/rtos_gpio.c sources/os/boot/rtos_pmd.c sources/os/boot/rtos_timer.c sources/os/rtos.c sources/os/boot.c sources/main.c sources/power_control/devices/dev_sepic_converter210.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o ${OBJECTDIR}/sources/fault_handler/app_fault_config.o ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o ${OBJECTDIR}/sources/power_control/app_power_control.o ${OBJECTDIR}/sources/power_control/app_power_control_isr.o ${OBJECTDIR}/sources/power_control/app_power_config.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o ${OBJECTDIR}/sources/power_control/drivers/i_loop.o ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o ${OBJECTDIR}/sources/power_control/drivers/v_loop.o ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o ${OBJECTDIR}/sources/config/init/init_opa.o ${OBJECTDIR}/sources/config/init/init_dac.o ${OBJECTDIR}/sources/config/init/init_ios.o ${OBJECTDIR}/sources/config/config_bits.o ${OBJECTDIR}/sources/config/apps.o ${OBJECTDIR}/sources/config/usercfg.o ${OBJECTDIR}/sources/os/boot/rtos_dsp.o ${OBJECTDIR}/sources/os/boot/rtos_fosc.o ${OBJECTDIR}/sources/os/boot/rtos_gpio.o ${OBJECTDIR}/sources/os/boot/rtos_pmd.o ${OBJECTDIR}/sources/os/boot/rtos_timer.o ${OBJECTDIR}/sources/os/rtos.o ${OBJECTDIR}/sources/os/boot.o ${OBJECTDIR}/sources/main.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o
POSSIBLE_DEPFILES=${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d ${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d ${OBJECTDIR}/sources/power_control/app_power_control.o.d ${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d ${OBJECTDIR}/sources/power_control/app_power_config.o.d ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d ${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d ${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d ${OBJECTDIR}/sources/config/init/init_opa.o.d ${OBJECTDIR}/sources/config/init/init_dac.o.d ${OBJECTDIR}/sources/config/init/init_ios.o.d ${OBJECTDIR}/sources/config/config_bits.o.d ${OBJECTDIR}/sources/config/apps.o.d ${OBJECTDIR}/sources/config/usercfg.o.d ${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d ${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d ${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d ${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d ${OBJECTDIR}/sources/os/boot/rtos_timer.o.d ${OBJECTDIR}/sources/os/rtos.o.d ${OBJECTDIR}/sources/os/boot.o.d ${OBJECTDIR}/sources/main.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o ${OBJECTDIR}/sources/fault_handler/app_fault_config.o ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o ${OBJECTDIR}/sources/power_control/app_power_control.o ${OBJECTDIR}/sources/power_control/app_power_control_isr.o ${OBJECTDIR}/sources/power_control/app_power_config.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o ${OBJECTDIR}/sources/power_control/drivers/i_loop.o ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o ${OBJECTDIR}/sources/power_control/drivers/v_loop.o ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o ${OBJECTDIR}/sources/config/init/init_opa.o ${OBJECTDIR}/sources/config/init/init_dac.o ${OBJECTDIR}/sources/config/init/init_ios.o ${OBJECTDIR}/sources/config/config_bits.o ${OBJECTDIR}/sources/config/apps.o ${OBJECTDIR}/sources/config/usercfg.o ${OBJECTDIR}/sources/os/boot/rtos_dsp.o ${OBJECTDIR}/sources/os/boot/rtos_fosc.o ${OBJECTDIR}/sources/os/boot/rtos_gpio.o ${OBJECTDIR}/sources/os/boot/rtos_pmd.o ${OBJECTDIR}/sources/os/boot/rtos_timer.o ${OBJECTDIR}/sources/os/rtos.o ${OBJECTDIR}/sources/os/boot.o ${OBJECTDIR}/sources/main.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o

# Source Files
SOURCEFILES=sources/fault_handler/app_fault_monitor.c sources/fault_handler/app_fault_config.c sources/fault_handler/drivers/drv_fault_handler.c sources/fault_handler/drivers/drv_trap_handler.c sources/power_control/app_power_control.c sources/power_control/app_power_control_isr.c sources/power_control/app_power_config.c sources/power_control/devices/templates/dev_sepic_ptemp_adc.c sources/power_control/devices/templates/dev_sepic_ptemp_dac.c sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c sources/power_control/devices/dev_sepic_opstates.c sources/power_control/devices/dev_sepic_pconfig.c sources/power_control/devices/dev_sepic_special_functions.c sources/power_control/devices/dev_sepic_substates.c sources/power_control/drivers/i_loop.c sources/power_control/drivers/i_loop_asm.s sources/power_control/drivers/v_loop.c sources/power_control/drivers/v_loop_asm.s sources/power_control/drivers/v_loop_extensions.s sources/power_control/drivers/i_loop_agc.s sources/common/p33c_pral/p33c_pwm.c sources/common/p33c_pral/p33c_gpio.c sources/common/p33c_pral/p33c_dsp.c sources/common/p33c_pral/p33c_osc.c sources/common/p33c_pral/p33c_dac.c sources/common/p33c_pral/p33c_opa.c sources/config/init/init_opa.c sources/config/init/init_dac.c sources/config/init/init_ios.c sources/config/config_bits.c sources/config/apps.c sources/config/usercfg.c sources/os/boot/rtos_dsp.c sources/os/boot/rtos_fosc.c sources/os/boot/rtos_gpio.c sources/os/boot/rtos_pmd.c sources/os/boot/rtos_timer.c sources/os/rtos.c sources/os/boot.c sources/main.c sources/power_control/devices/dev_sepic_converter210.c



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
	${MAKE}  -f nbproject/Makefile-210.mk ${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33CK256MP206
MP_LINKER_FILE_OPTION=,--script=p33CK256MP206.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o: sources/fault_handler/app_fault_monitor.c  .generated_files/flags/210/67f808ef92777bcbc9b4d18befd211bdabefe5b9 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/app_fault_monitor.c  -o ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/app_fault_config.o: sources/fault_handler/app_fault_config.c  .generated_files/flags/210/4486aa5d6b144b9e310769298380f7b14810c02c .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/app_fault_config.c  -o ${OBJECTDIR}/sources/fault_handler/app_fault_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o: sources/fault_handler/drivers/drv_fault_handler.c  .generated_files/flags/210/fca0ee14fe6d42ce470c4264a1249e84ad680a9f .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler/drivers" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/drivers/drv_fault_handler.c  -o ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o: sources/fault_handler/drivers/drv_trap_handler.c  .generated_files/flags/210/68ff9b07c7645eea5562e1062d7157cc47ee58c7 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler/drivers" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/drivers/drv_trap_handler.c  -o ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_control.o: sources/power_control/app_power_control.c  .generated_files/flags/210/46af7075cc5bac66873d4688168a85ff3b86fc9a .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_control.c  -o ${OBJECTDIR}/sources/power_control/app_power_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_control.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_control_isr.o: sources/power_control/app_power_control_isr.c  .generated_files/flags/210/dbb69db6f2f493195aa2e827a684823d45489a91 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control_isr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_control_isr.c  -o ${OBJECTDIR}/sources/power_control/app_power_control_isr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_config.o: sources/power_control/app_power_config.c  .generated_files/flags/210/c10ad075995bd16fc760de39b0a09b6a1aaca463 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_config.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_config.c  -o ${OBJECTDIR}/sources/power_control/app_power_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_config.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o: sources/power_control/devices/templates/dev_sepic_ptemp_adc.c  .generated_files/flags/210/d84ef31c32631a63bcfab2a1c6affb8ab36ea4fe .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_adc.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o: sources/power_control/devices/templates/dev_sepic_ptemp_dac.c  .generated_files/flags/210/4be4ea9e1f9391d0c2d16879d6be56fdb06148bd .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_dac.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o: sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c  .generated_files/flags/210/99775aacd3f13861768da204026f55d36c3a0a22 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o: sources/power_control/devices/dev_sepic_opstates.c  .generated_files/flags/210/ace792efe57a3d1a2efddf99f9ecc965f89a5390 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_opstates.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o: sources/power_control/devices/dev_sepic_pconfig.c  .generated_files/flags/210/338312b79d1778106774cb642f4af6b6608645bd .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_pconfig.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o: sources/power_control/devices/dev_sepic_special_functions.c  .generated_files/flags/210/40f23942a17b4f862c19d8234008e32f42b94a23 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_special_functions.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o: sources/power_control/devices/dev_sepic_substates.c  .generated_files/flags/210/56490acce26b6f1f34e5f33389befaa0a16be038 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_substates.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/i_loop.o: sources/power_control/drivers/i_loop.c  .generated_files/flags/210/b5df6ab03c52b0a991facdf06c6fc078c325bae3 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/drivers/i_loop.c  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop.o: sources/power_control/drivers/v_loop.c  .generated_files/flags/210/da7c0059c7fe40dec2463e2c246ae8461cc105db .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/drivers/v_loop.c  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o: sources/common/p33c_pral/p33c_pwm.c  .generated_files/flags/210/2bb004674d48ff4da20c858118a8e9fc43776c8b .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_pwm.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o: sources/common/p33c_pral/p33c_gpio.c  .generated_files/flags/210/6e85bd6452345f0051fff63b417099f697c54246 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_gpio.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o: sources/common/p33c_pral/p33c_dsp.c  .generated_files/flags/210/a56a35313da9ec0cbae77fac2d8858ceba2da1 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_dsp.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o: sources/common/p33c_pral/p33c_osc.c  .generated_files/flags/210/22e995b4d7b75381edac5841682109deaa11451c .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_osc.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o: sources/common/p33c_pral/p33c_dac.c  .generated_files/flags/210/a37e75fe619257e7d5eadf49f3c58e6d776ec280 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_dac.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o: sources/common/p33c_pral/p33c_opa.c  .generated_files/flags/210/af40829e7dd2248f5d5198b011f93c47ff127ad3 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_opa.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_opa.o: sources/config/init/init_opa.c  .generated_files/flags/210/bf9727a7bcbf3fee3f8bbbddbd3cdb5d0a8d08b5 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_opa.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_opa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_opa.c  -o ${OBJECTDIR}/sources/config/init/init_opa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_opa.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_dac.o: sources/config/init/init_dac.c  .generated_files/flags/210/19e804148370623063e5a28b23360a812009d291 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_dac.c  -o ${OBJECTDIR}/sources/config/init/init_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_dac.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_ios.o: sources/config/init/init_ios.c  .generated_files/flags/210/7cdd1c9e7b2aa95e6bb24c55a356da396b598d41 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_ios.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_ios.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_ios.c  -o ${OBJECTDIR}/sources/config/init/init_ios.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_ios.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/config_bits.o: sources/config/config_bits.c  .generated_files/flags/210/ef26f77261ba23d1b89a113b99e40305f33328c5 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/config_bits.o.d 
	@${RM} ${OBJECTDIR}/sources/config/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/config_bits.c  -o ${OBJECTDIR}/sources/config/config_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/config_bits.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/apps.o: sources/config/apps.c  .generated_files/flags/210/20743dfdcfbfa67e523d40411bea2399f67c7a8e .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/apps.o.d 
	@${RM} ${OBJECTDIR}/sources/config/apps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/apps.c  -o ${OBJECTDIR}/sources/config/apps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/apps.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/usercfg.o: sources/config/usercfg.c  .generated_files/flags/210/3472b2b5174c8504909351679d75af7e4131eb53 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/usercfg.o.d 
	@${RM} ${OBJECTDIR}/sources/config/usercfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/usercfg.c  -o ${OBJECTDIR}/sources/config/usercfg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/usercfg.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_dsp.o: sources/os/boot/rtos_dsp.c  .generated_files/flags/210/62344cbdb719288e3ee7969b8e097c259eb6b3bf .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_dsp.c  -o ${OBJECTDIR}/sources/os/boot/rtos_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_fosc.o: sources/os/boot/rtos_fosc.c  .generated_files/flags/210/5f9730968ead51b8645bff6037e0aef5f2666066 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_fosc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_fosc.c  -o ${OBJECTDIR}/sources/os/boot/rtos_fosc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_gpio.o: sources/os/boot/rtos_gpio.c  .generated_files/flags/210/3bc39ba099946ad6b104f98a1a23c018e3d60d5e .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_gpio.c  -o ${OBJECTDIR}/sources/os/boot/rtos_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_pmd.o: sources/os/boot/rtos_pmd.c  .generated_files/flags/210/7d5ab089146a2e2b3abad474667aed111b039ff3 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_pmd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_pmd.c  -o ${OBJECTDIR}/sources/os/boot/rtos_pmd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_timer.o: sources/os/boot/rtos_timer.c  .generated_files/flags/210/26d4241f430b0e4b8620b4f67ef47b14fa94ed8f .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_timer.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_timer.c  -o ${OBJECTDIR}/sources/os/boot/rtos_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_timer.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/rtos.o: sources/os/rtos.c  .generated_files/flags/210/cdab0106ae4cb7e787b2c96c46a2c8bbe8497211 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os" 
	@${RM} ${OBJECTDIR}/sources/os/rtos.o.d 
	@${RM} ${OBJECTDIR}/sources/os/rtos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/rtos.c  -o ${OBJECTDIR}/sources/os/rtos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/rtos.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot.o: sources/os/boot.c  .generated_files/flags/210/de92271d18434781601f37cd985527b483f1547e .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os" 
	@${RM} ${OBJECTDIR}/sources/os/boot.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot.c  -o ${OBJECTDIR}/sources/os/boot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/main.o: sources/main.c  .generated_files/flags/210/f1f3a68c3f28584c410ee6d9a6d0412340218a2 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/main.o.d 
	@${RM} ${OBJECTDIR}/sources/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/main.c  -o ${OBJECTDIR}/sources/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o: sources/power_control/devices/dev_sepic_converter210.c  .generated_files/flags/210/ffc0778dd0b60ef86954405bd8ffa5ddb5b58a07 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_converter210.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o: sources/fault_handler/app_fault_monitor.c  .generated_files/flags/210/cfd708d62b279a5bc26ddc76595edb1de9559f2a .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/app_fault_monitor.c  -o ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/app_fault_config.o: sources/fault_handler/app_fault_config.c  .generated_files/flags/210/4e2291ede41a25aae3531a6c0582728c4ab88b1c .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/app_fault_config.c  -o ${OBJECTDIR}/sources/fault_handler/app_fault_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o: sources/fault_handler/drivers/drv_fault_handler.c  .generated_files/flags/210/8f7fbe849636bbb5560f41ff5a018a3600d316bf .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler/drivers" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/drivers/drv_fault_handler.c  -o ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o: sources/fault_handler/drivers/drv_trap_handler.c  .generated_files/flags/210/2b43bfbdd323d5179915077a1f83a9b5f5a4fc2f .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler/drivers" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/drivers/drv_trap_handler.c  -o ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_control.o: sources/power_control/app_power_control.c  .generated_files/flags/210/8143e524f632e838e0df19a281125986ee2128c9 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_control.c  -o ${OBJECTDIR}/sources/power_control/app_power_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_control.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_control_isr.o: sources/power_control/app_power_control_isr.c  .generated_files/flags/210/eea811571268f8bba58b811a7c20c53900ec7197 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control_isr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_control_isr.c  -o ${OBJECTDIR}/sources/power_control/app_power_control_isr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_config.o: sources/power_control/app_power_config.c  .generated_files/flags/210/6295dd2480cfa3066dc445c2a1b0b28f38189aae .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_config.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_config.c  -o ${OBJECTDIR}/sources/power_control/app_power_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_config.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o: sources/power_control/devices/templates/dev_sepic_ptemp_adc.c  .generated_files/flags/210/47da86f529c5efc49088a982ef543cbb8ed7b47d .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_adc.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o: sources/power_control/devices/templates/dev_sepic_ptemp_dac.c  .generated_files/flags/210/e6df6a739267585b53477867a2823c4450c3850 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_dac.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o: sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c  .generated_files/flags/210/d31e0a64127ec4afc40afdb81f6eac5b9d2c274d .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o: sources/power_control/devices/dev_sepic_opstates.c  .generated_files/flags/210/bab688f0aa080ff5c6d41800b025c6fe6632fcbd .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_opstates.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o: sources/power_control/devices/dev_sepic_pconfig.c  .generated_files/flags/210/a3d30e1eb964a98c038759a7febd0e7467f03dc .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_pconfig.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o: sources/power_control/devices/dev_sepic_special_functions.c  .generated_files/flags/210/b5bfdd32d0e2f744926bc37868ae7b0ee3dbefdd .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_special_functions.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o: sources/power_control/devices/dev_sepic_substates.c  .generated_files/flags/210/7062484a1bfae206bdd17b7d7f2a55fac569b284 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_substates.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/i_loop.o: sources/power_control/drivers/i_loop.c  .generated_files/flags/210/d2d49c4f1beb3e3779e4744c5fe7dfc1bbee8c85 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/drivers/i_loop.c  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop.o: sources/power_control/drivers/v_loop.c  .generated_files/flags/210/f897094411281e21a0fc2d38e9dbee13168ca013 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/drivers/v_loop.c  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o: sources/common/p33c_pral/p33c_pwm.c  .generated_files/flags/210/acda55477ce9e4c13825320d9d15871088f0886c .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_pwm.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o: sources/common/p33c_pral/p33c_gpio.c  .generated_files/flags/210/f2939adc136f8ebc001e49e24200b520b4bc7a5 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_gpio.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o: sources/common/p33c_pral/p33c_dsp.c  .generated_files/flags/210/39992a72d18cde926d49f3ee1d73f83146f8d67d .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_dsp.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o: sources/common/p33c_pral/p33c_osc.c  .generated_files/flags/210/458adc4188c8b1698fd223b70c11d4b438bb9caa .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_osc.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o: sources/common/p33c_pral/p33c_dac.c  .generated_files/flags/210/a34cb2c4f5b23cfd339c38f182ed35bca509a359 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_dac.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o: sources/common/p33c_pral/p33c_opa.c  .generated_files/flags/210/6782bf92d7f9b7690abea71e8a4142ff7db6845b .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_opa.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_opa.o: sources/config/init/init_opa.c  .generated_files/flags/210/e4988c8ac9ac7f7f091dd1ebd8b84ed78502ef83 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_opa.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_opa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_opa.c  -o ${OBJECTDIR}/sources/config/init/init_opa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_opa.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_dac.o: sources/config/init/init_dac.c  .generated_files/flags/210/99a6703454171866ae879505f13ab070da1d6b70 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_dac.c  -o ${OBJECTDIR}/sources/config/init/init_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_dac.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_ios.o: sources/config/init/init_ios.c  .generated_files/flags/210/4ac8b93e7105509a77cc0d1d07b67437be5f84d6 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_ios.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_ios.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_ios.c  -o ${OBJECTDIR}/sources/config/init/init_ios.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_ios.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/config_bits.o: sources/config/config_bits.c  .generated_files/flags/210/88e8b3c4f131542b15aca43edf4f6cdd2c441851 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/config_bits.o.d 
	@${RM} ${OBJECTDIR}/sources/config/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/config_bits.c  -o ${OBJECTDIR}/sources/config/config_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/config_bits.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/apps.o: sources/config/apps.c  .generated_files/flags/210/70b7de101f1bc802eadf937db0e983da138698b9 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/apps.o.d 
	@${RM} ${OBJECTDIR}/sources/config/apps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/apps.c  -o ${OBJECTDIR}/sources/config/apps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/apps.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/usercfg.o: sources/config/usercfg.c  .generated_files/flags/210/1d23770e81b78722f2ad7469838accd2d4e64430 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/usercfg.o.d 
	@${RM} ${OBJECTDIR}/sources/config/usercfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/usercfg.c  -o ${OBJECTDIR}/sources/config/usercfg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/usercfg.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_dsp.o: sources/os/boot/rtos_dsp.c  .generated_files/flags/210/ab51352677b75a86aab55cec9ece7c4de4e2ed7e .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_dsp.c  -o ${OBJECTDIR}/sources/os/boot/rtos_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_fosc.o: sources/os/boot/rtos_fosc.c  .generated_files/flags/210/c19c49d0246fbe332647e5a7a71c6fb0163ca9e0 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_fosc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_fosc.c  -o ${OBJECTDIR}/sources/os/boot/rtos_fosc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_gpio.o: sources/os/boot/rtos_gpio.c  .generated_files/flags/210/9bcd8209879058502e81d75daf6e3f6279a1626c .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_gpio.c  -o ${OBJECTDIR}/sources/os/boot/rtos_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_pmd.o: sources/os/boot/rtos_pmd.c  .generated_files/flags/210/fecd77cf4f7cdadf86afd6cafc5f799b8bc5206e .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_pmd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_pmd.c  -o ${OBJECTDIR}/sources/os/boot/rtos_pmd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_timer.o: sources/os/boot/rtos_timer.c  .generated_files/flags/210/dec1fea6c47031e37094e947acb78ecdeab1e36 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_timer.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_timer.c  -o ${OBJECTDIR}/sources/os/boot/rtos_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_timer.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/rtos.o: sources/os/rtos.c  .generated_files/flags/210/71660d88337cb13aa147eed012327f63abbee042 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os" 
	@${RM} ${OBJECTDIR}/sources/os/rtos.o.d 
	@${RM} ${OBJECTDIR}/sources/os/rtos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/rtos.c  -o ${OBJECTDIR}/sources/os/rtos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/rtos.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot.o: sources/os/boot.c  .generated_files/flags/210/15e25b59835e64c8653295ce71fe90c61162e6b7 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os" 
	@${RM} ${OBJECTDIR}/sources/os/boot.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot.c  -o ${OBJECTDIR}/sources/os/boot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/main.o: sources/main.c  .generated_files/flags/210/45ee938f7d331934122685bf70e6c9c414419747 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/main.o.d 
	@${RM} ${OBJECTDIR}/sources/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/main.c  -o ${OBJECTDIR}/sources/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/main.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o: sources/power_control/devices/dev_sepic_converter210.c  .generated_files/flags/210/750f09979cb58cf5d3f158f60b31c64542d6ca0c .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_converter210.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter210.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o: sources/power_control/drivers/i_loop_asm.s  .generated_files/flags/210/31f90232d1040682cea01da983bc5bc2316ca7a2 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/i_loop_asm.s  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o: sources/power_control/drivers/v_loop_asm.s  .generated_files/flags/210/4f06f50a5a5f092d51b17f1318463084d975b067 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/v_loop_asm.s  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o: sources/power_control/drivers/v_loop_extensions.s  .generated_files/flags/210/cd369dfb906b2cc4134c7fb65476de6850acbbc0 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/v_loop_extensions.s  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o: sources/power_control/drivers/i_loop_agc.s  .generated_files/flags/210/3ad8c578d10295cf1f3e4715de1ea05d1e59a8a8 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/i_loop_agc.s  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o: sources/power_control/drivers/i_loop_asm.s  .generated_files/flags/210/86fe85894dcf3f6f3dac6112fa715ccd8ac2845 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/i_loop_asm.s  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o: sources/power_control/drivers/v_loop_asm.s  .generated_files/flags/210/58cd6b5685385b307140f5abe2341ec18577d901 .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/v_loop_asm.s  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o: sources/power_control/drivers/v_loop_extensions.s  .generated_files/flags/210/f0e8baabbd97192effdec07f58790727db85a07b .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/v_loop_extensions.s  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o: sources/power_control/drivers/i_loop_agc.s  .generated_files/flags/210/12cd1cd1602f0f8c1b7b681dbc3662365b9d43ce .generated_files/flags/210/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/i_loop_agc.s  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral"     -Wl,--local-stack,--preserve-all,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -D__c2303_r10__ -DXPRJ_210=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -Wl,--local-stack,--preserve-all,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
