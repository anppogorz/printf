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

    str = "abcdef";
    p = str;

    ft_printf("%--012.30d%d\n" , 123456789, 12);
    printf("%--012.30d%d" , 123456789, 12);
    return (0);
}