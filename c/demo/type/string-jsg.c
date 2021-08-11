#include "string-jsg.h"

/* @func string_length
 * @author: Wenger Binning
 * @email: wengerbinning@163.com
 * @version: 0.0.0.2
 * @date: 2021-05-31 15:55
 * @depend: stdio.h string.h byte-jsg.h char-jsg.h
 */

int string_length(const void *ptr) {
    int len = 0;
    if( ptr != NULL ) {
        while( *(char*)(ptr+len) != 0x00 ) {
            len++;
        }
    }
    return len;
}

/* @func string_parse
 * @author: Wenger Binning
 * @email: wengerbinning@163.com
 * @version: 0.0.0.1
 * @date: 2021-05-31 15:29
 * @depend: string.h byte-jsg.h char-jsg.h
 */

int string_parse(const char *ptr, int count, char *buffer) {
    int indexs[STRING_INDEX_MAX][2] = {0};
    int flags[STRING_INDEX_MAX] = {0};
    int i = 0, index = 0;

    while( ptr[i] != 0x00 ) {
        if( flags[index] == 0 ) {
            if( ptr[i] != 0x20 ) {
                flags[index] = 1;
                indexs[index][0] = i;
            }
        } else {
            if (ptr[i] == 0x20 ) {
                indexs[index][1] = i-indexs[index][0];
                flags[index] = 2;
                index++;
            }
        }
        i++;
    }
    if( flags[index] ) {
        indexs[index][1] = i-indexs[index][0];
        flags[index] = 2;
    }
    strncpy(buffer,ptr+indexs[count][0],indexs[count][1]);
    buffer[indexs[count][1]]=0x00;

    return 0;
}

/*/#########################################################################/*/

/* @func main
 * @author: Wenger Binning
 * @email: wengerbinning@163.com
 * @version: 0.0.0.1
 * @date: 2021-05-31 15:29
 * @depend: stdio.h string.h byte-jsg.h char-jsg.h
 */

int main(int argc, char * argv[]) {
    char *string = "hello, I am clark!";
    char buffer[30];
    int count = string_parse(string, 4, buffer);
    printf("%s\n",buffer);
    return 0;
}