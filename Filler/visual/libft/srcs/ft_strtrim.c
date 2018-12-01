/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 18:09:18 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/01 12:30:24 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	int		k;
	char	*d;

	if (!s)
		return (NULL);
	i = 0;
	k = (int)ft_strlen(s) - 1;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	len = k - i + 1;
	if (i > 0 && !s[i])
		len = 0;
	k = 0;
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	while (len--)
		d[k++] = s[i++];
	d[k] = '\0';
	return (d);
}
