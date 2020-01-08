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
	t_list flags;

	va_start (ap);
	while (*format)
		{
			if (*format == '%')
			{
				format++;
                flags = ft_check_flags(*format);
				ft_treatment(*format, ap);
				format++;

			}
			putchar(*format);
			format++;
		}
	va_end (ap);
}

int     ft_check_format(const char *format)
{
    if (*format != '0' && *format != '-')
        return -1;
    format++;
    if (*format != '*' && (*format > 9 || *format < 0))
        return -1;
    format = ft_pass_nbr(format);
    if (*format != '.' && *format != )
}

char    *ft_pass_nbr(const char *format)
{
    char *str;

    str = strdup(format);
    while (*str >= 0 && *str <= 9)
        str++;
    return (str);
}

t_list  ft_check_flags(const char *format)
{
    t_list flags;

    if (*format == '-' || *format == '0')
    {
        flags.first = *format;
        format++;
    }
    if (*format == '*')
        flags.second = *format;
    else
        flags.second = ft_atoi(format);
    format = ft_pass_nbr(format);
    flags.third = *format;
    if (*format == '.')
        format++;
    if (*format == '*')
        flags.fourth = *format;
    else
        flags.fourth = ft_atoi(*format);
    return(flags);
}