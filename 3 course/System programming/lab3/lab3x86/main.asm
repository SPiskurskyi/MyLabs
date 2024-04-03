.686 ; 
.model flat, STDCALL ; 
option casemap :none ; 

GetShortPathNameA proto STDCALL, lpszLongPath:DWORD, lpszShortPath:DWORD, cchBuffer:DWORD
MessageBoxA proto STDCALL, h : DWORD, lpText : DWORD, LPCSTR : DWORD, UINT : DWORD
ExitProcess proto STDCALL, uExitCode : DWORD

.data ; ���� �������� �����:
lpFileName db 'C:\Users\admin\Desktop\MyLabs\3 course\System programming\lab3\lab3x86\main.asm', 0
;nBufferLength dw 256
lab_title db ' Lab �3 ', 0
hello_message db 'GetShortPathNameA: ', 0 ;
error_message db 'Error: File not found or buffer too small', 0
lpBuffer db 256 dup (0) ;

.code ; ���� �������� ����:
Start:
    ; ���������� ��������� ��� ������� ������ �������
    ;push offset nBufferLength
    push offset lpBuffer
    push offset lpFileName

    call GetShortPathNameA ; ������ ������� API

    ; �������� ����������� ��������
    cmp eax, 0
    je DisplayError

    ; ���������� ��������� ���� ��� ����������� ����������
    push 40h ; ����� ���� - ���� ������ "OK" � ���������� "�"
    push offset lab_title ; ������ ����� �� ����������
    push offset lpBuffer ; ������ ����� � ������������
    push 0 ; ����� ��������-�������� ����
    call MessageBoxA ; ������ ������� API

    jmp ExitProgram

DisplayError:
    push 40h ; ����� ���� - ���� ������ "OK" � ���������� "�"
    push offset lab_title ; ������ ����� �� ����������
    push offset error_message ; ������ ����� � ������������
    push 0 ; ����� ��������-�������� ����
    call MessageBoxA ; ������ ������� API

ExitProgram:
    push 0 ; ��� ������ � ��������
    call ExitProcess ; ���������� ��������

end Start
