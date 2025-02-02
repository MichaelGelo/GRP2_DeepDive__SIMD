;datatype   Bits    Bytes    Register  Allocate memory 
;char       8       1        al/ah     db (BYTE)	      
;short      16      2        ax        dw (WORD)            
;int        32      4        eax       dd (DWORD)           
;long       64      8        rax       dq (QWORD)     

section .text
default rel
global x86
x86:
    ;rcx count,r8-1st source, r9- 2nd source, rdx - destination

    xor rax, rax                

L1:
    mov r10, [r8]        ; load vector a
    mov r11, [r9]        ; load vector b
    imul r10, r11        
    add rax, r10         

    add r8, 8            
    add r9, 8          

    loop L1           

FINIS:
    mov [rdx], rax 
    ret
