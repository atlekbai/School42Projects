/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:38:23 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/07 14:38:24 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t			ft_len_num(uintmax_t value, int base)
{
	int			count;

	count = 0;
	if (value <= 0)
		count++;
	while (value != 0)
	{
		count++;
		value /= base;
	}
	return (count);
}

int				ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

char			*ft_lower_case(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

char			*ft_itoa_base(uintmax_t value, t_desc *list, int base)
{
	char		*itoa;
	char		*box;
	size_t		len;

	box = "0123456789ABCDEF";
	len = ft_len_num(value, base);
	itoa = ft_strnew(len);
	if (itoa)
	{
		itoa[len] = '\0';
		if (value == 0)
			itoa[0] = '0';
		while (value != 0)
		{
			itoa[--len] = box[(value % base)];
			value = value / base;
		}
		if (list->spec == 'x' || list->spec == 'p')
			itoa = ft_lower_case(itoa);
	}
	return (itoa);
}
