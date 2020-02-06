#include "../includes/ft_printf.h"

p_list  flags_init(const char* format)
{
    (void)format;
    p_list flags;

    flags.first = '\0';
    flags.second = "\0";
    flags.third = '\0';
    flags.fourth = "\0";
    flags.count = -1;
    return (flags);
}

p_list  ft_check_stars(p_list flags, va_list ap)
{
    int second;
    int fourth;

    if (ft_strncmp(flags.second, "*", 1) == 0)
    {
        second = (va_arg(ap, int));
        if (second < 0)
        {
            second = -second;
            flags.first = '-';
        }
        flags.second = ft_itoa(second);
    }
    if (ft_strncmp(flags.fourth, "*", 1) == 0)
    {
        fourth = (va_arg(ap, int));
        flags.fourth = ft_itoa(fourth);
    }
    return (flags);
}

const char    *ft_skip_flags(const char *s1)
{
    while (*s1 != 'd' && *s1 != 'p' && *s1 != 's' && *s1 != 'c' && *s1 != 'u' && *s1 != 'i' && *s1 != 'x' && *s1 != 'X'
           && *s1 != '%')
        s1++;
    return (s1);
}

p_list  ft_check_flags(const char *format, p_list flags)
{
    while (*format == '-' || *format == '0')
    {
        flags.first = *format;
        format++;
    }
    if (*format == '*')
    {
        flags.second = ft_strdup("*");
        format++;
    }
    else
        flags.second = ft_strdup_num(format);
    format = ft_pass_nbr(format);
    if (*format == '.')
    {
        flags.third = '.';
        format++;
    }
    if (*format == '*')
        flags.fourth = ft_strdup("*");
    else
        flags.fourth = ft_strdup_num(format);
    return(flags);
}