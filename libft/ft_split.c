/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 07:10:45 by anpogorz          #+#    #+#             */
/*   Updated: 2020/01/15 07:22:36 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free(char **tab, int nb)
{
	while (nb > 0)
	{
		free(tab[nb]);
		nb--;
	}
	free(tab);
	return (tab);
}

static char		**ft_malloc(char const *s, char c, char **tab, int nb)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0' && j < nb)
	{
		while (s[i] == c && (s[i] != '\0'))
			i++;
		while (s[i] != c && (s[i] != '\0'))
		{
			i++;
			k++;
		}
		if (!(tab[j] = malloc(sizeof(char) * (k + 1))))
			return (ft_free(tab, (j - 1)));
		k = 0;
		j++;
	}
	return (tab);
}

static int		ft_words(char const *s, char c)
{
	int i;
	int l;

	i = 0;
	l = 1;
	while (s[i] == c)
	{
		i++;
		if (s[i] == '\0')
			l = 0;
	}
	while (s[i] != '\0')
	{
		if ((s[i] == c) && (s[i + 1] != c) && (s[i + 1] != '\0'))
			l++;
		i++;
	}
	return (l);
}

static char		**ft_strcpy(char const *s, char c, char **tab, int nb)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (j < nb && s[i] != '\0')
	{
		while (s[i] == c && (s[i] != '\0'))
			i++;
		while (s[i] != c && (s[i] != '\0'))
		{
			tab[j][k] = s[i];
			k++;
			i++;
		}
		tab[j][k] = '\0';
		j++;
		k = 0;
	}
	tab[j] = 0;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb;

	if (!s)
		return (NULL);
	nb = 0;
	nb = ft_words(s, c);
	tab = malloc(sizeof(char **) * (nb + 1));
	if (tab == NULL)
		return (0);
	tab = ft_malloc(s, c, tab, nb);
	if (tab == NULL)
		return (tab);
	tab = ft_strcpy(s, c, tab, nb);
	return (tab);
}
