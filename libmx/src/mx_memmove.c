#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len)
{
    char *dst_copy = (char *)dst;
    const char *src_copy = (const char *)src;
    char *temp = mx_strnew(len);

    for (size_t i = 0; i < len; i++) {
        temp[i] = src_copy[i];
    }
    for (size_t i = 0; i < len; i++) {
        dst_copy[i] = temp[i];
    }
    free(temp);

    return dst_copy;
}
