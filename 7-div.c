#include "main.h"

/**
 * divide - This function divides the top 2nd elemnt over the 1st element and pop 1st
 * @stack: linear node structure
 * @line_number: number of line in m file
 *
 * Return: void
 */

void divide(stack_t **stack, unsigned int line_number)
{
	int aggregate;

	/* Check if the stack contains less than two elements.*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Get the value of the 2nd top element*/
	aggregate = (*stack)->next->n;
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Add the value to the top element.*/
	aggregate = aggregate / (*stack)->n;

	/* Remove the top element from the stack.*/
	pop(stack, line_number);

	/*update the value of the new top element*/
	(*stack)->n = aggregate;
}


