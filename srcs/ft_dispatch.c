#include "../includes/ft_printf.h"

void    ft_dispatch(char *str, p_list flags)
{
    if (flags.option == 'd')
        ft_displayd(str, flags);
    if (flags.option == 's')
        ft_displays(str, flags);
}
