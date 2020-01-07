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

int    ft_treatment(const char c, va_list ap)
{
    if (c == 'c')
        return (ft_treatment_c(va_arg(ap, char)));
    if (c == 's')
        return (ft_treatment_s(va_arg(ap, char *)));
    if (c == 'p')
        return (ft_treatment_p(va_arg(ap, void *)));
    if (c == 'd')
        return (ft_treatment_d(va_arg(ap, int)));
    if (c == 'i')
        return (ft_treatment_i(va_arg(ap, int)));
    if (c == 'u')
        return (ft_treatment_u(va_arg(ap, unsigned int)));
    if (c == 'x')
        return (ft_treatment_x(va_arg(ap, unsigned int)));
    if (c == 'X')
        return (ft_treatment_X(va arg(ap, unsigned int)));
    return (0);
}

int     ft_c(char c)
{
    ft_putchar_fd(c, 1);
    return (1);
}

int     ft_s(char *str)
{
    ft_putstr_fd(str, 1);
    return (ft_strlen(str));
}

int     ft_p(void *ptr)
{
    ft_putstr_fd (ft_treatment_p, 1)
    return (ft_strlen(ft_treatment_p));
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

int     ft_d(int i)
{
    ft_putnbr_fd(i, 1);
    return (ft_strlen_nbr(i));
}

int     ft_i(int i)
{
    ft_putnbr_fd(i, 1);
    return (ft_strlen_nbr(i));
}

int     ft_u(unsigned int u)
{
    ft_putnbr_fd_u(u, 1);
    return (ft_strlen_nbr_u(u))
}

void	ft_putnbr_fd_u(unsigned int n, int fd)
{
    if (n > 9)
    {
        ft_putnbr_fd_u((n / 10), fd);
        ft_putchar_fd(((n % 10) + 48), fd);
    }
    if (n < 10)
        ft_putchar_fd((n + 48), fd);
}

int     ft_x(unsigned int u)
{
    ft_putstr_fd(ft_treatment_x(u), 1);
    return(ft_strlen(ft_treatment_x(u)));
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

int     ft_X(unsigned int u)
{
    ft_putstr_fd(ft_treatment_X(u), 1);
    return(ft_strlen(ft_treatment_X(u)));
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