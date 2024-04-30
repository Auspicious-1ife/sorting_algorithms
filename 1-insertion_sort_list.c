#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
listint_t *curr, *temp;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
curr = (*list)->next;
while (curr != NULL)
{
temp = curr;
while (temp->prev != NULL && temp->n < temp->prev->n)
{
temp->prev->next = temp->next;
if (temp->next != NULL)
temp->next->prev = temp->prev;
temp->next = temp->prev;
temp->prev = temp->prev->prev;
temp->next->prev = temp;
if (temp->prev != NULL)
temp->prev->next = temp;
else
*list = temp;
temp = temp->prev;
print_list(*list);
}
curr = curr->next;
}
}

