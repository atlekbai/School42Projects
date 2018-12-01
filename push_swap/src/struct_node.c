/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:43:06 by atlekbai          #+#    #+#             */
/*   Updated: 2018/10/31 13:43:06 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*create_elem(int d)
{
	t_node *new;

	new = (t_node*)malloc(sizeof(t_node));
	new->d = d;
	new->next = NULL;
	return (new);
}
