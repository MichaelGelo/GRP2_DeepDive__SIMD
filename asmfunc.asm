;datatype   Bits    Bytes    Register  Allocate memory 
;char       8       1        al/ah     db (BYTE)	      
;short      16      2        ax        dw (WORD)            
;int        32      4        eax       dd (DWORD)           
;long       64      8        rax       dq (QWORD)            
%include "io64.inc"

section .data       ;initialized data
var1 dq -1,-2,-3,-4,-5,6,7,8,9,10
var2 dq 11,12,13,14,15,-16,-17,-18,-19,-20
count dq 10
section .text
bits 64
default rel

global main
extern printf

main:

XOR RCX,RCX
XOR RAX,RAX
XOR RDX,RDX

L1:
    
    
    MOV RAX,[var1 + RCX * 8]
    ;PRINT_DEC 8,RAX
    ;NEWLINE
    
    MOV RBX,[var2 + RCX * 8]
    ;PRINT_DEC 8,RBX
    ;NEWLINE
    
    IMUL RAX,RBX
    
    ADD RDX,RAX
    INC RCX
    CMP RCX,[count]
    JL L1
    
FINIS:
    PRINT_DEC 8,RDX
    NEWLINE
xor rax, rax ; comment this line if irrun na with c
ret