#include "monty.h"

/**
 * main - program entry
 * @argc: argument count
 * @argv: array of arguments availed
 *
 * Return: EXIT_SUCCESS on success EXIT_FAILURE on fail
 */
int main(int argc, char *argv[])
{
	FILE *mfile;
	int i = 0;
	size_t buffer = 1000;
	stack_t *stack = NULL;
	static char *cmds[1000] = {NULL};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mfile = fopen(argv[1], "r");
	if (mfile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (i = 0; getline(&(cmds[i]), &buffer, mfile) > 0; i++)
		;

	getfunc(cmds, stack);
	fclose(mfile);

	return (0);
}
