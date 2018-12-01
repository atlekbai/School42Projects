/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:36:49 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/17 12:36:50 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_byte			*ft_acg_split(unsigned int acg)
{
	t_byte	*acg_split;

	acg_split = (t_byte *)malloc(sizeof(t_byte) * 3);
	acg_split[2] = (acg & 15) >> 2;
	acg_split[1] = (acg & 63) >> 4;
	acg_split[0] = acg >> 6;
	return (acg_split);
}

unsigned int	ft_args_get(int64_t *i, int label, t_byte *map)
{
	unsigned int	arg;

	arg = 0;
	if (label == 1)
		arg = map[++(*i) % MEM_SIZE];
	else if (label == 2)
		arg = (map[++(*i) % MEM_SIZE] << 8) | map[++(*i) % MEM_SIZE];
	else if (label == 3)
		arg = (map[++(*i) % MEM_SIZE] << 16) | (map[++(*i) % MEM_SIZE] << 8)
		| map[++(*i) % MEM_SIZE];
	else if (label == 4)
		arg = (map[++(*i) % MEM_SIZE] << 24) | (map[++(*i) % MEM_SIZE] << 16)
		| (map[++(*i) % MEM_SIZE] << 8) | map[++(*i) % MEM_SIZE];
	return (arg);
}

t_byte			*value_to_cells(unsigned int val, int *k)
{
	unsigned int	temp;
	t_byte			*arr;
	int				i;

	temp = val;
	while (temp > 0)
	{
		temp = temp >> 8;
		*k = *k + 1;
	}
	i = *k;
	temp = val;
	arr = (t_byte *)malloc(sizeof(t_byte) * (*k));
	while (i-- > 0)
	{
		arr[i] = temp & 0x1FFFFFF;
		temp = temp >> 8;
	}
	return (arr);
}

int				num_to_map(t_game *gm, int indx, unsigned int r1,
							t_proc *proc)
{
	int		k;
	int		j;
	int		h;
	int		num;
	t_byte	*value;

	k = 0;
	j = -1;
	h = 4;
	value = value_to_cells(r1, &k);
	num = 0;
	while (gm->player_ids[num] != proc->r1 && num < MAX_PLAYERS)
		num++;
	indx = (indx < 0) ? MEM_SIZE + indx : indx;
	while (++j < 4)
	{
		if (k == 4)
			(*gm).map[(indx + j) % MEM_SIZE] = value[j];
		else
			(*gm).map[(indx + j) % MEM_SIZE] = (h > k) ? 0 : value[k - h];
		h -= (k != 4) ? 1 : 0;
		(*gm).map_color[(indx + j) % MEM_SIZE] = num + 1 + 20;
	}
	free(value);
	return (1);
}

int				num_to_reg(t_proc **proc, int index, unsigned int r1)
{
	(*proc)->reg[index] = r1;
	return (1);
}
