include "main.h"
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int p, prin_ted = 0, chars_printed = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list_of_chars;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list_of_chars, format);

	for (p = 0; format && format[p] != '\0'; p++)
	{
		if (format[p] != '%')
		{
			buffer[buff_ind++] = format[p];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[p], 1);*/
			chars_printed++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &p);
			width = get_width(format, &p, list_of_chars);
			precision = get_precision(format, &p, list_of_chars);
			size = get_size(format, &p);
			++p;

			prin_ted = handle_print(format, &p, list_of_chars, buffer,
				flags, width, precision, size);
			if (prin_ted == -1)
				return (-1);
			chars_printed += prin_ted;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list_of_chars);

	return (chars_printed);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}












