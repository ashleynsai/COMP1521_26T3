main:
	# $t0 - int n
	# $t1 - int fac
	# $t2 - int i

	li	$v0, 4
	la	$a0, prompt
	syscall

	li	$v0, 5
	syscall
	move	$t0, $v0

	li	$t1, 1

loop_init:
	li	$t2, 1
loop_cond:
	bgt	$t2, $t0, loop_end
loop_body:
	mul	$t1, $t1, $t2

loop_step:
	add	$t1, $t1, 1
	b	loop_cond
loop_end:
	li	$v0, 4
	la	$a0, str
	syscall

	li	$v0, 1
	move	$a0, $t0
	syscall

	la	$v0, 11
	la	$a0, '\n'
	syscall

	li	$v0, 0
	jr	$ra

	.data
prompt:
	.asciiz "n = "
str: 
	.asciiz "n! = "