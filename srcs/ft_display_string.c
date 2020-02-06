/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:25:55 by anpogorz          #+#    #+#             */
/*   Updated: 2020/02/06 11:20:22 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int    ft_displays(char *str, p_list flags)
{
    int spaces;
    int precision;

    if (str == NULL)
        str = ft_strdup("(null)");
    precision = ft_value_precision_s(flags, str);
    spaces = ft_value_spaces_s(flags, str, precision);
    if (flags.option == 's' || flags.option == 'p')
        flags.count = ft_display_s(precision, spaces, str, flags);
    if (flags.option == 'c')
        flags.count = ft_display_c(precision, spaces, str, flags);
    if (flags.option == '%')
    {
        precision = ft_value_precision_pourcent(flags, str);
        spaces = ft_value_spaces_s(flags, str, precision);
        flags.count = ft_display_pourcent(precision, spaces, str, flags);
    }
    return (flags.count);
}

int    ft_display_s(int precision, int spaces, char *str, p_list flags)
{
    if (flags.first == '-')
        flags.count = ft_display_s_minus(spaces, precision, str, flags);
    else
    {
        while (spaces)
        {
            ft_putchar_fd(' ', 1);
            flags.count++;
            spaces--;
        }
        while (precision)
        {
            ft_putchar_fd(*str, 1);
            flags.count++;
            str++;
            precision--;
        }
    }
    return (flags.count);
}

int ft_display_s_minus(int spaces, int precision, char *str, p_list flags)
{
    while (precision)
    {
        ft_putchar_fd(*str, 1);
        flags.count++;
        str++;
        precision--;
    }
    while (spaces)
    {
        ft_putchar_fd(' ', 1);
        flags.count++;
        spaces--;
    }
    return (flags.count);
}

int     ft_value_precision_s(p_list flags, char *str)
{
    int precision;

    precision = ft_strlen(str);
    if (flags.third == '.' && flags.fourth[0] != '\0')
    {
        precision = ft_atoi(flags.fourth);
        if (precision > (int)ft_strlen(str))
            precision = ft_strlen(str);
    }
    if (precision < 0)
        precision = ft_strlen(str);
    if (flags.fourth[0] == '0')
        precision = 0;
    if (flags.third == '.' && flags.fourth[0] == '\0')
        precision = 0;
    return (precision);
}

int     ft_value_spaces_s(p_list flags, char *str, int precision)
{
    int spaces;

    spaces = 0;
    (void)str;
    if (flags.second)
    {
        spaces = ft_atoi(flags.second);
        if (spaces > precision)
            spaces = spaces - precision;
        else
            spaces = 0;
    }
    return (spaces);
}
