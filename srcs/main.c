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
    //ft_printf("%--88.150i%-29.24X%0093.174x%-102p%--10.53%|\n" ,-1783156668,2239188502u,641500396u,(void*)2012673575403926174lu);
    ft_printf("%0.53%|\n");
    printf("%0.53%");
    return (0);
}