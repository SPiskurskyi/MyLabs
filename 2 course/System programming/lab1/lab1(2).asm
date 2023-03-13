.686
.model flat, stdcall
option casemap:none

AllocConsole proto STDCALL
GetStdHandle proto STDCALL, nStdHandle : DWORD
WriteConsoleA proto STDCALL, hConsoleOutput : DWORD, lpBuffert : DWORD, nNumberOfCharsToWrite : DWORD, lpNumberOfCharsWritten : DWORD, lpReserved : DWORD  
ExitProcess proto STDCALL, uExitCode : DWORD
ReadConsoleA proto STDCALL,  hConsoleInput : DWORD, lpBuffer : DWORD, nNumberOfCharsToRead : DWORD, lpNumberOfCharsRead : DWORD, pInputControl : DWORD

.data
hConsoleOutput dd 0
NumberOfCharsWritten dd 0
Symbol db 5 dup(32), 32 dup (176),10
;sum32
db 5 dup(32),4 dup (176),5 dup(219),9 dup (176),4 dup (176),5 dup(219),5 dup (176),10
db 5 dup(32),5 dup (176),5 dup(219),7 dup (176),3 dup (176),6 dup(219),6 dup (176),10
db 5 dup(32),6 dup (176),6 dup(219),5 dup (176),2 dup (176),6 dup(219),7 dup (176),10
db 5 dup(32),7 dup (176),7 dup(219),3 dup (176),1 dup (176),6 dup(219),8 dup (176),10
db 5 dup(32),8 dup (176),14 dup(219),10 dup (176),10
db 5 dup(32),9 dup (176),11 dup(219),12 dup (176),10
db 5 dup(32),11 dup (176),8 dup(219),13 dup (176),10
db 5 dup(32),11 dup (176),6 dup(219),15 dup (176),10
db 5 dup(32),10 dup (176),6 dup(219),16 dup (176),10
db 5 dup(32),9 dup (176),5 dup(219),18 dup (176),10
db 5 dup(32),8 dup (176),4 dup(219),20 dup (176),10
db 5 dup(32),5 dup (176),5 dup(219),22 dup (176),10

db 5 dup(32), 32 dup (176),10

NumberOfCharsToWrite dd $-Symbol
ReadBuf db 128 dup(?)
hConsoleInput dd 0
.code
start:
call AllocConsole
push -11
call GetStdHandle
mov hConsoleOutput, eax
push 0
push offset NumberOfCharsWritten
push NumberOfCharsToWrite
push offset Symbol
push hConsoleOutput
call WriteConsoleA
push -10
call GetStdHandle
mov hConsoleInput, eax
push 0
push offset NumberOfCharsWritten
push 128
push offset ReadBuf
push hConsoleInput
call ReadConsoleA
push 0
call ExitProcess
end start