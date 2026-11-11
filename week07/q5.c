#include <stdio.h>
#include <stdint.h>

// On a machine with 16-bit `int`s, the C expression `(30000 + 30000)` yields a negative result.
// Why the negative result? How can you make it produce the correct result?

int main() {
    // Format specifier for int16_t (short int) is %hd

    uint16_t result = 30000 + 30000;

    // 1xxx xxxx xxxx xxxx = 60000

    printf("Result of 30000 + 30000 is: %d\n", result);
}