#include "monty.h"

/**
 * m_push - push an element onto the stack
 * @stack: pointer of a pointer to actual stack
 * @line_number: the line number in the file
 * @n: integer
 *
 */
void m_push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *a, *b = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	a = malloc(sizeof(stack_t));
	if (a == NULL)
		exit(EXIT_FAILURE);
	a->prev = NULL;
	a->n = n;
	a->next = *stack;
	if (*stack)
		b->prev = a;
	*stack = a;
}

/**
 * m_pall - prints all the values on the stack from the top of the stack.
 * @stack: pointer of a pointer to actual stack
 * @line_number: the line number in the file
 *
 */
void m_pall(stack_t **stack, unsigned int line_number)
{
	(void)lin_number;
	stack_t *a = *stack;

	while (a)
	{
		printd("%d\n", a->n);
		a = a->next;
	}
}
