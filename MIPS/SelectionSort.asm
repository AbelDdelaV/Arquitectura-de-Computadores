.data

	array: .word 5, 2, 3, 9, 7, 8, 6, 1, 1, 10, 15
	#aux: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	ini: .asciiz  "Array inicial: "
	order: .asciiz "\nArray ordenado: "
	coma: .asciiz ", "
	endl: .asciiz "\n\n
.text

main:
la $t0, array
li $t9, 9
li $t5, 10
li $t8, 0
move $s0, $t0
li $v0, 4
la $a0, ini
syscall

Print_array:
	bgt $t8, $t9, sort	# if $t8 > $t9 then
	lw $t1, 0($t0)

	li $v0, 1
	move $a0, $t1
	syscall

	beq $t8, $t9, barf	# if $t8 == $t9 tbarf
	li $v0, 4
	la $a0, coma
	syscall
	barf:

addi	$t8, $t8, 1			# $t8 = $t8 + 1
addi	$t0, $t0, 4			# $t0 = $t0 + 4
j Print_array

sort:

li $t8, 0
move $t0, $s0

li $v0, 4
la $a0, endl
syscall #endl

for_i:
	bgt  $t8, $t9, sortFin	
	lw   $t1, 0($t0)
	addi $t7, $t8, 1			
	move  $t4, $t0		
	for_j:
		bgt  $t7, $t5, exitFor	#condicion salida bucle
		addi $t4, $t4, 4	
		lw   $t2, 0($t4)
		bgt  $t2, $t1, swap	 #swap?
		sw   $t1, 0($t4)		
		move $t1, $t2	
		swap:
			addi	$t7, $t7, 1			
			j for_j #end
		exitFor:
			sw   $t1, 0($t0)
			addi $t0, $t0, 4	#int	
			addi $t8, $t8, 1	#char
j for_i

sortFin:
	move $t0, $s0		
	li $t8, 0
	li $v0, 4
	la $a0, order
	syscall

Print:
	bgt $t8, $t9, exit
	lw $t1, 0($t0)

	li $v0, 1
	move $a0, $t1
	syscall

	beq $t8, $t9, sig
	li $v0, 4
	la $a0, coma
	syscall
	sig:
		addi	$t8, $t8, 1			
		addi	$t0, $t0, 4			
		j Print
	exit:
		li $v0, 10
		syscall

