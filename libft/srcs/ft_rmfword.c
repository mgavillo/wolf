/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmfword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 02:05:02 by mgavillo          #+#    #+#             */
/*   Updated: 2019/01/30 03:12:50 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_rmfword(char *s)
{
	int		i;
	char	*string;

	i = 0;
	while (s[i] != '\0' && s[i] != ' ')
		i++;
	while (s[i] == ' ')
	{
		i++;
	}
	if (s[i] == '\0')
	{
		ft_strdel(&s);
		return (NULL);
	}
	string = ft_strdup((char *)&s[i]);
	ft_strdel(&s);
	return (string);
}
