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

t_stack	*ft_stacknew(char *content, int fd)
{
	t_stack *list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (list)
	{
		list->stack = content;
		list->fd = fd;
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
