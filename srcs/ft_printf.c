/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:31:21 by anpogorz          #+#    #+#             */
/*   Updated: 2019/12/17 15:31:23 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
