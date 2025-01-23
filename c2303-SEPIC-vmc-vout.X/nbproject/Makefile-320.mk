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
ifeq "$(wildcard nbproject/Makefile-local-320.mk)" "nbproject/Makefile-local-320.mk"
include nbproject/Makefile-local-320.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=320
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
SOURCEFILES_QUOTED_IF_SPACED=sources/fault_handler/app_fault_monitor.c sources/fault_handler/app_fault_config.c sources/fault_handler/drivers/drv_fault_handler.c sources/fault_handler/drivers/drv_trap_handler.c sources/power_control/app_power_control.c sources/power_control/app_power_control_isr.c sources/power_control/app_power_config.c sources/power_control/devices/templates/dev_sepic_ptemp_adc.c sources/power_control/devices/templates/dev_sepic_ptemp_dac.c sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c sources/power_control/devices/dev_sepic_opstates.c sources/power_control/devices/dev_sepic_pconfig.c sources/power_control/devices/dev_sepic_special_functions.c sources/power_control/devices/dev_sepic_substates.c sources/power_control/drivers/i_loop.c sources/power_control/drivers/i_loop_asm.s sources/power_control/drivers/v_loop.c sources/power_control/drivers/v_loop_asm.s sources/power_control/drivers/v_loop_extensions.s sources/power_control/drivers/i_loop_agc.s sources/common/p33c_pral/p33c_pwm.c sources/common/p33c_pral/p33c_gpio.c sources/common/p33c_pral/p33c_dsp.c sources/common/p33c_pral/p33c_osc.c sources/common/p33c_pral/p33c_dac.c sources/common/p33c_pral/p33c_opa.c sources/config/init/init_opa.c sources/config/init/init_dac.c sources/config/init/init_ios.c sources/config/config_bits.c sources/config/apps.c sources/config/usercfg.c sources/os/boot/rtos_dsp.c sources/os/boot/rtos_fosc.c sources/os/boot/rtos_gpio.c sources/os/boot/rtos_pmd.c sources/os/boot/rtos_timer.c sources/os/rtos.c sources/os/boot.c sources/main.c sources/power_control/devices/dev_sepic_converter320.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o ${OBJECTDIR}/sources/fault_handler/app_fault_config.o ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o ${OBJECTDIR}/sources/power_control/app_power_control.o ${OBJECTDIR}/sources/power_control/app_power_control_isr.o ${OBJECTDIR}/sources/power_control/app_power_config.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o ${OBJECTDIR}/sources/power_control/drivers/i_loop.o ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o ${OBJECTDIR}/sources/power_control/drivers/v_loop.o ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o ${OBJECTDIR}/sources/config/init/init_opa.o ${OBJECTDIR}/sources/config/init/init_dac.o ${OBJECTDIR}/sources/config/init/init_ios.o ${OBJECTDIR}/sources/config/config_bits.o ${OBJECTDIR}/sources/config/apps.o ${OBJECTDIR}/sources/config/usercfg.o ${OBJECTDIR}/sources/os/boot/rtos_dsp.o ${OBJECTDIR}/sources/os/boot/rtos_fosc.o ${OBJECTDIR}/sources/os/boot/rtos_gpio.o ${OBJECTDIR}/sources/os/boot/rtos_pmd.o ${OBJECTDIR}/sources/os/boot/rtos_timer.o ${OBJECTDIR}/sources/os/rtos.o ${OBJECTDIR}/sources/os/boot.o ${OBJECTDIR}/sources/main.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o
POSSIBLE_DEPFILES=${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d ${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d ${OBJECTDIR}/sources/power_control/app_power_control.o.d ${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d ${OBJECTDIR}/sources/power_control/app_power_config.o.d ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d ${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d ${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d ${OBJECTDIR}/sources/config/init/init_opa.o.d ${OBJECTDIR}/sources/config/init/init_dac.o.d ${OBJECTDIR}/sources/config/init/init_ios.o.d ${OBJECTDIR}/sources/config/config_bits.o.d ${OBJECTDIR}/sources/config/apps.o.d ${OBJECTDIR}/sources/config/usercfg.o.d ${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d ${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d ${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d ${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d ${OBJECTDIR}/sources/os/boot/rtos_timer.o.d ${OBJECTDIR}/sources/os/rtos.o.d ${OBJECTDIR}/sources/os/boot.o.d ${OBJECTDIR}/sources/main.o.d ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o ${OBJECTDIR}/sources/fault_handler/app_fault_config.o ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o ${OBJECTDIR}/sources/power_control/app_power_control.o ${OBJECTDIR}/sources/power_control/app_power_control_isr.o ${OBJECTDIR}/sources/power_control/app_power_config.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o ${OBJECTDIR}/sources/power_control/drivers/i_loop.o ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o ${OBJECTDIR}/sources/power_control/drivers/v_loop.o ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o ${OBJECTDIR}/sources/config/init/init_opa.o ${OBJECTDIR}/sources/config/init/init_dac.o ${OBJECTDIR}/sources/config/init/init_ios.o ${OBJECTDIR}/sources/config/config_bits.o ${OBJECTDIR}/sources/config/apps.o ${OBJECTDIR}/sources/config/usercfg.o ${OBJECTDIR}/sources/os/boot/rtos_dsp.o ${OBJECTDIR}/sources/os/boot/rtos_fosc.o ${OBJECTDIR}/sources/os/boot/rtos_gpio.o ${OBJECTDIR}/sources/os/boot/rtos_pmd.o ${OBJECTDIR}/sources/os/boot/rtos_timer.o ${OBJECTDIR}/sources/os/rtos.o ${OBJECTDIR}/sources/os/boot.o ${OBJECTDIR}/sources/main.o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o

# Source Files
SOURCEFILES=sources/fault_handler/app_fault_monitor.c sources/fault_handler/app_fault_config.c sources/fault_handler/drivers/drv_fault_handler.c sources/fault_handler/drivers/drv_trap_handler.c sources/power_control/app_power_control.c sources/power_control/app_power_control_isr.c sources/power_control/app_power_config.c sources/power_control/devices/templates/dev_sepic_ptemp_adc.c sources/power_control/devices/templates/dev_sepic_ptemp_dac.c sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c sources/power_control/devices/dev_sepic_opstates.c sources/power_control/devices/dev_sepic_pconfig.c sources/power_control/devices/dev_sepic_special_functions.c sources/power_control/devices/dev_sepic_substates.c sources/power_control/drivers/i_loop.c sources/power_control/drivers/i_loop_asm.s sources/power_control/drivers/v_loop.c sources/power_control/drivers/v_loop_asm.s sources/power_control/drivers/v_loop_extensions.s sources/power_control/drivers/i_loop_agc.s sources/common/p33c_pral/p33c_pwm.c sources/common/p33c_pral/p33c_gpio.c sources/common/p33c_pral/p33c_dsp.c sources/common/p33c_pral/p33c_osc.c sources/common/p33c_pral/p33c_dac.c sources/common/p33c_pral/p33c_opa.c sources/config/init/init_opa.c sources/config/init/init_dac.c sources/config/init/init_ios.c sources/config/config_bits.c sources/config/apps.c sources/config/usercfg.c sources/os/boot/rtos_dsp.c sources/os/boot/rtos_fosc.c sources/os/boot/rtos_gpio.c sources/os/boot/rtos_pmd.c sources/os/boot/rtos_timer.c sources/os/rtos.c sources/os/boot.c sources/main.c sources/power_control/devices/dev_sepic_converter320.c



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
	${MAKE}  -f nbproject/Makefile-320.mk ${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33CK256MP206
MP_LINKER_FILE_OPTION=,--script=p33CK256MP206.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o: sources/fault_handler/app_fault_monitor.c  .generated_files/flags/320/947ad7a89b2dcce0d0cb09aef3518417b8f28288 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/app_fault_monitor.c  -o ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/app_fault_config.o: sources/fault_handler/app_fault_config.c  .generated_files/flags/320/23ceca571e644be2d8bc62bd1884e4dd7c45732b .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/app_fault_config.c  -o ${OBJECTDIR}/sources/fault_handler/app_fault_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o: sources/fault_handler/drivers/drv_fault_handler.c  .generated_files/flags/320/5f15d2c4c04f922879e07757199224aa78d158f6 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler/drivers" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/drivers/drv_fault_handler.c  -o ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o: sources/fault_handler/drivers/drv_trap_handler.c  .generated_files/flags/320/35d7c8e8acbe036e99291da4cfaf1423087e286d .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler/drivers" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/drivers/drv_trap_handler.c  -o ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_control.o: sources/power_control/app_power_control.c  .generated_files/flags/320/57412b3edae5832e9c15bf5781632c13b36883c3 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_control.c  -o ${OBJECTDIR}/sources/power_control/app_power_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_control.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_control_isr.o: sources/power_control/app_power_control_isr.c  .generated_files/flags/320/b55d222a161279d7fecb5018d8f62e0ee9b61d13 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control_isr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_control_isr.c  -o ${OBJECTDIR}/sources/power_control/app_power_control_isr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_config.o: sources/power_control/app_power_config.c  .generated_files/flags/320/ac7dbe102016a72e64631025bc7dcf494d71150b .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_config.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_config.c  -o ${OBJECTDIR}/sources/power_control/app_power_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_config.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o: sources/power_control/devices/templates/dev_sepic_ptemp_adc.c  .generated_files/flags/320/85c75e7687b2fc45fa738de6e2d887fc2fe0203 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_adc.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o: sources/power_control/devices/templates/dev_sepic_ptemp_dac.c  .generated_files/flags/320/a85f3d9444ab16f0a29e0d7f5182dc1e1cde94b7 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_dac.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o: sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c  .generated_files/flags/320/3bed621208c5317064aa89421fa788d409a5d900 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o: sources/power_control/devices/dev_sepic_opstates.c  .generated_files/flags/320/73c3feac524348111c373d45138bbdd22ff81e8e .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_opstates.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o: sources/power_control/devices/dev_sepic_pconfig.c  .generated_files/flags/320/4992daeed57826d840cbf8dde7818e26ae988f .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_pconfig.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o: sources/power_control/devices/dev_sepic_special_functions.c  .generated_files/flags/320/fb6eae030ea5cda57019fbf02355a6e71fe1b3fc .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_special_functions.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o: sources/power_control/devices/dev_sepic_substates.c  .generated_files/flags/320/1248fbc30ab7a7b595105041fcc272a87571ef .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_substates.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/i_loop.o: sources/power_control/drivers/i_loop.c  .generated_files/flags/320/d004ad013aac49260479321d22ad9ab3f046dbb6 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/drivers/i_loop.c  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop.o: sources/power_control/drivers/v_loop.c  .generated_files/flags/320/1dcf40fb6b2e6673e2006b644909e74b25552d3 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/drivers/v_loop.c  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o: sources/common/p33c_pral/p33c_pwm.c  .generated_files/flags/320/af70fc8109495274c053d6fdbc6c6743516cb87e .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_pwm.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o: sources/common/p33c_pral/p33c_gpio.c  .generated_files/flags/320/a4d3aea3008d8a988ec87040452121c63034ed42 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_gpio.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o: sources/common/p33c_pral/p33c_dsp.c  .generated_files/flags/320/80b50c17a6afd92ac324255861b55f7b2334b7f7 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_dsp.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o: sources/common/p33c_pral/p33c_osc.c  .generated_files/flags/320/3c21ebe02175c5c2c2ab45254d88f36ca797d656 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_osc.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o: sources/common/p33c_pral/p33c_dac.c  .generated_files/flags/320/13fe2a14a427f7d51f4216f341dd6140e752242f .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_dac.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o: sources/common/p33c_pral/p33c_opa.c  .generated_files/flags/320/b9f30551bc975cea7096c65ba011b210c1a433c9 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_opa.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_opa.o: sources/config/init/init_opa.c  .generated_files/flags/320/ed03aa8c4582c36f7bec615ceefdae5b48f5a314 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_opa.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_opa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_opa.c  -o ${OBJECTDIR}/sources/config/init/init_opa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_opa.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_dac.o: sources/config/init/init_dac.c  .generated_files/flags/320/a6abc318114b20c584297dfb5b14cb02963d653b .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_dac.c  -o ${OBJECTDIR}/sources/config/init/init_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_dac.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_ios.o: sources/config/init/init_ios.c  .generated_files/flags/320/a44043cff10d60497741eb7ec5d7f089b837fcc .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_ios.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_ios.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_ios.c  -o ${OBJECTDIR}/sources/config/init/init_ios.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_ios.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/config_bits.o: sources/config/config_bits.c  .generated_files/flags/320/136632dac3f61e737143d92c63e9dc600db30773 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/config_bits.o.d 
	@${RM} ${OBJECTDIR}/sources/config/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/config_bits.c  -o ${OBJECTDIR}/sources/config/config_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/config_bits.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/apps.o: sources/config/apps.c  .generated_files/flags/320/8fd4379c14040008b2f5b9750f865d9251d7ec46 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/apps.o.d 
	@${RM} ${OBJECTDIR}/sources/config/apps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/apps.c  -o ${OBJECTDIR}/sources/config/apps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/apps.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/usercfg.o: sources/config/usercfg.c  .generated_files/flags/320/cf8db05e8b181a2525831a7b3b936fa16ca91dc4 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/usercfg.o.d 
	@${RM} ${OBJECTDIR}/sources/config/usercfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/usercfg.c  -o ${OBJECTDIR}/sources/config/usercfg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/usercfg.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_dsp.o: sources/os/boot/rtos_dsp.c  .generated_files/flags/320/1d3786bd73a90f9e2796a54e2684db9e6b207487 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_dsp.c  -o ${OBJECTDIR}/sources/os/boot/rtos_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_fosc.o: sources/os/boot/rtos_fosc.c  .generated_files/flags/320/33f20b1a03c11d6cf82793cdc1955d324bffa3a0 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_fosc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_fosc.c  -o ${OBJECTDIR}/sources/os/boot/rtos_fosc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_gpio.o: sources/os/boot/rtos_gpio.c  .generated_files/flags/320/168429db9b3a172022d199b4738021f0a9552d6d .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_gpio.c  -o ${OBJECTDIR}/sources/os/boot/rtos_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_pmd.o: sources/os/boot/rtos_pmd.c  .generated_files/flags/320/8a2fa8cd0d70759c04ef3cfd01723f58962aa3a .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_pmd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_pmd.c  -o ${OBJECTDIR}/sources/os/boot/rtos_pmd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_timer.o: sources/os/boot/rtos_timer.c  .generated_files/flags/320/d1455a7629f0e68995e25377b1aadebaf5c996a4 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_timer.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_timer.c  -o ${OBJECTDIR}/sources/os/boot/rtos_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_timer.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/rtos.o: sources/os/rtos.c  .generated_files/flags/320/a72dba628cf3c451db5e2899a94053edbed57a94 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os" 
	@${RM} ${OBJECTDIR}/sources/os/rtos.o.d 
	@${RM} ${OBJECTDIR}/sources/os/rtos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/rtos.c  -o ${OBJECTDIR}/sources/os/rtos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/rtos.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot.o: sources/os/boot.c  .generated_files/flags/320/35ef0f1359eee6a5c321a17665a80c67fe524e21 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os" 
	@${RM} ${OBJECTDIR}/sources/os/boot.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot.c  -o ${OBJECTDIR}/sources/os/boot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/main.o: sources/main.c  .generated_files/flags/320/b5bd221ce80c102591fa9a58ab79936fbe66cc95 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/main.o.d 
	@${RM} ${OBJECTDIR}/sources/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/main.c  -o ${OBJECTDIR}/sources/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o: sources/power_control/devices/dev_sepic_converter320.c  .generated_files/flags/320/eaeadf4e0ae9fb1aa6e786705aaadaa60a415391 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_converter320.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o: sources/fault_handler/app_fault_monitor.c  .generated_files/flags/320/a919fe9be893ebcfa39e69e53b3439b2814938c7 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/app_fault_monitor.c  -o ${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/app_fault_monitor.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/app_fault_config.o: sources/fault_handler/app_fault_config.c  .generated_files/flags/320/3107048f82ace35c06ce0828b7f3925e86b46831 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/app_fault_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/app_fault_config.c  -o ${OBJECTDIR}/sources/fault_handler/app_fault_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/app_fault_config.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o: sources/fault_handler/drivers/drv_fault_handler.c  .generated_files/flags/320/debecace483bd344c62ec3fe290218614e5a2d11 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler/drivers" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/drivers/drv_fault_handler.c  -o ${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/drivers/drv_fault_handler.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o: sources/fault_handler/drivers/drv_trap_handler.c  .generated_files/flags/320/fd9f4d996f7abb59de0dc1f1c0b9011cddbc0861 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/fault_handler/drivers" 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d 
	@${RM} ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/fault_handler/drivers/drv_trap_handler.c  -o ${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/fault_handler/drivers/drv_trap_handler.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_control.o: sources/power_control/app_power_control.c  .generated_files/flags/320/b5f3517db765235c4a92b466f351c290fbbd8bc1 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_control.c  -o ${OBJECTDIR}/sources/power_control/app_power_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_control.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_control_isr.o: sources/power_control/app_power_control_isr.c  .generated_files/flags/320/35a01fbf66d6e3f62169c2ed770acd5bef4cfedf .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_control_isr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_control_isr.c  -o ${OBJECTDIR}/sources/power_control/app_power_control_isr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_control_isr.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/app_power_config.o: sources/power_control/app_power_config.c  .generated_files/flags/320/7c4bffbdce90497683328fc69a43bb175dae8d41 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control" 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_config.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/app_power_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/app_power_config.c  -o ${OBJECTDIR}/sources/power_control/app_power_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/app_power_config.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o: sources/power_control/devices/templates/dev_sepic_ptemp_adc.c  .generated_files/flags/320/638cc328153ad8265c19d3a9a805eff79d47b5f3 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_adc.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_adc.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o: sources/power_control/devices/templates/dev_sepic_ptemp_dac.c  .generated_files/flags/320/8e4c37ec4a7420b1a1cc5034b6660a95e3b38248 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_dac.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_dac.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o: sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c  .generated_files/flags/320/8ce4f90177b3e15b049961db39e380014da0fb87 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices/templates" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/templates/dev_sepic_ptemp_pwm.c  -o ${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/templates/dev_sepic_ptemp_pwm.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o: sources/power_control/devices/dev_sepic_opstates.c  .generated_files/flags/320/cf663f278abe8306ae620e8b27da8c4009d67395 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_opstates.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_opstates.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o: sources/power_control/devices/dev_sepic_pconfig.c  .generated_files/flags/320/6d8fc9c05c007d5c5a2a5c740f56a8f469c6d96 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_pconfig.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_pconfig.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o: sources/power_control/devices/dev_sepic_special_functions.c  .generated_files/flags/320/2e61c2352f1b05decedb618b22a71657b41735ea .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_special_functions.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_special_functions.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o: sources/power_control/devices/dev_sepic_substates.c  .generated_files/flags/320/da4e68e87bc6537bdc62b85746b524bf1418b7e9 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_substates.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_substates.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/i_loop.o: sources/power_control/drivers/i_loop.c  .generated_files/flags/320/23c3fb5c44a1ce424a1d315af4e3dfd3545ce209 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/drivers/i_loop.c  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/drivers/i_loop.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop.o: sources/power_control/drivers/v_loop.c  .generated_files/flags/320/3adf527aedda4208fefe95c9a7783728cc497409 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/drivers/v_loop.c  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/drivers/v_loop.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o: sources/common/p33c_pral/p33c_pwm.c  .generated_files/flags/320/8c092e7ea904480e403cb899c257652e0407be73 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_pwm.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_pwm.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o: sources/common/p33c_pral/p33c_gpio.c  .generated_files/flags/320/b2fc3687517df9dfa5b48ba356208aa9c1f8deb3 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_gpio.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_gpio.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o: sources/common/p33c_pral/p33c_dsp.c  .generated_files/flags/320/31dae7c16378ebb6314a554cbd8b54c08c0dab7f .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_dsp.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_dsp.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o: sources/common/p33c_pral/p33c_osc.c  .generated_files/flags/320/44bf13fd43013d36e2a129154e85cc56064f7a57 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_osc.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_osc.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o: sources/common/p33c_pral/p33c_dac.c  .generated_files/flags/320/60acfc51101b19659b8c378fff72a84aad095924 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_dac.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_dac.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o: sources/common/p33c_pral/p33c_opa.c  .generated_files/flags/320/54aaa490010e311a41908f46e2db1aa93c1bed80 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/common/p33c_pral" 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d 
	@${RM} ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/common/p33c_pral/p33c_opa.c  -o ${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/common/p33c_pral/p33c_opa.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_opa.o: sources/config/init/init_opa.c  .generated_files/flags/320/f8d1a9f26642a1a9011394ed4e6e95d10b4edddf .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_opa.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_opa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_opa.c  -o ${OBJECTDIR}/sources/config/init/init_opa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_opa.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_dac.o: sources/config/init/init_dac.c  .generated_files/flags/320/b42f72315d1d20bd91329320c62b02db590684a1 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_dac.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_dac.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_dac.c  -o ${OBJECTDIR}/sources/config/init/init_dac.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_dac.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/init/init_ios.o: sources/config/init/init_ios.c  .generated_files/flags/320/8f0c24641a62c88a414db4fd258ad78b7e6c59f0 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config/init" 
	@${RM} ${OBJECTDIR}/sources/config/init/init_ios.o.d 
	@${RM} ${OBJECTDIR}/sources/config/init/init_ios.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/init/init_ios.c  -o ${OBJECTDIR}/sources/config/init/init_ios.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/init/init_ios.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/config_bits.o: sources/config/config_bits.c  .generated_files/flags/320/7b7a0da8c8095c1482df14ed247053f733064e44 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/config_bits.o.d 
	@${RM} ${OBJECTDIR}/sources/config/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/config_bits.c  -o ${OBJECTDIR}/sources/config/config_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/config_bits.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/apps.o: sources/config/apps.c  .generated_files/flags/320/5e555f7683fb9a8fc3f2bb255e78ef4f7f94d4d0 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/apps.o.d 
	@${RM} ${OBJECTDIR}/sources/config/apps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/apps.c  -o ${OBJECTDIR}/sources/config/apps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/apps.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/config/usercfg.o: sources/config/usercfg.c  .generated_files/flags/320/7d4c0a389fae5af7177f2dfbed1352944b4cf22 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/config" 
	@${RM} ${OBJECTDIR}/sources/config/usercfg.o.d 
	@${RM} ${OBJECTDIR}/sources/config/usercfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/config/usercfg.c  -o ${OBJECTDIR}/sources/config/usercfg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/config/usercfg.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_dsp.o: sources/os/boot/rtos_dsp.c  .generated_files/flags/320/17437fb26fc330f56aecb413ab06016172841420 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_dsp.c  -o ${OBJECTDIR}/sources/os/boot/rtos_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_dsp.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_fosc.o: sources/os/boot/rtos_fosc.c  .generated_files/flags/320/f0b8854467e6d93a63f9fe00dfe4aa51917533da .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_fosc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_fosc.c  -o ${OBJECTDIR}/sources/os/boot/rtos_fosc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_fosc.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_gpio.o: sources/os/boot/rtos_gpio.c  .generated_files/flags/320/5d6b36d84643ae30379b4f03d10ffed20db43a09 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_gpio.c  -o ${OBJECTDIR}/sources/os/boot/rtos_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_gpio.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_pmd.o: sources/os/boot/rtos_pmd.c  .generated_files/flags/320/820e2e8eece8b1e0aa4f4fbe8aa0261364660e07 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_pmd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_pmd.c  -o ${OBJECTDIR}/sources/os/boot/rtos_pmd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_pmd.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot/rtos_timer.o: sources/os/boot/rtos_timer.c  .generated_files/flags/320/4b08b9b13b50b682ad93dd8a02a2d9cc9681b14d .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os/boot" 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_timer.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot/rtos_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot/rtos_timer.c  -o ${OBJECTDIR}/sources/os/boot/rtos_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot/rtos_timer.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/rtos.o: sources/os/rtos.c  .generated_files/flags/320/3a3ee56f9bf47d25f2de9306d89446fb2a474192 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os" 
	@${RM} ${OBJECTDIR}/sources/os/rtos.o.d 
	@${RM} ${OBJECTDIR}/sources/os/rtos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/rtos.c  -o ${OBJECTDIR}/sources/os/rtos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/rtos.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/os/boot.o: sources/os/boot.c  .generated_files/flags/320/5aeeae3ac7e171830ef02ed977e0cf041ebd02ac .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/os" 
	@${RM} ${OBJECTDIR}/sources/os/boot.o.d 
	@${RM} ${OBJECTDIR}/sources/os/boot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/os/boot.c  -o ${OBJECTDIR}/sources/os/boot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/os/boot.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/main.o: sources/main.c  .generated_files/flags/320/34cea3ea05a914c4576fe802f765451ebb404b41 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/main.o.d 
	@${RM} ${OBJECTDIR}/sources/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/main.c  -o ${OBJECTDIR}/sources/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/main.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o: sources/power_control/devices/dev_sepic_converter320.c  .generated_files/flags/320/1c053fcf3844527f0a4889cdce69f6c278e0a607 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/devices" 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sources/power_control/devices/dev_sepic_converter320.c  -o ${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sources/power_control/devices/dev_sepic_converter320.o.d"      -mno-eds-warn  -g -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -msmall-code -msmall-data -O0 -I"sources" -msmart-io=1 -Wall -msfr-warn=on    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o: sources/power_control/drivers/i_loop_asm.s  .generated_files/flags/320/90f818007664a767efe6418b71179e47372a9b6d .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/i_loop_asm.s  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o: sources/power_control/drivers/v_loop_asm.s  .generated_files/flags/320/9bab6d67e42c2d0d0312af6f9169f85b59870102 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/v_loop_asm.s  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o: sources/power_control/drivers/v_loop_extensions.s  .generated_files/flags/320/38b00f68389244aa6a717549a564c9e9c3b9bad2 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/v_loop_extensions.s  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o: sources/power_control/drivers/i_loop_agc.s  .generated_files/flags/320/85d3340ba43b18f601ecc2a309a651bd74664185 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/i_loop_agc.s  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o: sources/power_control/drivers/i_loop_asm.s  .generated_files/flags/320/b15c561ed7f6ee4fccd52e8d9b465d762fa1688c .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/i_loop_asm.s  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/i_loop_asm.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o: sources/power_control/drivers/v_loop_asm.s  .generated_files/flags/320/753087683fd7c7f7f975d5adab41ee18340c7bae .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/v_loop_asm.s  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/v_loop_asm.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o: sources/power_control/drivers/v_loop_extensions.s  .generated_files/flags/320/b59f52d8cd6595984a600226911732f829b6ef16 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/v_loop_extensions.s  -o ${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/v_loop_extensions.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o: sources/power_control/drivers/i_loop_agc.s  .generated_files/flags/320/fcc119bac8e77175a9b6a54b81fa994e5b26d821 .generated_files/flags/320/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sources/power_control/drivers" 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d 
	@${RM} ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sources/power_control/drivers/i_loop_agc.s  -o ${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    -I"sources/common/p33c_pral" -Wa,-MD,"${OBJECTDIR}/sources/power_control/drivers/i_loop_agc.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral"     -Wl,--local-stack,--preserve-all,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/c2303-SEPIC-vmc-vout.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -D__c2303_r10__ -DXPRJ_320=$(CND_CONF)    $(COMPARISON_BUILD)  -I"sources/common/p33c_pral" -Wl,--local-stack,--preserve-all,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
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
