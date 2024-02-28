#include"shell.h"

/**
 * commandread - takes users input
 * Return: returns the number of characters read
 */
int commandread(void)
{
	size_t n = 0;
	int s;
	char *buffer = NULL, *command, *argsC[MAX_ARG];

	s = getline(&buffer, &n, stdin);
	if (s == -1)
	{
		if (feof(stdin))
		{
			free(buffer);
			exit(0);
		}
		else
		{
			perror("failed to read user input");
			free(buffer);
		}
	}
	command = erasenull(buffer, s);

	if (strcmp(command, "exit") == 0)
	{
		free(buffer);
		exit(0);
	}
	tokenizer(command, argsC);

	executecmd(argsC);

	free(buffer);
	return (s);
}
