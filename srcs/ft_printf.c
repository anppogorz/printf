#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list ap;

	va_start (ap);
	while (*format)
		{
			if (*format == '%')
			{
				format++;
				ft_treatment(*format, ap);
				format++;

			}
			putchar(*format);
			format++;
		}
	va_end (ap);
}
