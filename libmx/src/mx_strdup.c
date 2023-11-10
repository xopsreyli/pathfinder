#include "../inc/libmx.h"

char *mx_strdup(const char *str)
{
    int length = mx_strlen(str);
    char *dst = mx_strnew(length);

    if (dst != NULL)
    {
        mx_strcpy(dst, str);
        return dst;
    }

    return NULL;
}
