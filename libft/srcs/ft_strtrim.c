/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:43:42 by mgavillo          #+#    #+#             */
/*   Updated: 2018/11/20 18:25:02 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_compt(char const *s, int *i, int *j)
{
	while (s[*j] == ' ' || s[*j] == '\n' || s[*j] == '\t')
		*j = *j - 1;
	while (s[*i] == ' ' || s[*i] == '\n' || s[*i] == '\t')
		*i = *i + 1;
}

char		*ft_strtrim(char const *s)
{
	char	*d;
	int		i;
	int		j;
	int		l;

	i = 0;
	if (!s)
		return (NULL);
	j = (int)ft_strlen(s) - 1;
	ft_compt(s, &i, &j);
	if (j == -1)
		return (ft_strdup(""));
	l = j - i + 1;
	if (!(d = malloc((l + 1) * sizeof(char))))
		return (NULL);
	j = 0;
	while (j != l)
	{
		d[j] = s[i];
		j++;
		i++;
	}
	d[j] = '\0';
	return (d);
}
