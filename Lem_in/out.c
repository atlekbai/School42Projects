/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:32:04 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/07 18:32:07 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_out(char **cat, char **line)
{
	*cat = ft_strjoin_free(*cat, *line);
	*cat = ft_stradd(*cat, '\n');
	free(*line);
	return (1);
}

int			ft_bridge(char *f, char *s, t_node **nodes, char **line)
{
	f = ft_strtil(*line, '-');
	s = ft_strchr(*line, '-') + 1;
	if (!f || !*f || !s || !*s)
		ft_err();
	nodes_connect(nodes, f, s);
	free(f);
	return (1);
}

t_info		info_def(void)
{
	t_info info;

	info.id = 0;
	info.name = 0;
	info.start = 0;
	info.x = 0;
	info.y = 0;
	return (info);
}

int			ft_start(int start, char **line)
{
	if (start != 0)
		ft_err();
	start = (ft_strequ(*line, "##start")) ? 1 : start;
	start = (ft_strequ(*line, "##end")) ? -1 : start;
	return (start);
}

int			node_proc(char **line, int *i_s, t_info info, t_node **nodes)
{
	char *tmp;

	tmp = ft_strtil(*line, 32);
	info = info_set(tmp, i_s[1], *line);
	info.id = i_s[0]++;
	*nodes = node_new(*nodes, info);
	free(tmp);
	i_s[1] = 0;
	return (1);
}
