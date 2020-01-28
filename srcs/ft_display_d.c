/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:25:55 by anpogorz          #+#    #+#             */
/*   Updated: 2020/01/22 14:54:34 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    ft_display(char *str, p_list flags)
{
    int spaces;
    int precision;

    precision = ft_value_precision(flags, str);
    spaces = ft_value_spaces(flags, str, precision);
    if (flags.option == 'd')
        ft_display_d(precision, spaces, str, flags);
}

void    ft_display_d(int precision, int spaces, char *str, p_list flags)
{
    if (flags.first == '-')
    {
        while (precision)
        {
            ft_putchar_fd('0', 1);
            precision--;
        }
        ft_putstr_fd(str, 1);
        while (spaces)
        {
            ft_putchar_fd(' ', 1);
            spaces--;
        }
    }
    else
    {
        while (spaces)
        {
            ft_putchar_fd(' ', 1);
            spaces--;
        }
        while (precision)
        {
            ft_putchar_fd('0', 1);
            precision--;
        }
        ft_putstr_fd(str, 1);
    }
}

int     ft_value_precision(p_list flags, char *str)
{
    int precision;

    precision = 0;
    if (flags.third == '.')
        precision = ft_atoi(flags.fourth);
    if (precision > ft_strlen(str))
        precision = precision - ft_strlen(str);
    if (precision <= ft_strlen(str))
        precision = 0;
    return (precision);
}

int     ft_value_spaces(p_list flags, char *str, int precision)
{
    int spaces;

    spaces = 0;
    if (flags.second)
        spaces = ft_atoi(flags.second);
    if (spaces > (ft_strlen(str) + precision))
        spaces = spaces - (ft_strlen(str) + precision);
    if (spaces <= (ft_strlen(str) + precision))
        spaces = 0;
    return (spaces);
}
