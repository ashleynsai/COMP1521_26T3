# Floating Point Numbers (IEEE754)



### What is the IEEE 754 standard?

- Sometimes we need to encode very small or very large numbers in a compact form
- Scientific notation helps us do that

- IEEE 754 is a way to encode **binary** scientific notation in 32 bits (scientific notation can be applied to any base!)
  - The binary number 10001.011 would be represented as base-2 scientific notation as 1.0001011 x 2^4
    - Note that in binary, the single bit to the left of the decimal point **MUST BE** 1 



### Components

![Components](components.png)

- **Sign bit**: 0 for positive, 1 for negative
- **Exponent bits** store a value in the range [0, 255]
- The actual value of the exponent is ```exponent - bias``` so that we can store negatives. The bias is 127 so we can actually store the range [-127, 128]
- **Fraction** bits represent a binary fraction



### IEEE 754 Standard: Special Cases

![Special Cases](special_cases.png)

### Tutorial Q4

What decimal numbers do the following single-precision IEEE 754-encoded bit-strings represent?

1. `0 00000000 00000000000000000000000`  = +0
2. `1 00000000 00000000000000000000000`  = -0
3. `0 01111111 10000000000000000000000`  = 

sign = 0 (positive)

exponent = 0b01111111 = 127 (stored exponent), real exponent = 127 - bias = 0

fraction = 100000000000000000

1.10000000000 x 2^0 = 1.5 (decimal) = 0b1.1 = 1 + 0.5

1. `0 01111110 00000000000000000000000` =

   sign = 0

   exponent = 126, real exponent = 126 - bias = -1

   fraction = 0000000

0b1.00000 x 2^(-1) = 0b0.1 = 0.5 (decimal)



Each of the above is a single 32-bit bit-string, but partitioned to show the sign, exponent and fraction parts.





### Tutorial Q5

Convert the following decimal numbers into IEEE 754-encoded bit-strings:

2.5

0.375

-2

100

