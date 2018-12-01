/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:50:20 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/06 17:06:54 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmp;

	if (*alst != NULL)
	{
		tmp = *alst;
		while (tmp)
		{
			del(tmp->content, tmp->content_size);
			free(tmp);
			*alst = NULL;
			tmp = tmp->next;
		}
	}
}
