#define _GNU_SOURCE
#include "monty.h"

/*var_t var; */

/**
 *  * close_monty_file - close monty file
 *   *
 *    * @status: exit status
 *     * @arg: file pointer
 */
void close_monty_file(int status, void *arg)
{
	FILE *fs;

	fs = (FILE *)arg;
	(void)status;
	if (fs)
		fclose(fs);
}

/**
 *  * main - Monty bytecode interpreter
 *   *
 *    * @ac: number of argements
 *     * @av: array of argument strings
 *      *
 *       * Return: EXIT_SUCCESS on success.
 */

int main(int ac, char **av)
{
	var_t var;
	unsigned int line_num = 0;
	stack_t *head = NULL;
	FILE *fs = NULL;
	char *lineptr = NULL, *op = NULL;
	size_t n = 0;

	var.stack_len = 0;
	var.queue = STACK;

	if (ac != 2)
	{
		fprintf(stderr,
				"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fs = fopen(av[1], "r");
	if (fs == NULL)
	{
		fprintf(stderr,
				"Error: Can't open file %s\n",
				av[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_lineptr, &lineptr);
	on_exit(free_stack, &head);
	on_exit(close_monty_file, fs);
	while (getline(&lineptr, &n, fs) != -1)
	{
		line_num++;
		op = strtok(lineptr, "\n\t\r ");
		if (op != NULL && *op != '#')
		{
			get_op(op, &head, line_num);
			_pint(&head, line_num);
		}
	}
	exit(EXIT_SUCCESS);
}
