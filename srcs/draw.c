/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:27:42 by mgavillo          #+#    #+#             */
/*   Updated: 2019/05/16 01:12:48 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			fill_pixel(t_sdl *sdl, int x, int y, unsigned int c)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		((unsigned int *)sdl->pixel)[x + (y * WIN_WIDTH)] = c;
}

void			if_fill_pixel(t_sdl *sdl, int x, int y, unsigned int c)
{
	if (((unsigned int *)sdl->pixel)[x + (y * WIN_WIDTH)] == 0)
	{
		if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
			((unsigned int *)sdl->pixel)[x + (y * WIN_WIDTH)] = c;
	}
}

unsigned int	getpixel(void *pixel, int x, int y, int width)
{
	unsigned char *p;

	p = (unsigned char *)pixel + y * width * 4 + x * 4 - 1;
	return (*(unsigned int *)p);
}
