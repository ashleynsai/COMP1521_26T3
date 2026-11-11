# Two's Complement

Two's complement is just another way of interpreting bits now that we want to represent negative numbers.

The leading (leftmost) bit in two's complement denotes the sign.



# Converting between negative and positive in two's complement

###### Flip every bit, then add 1 is how we convert from negative to positive AND positive to negative

```
Convert the following into its opposite sign 8-bit two's complement binary notation:
		1. 5 in binary is: 0b 0000 0101       therefore -5 in binary is:   0b 1111 1011
		2. 29 in binary is: 0b 0001 1101      therefore -29 in binary is:  0b 1110 0011
		4. -100 in binary is: 0b 1001 1100    therefore 100 in binary is:  0b 0110 0100
```



### Tutorial Q3

Assume that the following hexadecimal values are 16-bit twos-complement. Convert each to the corresponding decimal value.

i. 0x0013 = 

ii. 0x0444 = 

iii. 0x1234 = 

iv. 0xFFFF = 

v. 0x8000 = 



### Tutorial Q4

Give a representation for each of the following decimal values in 16-bit twos-complement bit-strings. Show the value in binary, octal and hexadecimal.

1. 1 in binary is          0b 0000 0000 0000 0001 -> 0o1 -> 0x1
2. 100 in binary is     0b 0000 0000 0110 0100 -> 0o144 -> 0x64
3. -5 in binary is        0b 001 111 111 111 111 011 -> 0o177773  -> 0xFFFB
4. -100 in binary is    0b 0000 0000 0000 0000 ->  0o -> 0x



### Tutorial Q5 (code)

On a machine with 16-bit `int`s, the C expression `(30000 + 30000)` yields a negative result.

Why the negative result? How can you make it produce the correct result?

