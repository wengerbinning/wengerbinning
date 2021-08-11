#ifndef POINTER_JSG_H
#define POINTER_JSG_H

#include <stdio.h>
#include <arpa/inet.h>

/* Print object address and value.
 * @param ptr This is a object pointer.
 * @param size This is a object size.
 * @return Return a printing number.
 */
int printPointer(const void *ptr, uint32_t size);

#endif