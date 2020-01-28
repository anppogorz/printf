/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 06:59:03 by anpogorz          #+#    #+#             */
/*   Updated: 2020/01/15 07:22:36 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_count(long long nbr, int sign)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (sign == -1)
		i = 1;
	(void)sign;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static char	*ft_nbr(char *str, long long nbr, int sign)
{
	int i;

	i = 0;
	if (nbr == 0)
		i++;
	if (nbr == -2147483648)
	{
		str[i] = '8';
		nbr = 214748364;
		i++;
	}
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
		i++;
	}
	if (sign == -1)
		str[i++] = '-';
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

char		*ft_itoa(int n)
{
	int			i;
	int			sign;
	long long	nbr;
	char		*str;

	sign = 1;
	if (n < 0)
		sign = -1;
	nbr = sign * n;
	i = ft_count(nbr, sign);
	str = malloc(sizeof(char) * (i + 1));
	if (str == 0)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	str = ft_nbr(str, nbr, sign);
	str = ft_swap_str(str);
	return (str);
}
