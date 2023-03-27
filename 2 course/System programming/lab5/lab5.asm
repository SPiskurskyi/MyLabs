.386
.model flat, stdcall
.stack 4096

GetStdHandle proto :dword
WriteConsoleA proto :dword, :dword, :dword, :dword, :dword
wsprintfA PROTO C :dword, :dword, :vararg
ExitProcess proto :dword

.data 
A dd 2
X dd 1, 2, 3, 4, 5, 6
N equ ($-X) / type X    ; N is the size of X
Message db 'SUM =               ', 13, 10
NumberOfCharsToWrite dd $-Message
format db '%d', 0
hConsoleOutput dd 0
NumberOfCharsWritten dd 0

.code
start:
        mov     esi, 0
        cmp     A, 0
        jl      SHORT FINISH
        cmp     A, N
        jg     SHORT FINISH
        mov     edi, N-1
        jmp     SHORT BODY
DECREMENT:
        sub     edi, 1
BODY:
        mov     ecx, N-1
        sub     ecx, A
        cmp     edi, ecx
        jle     SHORT FINISH
        mov     edx, edi
        mov     eax, DWORD PTR esi
        add     eax, [X+edx*4]
        mov     DWORD PTR esi, eax
        jmp     SHORT DECREMENT
FINISH:
    ; result in esi
    push esi
    push offset format
    push offset [Message+6]
    call wsprintfA

    push -11
    call GetStdHandle
    mov hConsoleOutput, eax
    push 0
    push offset NumberOfCharsWritten
    push NumberOfCharsToWrite
    push offset Message
    push hConsoleOutput
    call WriteConsoleA
    push 0
    call ExitProcess
    end start