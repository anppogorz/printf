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

void    ft_displays(char *str, p_list flags)
{
    int spaces;
    int precision;

    precision = ft_value_precision_s(flags, str);
    spaces = ft_value_spaces_s(flags, str, precision);
    //printf("precision = %d\n", precision);
    //printf("spaces = %d\n", spaces);
    if (flags.option == 's')
        ft_display_s(precision, spaces, str, flags);
}

void    ft_display_s(int precision, int spaces, char *str, p_list flags)
{
    if (flags.first == '-')
    {
        while (precision)
        {
            ft_putchar_fd(*str, 1);
            str++;
            precision--;
        }
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
            ft_putchar_fd(*str, 1);
            str++;
            precision--;
        }
    }
}

int     ft_value_precision_s(p_list flags, char *str)
{
    int precision;

    precision = ft_strlen(str);
    if (flags.third == '.')
    {
        precision = ft_atoi(flags.fourth);
        if (precision > ft_strlen(str))
            precision = ft_strlen(str);
    }
    return (precision);
}

int     ft_value_spaces_s(p_list flags, char *str, int precision)
{
    int spaces;

    spaces = 0;
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
