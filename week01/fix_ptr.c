// Tutorial 1, Question 3.

#include <stdio.h>
#include <stdlib.h>

int *get_num_ptr(void);

int main(void) {
    int *num = get_num_ptr();
    printf("%d\n", *num);
}

// What is wrong with the following code?
// Change the code below so that the program can be run.
// Do not change return type
int *get_num_ptr(void) {
    int *x = malloc(sizeof(int));
    *x = 42;

    return x;
    // int x = 42;
    // return &x;
}
