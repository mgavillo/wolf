/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:32:07 by mgavillo          #+#    #+#             */
/*   Updated: 2019/05/30 20:35:54 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static float	**createmap(t_sdl sdl)
{
	int i;

	if (!(sdl.map = (float **)malloc(sizeof(int *) * sdl.map_height)))
		mallocerror();
	i = 0;
	while (i < sdl.map_height)
	{
		if (!(sdl.map[i] = (float *)malloc(sizeof(int) * sdl.map_width)))
			mallocerror();
		i++;
	}
	return (sdl.map);
}

static void		findx(t_sdl *sdl, int i, int j, int *x)
{
	if (sdl->map[j][i] == 'X')
	{
		sdl->map[j][i] = 0;
		sdl->pos.x = i + 0.5;
		sdl->pos.y = j + 0.5;
		*x = 1;
	}
}

void			fillmap(t_sdl *sdl)
{
	int		i;
	int		j;
	t_nb	*first;
	int		x;

	j = 0;
	x = 0;
	sdl->map = createmap(*sdl);
	first = sdl->list;
	while (j < sdl->map_height)
	{
		i = 0;
		while (i < sdl->map_width)
		{
			sdl->map[j][i] = sdl->list->nb;
			if (sdl->list->next)
				sdl->list = sdl->list->next;
			findx(sdl, i, j, &x);
			i++;
		}
		j++;
	}
	sdl->list = first;
	if (x == 0)
		errorcase();
}

static void		testmap2(t_sdl *sdl)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (j < sdl->map_height)
	{
		if (sdl->map[j][i] != 1)
			errorcase();
		j++;
	}
	i = sdl->map_width - 1;
	j = 0;
	while (j < sdl->map_height)
	{
		if (sdl->map[j][i] != 1)
			errorcase();
		j++;
	}
}

void			testmap(t_sdl *sdl)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < sdl->map_width)
	{
		if (sdl->map[j][i] != 1)
			errorcase();
		i++;
	}
	j = sdl->map_height - 1;
	i = 0;
	while (i < sdl->map_width)
	{
		if (sdl->map[j][i] != 1)
			errorcase();
		i++;
	}
	testmap2(sdl);
}
