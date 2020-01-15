/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 09:56:16 by anpogorz          #+#    #+#             */
/*   Updated: 2020/01/15 07:22:36 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *lst;
	if (lst && del)
	{
		while (tmp != NULL)
		{
			(*del)(tmp->content);
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
		}
		free(tmp);
		*lst = NULL;
	}
	return ;
}
