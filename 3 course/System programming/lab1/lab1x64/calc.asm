printf proto c : vararg
EXTERN K : DWORD
.data
msg db 'Output from asm module is: %d', 0
.code
calc PROC
  sub rsp, 20h         ; ϳ�������� �����
  xor eax, eax         ; ��������� EAX

  mov eax, K           ; ������������ ��������� K � EAX
  add eax, ecx         ; ��������� �������� A
  
  xor ebx, ebx
  mov bx, dx           ; ������������ �������� C � EBX
  shl ebx, 2           ; �������� C �� 4
  add eax, ebx         ; ��������� 4*C
  
  mov ebx, r8d         ; ������������ �������� D � EBX
  sar ebx, 1           ; ĳ����� D �� 2
  sub eax, ebx         ; ³������� D/2

  mov r12d, eax        ; ��������� ����������
  lea rcx, msg         ; ϳ�������� �����������
  mov edx, eax         ; �������� ���������� � printf
  call printf          ; ��������� ����������

  mov eax, r12d        ; ������������ ���������� ����� � EAX
  add rsp, 20h         ; ³��������� �����
  ret
calc ENDP
END