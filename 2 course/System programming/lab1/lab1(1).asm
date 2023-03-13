.686
.model flat, stdcall
option casemap:none

GetStdHandle proto STDCALL, nStdHandle : DWORD
WriteConsoleA proto STDCALL, hConsoleOutput : DWORD, lpBuffert : DWORD, nNumberOfCharsToWrite : DWORD, lpNumberOfCharsWritten : DWORD, lpReserved : DWORD  
ExitProcess proto STDCALL, uExitCode : DWORD

.data
hConsoleOutput dd 0
NumberOfCharsWritten dd 0
Surname db 'Piskurskyi', 10, 13   
NumberOfCharsToWrite dd $-Surname 
.code
start:
push -11
call GetStdHandle
mov hConsoleOutput, eax
push 0
push offset NumberOfCharsWritten
push NumberOfCharsToWrite
push offset Surname 
push hConsoleOutput
call WriteConsoleA
push 0
call ExitProcess
end start