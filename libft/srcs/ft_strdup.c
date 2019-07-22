/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:20:58 by mgavillo          #+#    #+#             */
/*   Updated: 2018/11/20 18:19:04 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		a;
	char	*d;

	a = ft_strlen(src);
	if (!(d = malloc((a + 1) * sizeof(char))))
		return (NULL);
	ft_strcpy(d, src);
	return (d);
}
