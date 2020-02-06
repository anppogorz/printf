#include "../includes/ft_printf.h"

int    ft_dispatch(char *str, p_list flags)
{
    if (flags.option == 'd' || flags.option == 'i' || flags.option == 'u' || flags.option == 'x' || flags.option == 'X')
        flags.count = ft_displayd(str, flags);
    if (flags.option == 's' || flags.option == 'c' || flags.option == 'p' || flags.option == '%')
        flags.count = ft_displays(str, flags);
    return (flags.count);
}
