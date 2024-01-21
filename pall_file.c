#include "monty.h"

/**
 *  * _pall - prints all the values on the stack, starting from the top
 *   *
 *    * @stack: head of the stack
 *     * @line_num: line of file being executed
 *      *
 *       * Return: nothing
 */
void _pall(stack_t **stack, unsigned int line_num)
{
	stack_t *head;
	(void)line_num;

	head = *stack;
	while (head != NULL)
	{
		fprintf(stdout,
				"%d\n",
				head->n);
		head = head->next;
		if (head == *stack)
			return;
	}
}
