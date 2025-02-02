section .text
default rel
global xmm
xmm:
    xor rax, rax                  
    vxorps xmm3, xmm3, xmm3        
    mov rbx, rcx                   

    test rbx, rbx                  
    jz FINIS                       

    and rbx, -2                    
    jz REMAINING                   

L1:
    vmovdqa xmm0, [r8]             
    vmovdqa xmm1, [r9]   
    
    vpmuldq xmm2, xmm0, xmm1       
    vpaddq xmm3, xmm3, xmm2 
    
    add r8, 16                     
    add r9, 16

    sub rbx, 2

    jnz L1                         

REMAINING:
    test rcx, 1                    
    jz FINIS

    mov rdi, [r8]                  
    imul rdi, [r9]                 
    add rax, rdi                   

FINIS:
    vpsrldq xmm4, xmm3, 8          
    vpaddq xmm3, xmm3, xmm4 
    
    movq rdi, xmm3                 
    add rdi, rax                   
    mov [rdx], rdi 
    
    ret
