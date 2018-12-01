/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:31:11 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/25 00:01:42 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		if (!content)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			list->content = malloc(sizeof(content));
			if (!list->content)
				return (NULL);
			ft_memmove(list->content, content, content_size);
			list->content_size = content_size;
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
