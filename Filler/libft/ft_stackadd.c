/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:28:52 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/25 14:33:10 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackadd(t_stack **alst, t_stack *new)
{
	t_stack *list;

	list = *alst;
	*alst = new;
	new->next = list;
}
