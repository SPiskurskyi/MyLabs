	lw	0	1	num1
	lw	0	2	num2
	jmae	1	2	true1	
	jmle	1	2	true2	
true1	add	1	1	3
	halt 
true2	add	2	2	3
	halt 
num1	.fill	8			
num2	.fill	13			