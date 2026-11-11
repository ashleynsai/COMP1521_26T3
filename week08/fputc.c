#include <stdio.h>

int main() {
    FILE *fp = fopen("text", "w");

    
    //fwrite();
    fputc(0xFF, fp);
}