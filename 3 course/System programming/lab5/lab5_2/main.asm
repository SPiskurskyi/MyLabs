.686
.model flat, stdcall
option casemap:none

include windows.inc
include kernel32.inc
include user32.inc

.data
	LibName db "lab5_1.dll",0
	FunctionName db "MyFunction",0
	DllNotFound db "Cannot load library",0
	AppName db "Load explisit Library",0
	NotFound db "MyFunction function not found",0
	msg db "Its is 5 lab, the last one!!",0
    letter db 't', 0
.data?
	hLib dd ?
	MyFunctionAddr dd ?
.code
start:
invoke LoadLibrary,addr LibName ; завантаження бібліотеки
.if eax == NULL ; якщо завантаження не вдалося
invoke MessageBox,NULL,addr DllNotFound,addr AppName,MB_OK
.else
mov hLib,eax ; збереження заголовку бібліотеки
; визначення адреси функції
invoke GetProcAddress,hLib,addr FunctionName
.if eax == NULL ; якщо не вдалося взяти адресу
invoke MessageBox,NULL,addr NotFound,addr AppName,MB_OK
.else
mov dl, letter
push dx
push offset msg
mov MyFunctionAddr,eax
call [MyFunctionAddr] ; виклик функції
.endif
invoke FreeLibrary,hLib ; вивантаження бібліотеки
.endif
invoke ExitProcess,NULL
end start
