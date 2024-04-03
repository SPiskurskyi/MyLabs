	lw		0	1	num1
	lw		0	2	num2
	rcr		1	2	3
	bt		1	2	0	
	sbb		1	2	4
	halt 
num1		.fill	3		
num2		.fill	2		
