	.text

SQUARE_MAX = 46340
PRINT_STRING = 4
READ_INT = 5

main:
	# Registers
	# $t0 - int x
	# $t1 - int y

	li	$v0, PRINT_STRING
	la	$a0, prompt
	syscall						# printf("Enter a number:");

	li	$v0, READ_INT
	syscall
	move	$t0, $v0				# scanf("%d", &x);

	bgt	$t0, SQUARE_MAX, invalid_square		# if (...) ...

	b	valid_square				# goto valid_square

invalid_square:
	li	$v0, 4
	la	$a0, next_value
	syscall

	b	epilogue

valid_square:
	mul	$t1, $t0, $t0

	li	$v0, 1
	move	$a0, $t1
	syscall						# printf("%d", y);

	li	$v0, 11
	la	$a0, '\n'
	syscall

epilogue:
	li	$v0, 0
	jr	$ra

	.data
prompt:
	.asciiz "Enter a number: "
next_value:
	.asciiz "square too big for 32 bits\n"