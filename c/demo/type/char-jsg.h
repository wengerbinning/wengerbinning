#ifndef CHAR_JSG_H
#define CHAR_JSG_H

#include <stdio.h>
#include <arpa/inet.h>

/* Print object bu char.
 * @param ptr This is object pointer.
 * @param size This is a object size.
 * @return Return a printing number.
 */
int printChar(const void *ptr, uint32_t size);

#endif