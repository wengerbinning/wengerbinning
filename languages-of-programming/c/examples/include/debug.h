#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>


#define DEBUG_LEVEL_A 1
#define DBEUG_LEVEL_B 2
#define DEBUG_LEVEL_C 3



#define error(level, fmt, ...) \
    printf("[%02d ERROR] "fmt"\n",level, ##__VA_ARGS__)

#define warring(level, fmt, ...) \
    printf("[%02d WARRING] "fmt"\n",level, ##__VA_ARGS__)

#define info(level, fmt, ...) \
    printf("[%02d INFO] "fmt"\m", level, ##__VA_ARGS__)

#if defined(DEBUG)
#define debug(level, fmt, ...) \
    printf("[%02d DEBUG] "fmt"\n",level, ##__VA_ARGS__)
#else
#define debug(level, fmt, ...) do {} while(0)
#endif

#endif

