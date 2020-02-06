#include "../includes/ft_printf.h"

int    ft_display_d(int precision, int spaces, char *str, p_list flags)
{
    if (flags.first == '-')
        ft_display_d_minus(spaces, precision, str, flags);
    else if ((flags.first == '0' && flags.third != '.') || (flags.first == '0' && flags.fourth[0] == '-'))
    {
        {
            if (*str == '-' && (flags.fourth[0] == '-' || flags.fourth[0] == '\0'))
            {
                ft_putchar_fd('-', 1);
                flags.count++;
                str++;
            }
            flags.count = ft_display_d_0(spaces, precision, str, flags);
        }
    }
    else
        flags.count = ft_display_d_spaces(spaces, precision, str, flags);
    return (flags.count);
}

int ft_display_d_0(int spaces, int precision, char *str, p_list flags)
{
    while (spaces)
    {
        ft_putchar_fd('0', 1);
        flags.count++;
        spaces--;
    }
    if (*str == '-' && (flags.fourth[0] != '-' || flags.fourth[0] != '\0'))
    {
        ft_putchar_fd('-', 1);
        flags.count++;
        str++;
    }
    while (precision)
    {
        ft_putchar_fd('0', 1);
        flags.count++;
        precision--;
    }
    ft_putstr_fd(str, 1);
    flags.count = ft_strlen(str);
    return (flags.count);
}

int ft_display_d_minus(int spaces, int precision, char *str, p_list flags)
{
    if (*str == '-')
    {
        ft_putchar_fd('-', 1);
        flags.count++;
        str++;
    }
    while (precision)
    {
        ft_putchar_fd('0', 1);
        flags.count++;
        precision--;
    }
    ft_putstr_fd(str, 1);
    flags.count = ft_strlen(str);
    while (spaces)
    {
        ft_putchar_fd(' ', 1);
        flags.count++;
        spaces--;
    }
    return (flags.count);
}

int ft_display_d_spaces(int spaces, int precision, char *str, p_list flags)
{
    while (spaces)
    {
        ft_putchar_fd(' ', 1);
        flags.count++;
        spaces--;
    }
    if (*str == '-')
    {
        ft_putchar_fd('-', 1);
        flags.count++;
        str++;
    }
    while (precision)
    {
        ft_putchar_fd('0', 1);
        flags.count++;
        precision--;
    }
    ft_putstr_fd(str, 1);
    flags.count = ft_strlen(str);
    return (flags.count);
}