#include"shell.h"
/**
 * tokenizer - tokenizes user input
 * @command: input received from user
 * @argsC: array for the tokens
 * Return: the number of tokens
 */
int tokenizer(char *command, char *argsC[])
{
	char *deli = " ", *tokens;
	int counter = 0;

	tokens = strtok(command, deli);

	while (tokens)
	{
		argsC[counter++] = tokens;
		tokens = strtok(NULL, deli);
	}
	argsC[counter] = NULL;

	return (counter);
}
