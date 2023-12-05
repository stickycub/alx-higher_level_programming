#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_middle - Finds the middle of the linked list
 * @head: Pointer to the head of the list
 *
 * Return: Pointer to the middle node of the list
 */

listint_t *find_middle(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	return (slow);
}

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to the head of the list
 *
 * Return: Pointer to the head of the reversed list
 */

listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *current = head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to a pointer to the head of the list
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return (1);

	listint_t *mid = find_middle(*head);
	listint_t *second_half = reverse_list(mid->next);

	listint_t *first_half = *head;
	listint_t *second_half_copy = second_half;

	int is_palindrome = 1;

	while (first_half != NULL && second_half != NULL)
	{
		if (first_half->n != second_half->n)
		{
			is_palindrome = 0;
			break;
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}

	mid->next = reverse_list(second_half_copy);

	return (is_palindrome);
}
