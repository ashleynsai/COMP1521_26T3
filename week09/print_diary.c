#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// print the contents of the file `$HOME/.diary` to stdout.
// snprintf is a convenient function for constructing the pathname of the diary file.

int main(void) {
    // Expand the $HOME env variable
    char *home = getenv("HOME");

    // /mnt/accounts/user... but no /.diary
    //strcat(home, "/.diary"); can be used to add two strings together but may be
    // a bad idea as we could overwrite other data

    // printf - prints to stdout
    // fprintf - prints to FILE *
    // snprintf - prints to a char buffer

    // Create full filename
    char filename[1024] = {0};
    snprintf(filename, 1024, "%s/.diary", home);

    // Open the file in read mode
    FILE *diary = fopen(filename, "r");

    // Read each byte and print to stdout
    int c;
    while ((c = fgetc(diary)) != EOF) {
        putchar(c);
    }

    fclose(diary);
}