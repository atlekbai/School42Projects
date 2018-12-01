/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:55:18 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/25 00:10:51 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackdelone(t_stack **alst, void (*del)(char *, int))
{
	del((*alst)->stack, (*alst)->fd);
	free(*alst);
	*alst = NULL;
}
