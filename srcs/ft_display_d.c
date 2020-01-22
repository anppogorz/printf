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

    spaces = ft_value_longueur(flags, str);
    precision = ft_value_precision(flags, str);
}


int     ft_value_precision(p_list flags, char *str)
{
    int precision;

    precision = 0;
    if (flags.third == '.')
        precision = ft_atoi(flags.fourth);
    if ((precision > ft_atoi(flags.second)) && (precision < ft_strlen(str)))
    {
        if (ft_atoi(flags.second) >= ft_strlen(str))
            precision = precision - ft_atoi(flags.second);
        if (ft_atoi(flags.second) < ft_strlen(str))
            precision = precision - ft_strlen(str);
    }
    return (precision);
}

int     ft_value_longueur(p_list flags, char *str)
{
    int spaces;
    int compare;

    spaces = 0;
    if (flags.second)
        spaces = ft_atoi(flags.second);
    if ((spaces > ft_atoi(flags.fourth)) && (spaces > ft_strlen(str)))
    {
        if (ft_atoi(flags.fourth) >= ft_strlen(str))
            spaces = spaces - ft_atoi(flags.fourth);
        if (ft_atoi(flags.fourth) < ft_strlen(str))
            spaces = spaces - ft_strlen(str);
    }
    return (spaces);
}
