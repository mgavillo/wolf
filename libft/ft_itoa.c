/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:44:20 by mgavillo          #+#    #+#             */
/*   Updated: 2018/11/20 17:50:30 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_neg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

static void		len(int n, int *i)
{
	while (n)
	{
		n /= 10;
		*i += 1;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	neg = 0;
	ft_neg(&n, &neg);
	len(n, &i);
	i = i + neg;
	if (!(str = malloc((i + 1) * sizeof(char))))
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		str[i] = '0' + n % 10;
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
