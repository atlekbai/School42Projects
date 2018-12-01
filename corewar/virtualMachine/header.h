/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:24:09 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/01 15:17:56 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/printf.h"
# include "op.h"
# include <stdio.h>
# include <fcntl.h>
# include <ncurses.h>
# include <sys/time.h>
# define WIDTH 64
# define CODE_SIZE 4096 * 10
# define Y1 196
# define Y2 57
# define X1 67

unsigned int		g_phase;
int					g_limit;

typedef unsigned char	t_byte;

typedef struct		s_player
{
	int				id;
	char			*bot_name;
	int				size;
	char			*bot_comment;
	t_byte			*exec_code;
	unsigned int	last_live;
	int				lives_cur;
	int				alive;
}					t_player;

typedef struct		s_proc
{
	int				alive;
	unsigned int	reg[16];
	unsigned int	r1;
	int				carry;
	int				pc;
	int				id;
	int				nbr_live;
	int				cycles;
	int				cur_cmd;
	int				cmd;
	struct s_proc	*next;
}					t_proc;

typedef struct		s_code
{
	t_byte			code[CODE_SIZE];
	int				size;
}					t_code;

typedef struct		s_game
{
	int				procs;
	int				i;
	int				cycle_to_die;
	int				cycle_delta;
	int				nbr_live;
	int				max_checks;
	t_player		p[4];
	t_proc			*procs_arr;
	int				last_player;
	t_byte			*map;
	int				*map_color;
	int				pos;
	int				vis;
	int				vis_n;
	int				dump;
	int				dump_n;
	int				aff;
	int				audio;
	int				over;
	int				ctd;
	unsigned int	player_ids[4];
	char			aff_arr[MEM_SIZE];
}					t_game;

typedef struct		s_op
{
	int				(*f)(t_byte**, t_proc**, t_game*);
	unsigned char	index;
	int				cycles;
	int				label;
	int				codage;
}					t_op;
/*
** Map ops
*/
t_byte				*init_map(void);
int					*init_intmap();
void				ft_error(char *err_msg);
t_byte				*load_player(t_byte *map, t_player p, int pos);
void				dump_map(t_game game);
/*
** .cor files
*/
t_code				read_cor(char *filename);
void				print_cor(t_code code);
/*
** Players
*/
t_player			create_player(t_code code, int id);
int					get_player_by_id(t_player *players, unsigned int id);

/*
** Processes
*/
t_proc				*create_proc(int pc, int id);
t_proc				*add_proc(t_proc *proc, int pc, int id);
void				print_map_w_procs(t_game **game);
t_op				*command_struct(void);
int					check_processes(t_game *game);

/*
** Useful ops
*/
unsigned int		ft_args_get(int64_t *i, int label, t_byte *map);
t_byte				*ft_acg_split(unsigned int acg);
int					num_to_map(t_game *game, int index,
					unsigned int r1, t_proc *proc);
int					num_to_reg(t_proc **proc, int index, unsigned int r1);
t_byte				*value_to_cells(unsigned int val, int *k);

/*
**	Game ops
*/
int					reset_game(t_game *game);
int					init_game(t_game *game);
int					load_game(t_game *game, int ac, char *file, int i);
int					action(t_op *ops, t_proc **proc, t_game *game);
void				move_around(t_op *ops, t_game *game);
int					violin(t_game *game, int num);

void				print_aff(t_game game);
void				intro_players(t_game game);
int					get_players_nums(t_game *game, int i, char **av);
int					validate_ids(t_game game);
int					check_flags(t_game *game, char **av);
void				ft_usage(void);
void				game_over(t_game gm);

int					ft_abs(int x);
void				print_text(t_game game);
void				print_refresh(t_game game);
void				print_liveline(t_game game, int i);
void				print_start_map(t_game *game, t_proc *proc);
void				print_map(t_game game);
void				carriage(t_game **game, t_proc *proc);
void				fresh_carriage(t_game **game);
void				fresh_line(t_game game);
void				check_bold(t_game **game, t_proc *proc);
void				check_last_bold(t_game **game, t_proc *proc);

int					validation_ldi(t_byte *acg_split, t_proc **procs,
										t_byte **map);
int					validation_xorand(t_byte *acg_split,
										t_proc **procs, t_byte **map);
int					validation_addsub(t_byte *acg_split,
										t_proc **procs, t_byte **map);
int					validation_st(t_byte *acg_split, t_proc **procs,
										t_byte **map);
int					validation_ld(t_byte *acg_split, t_proc **procs,
										t_byte **map);
int					validation_sti(t_byte *acg_split, t_proc **procs,
										t_byte **map);
int					validation_aff(t_byte *acg_split, t_proc **procs,
										t_byte **map);
#endif
