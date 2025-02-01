section .text
global ymm

ymm:
    ; rcx = count, rdx = destination (pointer), r8 = first source, r9 = second source

    xor rax, rax               
    vxorps ymm3, ymm3, ymm3    
    mov rbx, rcx
    mov rsi, 0             

L1:
    cmp rbx, 4
    jl REMAINING               

    vmovdqu ymm0, [r8]         
    vmovdqu ymm1, [r9]          

    vpmuldq ymm2, ymm0, ymm1   
    vpaddq ymm3, ymm3, ymm2     

    add r8, 32                  
    add r9, 32
    sub rbx, 4
    jg L1

REMAINING:
    cmp rbx, 0
    je FINIS                    

    mov rdi, [r8 + rsi]         
    imul rdi, [r9 + rsi]        
    add rax, rdi               

    add rsi, 8                  
    dec rbx
    jmp REMAINING

FINIS:
    vperm2i128 ymm4, ymm3, ymm3, 1
    vpaddq ymm3, ymm3, ymm4     

    vpsrldq ymm4, ymm3, 8       
    vpaddq ymm3, ymm3, ymm4     

    movq rdi, xmm3              
    add rdi, rax                

    mov [rdx], rdi             

    ret
