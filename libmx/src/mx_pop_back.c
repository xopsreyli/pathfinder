#include "../inc/libmx.h"

void mx_pop_back(t_list **head)
{
    if (!*head) {
        return;
    } else if (!(*head)->next) {
        free(*head);
        *head = NULL;
        return;
    }

    t_list *temp = *head;
    while (temp->next->next) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}
