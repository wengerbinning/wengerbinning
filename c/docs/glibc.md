stdio.h

* pretreatment

```c
#ifndef _STDIO_H

#if !define(__need_FILE)
#define _STDIO_H   1
#define __need_size_t  
#define __need_NULL  
#include <stddef.h>
#define __need___va_list  
#include <stdarg.h>

#ifndef __GNUC_VA_LIST  
#define __gnuc_va_list __ptr_t  
#endif

#include <gnu/types.h>
#endif /* Don't need FILE.  */
#undef __need_FILE

#ifndef __FILE_defined


```

> macro

```c

```

>> basic type

>> pointer

>> struct



> function
> 