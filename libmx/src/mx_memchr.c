#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n)
{
    const char *s_copy = (const char *)s;

    for (size_t i = 0; i < n; i++) {
        if (s_copy[i] == (char)c) {
            return (void *)&s_copy[i];
        }
    }

    return NULL;
}
