.386
.model flat, stdcall
.stack 4096

GetStdHandle proto :dword
WriteConsoleA proto :dword, :dword, :dword, :dword, :dword
ExitProcess proto :dword

.data
hConsoleOutput dd 0
NumberOfCharsWritten dd 0
HelloMessage db \
'\  /', 13, 10, \
' \/', 13, 10, \
' /', 13, 10
NumberOfCharsToWrite dd $-HelloMessage

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