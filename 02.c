#include "main.h"

 /**
  * print_string - Prints a string.
  *
  * Return: 
  */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, l;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (l = width - len; l > 0; l--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (l = width - len; l > 0; l--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}
