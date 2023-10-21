.686
.model flat, c
printf proto c : vararg
EXTERN K : DWORD
.data
msg db 'Output from asm module is: %d', 0
.code
calc PROC
    push ebp
    mov ebp, esp

    ; X = A + (4*C) - D/2 + K

    mov eax, dword ptr [ebp+8]  ; Завантаження A в EAX
    mov ecx, dword ptr [ebp+12] ; Завантаження C в ECX
    mov edx, dword ptr [ebp+16] ; Завантаження D в EDX
    
    shl ecx, 2 ; 4 * C
    add eax, ecx ; A + 4*C
    
    shr edx, 1 ; D / 2
    sub eax, edx ; A + 4*C - D/2
    
    add eax, K ; A + 4*C - D/2 + K
    
    pop ebp
    push eax
    invoke printf, offset msg, eax
    pop eax
    ret
calc ENDP
END