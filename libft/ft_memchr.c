/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:53:08 by mgavillo          #+#    #+#             */
/*   Updated: 2018/11/20 18:13:14 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	*s2;

	i = 0;
	c2 = (unsigned char)c;
	s2 = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (i < n - 1 && s2[i] != c2)
		i++;
	if (s2[i] == c2)
		return (&((void *)s2)[i]);
	return (NULL);
}
