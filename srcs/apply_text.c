/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 02:13:58 by mgavillo          #+#    #+#             */
/*   Updated: 2019/07/03 02:14:00 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	floor_ceiling_calc(t_sdl *sdl, int x, float y, int text)
{
	double			dist;
	t_pos			pos;
	t_pint			tex;
	double			inc;

	if (text == 4)
		inc = 1 - sdl->pos.z;
	else if (text == 5)
		inc = -sdl->pos.z;
	else
		inc = -sdl->pos.z + sdl->wa;
	dist = (double)((double)inc) / (sdl->plane.z
		- ((double)((double)(y) / (WIN_HEIGHT))));
	pos.x = sdl->raydir.x * dist + sdl->pos.x;
	pos.y = sdl->raydir.y * dist + sdl->pos.y;
	tex.i = (int)((double)(pos.x - (int)pos.x) * 256);
	tex.j = (int)((double)(pos.y - (int)pos.y) * 256);
	if (sdl->fill[(int)y] == 0)
	{
		if_fill_pixel(sdl, x, y, getpixel(sdl->text[text], tex.i, tex.j, 256));
		sdl->fill[(int)y] = 1;
	}
}

void			floor_ceiling(t_sdl *sdl, int x)
{
	float			y;

	if (sdl->end < 0)
		sdl->end = WIN_HEIGHT;
	y = 0;
	while (y <= sdl->start)
	{
		floor_ceiling_calc(sdl, x, y, 4);
		y++;
	}
	y = sdl->end;
	while (y <= WIN_HEIGHT)
	{
		floor_ceiling_calc(sdl, x, y, 5);
		y++;
	}
}

static int		which_wall(t_sdl *sdl)
{
	if (sdl->raydir.x > 0 && sdl->side == 0)
		return (0);
	if (sdl->raydir.x <= 0 && sdl->side == 0)
		return (1);
	if (sdl->raydir.y > 0 && sdl->side == 1)
		return (2);
	if (sdl->raydir.y <= 0 && sdl->side == 1)
		return (3);
	return (0);
}

void			wall(t_sdl *sdl, int x, int floor)
{
	int				y;
	t_pint			tex;
	int				i;

	if (sdl->realstart <= 1)
		sdl->realstart = 1;
	if (sdl->realstart > WIN_HEIGHT)
		sdl->realstart = WIN_HEIGHT;
	y = (int)sdl->realstart - 1;
	i = which_wall(sdl);
	while (sdl->fill[++y] == 0 && floor == 0)
		floor_ceiling_calc(sdl, x, y, 2);
	y = (int)sdl->realstart;
	while (sdl->fill[++y] == 0 && y < sdl->end)
	{
		tex.i = (int)((double)(sdl->tex.x - (int)sdl->tex.x) * 256);
		tex.j = (int)(((float)(y - (int)sdl->start) /
			((int)sdl->end - (int)sdl->start)) * 256);
		if_fill_pixel(sdl, x, y, getpixel(sdl->text[i], tex.i, tex.j, 256));
		sdl->fill[y] = 1;
	}
}

void			target(t_sdl *sdl)
{
	SDL_Rect	r;

	r.x = 280;
	r.y = 200;
	r.w = 80;
	r.h = 80;
	if (SDL_SetTextureBlendMode(sdl->pist[6], SDL_BLENDMODE_BLEND))
		sdlerror();
	if (SDL_SetTextureAlphaMod(sdl->pist[6], 255))
		sdlerror();
	if (SDL_RenderCopy(sdl->rend, sdl->pist[7], NULL, &r))
		sdlerror();
}
