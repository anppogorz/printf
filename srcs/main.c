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

    ft_printf("%175.123d\n" , 123456789);
    printf("%175.123d" , 123456789);
    return (0);
}