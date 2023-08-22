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
	char *static_cmd;
	struct stat st;

	if (stat(cmd, &st) == 0)
	{
		cmd_path = _strdup(cmd);
		static_cmd = d2s(cmd_path);
		free(cmd_path);
		return (static_cmd); /*needs free*/
	}
	path = getenv("PATH");
	path_copy = _strdup(path); /*needs free*/

	arr = str2arr(path_copy, delim);

	while (arr[i] != NULL)
	{
		cmd_path = malloc(_strlen(arr[i]) + _strlen(cmd) + 2);
		_strcpy(cmd_path, arr[i]);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, cmd);
		_strcat(cmd_path, "\0");
		i++;
		if (stat(cmd_path, &st) == 0)
		{
			free(path_copy);
			free_dp(arr);
			static_cmd = d2s(cmd_path);
			free(cmd_path);
			return (static_cmd);
		}
	}
	free(cmd_path);
	free_dp(arr);
	free(path_copy);
	return (NULL);
}
