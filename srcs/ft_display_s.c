/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:25:55 by anpogorz          #+#    #+#             */
/*   Updated: 2020/02/06 07:21:12 by anpogorz         ###   ########.fr       */
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
    /*printf("precision = %d\n", precision);
    printf("spaces = %d\n", spaces);
    printf("str = %s\n", str);*/
    if (flags.option == 's' || flags.option == 'p')
        flags.count = ft_display_s(precision, spaces, str, flags);
    if (flags.option == 'c')
        flags.count = ft_display_c(precision, spaces, str, flags);
    if (flags.option == '%')
    {
        precision = ft_value_precision_pourcent(flags, str);
        //printf("precision = %d\n", precision);
        spaces = ft_value_spaces_s(flags, str, precision);
        flags.count = ft_display_pourcent(precision, spaces, str, flags);
    }
    return (flags.count);
}

int    ft_display_pourcent(int precision, int spaces, char *str, p_list flags)
{
    if (flags.first == '-')
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
    }
    else if (flags.first == '0')
    {
        while (spaces)
        {
            ft_putchar_fd('0', 1);
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

int    ft_display_c(int precision, int spaces, char *str, p_list flags)
{
    if (str[0] == '\0')
    {
        spaces = spaces - 1;
        precision = precision + 1;
    }
    if (flags.first == '-')
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
    }
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

int    ft_display_s(int precision, int spaces, char *str, p_list flags)
{
    if (flags.first == '-')
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
    }
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

int     ft_value_precision_pourcent(p_list flags, char *str)
{
    int precision;

    precision = ft_strlen(str);
    if (flags.third == '.' && flags.fourth[0] != '\0' && flags.fourth[0] != '0')
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
