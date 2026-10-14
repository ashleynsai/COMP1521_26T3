#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int number = atoi(argv[1]);

    // TODO: print number in decimal, binary, octal and hexadecimal form
    printf("%d 0b%b 0o%o 0x%x\n", number, number, number, number);
}