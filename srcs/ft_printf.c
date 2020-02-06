/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:31:21 by anpogorz          #+#    #+#             */
/*   Updated: 2020/02/06 08:10:34 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list ap;
	p_list flags;

	va_start (ap, format);
	while (*format != '\0')
		{
	        while (*format == '%')
			{
				format++;
                flags = flags_init(format);
                flags = ft_check_flags(format, flags);
                format = ft_skip_flags(format);
                flags.option = *format;
                flags = ft_check_stars(flags, ap);
                flags.count = ft_dispatch((ft_treatment(*format, ap)), flags);
                format++;
			}
	        ft_putchar_fd(*format, 1);
            flags.count++;
	        if (*format != '\0')
                format++;
		}
	va_end (ap);
	return (flags.count);
}

char	*ft_strdup_num(const char *s1)
{
    int		i;
    char	*s2;

    i = 0;
    while (s1[i] >= '0' && s1[i] <= '9')
        i++;
    if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    while (s1[i] >= '0' && s1[i] <= '9')
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

char    *ft_pass_nbr(const char *format)
{
    char *str;

    str = ft_strdup(format);
    while (*str >= '0' && *str <= '9')
        str++;
    return (str);
}