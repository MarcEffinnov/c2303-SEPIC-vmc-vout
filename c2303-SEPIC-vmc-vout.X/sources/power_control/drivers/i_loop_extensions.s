; **********************************************************************************
;  SDK Version: PowerSmart(TM) Digital Control Library Designer v0.9.12.660
;  CGS Version: Code Generator Script v3.0.2 (01/05/2021)
;  Author:      M91406
;  Date/Time:   01/12/2021 21:22:33
; **********************************************************************************
;  Template for user extension functions extending functions of the common
;  control loop code using User Extension Hooks. These extensions allow user 
;  to tie in proprietary user code into the assembly routine of the main control
;  loop.
;
;  Please refer to the PS-DCLD User Guide for details about how to use this
;  feature.
;
; **********************************************************************************
    
;------------------------------------------------------------------------------
; file start
    .nolist                                 ; (no external dependencies)
    .list                                   ; list of all external dependencies
    
;------------------------------------------------------------------------------
; local inclusions.
    .section .data                          ; place constant data in the data section
    
;------------------------------------------------------------------------------
; include NPNZ16B_t data structure and global constants to allow access
; to the active control loop data object
 
    .include "./sources/power_control/drivers/npnz16b.inc" ; include NPNZ16b_t object data structure value offsets and status flag labels
    
;------------------------------------------------------------------------------
; source code section.
    .section .text                          ; place code in the text section
    
;------------------------------------------------------------------------------
; Global function call prototype declarations
; These global function calls are used to publish functions across the 
; application. Add a function call prototype to a C-header file to allow 
; calling this function from C-code.
;
;        extern void __attribute__((near))my_function(void);
;
;------------------------------------------------------------------------------

    .global _Triggers_Update_Half_Toff                  ; provide global scope to routine
 
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; User Functions
;------------------------------------------------------------------------------
    
;------------------------------------------------------------------------------
; MY FUNCTION is a simple function template, when used as a user extension 
; function, this function will be directly called by a CALL Wn instruction
; to minimize the function call overhead to 2 instruction cycles only. 
; However, there is no context handling as it is assumed user extension
; functions are commonly using the same data object as the main control loop.
; Hence, all data is kept in its place just like this code would be part of
; the main loop itself.
;    
; Please refer to the PS-DCLD User Guide for details about how to use this
; feature, which working registers are in use by the main loop and which
; can/may be used and/or manipulated by this routine.
;
;------------------------------------------------------------------------------
; Start of routine
_myfunction:                               ; local function label (placeholder)
    ; Called from compensator assembly routine, w0 stores pointer to NPNZ structure
    ; W4, W8, W6, W10, W12 are used by compensator routine and poped at the end => free to use
    mov [w0 + #ptrTargetRegister], w4	    ; load duty cycle value to W4
    mov [w0 + #usrParam0], w6		    ; load PWM period value to W6 (passed as user custom parameter in config
    sub w6, w4, w8			    ; Calculate difference PERIOD - DC (TON) = TOFF and load in w8
    asr w8, #1, w10			    ; Calculate TOFF/2 value by shifting 1-bit right and store in w10
    add w4, w10, w8			    ; add DC (TON) + TOFF/2 to set default trigger placement; result store in w8
    
    ; Update ADC trigger B position 
    mov [w0 + #ADCTriggerBOffset], w12      ; load user-defined ADC trigger B offset value into working register w12
    add w8, w12, w10                        ; add user-defined ADC trigger B offset to previously calculated default trigger placement. Result stored in w10
    mov [w0 + #ptrADCTriggerBRegister], w4  ; load pointer to ADC trigger B register into working register w4
    mov w10, [w4]                           ; push new ADC trigger value to ADC trigger B register

    ; Update ADC trigger A position 
    mov [w0 + #ADCTriggerAOffset], w12      ; load user-defined ADC trigger A offset value into working register w12
    add w8, w12, w10                        ; add user-defined ADC trigger A offset to previously calculated default trigger placement. Result stored in w10
    mov [w0 + #ptrADCTriggerBRegister], w4  ; load pointer to ADC trigger A register into working register w4
    mov w10, [w4]                           ; push new ADC trigger value to ADC trigger B register    
    
;------------------------------------------------------------------------------
; End of routine
    return                                  ; end of function; return to caller
    
;------------------------------------------------------------------------------

    
;------------------------------------------------------------------------------
; End of file
    .end                                    ; end of file v_loop_extensions.s
    
;------------------------------------------------------------------------------

     
; **********************************************************************************
;  Download latest version of this tool here: https://microchip-pic-avr-tools.github.io/powersmart-dcld
; **********************************************************************************
