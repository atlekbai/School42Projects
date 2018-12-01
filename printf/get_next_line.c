/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:53:57 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/04 11:54:04 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		endl(char **line, char **stack)
{
	char *c;
	char *t;

	if (*stack != NULL && (c = ft_strchr(*stack, 10)))
	{
		t = *stack;
		*line = ft_strsub(t, 0, c - t);
		*stack = ft_strsub(t, c - t + 1, ft_strlen(t) - (c - t) + 1);
		free(t);
		return (1);
	}
	return (0);
}

static int		record(char **line, char **stack, int fd)
{
	char		buf[BUFF_SIZE + 1];
	char		*t;
	int			size;

	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		t = *stack;
		*stack = ft_strjoin(t, buf);
		free(t);
		if (endl(line, stack))
			return (1);
	}
	return (0);
}

static t_stack	*find(int fd, t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	ft_stackadd(stack, ft_stacknew(ft_strnew(0), fd));
	return (*stack);
}

int				get_next_line(const int fd, char **line)
{
	static t_stack	*stack;
	t_stack			*temp;

	if (read(fd, 0, 0) < 0)
		return (-1);
	temp = find(fd, &stack);
	if (endl(line, &temp->stack) || record(line, &temp->stack, fd))
		return (1);
	if (temp->stack == NULL || !*(temp->stack))
		return (0);
	*line = ft_strdup(temp->stack);
	ft_strdel(&temp->stack);
	return (1);
}
