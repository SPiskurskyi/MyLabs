.686
.model flat, STDCALL


MessageBoxA proto STDCALL, h:DWORD, lpText:DWORD, LPCSTR:DWORD, UINT:DWORD
ExitProcess proto STDCALL, uExitCode:DWORD

.data
    caption db "Lab5", 0                         
    output db 256 dup(0)
    outputFormat db "Lab5", 0            
    j dd 0
.code

IntToStr PROC  value:DWORD
     ; Reserve space for the string buffer (max 11 characters for a 32-bit integer)
    LOCAL buffer[12]:BYTE

    mov eax, value        ; Copy the integer value to eax
    mov ecx, 10           ; Set divisor to 10

    lea edi, buffer + 11
    mov BYTE PTR [edi], 0        ; Null-terminate the string

    ; Loop to convert the integer to a string
convert_loop:
    dec edi                     ; Move edi to the next position in the buffer

    xor edx, edx                ; Clear any previous remainder
    div ecx                     ; Divide eax by 10, result in eax, remainder in edx

    add dl, '0'                 ; Convert remainder to ASCII
    mov [edi], dl               ; Store ASCII character in the buffer

    test eax, eax               ; Check if quotient is zero
    jnz convert_loop            ; If not, continue the loop

    ; At this point, edi points to the beginning of the string
    ; You can use this string for further processing or display

    ; Example: Copy the string to the "output" buffer
    lea esi, [edi]              ; Load the address of the beginning of the string
    lea edi, OFFSET output      ; Load the address of the output buffer

    ; Copy the string byte by byte
    mov ecx, 12                 ; Maximum length of the string
    rep movsb

    ret
IntToStr ENDP

;-------------------- Start function --------------------------
DllEntry PROC hInstDLL:DWORD, reason:DWORD, reserved:DWORD
    mov eax, 1
    ret
DllEntry ENDP

;-------------------- Test function in the library --------------
MyFunction PROC input:DWORD, letter:BYTE
    xor eax, eax
    xor ecx, ecx           ; ecx = index
    xor ebx, ebx           ; ebx = sum
    mov esi, input        ; Load the address of the string into ESI

main_loop:
    lodsb ; Load the next character into AL
    test al, al ; Check if AL is null terminator (end of string)
    jz end_main_loop ; If null terminator, jump to end_main_loop

    ; Check if the current character is the specified letter
    cmp al, letter
    je  letter_found

    ; If not, move to the next character
    inc ecx
    jmp main_loop

letter_found:
    ; Increment the sum by the current index (1-based)
    add ebx, ecx
    inc ebx
    ; Move to the next character
    inc ecx

    jmp main_loop
    
end_main_loop:
    push ebx                 ; Value to be converted
    call IntToStr

    ; Display the sum using MessageBoxA
    push 40h                 ; hWnd (handle to the owner window; 0 for no owner)
    push offset outputFormat ; lpText (format string)
    push offset output       ; Value to be printed
    push 0                   ; uType (MessageBox style; 0 for OK button only)
    call MessageBoxA

    ; Exit the process using ExitProcess
    push 0                  ; uExitCode (exit code for the process)
    call ExitProcess
    ret
MyFunction ENDP
End DllEntry