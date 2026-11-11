#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main(void) {
    // Part 1 — Print CWD: Get and print the current working directory pathname.
    // Hint: getcwd()
    char cwd[1024] = {0};
    getcwd(cwd, 1024);

    // Part 2 — List current directory: Print one line per entry in the current directory (non-recursive):
    // <perms> <pathname>
    // Hint: use readdir() to recurse through subdirectories

    // opendir opens a directory stream so we can traverse through all the files within
    DIR *directory = opendir(cwd);
    struct dirent *e;

    // readdir returns very basic info about the next file in the directory
    while ((e = readdir(directory)) != NULL) {
        printf("Directory entry has name: %s ", e->d_name);

        // stat function necessary to extract file permissions
        struct stat file_info;
        stat(e->d_name, &file_info);

        // permissions (as a number)
        int permissions = file_info.st_mode;

        printf("and it's permissions is set to %o ", permissions & 0b111111111);

        // How do I know if the file is a directory or normal file?
        // man 7 inode has macros S_ISREG(permissions) for reg file or S_ISDIR(permissions) for directories
        if (S_ISREG(permissions)) {
            printf("Regular file\n");
        } else {
            printf("Directory\n");
        }
    }

    // Part 3 — Recurse: Recurse into all subdirectories and print pathnames in the same format as Part 1.

    // Part 4 — Filter by name: Only print lines for files whose basename contains "hello" (case-sensitive match).
}


