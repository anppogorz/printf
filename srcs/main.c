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
    //ft_printf("%--12.128u%-11.100s%0076.69u%--77.*%%-41.74i" ,2535190889u,"e5px;sLb",1202957233u,-3,1664435419);
    //ft_printf("%--51.30u%--71.125u%60.59s" ,145841354u,3091705823u,"%0\r2ZJJjhjt{+{");
    printf("%--51.30u%--71.125u%60.59s" ,145841354u,3091705823u,"%0\r2ZJJjhjt{+{");
   //printf("%--12.128u%-11.100s%0076.69u%--77.*%%-41.74i" ,2535190889u,"e5px;sLb",1202957233u,-3,1664435419);
    return (0);
}