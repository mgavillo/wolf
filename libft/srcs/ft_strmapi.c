/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:41:49 by mgavillo          #+#    #+#             */
/*   Updated: 2018/11/18 21:00:05 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*d;

	i = 0;
	if (s)
	{
		if (!(d = malloc((ft_strlen((char *)s) + 1) * sizeof(char))))
			return (NULL);
		while (s[i] != '\0')
		{
			d[i] = f(i, s[i]);
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	return (NULL);
}
