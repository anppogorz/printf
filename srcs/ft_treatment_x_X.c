#include "ft_printf.h"

char    *ft_x(unsigned int u)
{
    return(ft_treatment_x(u));
}

char    *ft_treatment_x(unsigned int u)
{
    char *base;
    char *nbr_final;
    char base_conv[100];
    int i;
    int j;

    if (!(nbr_final = (char *)malloc(sizeof(char) * 50)))
        return (NULL);
    base = "0123456789abcdef";
    i = 0;
    j = 0;
    if (u == 0)
        return ("0");
    while (u > 0)
    {
        base_conv[i] = u % 16;
        u = u / 16;
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

char    *ft_X(unsigned int u)
{;
    return (ft_treatment_X(u));
}

char    *ft_treatment_X(unsigned int u)
{
    char *base;
    char *nbr_final;
    char base_conv[100];
    int i;
    int j;

    if (!(nbr_final = (char *)malloc(sizeof(char) * 50)))
        return (NULL);
    base = "0123456789ABCDEF";
    i = 0;
    j = 0;
    if (u == 0)
        return ("0");
    while (u > 0)
    {
        base_conv[i] = u % 16;
        u = u / 16;
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