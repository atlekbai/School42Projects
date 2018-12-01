/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:37:56 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/25 14:41:34 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;

	temp = (*f)(lst);
	new = temp;
	if (!new)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		temp->next = (*f)(lst);
		if (!temp->next)
			return (NULL);
		temp = temp->next;
	}
	return (new);
}
