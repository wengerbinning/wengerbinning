#include <stdio.h>

#define TMP_FILE "./temp.txt"

int main(int argc, const char *argv[]) {
    FILE *file = NULL;

    file = fopen( TMP_FILE, "r");
    if( NULL == file) {
        return -1;
    }

    fclose(file);
    return 0;
}

