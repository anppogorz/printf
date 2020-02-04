/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:25:55 by anpogorz          #+#    #+#             */
/*   Updated: 2020/02/04 12:16:37 by anpogorz         ###   ########.fr       */
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
    if (flags.option == 's' || flags.option == 'p' || flags.option == 'c')
        ft_display_s(precision, spaces, str, flags);
    if (flags.option == '%')
        ft_display_pourcent(precision, spaces, str, flags);
}
void    ft_display_pourcent(int precision, int spaces, char *str, p_list flags)
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
    else if (flags.first == '0')
    {
        while (spaces)
        {
            ft_putchar_fd('0', 1);
            spaces--;
        }
        while (precision)
        {
            ft_putchar_fd(*str, 1);
            str++;
            precision--;
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
        if (precision > (int)ft_strlen(str))
            precision = ft_strlen(str);
    }
    if (precision < 0)
        precision = ft_strlen(str);
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
