// 5. Write a c program `count_chars.c` that uses [getchar](https://man7.org/linux/man-pages/man3/getchar.3p.html) 
// to read in characters until the user enters Ctrl-D and then prints the total number of characters entered.

// ​	Use `man 3 getchar` to look at the manual entry.

#include <stdio.h>

int main(void) { // no  need for command line arguments, reading from stdin
    int characters_entered = 0;

    while (getchar() != EOF) {
        characters_entered++;
    }

    printf("Number of characters entered: %d\n", characters_entered);

    return 0;
}