#include "shell.h"
/**
 * main - entry point to program
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	while (1)
	{
		dis_prompt();
		commandread();
	}
	return (0);
}
