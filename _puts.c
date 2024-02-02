#include "main.h"
/**
 * puts - print string
 *
 * @c: string
 * Return: num of bytes
 */
int puts_function(char *c)
{
	int counter = 0;

	if (c)
	{
		for (counter = 0; c[counter] != '\0'; counter++)
		{
			func_to_print_characters(c[counter]);
		}
	}
	return (counter);
}
