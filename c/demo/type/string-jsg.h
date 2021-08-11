#ifndef STRING_JSG_H
#define STRING_JSG_H

#include <stdio.h>
#include <string.h>

#include "byte-jsg.h"
#include "char-jsg.h"
#include "string-jsg.h"

#define STRING_INDEX_MAX 10

/* Get string length.
 * @param ptr This is a string pointer.
 * @return Return string length.
 */
int string_length(const void *ptr);

/* Parse string
 * @param ptr This is a string pointer.
 * @param count This is a substring index.
 * @param buffer This save substring pointer.
 * @return Return a substring length.
 */
int string_parse(const char *ptr, int count, char *buffer);

#endif