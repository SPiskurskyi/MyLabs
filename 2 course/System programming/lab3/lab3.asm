.386
.model flat, stdcall
.stack 4096

GetStdHandle proto :dword
WriteConsoleA proto :dword, :dword, :dword, :dword, :dword
wsprintfA PROTO C :dword, :dword, :vararg
ExitProcess proto :dword

.data 
B db 36h ; 54
Cc db 64h ; 100
D dw 3E8h ; 1000
F dw 0Ah ; 10
E db 5h ; 5
K equ 45781022h ; 1165496354
Message db 'X = K - B - C - D / E + F * B =               ', 13, 10  ;   1 165 496 540 DEC ||  4578 10DC HEX
NumberOfCharsToWrite dd $-Message
format db '%d', 0
hConsoleOutput dd 0
NumberOfCharsWritten dd 0

.code
start:
; X = K - B - C - D / E + F * B

;K - B -> edx
movsx   eax, B
mov     edx, K
sub     edx, eax

;K - B - C -> ecx
movsx   eax, Cc
mov     ecx, edx
sub     ecx, eax

;D / E -> eax
movsx   eax, D
movsx   esi, E
cdq
idiv    esi

;K - B - C - D / E -> ecx
sub     ecx, eax

;F * B -> eax
movsx   edx, F
movsx   eax, B
imul    eax, edx

;K - B - C - D / E + F * B -> eax
add     eax, ecx


;result in eax
push eax
push offset format
push offset [Message+32]
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
