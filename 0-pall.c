#include "monty.h"

/**
 *pall - prints all the values on the stack, starting from the top of the stack.
 *
 *@stack_t pointer representation of the linked list
 *
 *@line_number: represent the stack
 *
 *samueljilowa@gmail.com
 *+260977224549
 *
 */

void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *count;

	count = *stack;

	while (count != NULL)
	{
		printf("%d\n", count->n);
		count = count->next;
	}
}
