.686
.model flat, stdcall
option casemap:none
include C:\masm32\include\windows.inc
include C:\masm32\include\kernel32.inc
include C:\masm32\include\user32.inc
include C:\masm32\include\msvcrt.inc
includelib C:\masm32\lib\kernel32.lib
includelib C:\masm32\lib\user32.lib
includelib C:\masm32\lib\msvcrt.lib
.data
X dd 5 dup(0) ;масив
N equ ($-X) / type X ;розмір масиву
A dd 10
Res dd ? ;результат
hConsoleInput dd 0 ;дескриптор консолі для вводу
hConsoleOutput dd 0 ;дескриптор консолі для виводу
NumberOfChars dd 0 ;кількість введених/виведених символів
ReadBuf db 32 dup(0) ;будеф для введених символів
Message db 'Input elements of array:', 13,10
NumberOfChToWMessage dd $-Message
Message2 db 13,10, 'Input A:', 13, 10
NumberOfChToWMessage2 dd $-Message2
format_scan db '%d',0
Format db 'Result = %d', 0
Result db 32 dup (0), 10, 13
NumberOfChToWResult dd $-Result
.code
start:


call Input
push dword ptr N ;другий параметр - кількість елементів у масиві
push offset X ;перший параметр - адреса масиву
call Calculation
mov Res, eax
call Output
invoke ExitProcess, 0
;процедура вводу даних - параметри передаються через глобальні змінні
Input proc


invoke GetStdHandle, -11
mov hConsoleOutput, eax
invoke WriteConsoleA, hConsoleOutput, addr Message, NumberOfChToWMessage, addr NumberOfChars, 0
invoke GetStdHandle, -10
mov hConsoleInput, eax
mov ecx, dword ptr N
lea ebx, X
mov edi, 0
L_input:
push ecx
invoke ReadConsoleA, hConsoleInput, addr ReadBuf, 32, addr NumberOfChars, 0
invoke crt_atoi, addr ReadBuf
pop ecx
mov [ebx][edi], eax
add edi, 4
loop L_input

invoke GetStdHandle, -11
mov hConsoleOutput, eax
invoke WriteConsoleA, hConsoleOutput, addr Message2, NumberOfChToWMessage2, addr NumberOfChars, 0
invoke GetStdHandle, -10
mov hConsoleInput, eax
push ecx
invoke ReadConsoleA, hConsoleInput, addr ReadBuf, 32, addr NumberOfChars, 0
invoke crt_atoi, addr ReadBuf
pop ecx
mov A, eax

ret
Input endp



;процедура обчислення суми в циклі - параметри передаються через стек, результат в регістрі eax
Calculation proc
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
ret 8
Calculation endp


;процедура виводу даних - параметри передаються через глобальні змінні
Output proc
invoke wsprintfA, addr Result, addr Format, Res
invoke GetStdHandle, -11
mov hConsoleOutput, eax
invoke WriteConsoleA, hConsoleOutput, addr Result, NumberOfChToWResult, addr NumberOfChars, 0
ret
Output endp
end start