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

    ft_printf("%17.14d\n" , 123456789);
    printf("%17.14d" , 123456789);
    return (0);
}