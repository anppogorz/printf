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
    //ft_printf("%-92.9%%-151.s|\n" ,"ED&1\n#8oun{J4ca-c=$#~");
    ft_printf("%97c|\n" ,0);
    printf("%97c" ,0);
    return (0);
}