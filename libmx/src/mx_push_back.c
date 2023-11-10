#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data)
{
    t_list *last = mx_create_node(data);

    if (*list == NULL) {
        *list = last;
        return;
    }

    t_list *temp = *list;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = last;
}
