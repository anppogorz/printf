/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:05:18 by anpogorz          #+#    #+#             */
/*   Updated: 2019/11/06 09:56:28 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*p;
	size_t	i;

	i = 0;
	p = dst;
	while (i < n)
	{
		*((unsigned char *)p++) = *((unsigned char *)src);
		if (*((unsigned char *)src++) == (unsigned char)c)
			return (p);
		i++;
	}
	return (NULL);
}
