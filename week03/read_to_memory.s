N_SIZE = 10

main:
	# $t0 - int i

loop_init:
	li	$t0, 0

loop_cond:
	# What is the exit condition
	bge	$t0, N_SIZE, loop_end

loop_body:
	li	$v0, 5
	syscall
	# numbers[i] = &numbers + (i * 4)
	mul	$t1, $t0, 4
	sw	$v0, numbers($t1)

loop_step:
	add	$t0, $t0, 1
	b	loop_cond

loop_end:
	jr	$ra

	.data
numbers:
	.word 	N_SIZE:0		# int numbers[N_SIZE] = {0};