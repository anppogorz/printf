#include "../includes/ft_printf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t			i;
    unsigned char	*ss1;
    unsigned char	*ss2;

    if (n == 0)
        return (0);
    i = 0;
    ss1 = (unsigned char *)s1;
    ss2 = (unsigned char *)s2;
    while ((ss1[i] == ss2[i]) && (i < n) && (ss1[i] != '\0'))
        i++;
    if (ss1[i] != ss2[i] && (i < n))
        return (ss1[i] - ss2[i]);
    return (0);
}

size_t	ft_strlen(const char *s)
{
    int i;

    i = 0;
    if (s == NULL)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

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

char	*ft_strdup(const char *s1)
{
    int		i;
    char	*s2;

    i = 0;
    while (s1[i] != '\0')
        i++;
    if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    while (s1[i] != '\0')
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}