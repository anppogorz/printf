#include "../includes/ft_printf.h"

void    ft_dispatch(char *str, p_list flags)
{
    if (flags.option == 'd' || flags.option == 'i' || flags.option == 'u' || flags.option == 'x' || flags.option == 'X')
        ft_displayd(str, flags);
    if (flags.option == 's' || flags.option == 'c' || flags.option == 'p')
        ft_displays(str, flags);
}
