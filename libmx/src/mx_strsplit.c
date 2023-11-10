#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c)
{
    if (!s) {
        return NULL;
    }

    int substrings = mx_count_words(s, c);
    char **arr = (char **)malloc(sizeof (char *) * (substrings + 1));

    if (!arr) {
        return NULL;
    }

    int i = 0;
    while (*s) {
        if (*s != c) {
            const char *start = s;
            while (*s && *s != c) {
                s++;
            }

            arr[i] = mx_strnew(s - start + 1);

            mx_strncpy(arr[i], start, s - start);
            arr[i][s - start] = '\0';
            i++;
        }

        if (*s) {
            s++;
        }
    }

    arr[substrings] = NULL;

    return arr;
}
