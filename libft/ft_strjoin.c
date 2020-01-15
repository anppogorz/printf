/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 06:58:32 by anpogorz          #+#    #+#             */
/*   Updated: 2020/01/15 07:22:36 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_strlen_s1_s2(char const *s1, char const *s2)
{
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	j++;
	return (i + j);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	long long	i;
	long long	j;
	char		*new;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(s1) * (ft_strlen_s1_s2(s1, s2)));
	if (new == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
