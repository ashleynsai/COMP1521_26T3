// Simple factorial calculator - without error checking

#include <stdio.h>

int main(void) {
    int n; // $t0
    printf("n  = "); // SYSCALL 4
    scanf("%d", &n); // SYSCALL 5

    int fac = 1; // $t1
    // for (int i = 1; i <= n; i++) {
    //     fac *= i;
    // }

    // if (cond) goto label;
    int i;
loop_init:
    i = 1;
loop_cond:
    // cond to jump to the end
    if (i > n) goto loop_end;

loop_body:
    fac *= i;
    // fac = fac * i;

loop_step:
    i++; // i = i + 1

    goto loop_cond;

loop_end:

    printf("n! = %d\n", fac);

    return 0;
}