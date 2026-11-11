#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

// This program is given one command-line argument, the name of a file,
// and which reads a line from stdin and appends it to the specified file.
int main(int argc, char *argv[]) {
    // What does fopen do? What are its parameters?
    // opens a file and returns a FILE *
    // pathname: name of the file you want to open
    // mode: read/write/append
    FILE *fp = fopen(argv[1], "a");

    // What are some circumstances when fopen returns NULL?
    // no file with provided pathname in specific modes (not append)
    // invalid pathname, if pathname is too long
    // if your computer has run out of memory
    // if your pathname is empty
    // invalid mode

    // How do you print the specific reason that fopen returns NULL?
    // perror() takes the number errno is set to and prints the string related to it
    if (fp == NULL) {
        perror("Random words"); // "Random words: File or directory does not exist"
        exit(1);
    }

    // scanf
    // fgets
    // fread
    char line[1024] = {0};
    fgets(line, 1023, stdin);

    // fprintf - in my opinion is the easiest to use
    // fputs - prints a string to file
    // fputc - prints a byte to file
    // fwrite - slightly more complicated but you can use it
    fprintf(fp, "%s\n", line);

    fclose(fp);
    return 0;
}




