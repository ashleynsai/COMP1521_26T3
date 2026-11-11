#include <stdio.h>
#include <stdlib.h>

// given one command-line argument, the name of a file, and which 
// prints the first line of that file to `stdout`. 

// If given an incorrect number of arguments, or if there was an error opening the file, 
// it should print a suitable error message.
int main(int argc, char *argv[]) {
    // Invalid amount of command line arguments
    if (argc != 2) {
        // perror() - should not be used
        fprintf(stderr, "Usage: %s <filename>", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("");
        exit(1);
    }

    // fgets - reads in a string 
    // fread - slightly more complicated function, 
    // fgetc - reads in byte by byte
    char buffer[1024] = {0};
    fgets(buffer, 1024, fp);

    printf("%s\n", buffer);
}