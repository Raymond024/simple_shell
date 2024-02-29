#include"shell.h"
/**
 * executecmd - carries out the command given by user
 * @argsC: array containing the users' command
 * Return: return 0 on success
 */
int executecmd(char *argsC[])
{
	pid_t pid;
	int stat, fd;
	char *path = NULL;
	char buffer[4096];
	ssize_t bytesRead;

	pid = fork();
	if (pid == -1)
	{
		perror("Error in fork");
		return -1;
	}
	else if (pid == 0)
	{
		char **env = environ;

		if (strcmp(argsC[0], "env") == 0)
		{
			while (*env != NULL)
			{
				write(1, *env, strlen(*env));
				write(1, "\n", 1);
				env++;
			}
			_exit(EXIT_SUCCESS);
		}

		path = get_path(argsC[0]);
		if 
			(path == NULL)
			{
				perror("Command not found");
				_exit(EXIT_FAILURE);
			}
		fd = open(path, O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening file");
			_exit(EXIT_FAILURE);
		}

		while
			((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
			{
				write(1, buffer, bytesRead);
			}
		close(fd);
		_exit(EXIT_SUCCESS);
	}
	else
	{
		if (waitpid(pid, &stat, 0) == -1)
		{
			perror("Error in waitpid");
			return -1;
		}
		if (WIFEXITED(stat) && WEXITSTATUS(stat) != 0)
		{
			perror("Child process exited with non-zero status");
			return -1;
		}
		else if
			(WIFSIGNALED(stat))
			{
				perror("Child process terminated by signal");
				return -1;
			}
	}
	return 0;
}
