#include "../includes/ft_printf.h"

char    *ft_c(int i)
{
    char *str;

    if (!(str = (char *)malloc(sizeof(char) * 2)))
        return (NULL);
    str[0] = i;
    str[1] = '\0';
    return (str);
}

char    *ft_s(char *str)
{
    return (str);
}

char    *ft_p(void *ptr)
{
    return (ft_treatment_p(ptr));
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

char    *ft_d(int i)
{
    return (ft_itoa(i));
}