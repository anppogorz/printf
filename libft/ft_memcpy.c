/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:52:06 by anpogorz          #+#    #+#             */
/*   Updated: 2019/11/06 09:56:21 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*p;

	if ((!dst && !src) || dst == src)
		return (NULL);
	p = dst;
	while (n--)
	{
		*((unsigned char *)p++) = *((unsigned char *)src++);
	}
	return (dst);
}
