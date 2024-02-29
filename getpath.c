#include "shell.h"
/**
 * get_path - gets the environment path.
 * @program_name: the name of the program
 * Return: pointer to the environment path, NULL if not found
 */
char *get_path(const char *program_name)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");
	size_t token_len;
	size_t program_len;

	if (path == NULL)
	{
		perror("Error getting PATH");
		return (NULL);
	}

	while (token != NULL)
	{
		token_len = strlen(token);
		program_len = strlen(program_name);
		if (token_len + 1 + program_len + 1 <= PATH_MAX)
		{
			char *full_path = malloc(token_len + 1 + program_len + 1);

			if (full_path == NULL)
			{
				perror("Error allocating memory");
				return (NULL);
			}
			strcpy(full_path, token);
			strcat(full_path, "/");
			strcat(full_path, program_name);
			if (access(full_path, F_OK) == 0)
			{
				return (full_path);
			}
			free(full_path);
		}
		else
		{
			perror("Path length exceeds limit");
			return (NULL);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}
