/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:36:28 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/27 17:37:39 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "./libft/libft.h"
# include <stdlib.h>

# define MAX 2147483647

typedef struct	s_node
{
	int				id;
	char			*name;
	int				start;
	int				visited;
	int				used;
	int				distance;
	int				x;
	int				y;
	struct s_node	**kids;
	struct s_node	**way;
	struct s_node	*next;
	struct s_node	*parent;
}				t_node;

typedef struct	s_queue
{
	t_node			*node;
	struct s_queue	*next;
}				t_queue;

typedef struct	s_way
{
	int				dist;
	int				*way;
	struct s_way	*next;
}				t_way;

typedef struct	s_ant
{
	int				id;
	t_node			*cur;
	int				*way;
	int				end;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_info
{
	int				id;
	char			*name;
	int				start;
	int				x;
	int				y;
}				t_info;

typedef struct	s_lem
{
	int				ant;
	t_node			*nodes;
	int				**ways;
	t_way			*paths;
	t_ant			*ants;
	int				l;
	int				ret;
	int				i;
	int				p;
	char			*line;
	char			*cat;
}				t_lem;

void			nodes_connect(t_node **nodes, char *f, char *s);
t_node			**add_kid(t_node **kids, t_node *node);
t_node			*get_node_by_name(t_node **nodes, char *name);
void			node_fill(t_node **nodes, char **line, char **cat);
t_node			*node_new(t_node *nodes, t_info info);
void			node_routes(t_node **nodes, char **line, char **cat);
t_node			*pop_queue(t_queue **queue);
t_queue			*add_queue(t_queue *q, t_node *node);
t_node			**add_way(t_node **way, t_node **kids, t_node *node);
int				**add_route(int **ways, t_node *node, int l);
t_node			*get_by_start(t_node *node, int start);
t_node			*get_by_id(t_node *node, int id);
void			find_ways(t_node **nodes, int ***ways, int *l);
void			node_distance(t_node **nodes);
void			bfs(t_queue *q);
t_way			*add_path(t_way *path, int *way);
int				get_next_way(t_node **node, int *way, t_node *nodes);
int				get_index_in_arr(t_node *node, int *way);
int				is_ants_at_end(t_ant *ants);
t_ant			*ants_add(t_ant *ants, int id, t_node *node);
void			default_nodes(t_node **nodes);
int				*choose_way(int id, t_way *paths, t_node *nodes);
void			set_visit(t_node **nodes, int vis);
void			manage_ants(t_lem l);
void			print_paths(t_way *paths, t_node *nodes);
void			free_nodes(t_node **nodes);
void			choose(t_way **chosen, t_way *paths, int *id);
t_info			info_set(char *name, int start, char *line);
void			ft_err(void);
void			out_n_free(char **line);
int				str_is_dgt(char *s);
void			print_nodes(t_node **nodes);
int				ft_out(char **cat, char **line);
int				ft_bridge(char *f, char *s, t_node **nodes, char **line);
int				node_proc(char **line, int *i_s, t_info info, t_node **nodes);
int				ft_start(int start, char **line);
t_info			info_def(void);

#endif
