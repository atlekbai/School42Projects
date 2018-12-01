/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:02:53 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/07 16:10:59 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *lst;

	if (*alst != NULL)
	{
		lst = *alst;
		del(lst->content, lst->content_size);
		free(*alst);
		*alst = NULL;
	}
}
