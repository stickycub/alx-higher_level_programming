#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - Check if a linked list contains a cycle
 * @list: Pointer to the head of the linked list
 *
 * Return: 0 if no cycle, 1 if a cycle is detected
 */

int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	if (list == NULL || list->next == NULL)
		return (0);

	slow = list;
	fast = list->next;

	while (fast != NULL && fast->next != NULL)
	{
		if (slow == fast)
			return (1);

		slow = slow->next;
		fast = fast->next->next;
	}

	return (0);
}
