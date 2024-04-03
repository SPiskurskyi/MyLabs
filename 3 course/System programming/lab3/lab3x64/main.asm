GetShortPathNameA proto
MessageBoxA proto
ExitProcess proto

.data
lpFileName db 'C:\Users\admin\Desktop\MyLabs\3 course\System programming\lab3\lab3x86\main.asm', 0
;nBufferLength dw 256
lab_title db 'Lab №3', 0
hello_message db 'GetShortPathNameA: ', 0
error_message db 'Error: Could not retrieve short path name.', 0
lpBuffer db 256 dup (0)

.code
mainCRTStartup proc
    sub rsp, 28h
    ;lea r8,  nBufferLength ;3
    lea rdx, lpBuffer       ;2
    lea rcx, lpFileName     ;1
    call GetShortPathNameA ; виклик функції API
    
    test rax, rax           ; test return value
    jz DisplayError         ; jump to error handling if return value is zero

    mov r9, 40h ; стиль вікна - одна кнопка "OK" з піктограмою "і"
    lea r8, lab_title ; адреса рядка із заголовком
    lea rdx, lpBuffer ; адреса рядка з повідомленням
    mov rcx, 0 ; хендл програми-власника вікна
    call MessageBoxA ; виклик функції API

    jmp ExitProgram

DisplayError:
    ; display message box with error message
    mov r9, 40h             ; uType: MB_OK | MB_ICONINFORMATION
    lea r8, lab_title       ; lpCaption
    lea rdx, error_message  ; lpText
    mov rcx, 0              ; hWnd
    call MessageBoxA

ExitProgram:
    add rsp, 28h
    xor ecx, ecx            ; uExitCode
    call ExitProcess        ; call ExitProcess

mainCRTStartup endp
end
