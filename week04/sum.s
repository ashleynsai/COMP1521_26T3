	.text
main:
main__prologue:
	push	$ra

main__body:
	li	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19
	jal	sum4		# int result = sum4(11, 13, 17, 19);

	move	$a0, $v0
	li	$v0, 1
	syscall			# print the value in int result here

	li	$v0, 11
	li	$a0, '\n'
	syscall			# printf("%d\n", result);

main__epilogue:
	pop	$ra

	li	$v0, 0
	jr	$ra		# return 0;

########
	
########
sum4:
sum4__prologue:
	# $s0 - int res1

	push	$ra
	push	$s0
	push	$s1
	push	$s2

	move	$s1, $a2	
	move	$s2, $a3
sum4__body:
	jal	sum2
	move	$s0, $v0	# int res1 = sum2(a, b)

	move	$a0, $s1
	move	$a1, $s2
	jal	sum2		# int res2 = sum2(c, d);

	move	$a0, $s0
	move	$a1, $v0
	jal	sum2		

sum4__epilogue:
	pop	$s2
	pop	$s1
	pop	$s0
	pop	$ra

	jr	$ra

sum2:
sum2__prologue:
	# Don't need to push and pop anything
	# no jal means no need to push and pop $ra
	# no use of $s registers
sum2__body:
	add	$v0, $a0, $a1		# return x + y;

sum2__epilogue:
	jr	$ra