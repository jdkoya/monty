#include "monty.h"

/**
 * pop - it removes the top element of the stack just like the way the pop function is used in python.
 * @stack: double pointer to the beginning of the stack.
 * @line_number: current line number of the file being read.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *jerome;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	jerome = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(jerome);
}

