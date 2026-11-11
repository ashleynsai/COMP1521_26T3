# Files



### Reading and writing to a file: 

7. Write a C program, ```append_line.c```, which is given one command-line argument, the name of a file, and which reads a line from ```stdin``` and appends it to the specified file.

   - What does ```fopen``` do? What are its parameters? What is the return value?
   - What are some circumstances when ```fopen``` returns null
   - How do you print the specific reason that caused `fopen` to return `NULL`?  




5. Write a C program, `first_line.c`, which is given one command-line argument, the name of a file, and which prints the first line of that file to `stdout`. If given an incorrect number of arguments, or if there was an error opening the file, it should print a suitable error message.

   

6. Why should you not use ```fgets``` or `fputs` with binary data?

```
fgets and fputs ends the read/write when it encounters some newline or null terminators, which is common in binary data when it should not indicate a stop. fread/fwrite or fgetc/fputc for binary data
```



8. For each of the following calls to the `fopen()` library function, give an `open()` system call that has equivalent semantics relative to the state of the file.

   

   1. `fopen(FilePath, "r")`

      ```
      open(FilePath, O_RDONLY);
      ```

   2. `fopen(FilePath, "a")`

      ```
      open(FilePath, O_WRONLY | O_CREAT | O_APPEND);
      ```

   3. `fopen(FilePath, "w")`

      ```
      open(FilePath, O_WRONLY | O_CREAT | O_TRUNC);
      ```

   Obviously, `fopen()` returns a `FILE*`, and `open()` returns an integer file descriptor. Ignore this for the purposes of the question; focus on the state of the open file.













Consider the `lseek(fd, offset, whence)` function.

1. What is its purpose?

   Skips a couple bytes in some file fd

2. When would it be useful?

   - If you wanted to read something in the middle of the file

   - Find the size of the file
   - When you are parsing headers that have set offsets

3. What does its return value represent?

   returns the resulting offset location as measured in bytes from  the  beginning  of  the
      file.  On error, the value (off_t) -1 is returned and errno is set to indicate the error.		











Consider a file of size 10000 bytes, open for reading on file descriptor `fd`, initially positioned at the start of the file (offset 0). What will be the file position after each of these calls to `lseek()`? Assume that they are executed in sequence, and one will change the file state that the next one deals with.

1. `lseek(fd, 0, SEEK_END);` 10,000
2. `lseek(fd, -1000, SEEK_CUR);` 9,000
3. `lseek(fd, 0, SEEK_SET);` 0
4. `lseek(fd, -100, SEEK_SET);` lseek function returns -1, but the file position will remain the same
5. `lseek(fd, 1000, SEEK_SET);` 1,000
6. `lseek(fd, 1000, SEEK_CUR);` 2,000







### Extra 



13. Write a C program, `print_file_bits.c`, which given as a command line arguments the name of a file contain 32-bit hexadecimal numbers, one per line, prints the low (least significant) bytes of each number as a signed decimal number (-128..127).



If a file `xyz` contains 2500 bytes, and it is scanned using the following code:

```c
int fd;         // open file descriptor
int nb;         // # bytes read
int ns = 0;     // # spaces
char buf[BUFSIZ]; // input buffer

fd = open ("xyz", O_RDONLY);
assert (fd >= 0);
while ((nb = read (fd, buf, 1000)) > 0) {
    for (int i = 0; i < nb; i++)
        if (isspace (buf[i]))
            ns++;
}
close (fd);
```

Assume that all of the relevant `#include`'s are done.

How many calls with be made to the `read()` function, and what is the value of `nb` after each call?

4