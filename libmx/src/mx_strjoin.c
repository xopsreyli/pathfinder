#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2)
{
    char *new_str = NULL;

    if(!s1 && !s2) {
        return NULL;
    } else if (!s1) {
        new_str = mx_strnew(mx_strlen(s2));
        new_str = mx_strcat(new_str, s2);
    } else if (!s2) {
        new_str = mx_strnew(mx_strlen(s1));
        new_str = mx_strcat(new_str, s1);
    } else {
        new_str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        new_str = mx_strcat(mx_strcat(new_str, s1), s2);
    }

    return new_str;
}
