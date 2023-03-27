.386
.model flat, stdcall
.stack 4096

GetStdHandle proto :dword
WriteConsoleA proto :dword, :dword, :dword, :dword, :dword
wsprintfA PROTO C :dword, :dword, :vararg
ExitProcess proto :dword

.data 
A db 50
B db -5
MessageSuccess db 'X =                  ', 13, 10
NumberOfCharsToWriteSuccess dd $-MessageSuccess
MessageError db 'ERROR!', 13, 10
NumberOfCharsToWriteError dd $-MessageError
format db '%d', 0
hConsoleOutput dd 0
NumberOfCharsWritten dd 0

.code
start:
; if A != B, goto A_NE_B
    movsx   eax, A
    movsx   ecx, B
    cmp     eax, ecx
    jne     SHORT A_NE_B

; here, A == B
; set result to -a and goto EXIT_SUCCESS, result in eax
    movsx   eax, A
    neg     eax
    jmp     SHORT EXIT_SUCCESS

; here, A != B
; if A <= B, goto 
A_NE_B:
    movsx   edx, A
    movsx   eax, B
    cmp     edx, eax
    jle     SHORT A_LE_B

; here, A > B
; if B != 0, goto B_NOT_ZERO
    movsx   ecx, B
    test    ecx, ecx
    jne     SHORT B_NOT_ZERO

; here, A > B and A == 0
    jmp     EXIT_ERROR ;

; here, A > B and A != 0
; calculate (4 * A - B)/B and goto EXIT_SUCCESS, result in eax
B_NOT_ZERO:
        movsx   eax, A
        imul    edx, edx, 4
        movsx   eax, B
        mov     ecx, edx
        sub     ecx, eax
        movsx   esi, B
        mov     eax, ecx
        cdq
        idiv    esi
        jmp     SHORT EXIT_SUCCESS 

; here, A <= B; since A == B was already checked, here A < B
; if A != 0, goto A_NOT_ZERO
A_LE_B:
    movsx   edx, A
    test    edx, edx
    jne     SHORT A_NOT_ZERO

; here, A < B and B == 0
    jmp     EXIT_ERROR

; here, A < B and B != 0
; calculate (B - A) / A and goto EXIT_SUCCESS, result in eax
A_NOT_ZERO:
    movsx   edx, B
    movsx   eax, A
    sub     edx, eax
    mov     ecx, edx
    movsx   edi, A
    mov     eax, ecx
    cdq
    idiv    edi

EXIT_SUCCESS:
    ; result in eax
    push eax
    push offset format
    push offset [MessageSuccess+4]
    call wsprintfA

    push -11
    call GetStdHandle
    mov hConsoleOutput, eax
    push 0
    push offset NumberOfCharsWritten
    push NumberOfCharsToWriteSuccess
    push offset MessageSuccess
    push hConsoleOutput
    call WriteConsoleA

    jmp     SHORT EXIT

EXIT_ERROR:
    push -11
    call GetStdHandle
    mov hConsoleOutput, eax
    push 0
    push offset NumberOfCharsWritten
    push NumberOfCharsToWriteError
    push offset MessageError
    push hConsoleOutput
    call WriteConsoleA

EXIT:
    push 0
    call ExitProcess
end start
