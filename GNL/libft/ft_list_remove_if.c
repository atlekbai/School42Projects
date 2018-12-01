/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:51:36 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/25 15:56:53 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_if(t_list **begin_list, void *content, int (*cmp)())
{
	t_list *list;
	t_list *temp;

	list = *begin_list;
	while (list->next)
	{
		if (cmp(list->next->content, content) == 0)
		{
			temp = list->next;
			list->next = temp->next;
			free(temp);
		}
		else
			list = list->next;
	}
	if (cmp((*begin_list)->content, content) == 0)
	{
		temp = (*begin_list);
		*begin_list = temp->next;
		free(temp);
	}
}
