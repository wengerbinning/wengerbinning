#include "pointer-jsg.h"

/* @func: printPointer
 * @author: Wenger Binning 
 * @email: wengerbinning@163.com
 * @version: 0.0.0.1
 * @date: 2021-05-31 14:49
 * @depend: stdio.h arpa/inet.h
 */

int printPointer(const void *ptr, uint32_t size) {
    int i=0;
    for(int i=0; i<size; i++) {
        printf("(%p)[%02x]\n",(ptr+i),*((char*)(ptr+i)));
    }
    return i;
}