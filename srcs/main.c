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

    ft_printf("Ceci est ft_printf: %003.12d\n", 12);
    printf("ceci est printf: %003.12d", 12);
    return (0);
}