#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Create a helper function that returns the length of a codepoint
int length_codepoint(char codepoint) {
    // codepoint = 0b xxxx xxxx
    uint8_t first_four_bits = codepoint & 0b11111000;
    first_four_bits >>= 3;
    // first_four_bits = 0b xxxx x000

    // 4 byte codepoint
    if (first_four_bits == 0b11110) {
        return 4;
    } else if (first_four_bits >> 1 == 0b1110) {
        // 3 byte codepoint
        return 3;
    } else if (first_four_bits >> 2 == 0b110) {
        return 2;
    } else {
        return 1;
    }
}

// reads a null-terminated UTF-8 string as a command line argument and 
// counts how many Unicode characters (code points) it contains. 
// Assume that all codepoints in the string are valid.
int main(int argc, char *argv[]) {
    int count = 0;
    
    char *str = argv[1];
    
    while (*str != '\0') {
        // Read in the first byte of a codepoint
        // Match it with 1, 2, 3 or 4 width codepoint
        int codepoint_length = length_codepoint(*str);

        // Increment the address of str by the length of the codepoint in bytes
        count++;
        str += codepoint_length;
    };

    printf("the amount of codepoints: %d\n", count);
}