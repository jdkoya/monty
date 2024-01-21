#include "monty.h"

/**
 *  * _pint - prints the value at the top of stack
 *   *
 *    * @stack: double pointer to the head of stack
 *     * @line_num: line being executed
 *      *
 *       * Return: nothing
 */
void _pint(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	stack_t *head = *stack;

	fprintf(stdout, "%d\n", head->n);
}
