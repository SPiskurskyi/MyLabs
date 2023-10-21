.686
.model flat, c

.data
const_1		dd 1.0
const_4		dd 4.0
const_12	dd 12.0
temp_res	dd 0.0

.code
calc PROC

 push ebp
 mov ebp, esp
 finit

 fld dword ptr[ebp+16]   ;load c
 fcom dword ptr[ebp+20]  ;c - d
 fstsw ax		    ;save flags in ax
 sahf

 ja _calculate_c_abov_d  ;if c > d goto _calculate_c_abov_d
						 ;else skip this jamp
 fld qword ptr[ebp + 8]
 fmul dword ptr[ebp + 20] ;a * d result save to ST(0)
 fsub const_1		     ;a * d - 1 save to ST(0)
 fstp temp_res	     ;save temp result and pop out
			     ;ST(0)
 fld qword ptr[ebp + 8] ; load a
 fdiv const_4           ; a / 4
 fstp const_4			;save result and pop out ST(0)

 fld dword ptr[ebp + 16]  ; load c
 fmul dword ptr[ebp + 20] ; c * d
 fsub const_4             ; (c * d) - (a / 4)
 fstp const_4			  ;save result and pop out ST(0)

 fld dword ptr[ebp + 16] ; load c
 fld const_1
 fpatan                   ; atan(c)
 fadd const_4            ; atan(c) + ((c * d) - (a / 4))
 fdiv temp_res	

 jmp _to_return		;go to return result

 _calculate_c_abov_d:

 fld const_4      
 fmul dword ptr[ebp+20] ; 4 * d
 fld const_1
 fpatan				;atan(4*d)			
 fdiv dword ptr[ebp+16] ; atan(d*4)/c
 fsub const_1			;atan(d*4)/c - 1
 fstp temp_res
 fld qword ptr[ebp+8]   ;load a
 fsub dword ptr[ebp+16]  ; a - c
 fadd const_12			;12 + (a - c)	
 fdivr temp_res			; (atan(d*4)/c - 1)/(12 + a - c)

_to_return:
 pop ebp
 ret

calc ENDP
END
