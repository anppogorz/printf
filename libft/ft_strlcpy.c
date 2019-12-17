/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:14:03 by anpogorz          #+#    #+#             */
/*   Updated: 2019/11/05 11:07:01 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*ssrc;

	i = 0;
	ssrc = (char *)src;
	if (!src || !dst)
		return (0);
	while (ssrc[i] != '\0' && ((i + 1) < size))
	{
		dst[i] = ssrc[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while (ssrc[i] != '\0')
		i++;
	return (i);
}
