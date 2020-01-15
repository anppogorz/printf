/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:31:28 by anpogorz          #+#    #+#             */
/*   Updated: 2020/01/15 11:38:24 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_treatment(const char c, va_list ap)
{
    char *str;

    str = NULL;
    if (c == 'c')
        str = (ft_treatment_c(va_arg(ap, char)));
    if (c == 's')
        str = (ft_treatment_s(va_arg(ap, char *)));
    if (c == 'p')
        str = (ft_treatment_p(va_arg(ap, void *)));
    if (c == 'd')
        str = (ft_treatment_d(va_arg(ap, int)));
    if (c == 'i')
        str = (ft_treatment_i(va_arg(ap, int)));
    if (c == 'u')
        str = (ft_treatment_u(va_arg(ap, unsigned int)));
    if (c == 'x')
        str = (ft_treatment_x(va_arg(ap, unsigned int)));
    if (c == 'X')
        str = (ft_treatment_X(va arg(ap, unsigned int)));
    return (str);
}

char    *ft_i(int i)
{
    return (ft_itoa(i));
}

char    *ft_u(unsigned int u)
{
    return (ft_itoa_u(u))
}

int     ft_strlen_nbr(int i)
{
    int count;

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
    return (count)
}

int     ft_strlen_nbr_u(unsigned int u)
{
    int count;

    if (i == 0)
        return (1);
    while (i > 0)
    {
        i = i / 10;
        count++;
    }
    return (count)
}