.686 ; 
.model flat, STDCALL ; 
option casemap :none ; 

GetShortPathNameA proto STDCALL, lpszLongPath:DWORD, lpszShortPath:DWORD, cchBuffer:DWORD
MessageBoxA proto STDCALL, h : DWORD, lpText : DWORD, LPCSTR : DWORD, UINT : DWORD
ExitProcess proto STDCALL, uExitCode : DWORD

.data ; вміст сегменту даних:
lpFileName db 'C:\Users\admin\Desktop\MyLabs\3 course\System programming\lab3\lab3x86\main.asm', 0
;nBufferLength dw 256
lab_title db ' Lab №3 ', 0
hello_message db 'GetShortPathNameA: ', 0 ;
error_message db 'Error: File not found or buffer too small', 0
lpBuffer db 256 dup (0) ;

.code ; вміст сегменту коду:
Start:
    ; формування параметрів для виклику заданої функції
    ;push offset nBufferLength
    push offset lpBuffer
    push offset lpFileName

    call GetShortPathNameA ; виклик функції API

    ; перевірка поверненого значення
    cmp eax, 0
    je DisplayError

    ; формування параметрів вікна для відображення результату
    push 40h ; стиль вікна - одна кнопка "OK" з піктограмою "і"
    push offset lab_title ; адреса рядка із заголовком
    push offset lpBuffer ; адреса рядка з повідомленням
    push 0 ; хендл програми-власника вікна
    call MessageBoxA ; виклик функції API

    jmp ExitProgram

DisplayError:
    push 40h ; стиль вікна - одна кнопка "OK" з піктограмою "і"
    push offset lab_title ; адреса рядка із заголовком
    push offset error_message ; адреса рядка з повідомленням
    push 0 ; хендл програми-власника вікна
    call MessageBoxA ; виклик функції API

ExitProgram:
    push 0 ; код виходу з програми
    call ExitProcess ; завершення програми

end Start
