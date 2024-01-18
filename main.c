#include <stdio.h>
#include "monty.h"

arguments_t *arg = NULL;
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
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
	size_t i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	arg = malloc(sizeof(arguments_t));
	if (arg == NULL)
	{
		malloc_fail();
	}
	arg->montyfile = NULL;
	arg->line = NULL;
	mfile = fopen(argv[1], "r");
	arg->montyfile = mfile;
	if (arg->montyfile == NULL || mfile == NULL) 
	{
		fileopen(argv[1]);
	}
	while (getline(&arg->line, &i, arg->montyfile) != -1)
	{
		printf("%s", arg->line);
	}
	return (0);
}
