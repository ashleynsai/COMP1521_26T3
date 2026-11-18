#include <stdio.h>
#include <spawn.h>
#include <sys/wait.h>

// date +%d-%m-%Y
// date +%T
// whoami
// hostname -f
// realpath .
// spawn all of these processes

// extern means not defined here
extern char **environ;

void spawn(char *args[]) {
    // Spawning a single process
    pid_t child_pid;
    posix_spawn(
        &child_pid,     // when posix_spawn runs, it puts the childs PID into address provided
        args[0],        // full pathname of program
        NULL,           // advanced topic, redirect fds in the child (e.g. stdout to pipe or file)
        NULL,           // not examined in COMP1521
        args,           // NULL terminated argument array 
        environ         // environment variables
    );

    waitpid(
        child_pid, 
        NULL,           // not assessed, default to NULL
        0               // not assessed, default to 0 (waitpid blocks until child terminates)
    );
}

int main(void) {
    // spawn all of the processes
    char *date_args[] = {"/bin/date", "+%d-%m-%Y", NULL};
    spawn(date_args);

    char *date2_args[] = {"/bin/date", "+%T", NULL};
    spawn(date2_args);

    char *args3[] = {"/bin/whoami", NULL};
    spawn(args3);

    char *args4[] = {"/bin/hostname", "-f", NULL};
    spawn(args4);

    char *args5[] = {"/bin/realpath", ".", NULL};
    spawn(args5);
    
}