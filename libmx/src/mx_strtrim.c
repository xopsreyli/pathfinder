#include "../inc/libmx.h"

char *mx_strtrim(const char *str)
{
    if (!str) {
        return NULL;
    }

    int length = mx_strlen(str);
    int start = 0;
    int end = length - 1;

    while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n' || str[start] == '\f' || str[start] == '\r') {
        start++;
    }

    while (end > start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n' || str[end] == '\f' || str[end] == '\r')) {
        end--;
    }

    length = end - start + 1;

    if (length <= 0) {
        return mx_strnew(0);
    }

    char *new_str = mx_strnew(length);
    mx_strncpy(new_str, str + start, length);

    return new_str;
}
