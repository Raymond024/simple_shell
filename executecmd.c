#include"shell.h"
/**
 * executecmd - carries out the command given by user
 * @argsC: array containing the users' command
 * Return: return 0 on success
 */
int executecmd(char *argsC[])
{
	pid_t pid;
	int stat;

	pid = fork();
	if (pid == 0)
	{
		char *path = get_path(argsC[0]);

		if (path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", argsC[0]);
			exit(EXIT_FAILURE);
		}
		if (execv(path, argsC) == -1)
		{
			perror("Error in execution");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Process failure");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &stat, 0);
	}
	return (0);
}
