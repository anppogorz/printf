/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:31:28 by anpogorz          #+#    #+#             */
/*   Updated: 2020/01/07 11:19:56 by anpogorz         ###   ########.fr       */
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

char    *ft_c(char c)
{
    char *str;

    if (!(str = (char *)malloc(sizeof(char) * 2)))
        return (NULL);
    str[0] = c;
    str[1] = '\0';
    return (str);
}

char    *ft_s(char *str)
{
    return (str);
}

char    *ft_p(void *ptr)
{
    return (ft_treatment_p(ptr));
}

char    *ft_treatment_p(void *ptr)
{
    char *base;
    char *nbr_final;
    char base_conv[100];
    uintptr_t nbr;
    int i;
    int j;

    if (!(nbr_final = (char *)malloc(sizeof(char) * 50)))
        return (NULL);
    base = "0123456789abcdef";
    i = 0;
    j = 2;
    nbr = (uintptr_t)ptr;
    if (nbr == 0)
        return ("0x0");
    nbr_final[0] = '0';
    nbr_final[1] = 'x';
    while (nbr > 0)
    {
        base_conv[i] = nbr % 16;
        nbr = nbr / 16;
        i++;
    }
    while (i > 0)
    {
        nbr_final[j] = base[base_conv[i - 1]];
        j++;
        i--;
    }
    nbr_final[j] = '\0';
    return (nbr_final);
}

char    *ft_d(int i)
{
    return (ft_itoa(i));
}

char    *ft_i(int i)
{
    return (ft_itoa(i));
}

char    *ft_u(unsigned int u)
{
    return (ft_itoa_u(u))
}

char    *ft_x(unsigned int u)
{
    return(ft_treatment_x(u));
}

char    *ft_treatment_x(unsigned int u)
{
    char *base;
    char *nbr_final;
    char base_conv[100];
    int i;
    int j;

    if (!(nbr_final = (char *)malloc(sizeof(char) * 50)))
        return (NULL);
    base = "0123456789abcdef";
    i = 0;
    j = 0;
    if (u == 0)
        return ("0");
    while (u > 0)
    {
        base_conv[i] = u % 16;
        u = u / 16;
        i++;
    }
    while (i > 0)
    {
        nbr_final[j] = base[base_conv[i - 1]];
        j++;
        i--;
    }
    nbr_final[j] = '\0';
    return (nbr_final);
}

char    *ft_X(unsigned int u)
{;
    return (ft_treatment_X(u));
}

char    *ft_treatment_X(unsigned int u)
{
    char *base;
    char *nbr_final;
    char base_conv[100];
    int i;
    int j;

    if (!(nbr_final = (char *)malloc(sizeof(char) * 50)))
        return (NULL);
    base = "0123456789ABCDEF";
    i = 0;
    j = 0;
    if (u == 0)
        return ("0");
    while (u > 0)
    {
        base_conv[i] = u % 16;
        u = u / 16;
        i++;
    }
    while (i > 0)
    {
        nbr_final[j] = base[base_conv[i - 1]];
        j++;
        i--;
    }
    nbr_final[j] = '\0';
    return (nbr_final);
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