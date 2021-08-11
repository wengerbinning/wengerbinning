#include "byte-jsg.h"



/* @func printByte
 * @author: Wenger Binning
 * @email: wengerbinning@163.com
 * @version： 0.0.0.1
 * @date： 2021-05-31 14：49
 * @depend： stdio.h arpa/inet.h
 */

int printByte(const void *ptr, uint32_t size) {
    int i = 0;
    for(int i=0; i<size; i++) {
        if(i!=size-1)
            printf("[%02x]->",*((char*)(ptr+i)));
        else
            printf("[%02x]\n",*((char*)(ptr+i)));
    }
    return i;
}

/* @func: printArray
 * @author: Wenger Binning
 * @email: wengerbinning@163.com
 * @version: 0.0.0.1
 * @date: 2021-05-31 14:59
 * @depend: stdio.h arpa/inet.h 
 */

int printArray(const void *ptr, uint32_t count, uint32_t size) {
    int i = 0;
    for(i=0; i<count; i++) {
        printf("%d ",i);
        printByte((ptr+i*size),size);
    }
    return i;
}

/*/#########################################################################/*/

/* @func main
 * @author: Wenger Binning
 * @email: wengerbinning@163.com
 * @version: 0.0.0.1
 * @depend stdio.h arpa/inet.h
 */

// int main(int argc, char *argv[]) {
//     unsigned int var = htonl(17);
//     for (int i=0; i<argc; i++) {
//         printf("%s\n",argv[i]);
//     }
//     int i=len_string(argv[2]);
//     printf("%d\n",i);
//     return 0;
// }