/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:44:10 by mgavillo          #+#    #+#             */
/*   Updated: 2019/01/05 18:11:32 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int		nwords(char const *s, char c)
{
	int i;
	int word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			word += 1;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c)
			i++;
	}
	return (word);
}

static int		nchar(char const *s, char c, int n)
{
	int i;
	int j;
	int word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		j = 0;
		if (s[i] != c)
			word += 1;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			j++;
		}
		if (word == n + 1)
			return (j);
		while (s[i] == c)
			i++;
	}
	return (0);
}

static void		assign(char const *s, char c, char ***tab)
{
	int i;
	int j;
	int k;
	int space;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		j = 0;
		space = 1;
		while (s[i] != c && s[i] != '\0')
		{
			tab[0][k][j] = s[i];
			space = 0;
			i++;
			j++;
		}
		while (s[i] == c)
			i++;
		if (space == 0)
			tab[0][k++][j] = '\0';
	}
	tab[0][k] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	if (s)
	{
		if (!(tab = (char **)malloc(sizeof(char *) * (nwords(s, c) + 1))))
			return (NULL);
		while (i < nwords(s, c))
		{
			if (!(tab[i] = malloc(sizeof(char) * (nchar(s, c, i) + 1))))
				return (NULL);
			i++;
		}
		if (!(tab[i] = malloc(1)))
			return (NULL);
		assign(s, c, &tab);
		return (tab);
	}
	return (NULL);
}
