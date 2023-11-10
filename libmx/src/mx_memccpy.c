#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
    char *dst_ptr = (char *)dst,
         *src_ptr = (char *)src;

    for (size_t i = 0; src_ptr[i] && i < n; i++) {
        dst_ptr[i] = src_ptr[i];
        if (src_ptr[i] == (char)c) {
            return dst_ptr + i + 1;
        }
    }

    return NULL;
}
