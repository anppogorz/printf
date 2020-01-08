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

void	ft_putnbr_fd(int n, int fd)
{
    if (fd < 0)
        return ;
    if (n == -2147483648)
    {
        ft_putchar_fd('-', fd);
        ft_putchar_fd('2', fd);
        n = 147483648;
    }
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -1 * n;
    }
    if (n > 9)
    {
        ft_putnbr_fd((n / 10), fd);
        ft_putchar_fd(((n % 10) + 48), fd);
    }
    if (n < 10)
        ft_putchar_fd((n + 48), fd);
}

int main(int argc, char **argv)
{
    char *str;

    str = "abcde";
    printf("%3.s",str);
    return (0);
}