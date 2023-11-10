#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n)
{
    const char *s_copy = (const char *)s;
    int length = mx_strlen(s_copy);

    for (int i = length - 1; i >= 0 && n > 0; i-- && n--) {
        if (s_copy[i] == (char)c) {
            return (void *)&s_copy[i];
        }
    }

    return NULL;
}
