/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:41:00 by anpogorz          #+#    #+#             */
/*   Updated: 2020/01/14 10:41:02 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_count(long long nbr)
{
    int i;

    i = 0;
    if (nbr == 0)
        return (1);
    while (nbr > 0)
    {
        nbr = nbr / 10;
        i++;
    }
    return (i);
}

static char	*ft_nbr(char *str, long long nbr)
{
    int i;

    i = 0;
    if (nbr == 0)
        i++;
    while (nbr > 0)
    {
        str[i] = (nbr % 10) + 48;
        nbr = nbr / 10;
        i++;
    }
    str[i] = '\0';
    return (str);
}

static char	*ft_swap_str(char *str)
{
    char	swap;
    int		i;
    int		j;

    i = 0;
    j = 0;
    while (str[j] != '\0')
        j++;
    j--;
    while (i < j)
    {
        swap = str[j];
        str[j] = str[i];
        str[i] = swap;
        i++;
        j--;
    }
    return (str);
}

char		*ft_itoa_u(unsigned int n)
{
    int			i;
    long long	nbr;
    char		*str;

    nbr = n;
    i = ft_count(nbr);
    str = malloc(sizeof(char) * (i + 1));
    if (str == 0)
        return (NULL);
    if (nbr == 0)
        str[0] = '0';
    str = ft_nbr(str, nbr);
    str = ft_swap_str(str);
    return (str);
}