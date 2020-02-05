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
    ft_printf("%00097.*u|\n" ,-18,692442331u);
    printf("%00097.*u" ,-18,692442331u);
    return (0);
}