#include "main.h"

/**
 * sub - This function subtracts  top 2 elemnts in 2nd element and pop 1st
 * @stack: linear node structure
 * @line_number: number of line in monty file
 *
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int aggregate;

	/* validate if the stack contains less than two elements.*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Get the value of the 2nd top element*/
	aggregate = (*stack)->next->n;

	/* Add the value to the top element.*/
	aggregate = aggregate - (*stack)->n;

	/* Removes the top element from the stack.*/
	pop(stack, line_number);

	/* This updates the value of the new top element*/
	(*stack)->n = aggregate;
}
