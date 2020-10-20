.data
	exp_request: .asciiz"Exponente: "
	exp: .word 0
	coeficiente: .word 0
	num_request: .asciiz"Numero a usar: "
.text
.globl __start

__start:

li $v0, 4
la $a0, exp_request
syscall

li $v0, 5
syscall
move $t0, $v0
sw $v0, exp
#reserva de bits
add $t0, $t0, 1 
mul $t0, $t0, 32
li $v0, 9
move $a0, $t0
syscall

addi $s0, $v0, 0	
add $s1, $s0, $t0

#ingreso de coeficientes
addi $t1, $s0, 0  
coeficientes_request:
	beq $t1, $s1, coeficientes_exit
	
	li $v0, 4
	la $a0, coeficientes 
	syscall
	li $v0, 5
	syscall
	move $t0, $v0
	sw $t0,0($t1)
	addi $t1, $t1, 32
	
	j coeficientes_request
