#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str)
{
    if (!str) {
        return NULL;
    }

    char *new_str = mx_strtrim(str);
    int counter = 0;
    for (int i = 0; new_str[i]; i++) {
        if (new_str[i] == ' ' && new_str[i + 1] != '\n' && new_str[i + 1] != '\t' && new_str[i + 1] != '\f' && new_str[i + 1] != '\r' && new_str[i + 1] != ' ') {
            counter++;
        }
        if (new_str[i] != '\n' && new_str[i] != '\t' && new_str[i] != '\f' && new_str[i] != '\r' && new_str[i] != ' ') {
            counter++;
        }
    }

    char *result = mx_strnew(counter);
    int j = 0;
    for (int i = 0; new_str[i]; i++) {
        if (new_str[i] == ' ' && new_str[i + 1] != '\n' && new_str[i + 1] != '\t' && new_str[i + 1] != '\f' && new_str[i + 1] != '\r' && new_str[i + 1] != ' ') {
            result[j] = new_str[i];
            j++;
        }
        if (new_str[i] != '\n' && new_str[i] != '\t' && new_str[i] != '\f' && new_str[i] != '\r' && new_str[i] != ' ') {
            result[j] = new_str[i];
            j++;
        }
    }

    free(new_str);

    return result;
}
