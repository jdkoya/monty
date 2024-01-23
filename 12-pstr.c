#include "monty.h"

/**
 * pstr - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *sam = *stack;
	int s = 0;

	(void)line_number;


	while (sam)
	{
		s = sam->n;
		if (s == 0 || isalpha(s) == 0)
			break;
		putchar(s);
		sam = sam->next;
	}
	putchar('\n');
}
