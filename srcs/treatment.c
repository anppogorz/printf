void    ft_treatment(const char c)
{
    if (c == 'c')
        ft_treatment_c();
    if (c == 's')
        ft_treatment_s();
    if (c == 'p')
        ft_treatment_p();
    if (c == 'd')
        ft_treatment_d();
    if (c == 'i')
        ft_treatment_i();
    if (c == 'u')
        ft_treatment_u();
    if (c == 'x')
        ft_treatment_x();
    if (c == 'X')
        ft_treatment_X();
}

void    ft_treatment_c()
{
    char c;

    c = va_arg(va, char);
    ft_putchar(c);
}

void    ft_treatment_s()
{
    char *s;

    s = va_arg(va, char *);
    ft_putstr(s);
}

void    ft_treatment_p()
{
    void *p;

    p = va_arg(va, void *);
    ft_print_mem(p);
}

void    ft_treatment_d();
{
    int i;

    i = va_arg(va, int);
    ft_putnbr(i);
}

void