#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct  s_list
{
    char first;
    char *second;
    char *third;
    char *fourth;
}               t_list;

char	*ft_strdup(const char *s1)
{
    int		i;
    char	*s2;

    i = 0;
    while (s1[i] != '\0')
        i++;
    s2 = (char *)malloc(sizeof(char) * (i + 1));
    if (s2 == 0)
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

char	*ft_strdup_num(const char *s1)
{
    int		i;
    char	*s2;

    i = 0;
    while (s1[i] >= '0' && s1[i] <= '9')
        i++;
    s2 = (char *)malloc(sizeof(char) * (i + 1));
    if (s2 == 0)
        return (NULL);
    i = 0;
    while (s1[i] >= '0' && s1[i] <= '9')
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

static int	ft_skip_atoi(const char *str)
{
    int i;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f'
           || str[i] == '\r' || str[i] == '\v')
        i++;
    return (i);
}

int			ft_atoi(const char *str)
{
    unsigned long long stock;
    int i;
    int sign;

    stock = 0;
    i = ft_skip_atoi(str);
    sign = 1;
    if (str[i] == 45 || str[i] == 43) {
        if (str[i] == 45)
            sign = -1;
        i++;
    }
    while (str[i] > 47 && str[i] < 58) {
        stock = (str[i] - 48) + (stock * 10);
        if (stock > 9223372036854775807)
            return (sign > 0 ? -1 : 0);
        i++;
    }
    return ((int) stock * sign);
}

char    *ft_pass_nbr(const char *format)
{
    char *str;

    str = ft_strdup(format);
    while (*str >= '0' && *str <= '9')
        str++;
    return (str);
}

t_list  ft_check_flags(const char *format)
{
    t_list flags;

    if (*format == '-' || *format == '0')
    {
        flags.first = *format;
        format++;
    }
    if (*format == '*')
        flags.second = ft_strdup("*");
    else
        flags.second = ft_strdup_num(format);
    format = ft_pass_nbr(format);
    if (*format == '.')
    {
        flags.third = ".";
        format++;
    }
    if (*format == '*')
        flags.fourth = ft_strdup("*");
    else
        flags.fourth = ft_strdup_num(format);
    return(flags);
}

int main(int argc, char **argv)
{
    char *str;
    t_list flags;

    flags = ft_check_flags("-5");
    printf("first %c\n", flags.first);
    printf("second %s\n", flags.second);
    printf("third %s\n", flags.third);
    printf("fourth %s\n", flags.fourth);
    str = "abcde";
    //printf("%3.s",str);
    return (0);
}