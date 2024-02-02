#include "main.h"
/**
 * printf function 
 *
 * @format: format specifier
 * Return: no of bytes printed by function
 */
int _printf(const char *format, ...)
{
	int i, string_counter,  counter = 0;

	va_list my_list_of_arguments;

	if (!format||(format[0] == '%'&& format[1] == '\0'  ))
		return (-1);

	va_start(my_list_of_arguments, format);

	for(i=0; format[i] !='\0'; i++)
	{
		if(format[i] != '%')
		{
			func_to_print_characters(format[i]);
		}
		else if (format[i] == '%' &&  format[i + 1] == 'c')
		{	
		func_to_print_characters(va_arg(my_list_of_arguments, int));
		i++;
		}
		else if (format[ i + 1] == 's')
		{
			string_counter = puts_function(va_args(my_list_of_arguments, *char));
			i++;
			counter += (string_counter - 1);
		}

		counter += 1;
	}
	va_end(my_list_of_arguments);
	return (counter);
}
