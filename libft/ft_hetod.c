/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hetod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 23:32:07 by mgavillo          #+#    #+#             */
/*   Updated: 2019/07/01 23:35:41 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hetod(int hexa)
{
	int		nb;
	int		i;
	int		j;
	int		digit;
	char	*base;

	nb = 0;
	j = 1;
	base = ft_strdup("0123456789ABCDEF");
	while (hexa)
	{
		i = 0;
		digit = hexa % 16;
		if (digit >= 0 && digit <= 9)
			digit += 48;
		else
			digit += 55;
		while (base[i] != digit)
			i++;
		nb += i * j;
		hexa /= 16;
		j *= 16;
	}
	ft_strdel(&base);
	return (nb);
}

