N_SIZE = 10
PIZZA_PRICE_OFFSET = 24

main:
	# $t0 - int i

loop_init:
	li	$t0, 0

loop_cond:
	# What is the exit condition
	bge	$t0, N_SIZE, loop_end

loop_body:
	li	$v0, 1

	# numbers[i] = numbers + i * 4
	mul	$t1, $t1, 4
	lw	$a0, numbers($t1)

	# numbers[i] = numbers + i * 4 (alternative method)
	# la	$t1, numbers
	# mul	$t2, $t0, 4
	# add	$t1, $t1, $t2
	# lw	$a0, ($t1)

	# Struct example
	lw	$a0, pizza_info + PIZZA_PRICE_OFFSET($t1)
	lw	$a0, 4($t0)

	syscall

loop_step:
	add	$t0, $t0, 1
	b	loop_cond

loop_end:
	jr	$ra

	.data
numbers:
	# How can we initialise the array?
	.word 	99, 88, 77, 66, 55, 44, 33, 22, 11, 0
pizza_info: