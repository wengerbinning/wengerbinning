/*********************************************************************************************************************/
// @test content: string.
// @author: wenger
// @create date:8/22/21
// @update date:
// @version: 0.0.0.1
/*********************************************************************************************************************/

#include <stdio.h>

int convert_specific_char(const char *src, char *dest, unsigned int size, char old, char new) {
    int i = 0;
    int ret = 0;

    for( i = 0; i < (size-1); i++ ) {
        if( *(src+i) == '\0' ) {
            break;
        } else if( *(src+i) == old ) {
            *(dest+i) = new;
            ret++;
        } else {
            *(dest+i) = *(src+i);
        }
    }

    if( i < (size-1) ) {
        for(; i < size; i++ ) {
            *(dest+i) = '\0';
        }
    } else {
        *(dest+size-1) = '\0';
    }
    return ret;
}


int main( int argc, char *argv[]) {
    int ret = 0;
    char str1[]="";
    char str2[11];

    printf("convert before str2 |%s|\n",str2);
    ret = convert_specific_char(str1, str2, sizeof(str2), '_', '-');
    printf("convert finish str2 |%s|, convert %d\n",str2, ret);

    return 0;
}