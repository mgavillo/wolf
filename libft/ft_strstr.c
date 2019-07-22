/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:55:43 by mgavillo          #+#    #+#             */
/*   Updated: 2019/03/05 20:03:58 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *a, const char *b)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	if (b[j] == '\0' || (a[i] == '\0' && b[j] == '\0'))
		return ((char *)&a[i]);
	while (a[i] != '\0')
	{
		tmp = i;
		while (a[i] == b[j] && a[i] != '\0' && b[j]
				!= '\0')
		{
			i++;
			j++;
		}
		if (b[j] == '\0')
			return ((char *)&a[tmp]);
		i = tmp;
		i++;
		j = 0;
	}
	return (NULL);
}
