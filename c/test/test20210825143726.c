#include "test20210825143726.h"

#include <stdio.h>

int main(int argc, char * argv[] ) {
    int a;
    fflush(stdin);
    scanf("%d\n", &a);
    switch (a)
    {
    case A:
        printf("A\n");
    case B:
        printf("B\n");
    case C:
        printf("C\n");
    case D:
        printf("D\n");
    case E:
        printf("E\n");
    case F:
        printf("F\n");
    case G:
    case H:
        printf("G\n");
    default:
        printf("UNKNOW\n");
    }
    return 0;
}