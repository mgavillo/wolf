/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:25:23 by mgavillo          #+#    #+#             */
/*   Updated: 2019/05/30 21:15:14 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

//verifier les segfault
//revoir vision
//revoir menu
//ajouter plafond et changer mur

static void	init_fill(t_sdl *sdl)
{
	int i;

	i = 0;
	while (i < 481)
	{
		sdl->fill[i] = 0;
		i++;
	}
}

void		raycasting(t_sdl *sdl)
{
	int		x;
	t_pos	min;
	double	c;

	x = 0;
	c = (float)((float)180 / sdl->map_width);
	min.x = 450 + c * sdl->pos.x;
	min.y = 10 + c * sdl->pos.y;
	while (x < WIN_WIDTH)
	{
		init_fill(sdl);
		start(sdl, x);
		init_dda(sdl);
		dda(sdl, x);
		distance(sdl, x, sdl->map[sdl->square.j][sdl->square.i], 1);
		floor_ceiling(sdl, x);
		x++;
		vision(sdl, min, c);
	}

}
