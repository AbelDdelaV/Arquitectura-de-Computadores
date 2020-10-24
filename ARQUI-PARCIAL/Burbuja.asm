.text 
.globl __start		

__start:	# aqui comienzan sus instrucciones

li $s1 1			
lw $s3 size			#inicio size
li $s0 0			
la $t1 lista			# inicio lista

j while

while:

bne $s0 $zero print
move $s0 $s1
li $s2 0			# bucle admin
j for
	for:
	
	sll $t3 $s2 2		# 4 bits de memoria
	add $t3 $t3 $t1
	lw $t6 0($t3)		# lista[i]
	
	add $s4 $s2 $s1
	sll $t4 $s4 2		# 4 bits de memoria
	add $t4 $t4 $t1
	lw $t7 0($t4)		# lista[i+1]
	
	add $s2 $s2 $s1		
	beq $s2 $s3 while
	
	sle $t0 $t6 $t7
	
	bne $t0 $zero for
	sw $t6 0($t4)
	sw $t7 0($t3)
	move $s0 $zero	
	j for

print:

li $s2 0

forPrint:
	
	sll $t5 $s2 2
	add $t5 $t5 $t1
	lw $t7 0($t5)
	
	move $a0 $t7
	li $v0 1					
	syscall
	
	la $a0 coma		# inicializo la coma
	li $v0 4		
	syscall
	
	add $s2 $s2 $s1
	beq $s2 $s3 fin
	j forPrint

fin:

li $v0 10						
syscall				# servicio de finalizar programa

.data # aqui comienzan a definirse las variables

lista: .word  0,3,6,12,5,2,10,1,5,9 	 # que define lista de valores a ordenar
coma: .asciiz ", "			
size: .word 10				# cantidad de valores en la lista
