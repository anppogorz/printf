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

char    *ft_p(void *ptr)
{
    char *base;
    char *nbr_final;
    int i;

    i = 0;
    if (!(nbr_final = (char *)malloc(sizeof(char) * 50)))
        return (NULL);
    base = "0123456789abcdef";

    return (ft_treatment_p(ptr, base, nbr_final, i));
}

char    *ft_treatment_p(void *ptr, char *base, char *nbr_final, int i)
{
    char base_conv[100];
    uintptr_t nbr;
    int j;

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
        nbr_final[j] = base[(int)base_conv[i - 1]];
        j++;
        i--;
    }
    nbr_final[j] = '\0';
    return (nbr_final);
}