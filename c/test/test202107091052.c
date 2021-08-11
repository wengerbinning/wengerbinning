// test object: typedef

#include <stdio.h>
// define a new type, and this type is function pointer 
typedef int (*typedef_obj)(int a, int b);

int sum(int a, int b) {
    printf("%d\n", a+b);
    return a+b;
}

int main( int argc, char *argv[]) {
    int ret = 0;

    typedef_obj demo;
    demo = sum;

    printf("%d\n", demo(1, 2));

    return ret;
}