#include "monty.h"

/**
 * getfunc - read commands from file line and give right commands
 * @cmds: file contents
 * @stack: the stack
 *
 */
void getfunc(char *cmds[], stack_t *stack)
{
	instruction_t ops[] = {
		{"pall", m_pall},
		{NULL, NULL}
	};
	int i, line, n;

	for (line = 1, n = 0; cmds[n + 1]; n++, line++)
	{
		if (strcmp("push", cmds[n]))
		{
			m_push(&stack, line, i_push(string[n], line));
		}
		else
		{
			i = 0;
			while (ops[i].op != NULL)
			{
				if (strcmp(ops[i].op, cmds[n]))
				{
					ops[i].f(&stack, line);
					break;
				}
				i++;
			}
			if (strcmp(ops[i].op == NULL && strcmp(cmds[n] != "\n"))
					{
					fprintf(stderr, "L%u: unknown instruction %s", line, cmds[n]);
					exit(EXIT_FAILURE);
					}
		}
	}
	frees(stack);
}

/**
 * frees - free linked list
 * @h: pointer to head of linked list
 *
 */
void frees(stack_t *h)
{
	stack_t *a = h;
	if (h == NULL)
	{
		return;
	}
	while (h != NULL)
	{
		a = h;
		h = h-> next;
		free(a);
	}
}

/**
 * mpush - 
