/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:16:44 by mgavillo          #+#    #+#             */
/*   Updated: 2018/11/20 19:15:25 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dst[len] && len < n)
		len += 1;
	i = len;
	while (src[len - i] && len + 1 < n)
	{
		dst[len] = src[len - i];
		len++;
	}
	if (i < n)
		dst[len] = '\0';
	return (i + ft_strlen(src));
}
