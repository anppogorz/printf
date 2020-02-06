#include "../includes/ft_printf.h"

int    ft_display_pourcent(int precision, int spaces, char *str, p_list flags)
{
    if (flags.first == '-')
        flags.count = ft_display_pourcent_minus(spaces, precision, str, flags);
    else if (flags.first == '0')
        flags.count = ft_display_pourcent_0(spaces, precision, str, flags);
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

int ft_display_pourcent_minus(int spaces, int precision, char *str, p_list flags)
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
    return (flags.count);
}

int ft_display_pourcent_0(int spaces, int precision, char *str, p_list flags)
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
    return(flags.count);
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