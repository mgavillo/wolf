/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:56:47 by mgavillo          #+#    #+#             */
/*   Updated: 2018/11/18 20:33:55 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *a, const char *b, size_t len)
{
	size_t	len2;
	int		i;

	i = 0;
	if (b[i] == '\0')
		return ((char *)a);
	len2 = ft_strlen(b);
	while (a[i] != '\0' && len-- >= len2)
	{
		if (a[i] == b[0] && ft_strncmp(&a[i], b, len2) == 0)
			return ((char *)&a[i]);
		i++;
	}
	return (NULL);
}
