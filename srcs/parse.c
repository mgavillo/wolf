/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:55:35 by mgavillo          #+#    #+#             */
/*   Updated: 2019/05/30 20:34:33 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static t_nb		*newelement(t_nb *list, float nb)
{
	t_nb	*first;
	t_nb	*element;

	first = list;
	if (!(element = malloc(sizeof(*element))))
		return (NULL);
	element->nb = nb;
	element->next = NULL;
	if (list == NULL)
		return (element);
	while (list->next)
		list = list->next;
	list->next = element;
	return (first);
}

static int		beginning(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ' || str[i] == '\r')
		++i;
	if (str[i] == '-')
		errorcase();
	return (i);
}

static double	ft_atof(char *str)
{
	int		i;
	double	nb;
	int		dec;

	nb = 0;
	dec = 10;
	i = beginning(str);
	if (str[0] == 'X')
		return ('X');
	while (47 < str[i] && str[i] < 58)
	{
		nb = (nb * 10) + (int)str[i] - 48;
		++i;
	}
	if (str[i] == '.')
	{
		++i;
		while (47 < str[i] && str[i] < 58 && dec <= 1000000)
		{
			nb += (float)(str[i] - 48) / dec;
			dec *= 10;
			++i;
		}
	}
	return (nb);
}

static int		square(int previous, t_pars *p)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (p->line && p->line[0] != '\0')
	{
		while (p->line[i] != '\0')
		{
			if (p->line[i] != ' ' && p->line[i] != '\0')
				word++;
			while (p->line[i] != ' ' && p->line[i] != '\0')
				i++;
			while (p->line[i] == ' ')
				i++;
		}
		if (word != previous && p->first == 1)
			errorcase();
		p->first = 1;
		return (word);
	}
	return (0);
}

void			fill_list(t_sdl *sdl, t_pars p)
{
	while (p.ret > 0)
	{
		p.ret = get_next_line(p.fd, &p.line);
		p.word = square(p.word, &p);
		if (p.ret == 1)
		{
			sdl->map_width = 0;
			if (p.line[0] == '\0' && p.ret == 1)
				errorcase();
		}
		while (p.line != NULL)
		{
			if (p.line[0] == ' ')
				p.line = ft_rmfword(p.line);
			p.b = ft_atof(p.line);
			if (p.b > 1 && p.b != 'X')
				errorcase();
			sdl->list = newelement(sdl->list, (float)p.b);
			p.line = ft_rmfword(p.line);
			sdl->map_width++;
		}
		sdl->map_height++;
	}
}
