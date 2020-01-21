#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
    if (fd < 0)
        return ;
    write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    if (s == NULL || fd < 0)
        return ;
    while (s[i] != '\0')
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    char *str;
    void *p;
    unsigned int i;

    str = "abcdef";
    p = str;

    ft_printf("Ceci est ft_printf: %3p\n", p);
    printf("ceci est printf: %p", p);
    return (0);
}