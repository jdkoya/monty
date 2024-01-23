#include "main.h"

/**
 * mul -  This function multiplies  the top 2 elemnts in 2nd element and pop 1st
 * @stack: linear node structure
 * @line_number: number of line in monty file
 * School: Alx
 * File:8-mul.c
 *
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int aggregate;

	/* validate if the stack contains less than two elements.*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* This gets the value of the 2nd top element*/
	aggregate = (*stack)->next->n;

	/* To add the value to the top element.*/
	aggregate *= (*stack)->n;

	/* Remove the top element from the stack.*/
	pop(stack, line_number);

	/*update the value of the new top element*/
	(*stack)->n = aggregate;
}
