/**
 * _getline - reads input from a stream and stores it in a buffer
 * @lineptr: holds the address of the buffer
 * @n: determines the size of the buffer
 * @stream: determines the input to be read from
 *
 * Return: -1 on failure and 0 on success
 */
#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static size_t pos = 0, len;
	static char buffer[1024];
	char c;
	size_t lineLength = 0, buf_size = 1024;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = buf_size;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		if (pos >= len)
		{
			len = read(fileno(stream), buffer, 1024);
			if (len <= 0)
			{
				if (lineLength == 0)
					return (-1);
				break;
			}
		}
		c = buffer[pos++];
		(*lineptr)[lineLength++] = c;
		if (lineLength >= *n)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}
		if (c == '\n')
			break;
	}
	(*lineptr)[lineLength] = '\0';
	return (lineLength);
}
/**
 * main - test
 *
 * Return: 0 on success
 *
 *
 *
 * int main()
 * {
 *	char *line = NULL;
 *	size_t n = 0;
 *	ssize_t charsRead;
 *
 *	printf("Enter lines (Ctrl+D to exit):\n");
 *
 *	while ((charsRead = _getline(&line, &n, stdin)) != -1)
 *		printf("Read %ld chars: %s\n", charsRead, line);
 *	free(line);
 *	return (0);
 * }
*/
