#include "char-jsg.h"

/* @func printChar
 * @author: Wenger Binning
 * @email: wengerbinning@163.com
 * @version: 0.0.0.1
 * @date: 2021-05-21 15:13
 * @depend: stdio.h arpa/inet.h
 */ 

int printChar(const void *ptr, uint32_t size) {
    int i = 0;
    for(int i=0; i<size; i++) {
        if(i!=size-1)
            printf("%c",*((char*)(ptr+i)));
        else
            printf("%c\n",*((char*)(ptr+i)));
    }
    return i;
}