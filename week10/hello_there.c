// Write a C program, `hello_there.c` that creates a thread that infinitely 
// prints some message provided by main (eg. `"Hello\n"`), while the main 
// (default) thread infinitely prints a different message (eg. `"there!\n"`).

#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *print_string(void *arg) {
    // implement the print string
    printf("%s", (char *)arg);  // typecast

    char *return_string = strdup("surprise this is a string!");

    return return_string;
}

int main(void) {
    pthread_t thread;
    char *to_print = "Hello\n";
    pthread_create(
        &thread,            // where the new thread's ID is stored
        NULL,               // not assessed
        print_string,       // function the thread starts running
        to_print            // arguments passed to the function (arrives as void *)
    );

    void *returned_string;

    pthread_join(
        thread,             // which thread are we waiting for
        &returned_string    // if you wanted to capture the return value
    );

    printf("there!\n");

    printf("%s", (char *)returned_string);
}
