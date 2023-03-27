.386
.model flat, stdcall
.stack 4096

GetStdHandle proto :dword
WriteConsoleA proto :dword, :dword, :dword, :dword, :dword
ExitProcess proto :dword

.data 
A dq 12356789ABCDEFh
B dw 0CFA5h, 0AB3Ch
Cc dq 0.16e9
LBL LABEL BYTE
D dq 0090003261ABCDh
E dt 1187591ABC85C11123h
F dq 02356789ABCDEFh
K equ 45781022h
HelloMessage db 'Piskurskyi', 13, 10
NumberOfCharsToWrite dd $-HelloMessage
hConsoleOutput dd 0
NumberOfCharsWritten dd 0

.code
start:
push -11
call GetStdHandle
mov hConsoleOutput, eax
push 0
push offset NumberOfCharsWritten
push NumberOfCharsToWrite
push offset HelloMessage
push hConsoleOutput
call WriteConsoleA
push 0
call ExitProcess
end start
