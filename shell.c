#include "main.h"

/**
 * main - simple shell core. this is where the primary engine lives
 * @ac: argument count
 * @av: argument vector
 * @env: environment vector
 *
 * Return: 0 success
 *
 */

int main(int ac, char **av, char **env)
{
	char *buff = NULL, *delim = " \n", *f_name = av[0];
	size_t len = 0, count = 0;
	ssize_t read;

	(void)ac;

	if (ac > 1)
		file(av);
	else
		while (1)
		{
Point:
			count++;
			if (!(isatty(STDIN_FILENO)))
				non_interactive(env, f_name, count);
			else
			{
				printf("$ ");
				read = getline(&buff, &len, stdin);
				if (read == -1)
				{
					free(buff);
					printf("\n");
					exit(1);
				}
				av = str2arr(buff, delim);
				free(buff);
				buff = NULL;
				if (av == NULL)
					goto Point;
				getfunc(av, f_name, count);
			}
			free_dp(av);
			free(buff);
		}
	free_dp(av);
	free(buff);
	return (0);
}

/**
 * str2arr - performs tokenization of string recieved from main
 * @str: string to be tokenized
 * @delim: delimiter seperatimg each entry
 * Return: pointer to array of tokens
 */

char **str2arr(char *str, char *delim)
{
	int i = 0, n;
	char **arr, **a;

	arr = malloc(strlen(str) * sizeof(char *));
	arr[i] = _strtok(str, delim);
	if (arr[i] == NULL)
	{
		free(arr);
		return (NULL);
	}
	while (arr[i] != NULL)
	{
		i++;
		arr[i] = _strtok(NULL, delim);
	}
	a = malloc((i + 1) * sizeof(char *));
	if (a == NULL)
	{
		free_dp(arr);
		return (NULL);
	}
	for (n = 0; n < i; n++)
	{
		a[n] = strdup(arr[n]);
		if (a[n] == NULL)
		{
			free_dp(a);
			free_dp(arr);
			return (NULL);
		}

	}
	a[i] = NULL;
	free_dp(arr);
	return (a);
}

/**
 * chck_cmd - checks validity of command
 * @cmd: command string
 * Return: 0 if cmd_path is found but 1 if otherwise
 */
int chck_cmd(char *cmd)
{
	char *path = _getpath(cmd);

	if (path == NULL)
	{
		free(path);
		return (1);
	}
	free(path);
	return (0);
}


/**
 * getfunc - handles all functions from main
 * @av: array of arguments feom mamin
 * @f_name: name of shell executable
 * @count: line count
 * Return: 0 or -1
 */

void getfunc(char **av, char *f_name, size_t count)
{

	if (strcmp(av[0], "exit") == 0)
	{
		/* free_dp(av); */
		__exit(av[1]);
	}
	else if (strcmp(av[0], "env") == 0)
	{
		/* free_dp(av); */
		print_env();
		return;
	}
	exec_cmd(av, f_name, count);
}
/**
 * exec_cmd - executes command if PATH is found
 * @av: argument vector
 * @file_name: name of shell executable
 * @count: prompt display tracker
 *
 * Return: nothing
 */
void exec_cmd(char **av, char *file_name, size_t count)
{
	unsigned int cmd_status;
	size_t n = count;
	char *path,  **env = environ, *cmd = av[0];
	pid_t child;
	int status;

	cmd_status = chck_cmd(cmd);
	path = _getpath(cmd);
	/* strcpy(stat_path, path); */
	/* free(path); */

	if (cmd_status == 0)
	{
		child = fork();
		if (child == 0)
		{
			if (execve(path, av, env) == -1)
			{
				fprintf(stdout, "%s: %lu: %s: execution error", file_name, n, av[0]);
				exit(1);
			}
			/* free(path); */
			exit(1);
		}
		else
		{
			wait(&status);
			/* free(path); */
		}
	}
	else
	{
		free(path);
		fprintf(stdout, "%s: %lu: %s: not found\n", file_name, n, av[0]);
			return;
	}
}
