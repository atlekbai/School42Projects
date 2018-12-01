/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:04:50 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/07 16:13:48 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	char	*str;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (0);
	list->content_size = content_size;
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		str = (char*)malloc(content_size);
		list->content = ft_memcpy(str, content, content_size);
		list->next = NULL;
	}
	return (list);
}
