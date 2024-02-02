#include "main.h"
/**
 * _printf - function to print output to stdout
 *
 * @format: format specifier
 * Return: no of bytes printed by function
 */
int _printf(const char *format, ...)
{
	int i, string_counter,  counter = 0;

	va_list my_list_of_arguments;

	va_start(my_list_of_arguments, format);

	for (i = 0; format[i]  !=  '\0'; i++)
	{
		if (format[i] != '%')
		{
			func_to_print_characters(format[i]);
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{	
		func_to_print_characters(va_arg(my_list_of_arguments, int));
		i++;
		}
		else if (format[i + 1] == 's')
		{
			string_counter = puts_function(va_arg(my_list_of_arguments, char *));
			i++;
			counter += (string_counter - 1);
		}
		else if (format[i + 1] == '%')
		{
			func_to_print_characters('%');
		}
		counter += 1;
	}
		va_end(my_list_of_arguments);
	return (counter);
}
