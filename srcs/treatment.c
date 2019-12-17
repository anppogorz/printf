void    ft_treatment(const char c, va_list ap)
{
    if (c == 'c')
        ft_treatment_c(va_arg(ap, char));
    if (c == 's')
        ft_treatment_s(va_arg(ap, char *));
    if (c == 'p')
        ft_treatment_p(va_arg(ap, void *));
    if (c == 'd')
        ft_treatment_d(va_arg(ap, int));
    if (c == 'i')
        ft_treatment_i();
    if (c == 'u')
        ft_treatment_u();
    if (c == 'x')
        ft_treatment_x();
    if (c == 'X')
        ft_treatment_X();
}

void    ft_treatment_c(char c)
{
    ft_putchar(c);
}

void    ft_treatment_s(char *str)
{
    ft_putstr(str);
}

void    ft_treatment_p(void *ptr)
{
    ft_print_mem(ptr);
}

void    ft_treatment_d(int i);
{
    ft_putnbr(i);
}

void