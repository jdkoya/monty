#include "monty.h"
#include <ctype.h>

/**
 *  * check_for_digit - function to check for digit after opcode
 *   *
 *    * @arg: character to be checked for digit
 *     *
 *      * Return: integer
 */

static int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 *  * _push - increases length of stack for additional nodes
 *   *
 *    * @stack: head of the stack
 *     * @line_num: line being executed
 *      *
 *       * Return: nothing
 */
void _push(stack_t **stack, unsigned int line_num)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_for_digit(arg))
	{
		fprintf(stderr,
				"L%u: usage: push integer\n",
				line_num);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		fprintf(stderr,
				"Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
