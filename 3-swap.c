#include "monty.h"


/**
 *swap - function that switches places of stack
 *
 *@stack: pointer to linked list stack
 *
 *@line_number: number of line opcode occurs on
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *count;

	int swapped;

	count = *stack;

	if (count == NULL || count->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	swapped = count->n;
	count->n = count->next->n;
	count->next->n = swapped;
}

