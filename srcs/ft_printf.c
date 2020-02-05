/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:31:21 by anpogorz          #+#    #+#             */
/*   Updated: 2020/02/05 08:20:39 by anpogorz         ###   ########.fr       */
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
				flags.option = *format;
                flags = ft_check_flags(format, flags);
                //if (ft_check_format(flags) == -1)
                    //return (ft_free_flags(flags));
                format = ft_skip_flags(format);
                flags.option = *format;
                flags = ft_check_stars(flags, ap);
                //flags.fourth = "0";
                ft_dispatch((ft_treatment(*format, ap)), flags);
				/*printf("first : %c\n", flags.first);
                printf("second : %s\n", flags.second);
                printf("third : %c\n", flags.third);
                printf("fourth : %s\n", flags.fourth);
                printf("option : %c\n", flags.option);*/
                format++;
			}
	        ft_putchar_fd(*format, 1);
	        if (*format != '\0')
			    format++;
		}
	va_end (ap);
	return (0);
}

p_list  ft_check_stars(p_list flags, va_list ap)
{
    int second;
    int fourth;

    if (ft_strncmp(flags.second, "*", 1) == 0)
    {
        second = (va_arg(ap, int));
        if (second < 0)
        {
            second = -second;
            flags.first = '-';
        }
        flags.second = ft_itoa(second);
    }
    if (ft_strncmp(flags.fourth, "*", 1) == 0)
    {
        fourth = (va_arg(ap, int));
        flags.fourth = ft_itoa(fourth);
    }
    return (flags);
}

const char    *ft_skip_flags(const char *s1)
{
    while (*s1 != 'd' && *s1 != 'p' && *s1 != 's' && *s1 != 'c' && *s1 != 'u' && *s1 != 'i' && *s1 != 'x' && *s1 != 'X'
            && *s1 != '%')
        s1++;
    return (s1);
}

char	*ft_strdup_num(const char *s1)
{
    int		i;
    char	*s2;

    i = 0;
    while (s1[i] >= '0' && s1[i] <= '9')
        i++;
    s2 = (char *)malloc(sizeof(char) * (i + 1));
    if (s2 == 0)
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

p_list  ft_check_flags(const char *format, p_list flags)
{
    flags.first = '\0';
    flags.second = "\0";
    flags.third = '\0';
    flags.fourth = "\0";
    while (*format == '-' || *format == '0')
    {
        flags.first = *format;
        format++;
    }
    if (*format == '*')
    {
        flags.second = ft_strdup("*");
        format++;
    }
    else
        flags.second = ft_strdup_num(format);
    format = ft_pass_nbr(format);
    if (*format == '.')
    {
        flags.third = '.';
        format++;
    }
    if (*format == '*')
        flags.fourth = ft_strdup("*");
    else
        flags.fourth = ft_strdup_num(format);
    return(flags);
}