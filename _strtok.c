#include "main.h"

/**
 * _strtok - costum strtok
 * @str: string to be tokenized
 * @delim: delimiter
 * Return: each word
 */

char *_strtok(char *str, const char *delim)
{
	/* Stores the last position between function calls */
	static char *last = NULL;
	char *start, *end;

	if (str != NULL)
		last = str;/* Initialize last with str if str is not NULL */

	if (last == NULL)
		return NULL;/* Return NULL if there are no more tokens */

	start = last;/* Set the starting point for the token */
	end = strpbrk(start, delim);/* Find the next delimiter in the string */
	if (end != NULL)
	{
		*end = '\0';/* Replace the delimiter with a null terminator */
		/* Update last to point to the character after the delimiter */
		last = end + 1;
	}
	else
		last = NULL;/* Set last to NULL if no more tokens are found */

	return (start);/* Return the current token  and await next call*/
}
