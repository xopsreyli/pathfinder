#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    char *dst_ptr = (char *)dst;
    const char *src_ptr = (const char *)src;

    for (size_t i = 0; i < n; i++) {
        dst_ptr[i] = src_ptr[i];
    }

    return dst;
}
