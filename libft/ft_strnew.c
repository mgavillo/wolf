/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:40:43 by mgavillo          #+#    #+#             */
/*   Updated: 2019/01/08 18:33:38 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*d;

	if (!(d = malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_bzero(d, size + 1);
	return (d);
}
