#include "../inc/libmx.h"

int mx_list_size(t_list *list)
{
    if (!list) {
        return 0;
    }

    t_list *temp = list;
    int size = 1;
    while (temp->next) {
        temp = temp->next;
        size++;
    }

    return size;
}
