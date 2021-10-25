%include "io.inc"

section .text
global CMAIN
CMAIN:
    
    call rec
    
    xor eax, eax
    ret
    
rec:
    push    ebp
    mov     ebp, esp
    
    GET_DEC 4, eax
    
    cmp eax, 0
    je .end
    
    push eax
    call rec
    pop eax
    PRINT_DEC 4, eax
    PRINT_CHAR ' '
    
.end:
    mov esp, ebp
    pop ebp
    ret
