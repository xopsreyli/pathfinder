#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return mx_strnew(size);
    }else if (size == 0) {
        free(ptr);
        return NULL;
    }

    char *temp;
    char *new_ptr = mx_strnew(size);
    int length = mx_strlen(new_ptr);
    if (new_ptr == NULL) {
        return NULL;
    }

    temp = mx_strnew(size);
    temp = mx_memcpy(temp, ptr, length);
    ptr = mx_strnew(size);
    ptr = mx_memcpy(ptr, temp, length);
    free(temp);

    return ptr;
}
