/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 01:55:56 by mgavillo          #+#    #+#             */
/*   Updated: 2019/07/03 01:55:58 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		vision(t_sdl *sdl, t_pos min, float c)
{
	t_pos	max;
	double	dist;
	t_pos	pos;

	dist = (double)((double)-sdl->pos.z) / (sdl->plane.z - 
		((double)((double)(sdl->end) / (WIN_HEIGHT))));
	pos.x = sdl->raydir.x * dist + sdl->pos.x;
	pos.y = sdl->raydir.y * dist + sdl->pos.y;
	max.x = 450.0 + (c * pos.x);
	max.y = 10.0 + (c * pos.y);
	new_line(*sdl, min, max);
}

static void	printsquare(t_sdl *sdl, t_pint min, t_pint max, unsigned int color)
{
	int	x;

	while (min.j <= max.j)
	{
		x = min.i - 1;
		while (x++ <= max.i)
			((unsigned int *)sdl->pixel)[x + (min.j * WIN_WIDTH)] = color;
		min.j++;
	}
}

static void	create_square(t_sdl *sdl, int i, int j)
{
	float	c;
	t_pint	min;
	t_pint	max;

	c = (float)180 / sdl->map_width;
	min.i = 450 + (i * c);
	min.j = 10 + (j * c);
	max.i = min.i + c;
	max.j = min.j + c;
	printsquare(sdl, min, max, 255 + ((int)(sdl->map[j][i] *
		255) << 24) + ((int)(sdl->map[j][i] * 255) << 16) +
		((int)(sdl->map[j][i] * 255) << 8));
}

void		map(t_sdl *sdl)
{
	int		j;
	int		i;
	float	c;
	t_pint	min;

	j = 0;
	c = (float)180 / sdl->map_width;
	while (j < sdl->map_height)
	{
		i = 0;
		while (i < sdl->map_width)
		{
			if (sdl->map[j][i] > 0)
				create_square(sdl, i, j);
			i++;
		}
		j++;
	}
	min.i = 450 + c * ((sdl->pos.x));
	min.j = 10 + c * ((sdl->pos.y));
	printsquare(sdl, min, min, 0xFF000050);
}
