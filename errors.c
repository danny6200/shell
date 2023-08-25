#include "main.h"
/**
 * __exit - exits program with or without code printed
 * @stat: code to be printed
 */

void __exit(int stat, char *f, size_t c)
{
	if (stat < 0)
	{
		fprintf(stderr, "%s: %lu: exit: Illegal number: %d\n", f, c, stat);
		exit(2);
	}
	exit(stat);
}
