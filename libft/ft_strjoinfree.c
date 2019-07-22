/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:40:31 by mgavillo          #+#    #+#             */
/*   Updated: 2019/01/05 00:16:00 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char	*d;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s1 && s2))
		return (NULL);
	if (!(d = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		d[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		d[i] = s2[j];
		i++;
		j++;
	}
	d[i] = '\0';
	ft_strdel(&s1);
	return (d);
}
