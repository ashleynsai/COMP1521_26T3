#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Open the file
    int f = open(argv[1], O_RDONLY);

    // lseek to before the beginning of the file
    off_t lseek_ret = lseek(f, -1, SEEK_SET);
    perror();
    printf("first lseek return value is %ld\n", lseek_ret);

    // lseek past the end of the file
    lseek_ret = lseek(f, 1000, SEEK_SET);
    printf("second lseek return value is %ld\n", lseek_ret);
}