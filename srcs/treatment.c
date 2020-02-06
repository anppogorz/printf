/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:31:28 by anpogorz          #+#    #+#             */
/*   Updated: 2020/02/06 08:53:54 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char    *ft_treatment(const char c, va_list ap)
{
    char *str;

    str = NULL;
    if (c == 'c')
        str = (ft_c(va_arg(ap, int)));
    if (c == 's')
        str = va_arg(ap, char *);
    if (c == 'p')
        str = (ft_p(va_arg(ap, void *)));
    if (c == 'd')
        str = ft_itoa(va_arg(ap, int));
    if (c == 'i')
        str = ft_itoa(va_arg(ap, int));
    if (c == 'u')
        str = ft_itoa_u(va_arg(ap, unsigned int));
    if (c == 'x')
        str = (ft_x(va_arg(ap, unsigned int)));
    if (c == 'X')
        str = (ft_X(va_arg(ap, unsigned int)));
    if (c == '%')
        str = ft_strdup("%");
    return (str);
}

int     ft_strlen_nbr(int i)
{
    int count;

    count = 0;
    if (i == -2147483648)
        return (11);
    if (i < 0)
    {
        i = -i;
        count++;
    }
    if (i == 0)
        return (1);
    while (i > 0)
    {
        i = i / 10;
        count++;
    }
    return (count);
}

int     ft_strlen_nbr_u(unsigned int u)
{
    int count;

    count = 0;
    if (u == 0)
        return (1);
    while (u > 0)
    {
        u = u / 10;
        count++;
    }
    return (count);
}