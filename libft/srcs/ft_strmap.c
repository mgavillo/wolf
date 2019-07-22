/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:41:35 by mgavillo          #+#    #+#             */
/*   Updated: 2018/11/18 20:59:32 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*d;

	i = 0;
	if (s)
	{
		if (!(d = malloc((ft_strlen(s) + 1) * sizeof(char))))
			return (NULL);
		while (s[i] != '\0')
		{
			d[i] = f(s[i]);
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	return (NULL);
}
