printf proto c : vararg
EXTERN K : DWORD
.data
msg db 'Output from asm module is: %d', 0
.code
calc PROC
  sub rsp, 20h         ; Підготовка стеку
  xor eax, eax         ; Обнулення EAX

  mov eax, K           ; Завантаження константи K в EAX
  add eax, ecx         ; Додавання значення A
  
  xor ebx, ebx
  mov bx, dx           ; Завантаження значення C в EBX
  shl ebx, 2           ; Множення C на 4
  add eax, ebx         ; Додавання 4*C
  
  mov ebx, r8d         ; Завантаження значення D в EBX
  sar ebx, 1           ; Ділення D на 2
  sub eax, ebx         ; Віднімання D/2

  mov r12d, eax        ; Зберігання результату
  lea rcx, msg         ; Підготовка повідомлення
  mov edx, eax         ; Передача результату в printf
  call printf          ; Виведення результату

  mov eax, r12d        ; Завантаження результату назад в EAX
  add rsp, 20h         ; Відновлення стеку
  ret
calc ENDP
END