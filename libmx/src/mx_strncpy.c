#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len)
{
    if (!dst && !src) {
        return NULL;
    }

    int i = 0;
    for (; i < len && src[i]; i++) {
        dst[i] = src[i];
    }

    while (i < len) {
        dst[i] = '\0';
        i++;
    }

    return dst;
}
