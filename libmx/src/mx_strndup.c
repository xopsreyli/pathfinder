#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
    if (s1 == NULL) {
        return NULL;
    }

    char *copy = mx_strnew(n);
    copy = mx_strncpy(copy, s1, n);

    return copy;
}
