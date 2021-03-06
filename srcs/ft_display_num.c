/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:25:55 by anpogorz          #+#    #+#             */
/*   Updated: 2020/02/06 12:55:39 by anpogorz         ###   ########.fr       */
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
