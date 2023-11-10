#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *))
{
    if (lst == NULL || lst->next == NULL) {
        return lst;
    }

    bool swapped;
    t_list *temp;

    do {
        swapped = false;
        temp = lst;

        while (temp->next != NULL) {
            if (cmp(temp->data, temp->next->data)) {
                void *tmp_data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tmp_data;
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);

    return lst;
}
