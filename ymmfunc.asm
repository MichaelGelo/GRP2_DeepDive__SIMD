section .text
default rel
global ymm

ymm:

    ; rcx = count, rdx = destination (pointer), r8 = first source, r9 = second source
    xor rax, rax               
L1:
    cmp rcx, 4
    jl REMAINING               
    vmovdqu ymm0, [r8]         
    vmovdqu ymm1, [r9]          
    vpmuldq ymm2, ymm0, ymm1   
    vpaddq ymm3, ymm3, ymm2     
    add r8, 32                  
    add r9, 32
    sub rcx, 4
    jg L1
REMAINING:
    cmp rcx, 0
    je FINIS                    
    mov rdi, [r8]         
    imul rdi, [r9]        
    add rax, rdi               
    add r8, 8                  
    add r9, 8                 
    dec rcx
    jmp REMAINING
FINIS:
    vperm2i128 ymm4, ymm3, ymm3, 1
    vpaddq ymm3, ymm3, ymm4     
    vpsrldq ymm4, ymm3, 8       
    vpaddq ymm3, ymm3, ymm4     
    movq rdx, xmm3              
    add rdx, rax 
    
    ret
