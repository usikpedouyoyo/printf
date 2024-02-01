#include "main.h""
/**
 * putchar fucntion to print characters
 * @k: character input
 * Return: 1
 */
int func_to_print_characters(char k)
{
	return (write(1, &k, 1));
