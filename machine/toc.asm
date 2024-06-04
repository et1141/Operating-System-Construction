;******************************************************************************
;* Operating-System Construction                                              *
;*----------------------------------------------------------------------------*
;*                                                                            *
;*                               T O C . A S M                                *
;*                                                                            *
;*----------------------------------------------------------------------------*
;*
;******************************************************************************

%include "machine/toc.inc"

; EXPORTED FUNCTIONS

[GLOBAL toc_switch]
[GLOBAL toc_go]

; FUNCTION IMPLEMENTATIONS

[SECTION .text]

; TOC_GO: Starts the very first process.
;
; C prototype: void toc_go(struct toc* regs);

toc_go:
; rdi points to begining of struct toc
    mov rsp, [rdi]       ;rsp=regs->rsp;
    mov rbx, [rdi+8]     
    mov r12, [rdi+16]    
    mov r13, [rdi+24]    
    mov r14, [rdi+32]    
    mov r15, [rdi+40]    
    mov rbp, [rdi+48]    
    ret

; TOC_SWITCH: Context switch. Saves the current register values and replaces
;             them with values of the new "thread of control".
;
; C prototype: void toc_switch (struct toc* regs_now,
;                               struct toc* reg_then);

toc_switch:
; due to general schema for coroutine resume:
; < push non-volatile registers on the stack >(in our implementation we use struct toc instead of stack)
; < save CPU stack pointer in from_sp > 
; < load CPU stack pointer from to_sp >
; < pop non-volatile registers from the stack >

    ;
    mov [rdi+8], rbx    ;regs_now->rbx = rbx
    mov [rdi+16], r12   
    mov [rdi+24], r13
    mov [rdi+32], r14
    mov [rdi+40], r15
    mov [rdi+48], rbp
    mov [rdi], rsp     ;save CPU stack pointer in regs_now  

    mov rbx, [rsi+8]     
    mov r12, [rsi+16]    
    mov r13, [rsi+24]    
    mov r14, [rsi+32]    
    mov r15, [rsi+40]    
    mov rbp, [rsi+48]   
    mov rsp, [rsi]     ;load CPU stack pointer from regs_then
    
    ret


