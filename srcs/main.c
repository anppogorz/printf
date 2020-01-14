#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int main(void)
{
    ft_putstr_fd("1234", 1);
    return (0);
}