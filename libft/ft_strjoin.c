/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:42:36 by mgavillo          #+#    #+#             */
/*   Updated: 2019/03/05 20:00:26 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	while (s1[j] != '\0')
	{
		d[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		d[i] = s2[j];
		i++;
		j++;
	}
	d[i] = '\0';
	return (d);
}
