#include <stdio.h>

#define TMP_FILE "./temp.txt"

int main(int argc, const char *argv[]) {
    FILE *file = NULL;

    // const char *filename
    // filename是指打开的文件路径。
    // chost char *mode
    // mode是打开的模式。
    //   *
    //   *
    file = fopen( TMP_FILE, "");
    if( NULL == file) {
        return -1;
    }

    fclose(file);
    return 0;
}

