/*********************************************************************************************************************/
// @test content: typedef
// @author: wenger
// @create date:8/22/21
// @update date:
// @version: 0.0.0.1
/*********************************************************************************************************************/

#ifndef C_TEST20210822034022_H
#define C_TEST20210822034022_H

#include <stdio.h>

// define a function's pointer type named integer_arithmetic.
typedef int (*integer_arithmetic)(int a,int b);

int sum(int, int);

int sub(int, int);

#endif // C_TEST20210822034022_H
