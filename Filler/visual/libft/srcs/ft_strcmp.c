/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:22:33 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/01 11:05:46 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char const *s1, char const *s2)
{
	unsigned char	*src;
	unsigned char	*dst;
	int				i;

	src = (unsigned char*)s1;
	dst = (unsigned char*)s2;
	i = 0;
	while (src[i] == dst[i] && dst[i] != '\0')
		i++;
	if (src[i] == '\0' && dst[i] == '\0')
		return (0);
	return (src[i] - dst[i]);
}
