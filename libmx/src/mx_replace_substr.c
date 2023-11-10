#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
    if (!str || !sub || !replace) {
        return NULL;
    }

    int length = mx_strlen(str),
        sub_length = mx_strlen(sub),
        rep_length = mx_strlen(replace),
        new_length = length + (rep_length - sub_length) * mx_count_substr(str, sub) + 1,
        substr_i = mx_get_substr_index(str, sub),
        i = 0,
        j = 0;
    char *new_str = mx_strnew(new_length);

    while (str[i]) {
        if (i == substr_i) {
            mx_strncpy(&new_str[j], replace, rep_length);
            i += sub_length;
            j += rep_length;
            substr_i = mx_get_substr_index(&str[i], sub);
        } else {
            new_str[j] = str[i];
            j++;
            i++;
        }
    }

    new_str[i] = '\0';

    return new_str;
}
