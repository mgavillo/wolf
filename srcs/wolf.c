/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:01:24 by mgavillo          #+#    #+#             */
/*   Updated: 2019/05/30 20:36:28 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	errorcase(void)
{
	write(1, "Usage: bad input.\n", 18);
	exit(0);
}

void	mallocerror(void)
{
	write(1, "Usage: malloc error.\n", 21);
	exit(0);
}

void	sdlerror(void)
{
	write(1, "Usage: SDL error.\n", 18);
	exit(0);
}

void	sdl_init(t_sdl *sdl)
{
	sdl->pos.z = 0.5;
	sdl->dir.x = 1;
	sdl->dir.y = 0;
	sdl->plane.x = 0;
	sdl->plane.y = 0.6;
	sdl->plane.z = 0.5;
	sdl->speed = 0.09;
	sdl->pist[5] = sdl->pist[4];
	sdl->cos[0] = (float)cos(0.02);
	sdl->cos[1] = (float)cos(-0.02);
	sdl->cos[2] = (float)cos(M_PI_2);
	sdl->cos[3] = (float)cos(-M_PI_2);
	sdl->sin[0] = (float)sin(0.02);
	sdl->sin[1] = (float)sin(-0.02);
	sdl->sin[2] = (float)sin(M_PI_2);
	sdl->sin[3] = (float)sin(-M_PI_2);
	sdl->t = 0;
}

int		main(int ac, char **av)
{
	t_sdl		sdl;
	t_pars		p;

	sdl.list = NULL;
	sdl.first = 1;
	p.fd = open(av[1], O_RDONLY);
	p.ret = 1;
	p.word = 0;
	p.first = 0;
	p.line = NULL;
	sdl.map_height = -1;
	create_win(&sdl);
	fill_list(&sdl, p);
	fillmap(&sdl);
	sdl_init(&sdl);
	create_textures(&sdl);
	testmap(&sdl);
	menu(&sdl);
	events(sdl);
	return (ac);
}
