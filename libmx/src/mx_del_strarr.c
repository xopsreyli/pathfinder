#include "../inc/libmx.h"

void mx_del_strarr(char ***arr)
{
    if (arr == NULL || *arr == NULL) {
        return;
    }

    for (int i = 0; (*arr)[i]; i++) {
            mx_strdel(&(*arr)[i]);
    }
    free(*arr);
    *arr = NULL;
}
