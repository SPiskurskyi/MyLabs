.data
const_4		dd 4.0
const_1		dd 1.0
const_12	dd 12.0
temp_res	dd 0.0

.code
calc PROC
 ; переносимо параметр з xmm0, xmm1, xmm2 у стек. Згідно угод для 64-розрядної платформи перші 4
 ; параметри передаються в регістрах, а для дійсних параметрів використовуються регістри
 ; xmm0- xmm3. Результат дійсного типу повертають в регістрі xmm0.
 movsd qword ptr[rsp+8], xmm0
 movss dword ptr[rsp+16], xmm1
 movss dword ptr[rsp+20], xmm2

 push rbp
 mov rbp, rsp

 finit
 fld dword ptr[rbp+24]   ;load c
 fcom dword ptr[rbp+28]  ;c - d
 fstsw ax				 ;save flags in ax
 sahf

 ja _calculate_c_abov_d  ;if c > d goto _calculate_c_abov_d
						 ;else skip this jamp

fld qword ptr[rbp + 16]
fmul dword ptr[rbp + 28] ;a * d result save to ST(0)
fsub const_1		     ;a * d - 1 save to ST(0)
fstp temp_res	     ;save temp result and pop out			 
			 ;ST(0)
 fld qword ptr[rbp + 16] ; load a
 fdiv const_4           ; a / 4
 fstp const_4			;save result and pop out ST(0)

 fld dword ptr[rbp + 24]  ; load c
 fmul dword ptr[rbp + 28] ; c * d
 fsub const_4             ; (c * d) - (a / 4)
 fstp const_4			  ;save result and pop out ST(0)

 fld dword ptr[rbp + 24] ; load c to ST(1)
 fld const_1			;load 1 to ST(0)
 fpatan                   ; atan(c) -> atan(ST(1)/ST(0))
 fadd const_4            ; atan(c) + ((c * d) - (a / 4))
 fdiv temp_res	

jmp _to_return			 

 _calculate_c_abov_d:

 fld dword ptr[rbp+28]  ;load d
 fmul const_4			; d * 4 and save to ST(1)
 fld const_1			;load 1 to ST(0)
 fpatan				;atan(4*d)			
 fdiv dword ptr[rbp+24] ; atan(d*4)/c
 fsub const_1			;atan(d*4)/c - 1
 fstp temp_res
 fld qword ptr[rbp+16]   ;load a
 fsub dword ptr[rbp+24]  ; a - c
 fadd const_12			;12 + (a - c)	
 fdivr temp_res	

_to_return:
 pop rbp

 ;переносимо результат з математичного співпроцесора у xmm0
 fstp qword ptr [rsp+8]
 movsd xmm0, qword ptr [rsp+8]


 ret

calc ENDP
END
