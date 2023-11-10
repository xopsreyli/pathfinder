#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n)
{
    const char *s1_copy = (const char *)s1;
    const char *s2_copy = (const char *)s2;

    for (size_t i = 0; i < n; i++) {
        if (s1_copy[i] != s2_copy[i]) {
            return s1_copy[i] - s2_copy[i];
        }
    }

    return 0;
}
