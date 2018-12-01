/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:21:36 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/11/30 19:22:42 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;

	while (*alst)
	{
		list = (*alst)->next;
		if (del)
			del((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = list;
	}
	(*alst) = NULL;
}
