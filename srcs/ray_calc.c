/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 02:12:15 by mgavillo          #+#    #+#             */
/*   Updated: 2019/07/03 02:12:19 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	distance(t_sdl *sdl, int x, float w, int back)
{
	float	height;
	float	perpwalldist;

	if (sdl->side == 0)
		perpwalldist = fabs((sdl->square.i - sdl->pos.x
		+ (1 - sdl->step.i) / 2) / sdl->raydir.x);
	else
		perpwalldist = fabs((sdl->square.j - sdl->pos.y
		+ (1 - sdl->step.j) / 2) / sdl->raydir.y);
	if (perpwalldist < 0.05)
		perpwalldist = 0.05;
	sdl->dist = perpwalldist * sqrt(((((WIN_WIDTH / 2) - x) / WIN_HEIGHT) *
		(((WIN_WIDTH / 2) - x) / WIN_HEIGHT)) + 1);
	sdl->tex.x = sdl->side == 1 ? sdl->raydir.x * sdl->dist + sdl->pos.x :
		sdl->raydir.y * sdl->dist + sdl->pos.y;
	height = fabs(WIN_HEIGHT / perpwalldist);
	sdl->end = (WIN_HEIGHT * sdl->plane.z) + height * sdl->pos.z;
	sdl->start = sdl->end - (float)height;
	sdl->realstart = sdl->end - (float)(height * w);
	sdl->wa = w;
	wall(sdl, x, back);
}

void	mini_wall(t_sdl *sdl, int x)
{
	if (sdl->map[sdl->square.j][sdl->square.i] < 1
		&& sdl->map[sdl->square.j][sdl->square.i] > 0)
		distance(sdl, x, sdl->map[sdl->square.j][sdl->square.i], 1);
	else if ((sdl->square.j - sdl->step.j) >= 0 && (sdl->square.j - sdl->step.j)
		< sdl->map_height && sdl->side == 1)
	{
		if (sdl->map[sdl->square.j - sdl->step.j][sdl->square.i] > 0
			&& sdl->map[sdl->square.j - sdl->step.j][sdl->square.i] < 1)
			distance(sdl, x, sdl->map[sdl->square.j - sdl->step.j]
				[sdl->square.i], 0);
	}
	else if ((sdl->square.i - sdl->step.i) >= 0 && (sdl->square.j - sdl->step.j)
		< sdl->map_width && sdl->side == 0)
	{
		if (sdl->map[sdl->square.j][sdl->square.i - sdl->step.i] > 0
			&& sdl->map[sdl->square.j][sdl->square.i - sdl->step.i] < 1)
			distance(sdl, x, sdl->map[sdl->square.j]
				[sdl->square.i - sdl->step.i], 0);
	}
}

void	dda(t_sdl *sdl, int x)
{
	int		hit;

	hit = 0;
	while (hit == 0 && sdl->square.i >= 0 && sdl->square.j >= 0 && sdl->square.i
		< sdl->map_width && sdl->square.j < sdl->map_height)
	{
		if (sdl->d.x < sdl->d.y)
		{
			sdl->d.x += sdl->deltadist.x;
			sdl->square.i += sdl->step.i;
			sdl->side = 0;
		}
		else
		{
			sdl->d.y += sdl->deltadist.y;
			sdl->square.j += sdl->step.j;
			sdl->side = 1;
		}
		if (sdl->map[sdl->square.j][sdl->square.i] == 1)
			hit = 1;
		mini_wall(sdl, x);
	}
}

void	init_dda(t_sdl *sdl)
{
	if (sdl->raydir.x < 0)
	{
		sdl->step.i = -1;
		sdl->d.x = (sdl->pos.x - (double)sdl->square.i) * sdl->deltadist.x;
	}
	else
	{
		sdl->step.i = 1;
		sdl->d.x = ((double)sdl->square.i + 1.0 - sdl->pos.x) *
			sdl->deltadist.x;
	}
	if (sdl->raydir.y < 0)
	{
		sdl->step.j = -1;
		sdl->d.y = (sdl->pos.y - (double)sdl->square.j) * sdl->deltadist.y;
	}
	else
	{
		sdl->step.j = 1;
		sdl->d.y = ((double)sdl->square.j + 1.0 - sdl->pos.y) *
			sdl->deltadist.y;
	}
}

void	start(t_sdl *sdl, int x)
{
	float	camera;

	camera = (double)(2 * x) / WIN_WIDTH - 1;
	sdl->raydir.x = sdl->dir.x + sdl->plane.x * camera;
	sdl->raydir.y = sdl->dir.y + sdl->plane.y * camera;
	sdl->square.i = (int)sdl->pos.x;
	sdl->square.j = (int)sdl->pos.y;
	sdl->deltadist.x = sqrt(1 + ((double)(sdl->raydir.y * sdl->raydir.y) /
		(double)(sdl->raydir.x * sdl->raydir.x)));
	sdl->deltadist.y = sqrt(1 + ((double)(sdl->raydir.x * sdl->raydir.x) /
		(double)(sdl->raydir.y * sdl->raydir.y)));
}
