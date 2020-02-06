#include "../includes/ft_printf.h"

int    ft_display_c(int precision, int spaces, char *str, p_list flags)
{
    if (str[0] == '\0')
    {
        spaces = spaces - 1;
        precision = precision + 1;
    }
    if (flags.first == '-')
        flags.count = ft_display_c_minus(spaces, precision, str, flags);
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

int ft_display_c_minus(int spaces, int precision, char *str, p_list flags)
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
