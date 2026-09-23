// Squares a number, unless its square is too big for a 32-bit integer.
// If it is too big, prints an error message instead.

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    // Allocate C variables into registers
    int x, y;
    // $t0 - int x
    // $t1 - int y

    // Syscalls
    printf("Enter a number: ");     // SYSCALL 4
    scanf("%d", &x);                // SYSCALL 5
 
    // Simplify loops
    // if (cond) goto label;

    // BANNED: for loops, while loops, else if, else
    // if (x > SQUARE_MAX) {
    //     printf("square too big for 32 bits\n");
    // } else {
    //     y = x * x;
    //     printf("%d\n", y);
    // }
    if (x > SQUARE_MAX) goto invalid_square;
    goto valid_square;

invalid_square:
    printf("square too big for 32 bits\n"); // SYSCALL 4
    goto epilogue;

valid_square:
    y = x * x;
    printf("%d", y); // SYSCALL 1
    printf("\n");   // SYSCALL 11

epilogue:

    return 0;
}