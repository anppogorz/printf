#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int main(int argc, char **argv)
{
    unsigned int i;

    i = 0;
    printf("Ceci est printf: %x\n", 1362485);
    printf("Ceci est treatment: %s\n", ft_treatment_x(1362485));
    return (0);
}