#include <stdio.h>
#include <assert.h>
#include <stdint.h>

//typedef unsigned int Word;

// Reverse the order of the bits in variable w
uint32_t reverseBits(uint32_t w) {
    // 0b 1111 1010 0000 0000 0000 0000 0000 0000 - original value
    // 0b 0000 0000 0000 0000 0000 0000 0101 1111 - return value

    // for loop from 0 to 31 and extract the value from that position
    // track the return value with some other uint32_t variable
    // with each extracted bit in position i, set the (31-i)th bit in the return value

    uint32_t reversed_w = 0; // 0b 0000 0000 0000 0000 ... 0000

    for (int i = 0; i < 32; i++) {
        // First extract the value, so i should get either 1 or 0
        uint32_t value = (w >> i) & 1;

        // Second, set the bit in the return value
        reversed_w = reversed_w | (value << (31 - i)) ;
    }

    return reversed_w;
}

// testing
int main(void) {
    uint32_t w1 = 0x01234567;
    // 0000 => 0000 = 0
    // 0001 => 1000 = 8
    // 0010 => 0100 = 4
    // 0011 => 1100 = C
    // 0100 => 0010 = 2
    // 0101 => 1010 = A
    // 0110 => 0110 = 6
    // 0111 => 1110 = E
    assert(reverseBits(w1) == 0xE6A2C480);
    puts("All tests passed!");
    return 0;
}