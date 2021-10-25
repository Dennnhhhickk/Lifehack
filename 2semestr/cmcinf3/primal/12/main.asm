%include "io.inc"

section .bss
    NM equ 0x400 ; 1024
    N equ 0x20 ; 32
    M equ 0x80 ; 32 * 4 = 128 = 0x80

    n resd 0x1
    k resd 0x1
    a resd NM
    ans resd 0x1
    

section .text

global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    mov dword[ans], 0
    GET_DEC 0x4, n
    GET_DEC 0x4, k
    
    cmp dword[n], 0
    je .END
    
    xor eax, eax
    .1:
        mov dword[a + eax * 0x4], 0x0
    
    inc eax
    cmp eax, NM
    jl .1
    
    xor eax, eax
    .2:
        mov edx, eax
        imul edx, M
        mov dword[a + edx], 0x1
        
        cmp eax, 0x0
        jle .4
            mov ebx, 0x1
            .3:
            imul edx, eax, M
            imul ecx, ebx, 0x4
            add ecx, edx
            mov edx, dword[a + ecx - M]
            add edx, dword[a + ecx - M - 0x4]
            mov dword[a + ecx], edx
        
            inc ebx
            cmp ebx, eax
            jl .3
        .4:
        imul ecx, eax, M + 0x4
        mov dword[a + ecx], 0x1

    inc eax
    cmp eax, N ; 32
    jl .2
    
    ;xor eax, eax
    ;.5:
    ;    xor ebx, ebx
    ;    .6:
    ;    cmp ebx, eax
    ;    ja .OUTT
    ;        imul ecx, eax, M
    ;        PRINT_DEC 4, [a + ecx + ebx * 0x4]
    ;        PRINT_CHAR ' '
    ;    
    ;    inc ebx
    ;    jmp .6
    ;.OUTT:
    ;NEWLINE
    ;inc eax
    ;cmp eax, N
    ;jb .5
    
    bsr eax, dword[n]
    cmp eax, dword[k]
    jl .END
    
    mov eax, dword[n]
    bsr edx, eax
    inc edx
    .7:
        bsr ecx, eax
        mov ebx, 0x1
        .lop0:
        cmp ecx, 0x0
        jle .lop1
            shl ebx, 0x1
            dec ecx
            jmp .lop0
        .lop1:
        dec edx
        sub eax, ebx
    
    cmp eax, 0x0
    jne .7
    
    cmp edx, dword[k]
    jne .8
    inc dword[ans]
.8:

    mov eax, dword[k]
    bsr ebx, dword[n]
    cmp eax, ebx
    jnl .10
    .9:
        imul ecx, eax, M
        mov edx, dword[k]
        mov edx, [a + ecx + edx * 0x4]
        add dword[ans], edx
    inc eax
    cmp eax, ebx
    jl .9
    
    .10:
        mov eax, dword[n]
        bsr ecx, eax
        mov ebx, 0x1
        .lop2:
        cmp ecx, 0x0
        jle .lop3
            shl ebx, 0x1
            dec ecx
            jmp .lop2
        .lop3:
        sub eax, ebx
        xor ebx, ebx
        sub ebx, 0x1
        cmp eax, 0x0
        je .hh
        bsr ebx, eax
        .hh:
        bsr ecx, dword[n]
        mov dword[n], eax
        sub ecx, ebx
        dec ecx
        sub dword[k], ecx
        cmp ebx, 0x0
        jl .11
        cmp dword[k], 0x1
        jl .11
        imul ecx, ebx, M
        mov edx, dword[k]
        mov eax, dword[a + ecx + edx * 0x4 - 0x4]
        add dword[ans], eax
        .11:
    cmp dword[n], 0x0
    jg .10
    
    
.END:    
    ;PRINT_CHAR '$'
    PRINT_DEC 0x4, [ans]
    xor eax, eax
    ret
