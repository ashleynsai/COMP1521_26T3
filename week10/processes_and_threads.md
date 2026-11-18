# Processes and Threads

![p&t visual](threads.jpg)

### What is a process?

- any running program (you use them everyday!)
- an isolated execution environment
- encompasses one or more threads



- you could write C code that invokes the `system` function
- you can also do it manually using `fork` and `execve` 

- our recommendation to create a process in C using `posix_spawn(...)`
- `waitpid(...)` to wait for a process to finish



### What is a thread?

- unit of execution

- executes within a process

- many threads share the execution environment within a process

  

- create a thread within your C code using `pthread_create()`

- `pthread_join(...)` to wait for a particular thread to complete execution before the thread that called it resumes



### Demo spawning multiple processes:

2. Write a C program, `now.c`, which prints the following information:

   1. The current date.

   2. The current time.

   3. The current user.

   4. The current hostname.

   5. The current working directory.

      

      The following commands might be useful:

      - `date +%d-%m-%Y`
      - `date +%T`
      - `whoami`
      - `hostname -f`
      - `realpath .`



### Demo spawning threads:

5. Write a C program, `hello_there.c` that creates a thread that infinitely prints some message provided by main (eg. `"Hello\n"`), while the main (default) thread infinitely prints a different message (eg. `"there!\n"`).



6. The following C program attempts to say hello from another thread:

```c
#include <stdio.h>
#include <pthread.h>

void *thread_run(void *data) {
    printf("Hello from thread!\n");

    return NULL;
}

int main(void) {
    pthread_t thread;
  // Thread equivalent of posix_spawn is pthread_create
    pthread_create(
        &thread,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        NULL        // data we want to pass to the thread -- this will be
       
     // given in the `void *data` argument above
    );

  pthread_join(...)
    return 0;
}
```

However, when running this program after compiling with `clang`, the thread doesn't say hello.

```
clang -pthread program.c -o program
./program
./program
./program
```

Why does our program exhibit such behaviour?

Code continues and the thread that was created did not get a chance to print

How can we fix it?

