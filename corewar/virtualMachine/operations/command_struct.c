/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:16:53 by hdanylev          #+#    #+#             */
/*   Updated: 2018/05/16 14:16:56 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include "commands.h"

static void	set_codage(t_op **op)
{
	(*op)[0].codage = 0;
	(*op)[1].codage = 1;
	(*op)[2].codage = 1;
	(*op)[3].codage = 1;
	(*op)[4].codage = 1;
	(*op)[5].codage = 1;
	(*op)[6].codage = 1;
	(*op)[7].codage = 1;
	(*op)[8].codage = 0;
	(*op)[9].codage = 1;
	(*op)[10].codage = 1;
	(*op)[11].codage = 0;
	(*op)[12].codage = 1;
	(*op)[13].codage = 1;
	(*op)[14].codage = 0;
	(*op)[15].codage = 1;
}

static void	set_label(t_op **op)
{
	(*op)[0].label = 4;
	(*op)[1].label = 4;
	(*op)[2].label = 4;
	(*op)[3].label = 4;
	(*op)[4].label = 4;
	(*op)[5].label = 4;
	(*op)[6].label = 4;
	(*op)[7].label = 4;
	(*op)[8].label = 2;
	(*op)[9].label = 2;
	(*op)[10].label = 2;
	(*op)[11].label = 2;
	(*op)[12].label = 4;
	(*op)[13].label = 2;
	(*op)[14].label = 2;
	(*op)[15].label = 4;
}

static void	set_cycles(t_op **op)
{
	(*op)[0].cycles = 10;
	(*op)[1].cycles = 5;
	(*op)[2].cycles = 5;
	(*op)[3].cycles = 10;
	(*op)[4].cycles = 10;
	(*op)[5].cycles = 6;
	(*op)[6].cycles = 6;
	(*op)[7].cycles = 6;
	(*op)[8].cycles = 20;
	(*op)[9].cycles = 25;
	(*op)[10].cycles = 25;
	(*op)[11].cycles = 800;
	(*op)[12].cycles = 10;
	(*op)[13].cycles = 50;
	(*op)[14].cycles = 1000;
	(*op)[15].cycles = 2;
}

static void	set_pointers(t_op **op)
{
	(*op)[0].f = *live;
	(*op)[1].f = *ld;
	(*op)[2].f = *st;
	(*op)[3].f = *add;
	(*op)[4].f = *sub;
	(*op)[5].f = *and;
	(*op)[6].f = *or;
	(*op)[7].f = *xor;
	(*op)[8].f = *zjmp;
	(*op)[9].f = *ldi;
	(*op)[10].f = *sti;
	(*op)[11].f = *frk;
	(*op)[12].f = *lld;
	(*op)[13].f = *lldi;
	(*op)[14].f = *lfrk;
	(*op)[15].f = *aff;
}

t_op		*command_struct(void)
{
	int		i;
	t_op	*op;

	op = (t_op *)malloc(sizeof(t_op) * 16);
	i = 0;
	while (i < 16)
	{
		op[i].f = NULL;
		op[i].cycles = 0;
		op[i].index = 0;
		op[i].label = 0;
		i++;
	}
	set_codage(&op);
	set_cycles(&op);
	set_label(&op);
	set_pointers(&op);
	return (op);
}
