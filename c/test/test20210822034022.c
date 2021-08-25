/*********************************************************************************************************************/
// @author: wenger
// @create date:8/22/21
// @update date:
// @version: 0.0.0.1
/*********************************************************************************************************************/

#include "test20210822034022.h"


int sum(int a, int b) {
    return (int)(a+b);
}

int sub(int a, int b) {
    return (int)(a-b);
}


int main(int argc, char *argv[]) {
    int a, b;
    integer_arithmetic func = sum;
    printf("This is sum a & b : %d", func(a,b));
    func = sub;
    printf("This is sub a & b : %d", func(a,b));
}