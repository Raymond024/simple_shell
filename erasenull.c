#include"shell.h"
/**
 * erasenull - removes newline char from user iput
 * @string: user input
 * @leng: length of the string
 * Return: return input with new line character erased
 */
char *erasenull(char *string, int leng)
{
	if (string != 0 && string[leng - 1] == '\n')
		string[leng - 1] = '\0';
	return (string);
}
