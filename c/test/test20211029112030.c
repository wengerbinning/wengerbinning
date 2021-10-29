/* This test is
 *
 *
 */

#include <stdio.h>

int func(int a, int b) {
    int i=0;
    int array[10] = { 0 };

    for( i=0; i<11; i++ ) {
        array[i] = i;
    }

    return 0;
}

int main(int argc, const char *argv[]) {
    func(1, 2);

    return 0;
}



