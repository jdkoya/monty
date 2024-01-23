#include "main.h"



/**
 *pint - function that prints the number on top of  the stack
 *
 *@stack: pointer to linked list stack
 *
 *@line_number: line number opcode occurs
 * By samueljilowa@gmail.com
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *sam;

	sam = *stack;

	if (sam == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", sam->n);
}


