/**
 * _getpath - returns the path of a command
 * @cmd: command
 *
 * Return: pointer to path
 */
#include "main.h"
char *_getpath(char *cmd)
{
	char *path, *path_copy, **arr, *delim = ":", *cmd_path;
	unsigned int i = 0;

	if (stat(cmd, &st) == 0)
	{
		cmd_path = strdup(cmd);
		return (cmd_path); /*needs free*/
	}
	path = getenv("PATH");
	path_copy = strdup(path); /*needs free*/

	arr = str2arr(path_copy, delim);

	while (arr[i] != NULL)
	{
		cmd_path = malloc(strlen(arr[i]) + strlen(cmd) + 2);
		strcpy(cmd_path, arr[i]);
		strcat(cmd_path, "/");
		strcat(cmd_path, cmd);
		strcat(cmd_path, "\0");
		i++;
		if (stat(cmd_path, &st) == 0)
		{
			free(path_copy);
			free_dp(arr);
			return (cmd_path);
		}
	}
	free(cmd_path);
	free_dp(arr);
	free(path_copy);
	return (NULL);
}
