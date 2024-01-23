#include "monty.h"


/**
 * file:13-rotr.c
 * rotr - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *count = *stack;

	int inpt = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (count->next)
		count = count->next;

	inpt = count->n;

	while (count->prev)
	{
		count = count->prev;
		count->next->n = count->n;
	}

	count->n = inpt;
}
