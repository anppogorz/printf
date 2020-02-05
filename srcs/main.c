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
    printf("%-146c|\n" ,0);
    ft_printf("%-146c" ,0);
    //printf("%-146c", 0);
    return (0);
}