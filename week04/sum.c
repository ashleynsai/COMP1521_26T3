// sum 4 numbers using function calls

#include <stdio.h>

int sum4(int a, int b, int c, int d);
int sum2(int x, int y);

int main(void) { // Non-leaf function because it calls other functions
    // int result in $t0
    int result = sum4(11, 13, 17, 19);
    printf("%d\n", result); // SYSCALL 1, SYSCALL 11
    return 0;
}

int sum4(int a, int b, int c, int d) { // Non-leaf
    // int res1 in $s0 (has to be saved)
    // int res2 in $t0 (does not have to be saved)
    // int c in $s1
    // int d in $s2
    int res1 = sum2(a, b);
    int res2 = sum2(c, d);
    return sum2 (res1, res2);
}

int sum2(int x, int y) { // Leaf function, we don't need to worry
    // about pushing and popping, or $s registers
    return x + y;
}