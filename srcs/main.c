#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/ft_printf.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    char *str;
    void *p;
    unsigned int i;

    str = "123456789";
    p = str;
    printf("printf = %d\n", printf("%-*p%-167p%81c" ,122,(void*)13937049508044434163lu,(void*)11696584541373051259lu,-125));
    printf("ft_printf = %d\n", ft_printf("%-*p%-167p%81c" ,122,(void*)13937049508044434163lu,(void*)11696584541373051259lu,-125));
    //printf("%-146c", 0);
    return (0);
}