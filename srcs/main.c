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
    //ft_printf("%-.8d%--199.112i%0007.171x%0075i%-64p|\n" ,311559526,-1609268988,3889758006u,163204956,(void*)17667081281350694362lu);
    //printf("%-.8d%--199.112i%0007.171x%0075i%-64p" ,311559526,-1609268988,3889758006u,163204956,(void*)17667081281350694362lu);
    ft_printf("%84.43s|\n" , NULL);
    //printf("%84.43s" ,NULL);
    return (0);
}