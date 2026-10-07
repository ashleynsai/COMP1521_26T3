// A simple program that will print 10 numbers from an array

#define N_SIZE 10

#include <stdio.h>

int main(void) {
    int i;
    int numbers[N_SIZE] = {99, 88, 77, 66, 55, 44, 33, 22, 11, 0};

    i = 0;
    while (i < N_SIZE) {
        printf("%d\n", numbers[i]); // SYSCALL 1
        i++;
    }
}