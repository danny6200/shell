#include "main.h"

/**
 * main - simple shell core. this is where the primary engine lives
 * Return: 0 success
 *
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	char *buff = NULL, *delim = " \n";
	size_t len = 0;
	ssize_t read;
	int status;
	pid_t child;

	while (1)
	{
		printf("#simple_shell$ ");
		read = getline(&buff, &len, stdin);
		if (read == -1)
		{

			printf("\n");
			exit(1);
		}
		
		av = str2arr(buff, delim);
		/*printf("%p", arr[i]);*/
		if (strcmp(av[0], "exit") == 0)
			exit(0);
		if (strcmp(av[0], "env") == 0)
			print_env();
		child = fork();
		if (child == 0)
			chck_cmd(av);
		else
			wait(&status);

	}
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
	arr[i] = strtok(str, delim);
	while (arr[i] != NULL)
	{
		i++;
		arr[i] = strtok(NULL, delim);
	}
	arr[i] = NULL;
	a = malloc(i * sizeof(char *));
	if (a == NULL)
		exit(1);
	for (n = 0; n < i; n++)
	{
		a[n] = strdup(arr[n]);
		if (a[n] == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
	}
	free(arr);

	return (a);
}
/**
 * chck_cmd - checks if command is valid
 * @av: argument vector
 *
 * Return: nothing
 */
void chck_cmd(char **av)
{
	unsigned int i;
	struct stat st;
	extern char **environ;

	(void)i;
	if (stat(av[0], &st) == 0)
	{
		if (execve(av[0], av, environ) == -1)
		{
			perror("/hsh: not found");
			exit(1);
		}
	}
	else
	{
		perror("/hsh: not found");
		exit(1);
	}
}
