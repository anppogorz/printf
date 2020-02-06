/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:25:55 by anpogorz          #+#    #+#             */
/*   Updated: 2020/02/06 07:14:57 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int    ft_displayd(char *str, p_list flags)
{
    int spaces;
    int precision;

    precision = ft_value_precision_d(flags, str);
    spaces = ft_value_spaces_d(flags, str, precision);
    flags.count = ft_display_d(precision, spaces, str, flags);
    return (flags.count);
}

int    ft_display_d(int precision, int spaces, char *str, p_list flags)
{
    if (flags.first == '-')
    {
        if (*str == '-')
        {
            ft_putchar_fd('-', 1);
            flags.count++;
            str++;
        }
        while (precision)
        {
            ft_putchar_fd('0', 1);
            flags.count++;
            precision--;
        }
        ft_putstr_fd(str, 1);
        flags.count = flags.count + ft_strlen(str);
        while (spaces)
        {
            ft_putchar_fd(' ', 1);
            flags.count++;
            spaces--;
        }
    }
    else if ((flags.first == '0' && flags.third != '.') || (flags.first == '0' && flags.fourth[0] == '-'))
    {
        {
            if (*str == '-' && (flags.fourth[0] == '-' || flags.fourth[0] == '\0'))
            {
                ft_putchar_fd('-', 1);
                flags.count++;
                str++;
            }
            while (spaces)
            {
                ft_putchar_fd('0', 1);
                flags.count++;
                spaces--;
            }
            if (*str == '-' && (flags.fourth[0] != '-' || flags.fourth[0] != '\0'))
            {
                ft_putchar_fd('-', 1);
                flags.count++;
                str++;
            }
            while (precision)
            {
                ft_putchar_fd('0', 1);
                flags.count++;
                precision--;
            }
            ft_putstr_fd(str, 1);
            flags.count = flags.count + ft_strlen(str);
        }
    }
    else
    {
        while (spaces)
        {
            ft_putchar_fd(' ', 1);
            flags.count++;
            spaces--;
        }
        if (*str == '-')
        {
            ft_putchar_fd('-', 1);
            flags.count++;
            str++;
        }
        while (precision)
        {
            ft_putchar_fd('0', 1);
            flags.count++;
            precision--;
        }
        ft_putstr_fd(str, 1);
        flags.count = flags.count + ft_strlen(str);
    }
    return (flags.count);
}

int     ft_value_precision_d(p_list flags, char *str)
{
    int precision;
    int len;

    len = ft_strlen(str);
    if (str[0] == '-')
        len = len - 1;
    precision = 0;
    if (flags.third == '.')
    {
        precision = ft_atoi(flags.fourth);
        if (precision > len)
            precision = precision - len;
        else
            precision = 0;
    }
    return (precision);
}

int     ft_value_spaces_d(p_list flags, char *str, int precision)
{
    int spaces;

    spaces = 0;
    if (flags.second)
    {
        spaces = ft_atoi(flags.second);
        if (spaces > ((int)ft_strlen(str) + precision))
            spaces = spaces - (ft_strlen(str) + precision);
        else
            spaces = 0;
    }
    return (spaces);
}
