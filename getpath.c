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

	if (path == NULL)
	{
		perror("Error getting PATH");
		return (NULL);
	}

	while (token != NULL)
	{
		char *full_path = malloc(strlen(token) + strlen(program_name) + 2);

		if (full_path == NULL)
		{
			perror("Error allocating memory");
			return (NULL);
		}
		sprintf(full_path, "%s/%s", token, program_name);
		if (access(full_path, F_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
