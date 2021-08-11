#ifndef BYTE_JSG_H
#define BYTE_JSG_H

#include <stdio.h>
#include <arpa/inet.h>

/* Print object byte value.
 * @param ptr This is a object pointer.
 * @param size This is a object size.
 * @return Return a printing number.
 */
int printByte(const void *ptr, uint32_t size);

/* Print object array.
 * @param ptr This is a array pointer.
 * @param count This is a array count.
 * @param size This is a element size.
 * @return Return array size.
 */
int printArray(const void *ptr, uint32_t count, uint32_t size);

#endif