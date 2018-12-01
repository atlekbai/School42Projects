/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:50:06 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/01 12:50:07 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			**add_route(int **ways, t_node *node, int l)
{
	int **temp;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!ways)
		temp = (int **)malloc(sizeof(int *) * 1);
	else
	{
		temp = (int **)malloc(sizeof(int *) * (l + 1));
		i = -1;
		while (++i < l)
			temp[i] = ways[i];
	}
	j = -1;
	temp[i] = (int *)malloc(sizeof(int) * (node->distance + 2));
	while (node->way[++j])
		temp[i][j] = node->way[j]->id;
	temp[i][j] = 0;
	if (ways)
		free(ways);
	return (temp);
}

t_node		**add_kid(t_node **kids, t_node *node)
{
	int		i;
	int		j;
	t_node	**temp;

	if (!kids || !*kids)
	{
		temp = (t_node **)malloc(sizeof(t_node) * 2);
		temp[0] = node;
		temp[1] = 0;
	}
	else
	{
		i = 0;
		while (kids[i])
			i++;
		temp = (t_node **)malloc(sizeof(t_node) * (i + 1));
		j = -1;
		while (++j < i)
			temp[j] = kids[j];
		temp[j++] = node;
		temp[j] = 0;
		free(kids);
	}
	return (temp);
}

t_node		**add_way(t_node **way, t_node **kids, t_node *node)
{
	int		i;
	int		j;
	t_node	**temp;

	if (!kids || !*kids)
	{
		temp = (t_node **)malloc(sizeof(t_node) * 2);
		temp[0] = node;
		temp[1] = 0;
	}
	else
	{
		i = 0;
		while (kids[i])
			i++;
		temp = (t_node **)malloc(sizeof(t_node) * (i + 2));
		j = -1;
		while (++j < i)
			temp[j] = kids[j];
		temp[j++] = node;
		temp[j] = 0;
	}
	if (way)
		free(way);
	return (temp);
}

void		nodes_connect(t_node **nodes, char *f, char *s)
{
	t_node *temp1;
	t_node *temp2;

	temp1 = get_node_by_name(nodes, f);
	temp2 = get_node_by_name(nodes, s);
	if (!temp1 || !temp2 || temp1->id == temp2->id)
		ft_err();
	temp1->kids = add_kid(temp1->kids, temp2);
	temp2->kids = add_kid(temp2->kids, temp1);
}

void		default_nodes(t_node **nodes)
{
	t_node	*list;

	list = *nodes;
	while (list)
	{
		list->visited = 0;
		list->distance = MAX;
		if (list->way)
		{
			free(list->way);
			list->way = NULL;
		}
		list = list->next;
	}
}
