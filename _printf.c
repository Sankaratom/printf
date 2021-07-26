#include "holberton.h"
#include <stdlib.h>

/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, j = 0, count = 0;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{NULL, NULL}
	};
	va_list valist;

	va_start(valist, format);
	while (format && format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		for (j = 0; p[j].t != NULL && format[i] == '%'; j++)
		{
			if (*(p[j].t) == format[i + 1])
			{
				count += p[j].f(valist);
				i += 2;
				break;
			}
		}
		if (p[j].t == NULL && format[i] == '%')
		{
			_putchar(format[i]);
			count++;
			if (format[i + 1] == '%')
				i += 2;
			else
				i++;
		}
	}
	va_end(valist);
	return (count);
}
