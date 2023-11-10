#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len)
{
    const char *big_copy = (const char *)big;
    const char *little_copy = (const char *)little;

    for (size_t i = 0; i < big_len; i++) {
        if (big_copy[i] == little_copy[0]) {
                size_t j = 0;
            for (; j < little_len; j++) {
                if (big_copy[i + j] != little_copy[j]) {
                    break;
                }
            }
            if (j == little_len) {
                return (void *)&big_copy[i];
            }
        }
    }

    return NULL;
}
