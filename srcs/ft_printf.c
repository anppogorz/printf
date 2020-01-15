/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:31:21 by anpogorz          #+#    #+#             */
/*   Updated: 2020/01/15 15:11:46 by anpogorz         ###   ########.fr       */
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
				flags.option = *format;
                flags = ft_check_flags(*format);
                //if (ft_check_format(flags) == -1)
                    //return (ft_free_flags(flags));
                format = ft_skip_flags(format);
				ft_display((ft_treatment(*format, ap)), flags);
				format++;
			}
			ft_putchar_fd(*format, 1);
			format++;
		}
	va_end (ap);
	return (0);
}

const char    *ft_skip_flags(const char *s1)
{
    while (*s1 != 'd' && *s1 != 'p' && *s1 != 's' && *s1 != 'c' && *s1 != 'u' && *s1 != 'i' && *s1 != 'x' && *s1 != 'X')
        s1++;
    return (s1);
}

int     ft_check_format(t_list flags)
{

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

t_list  ft_check_flags(const char *format)
{
    t_list flags;

    if (*format == '-' || *format == '0')
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
        flags.third = ".";
        format++;
    }
    if (*format == '*')
        flags.fourth = ft_strdup("*");
    else
        flags.fourth = ft_strdup_num(format);
    return(flags);
}