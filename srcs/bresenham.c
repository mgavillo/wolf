/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:30:22 by mgavillo          #+#    #+#             */
/*   Updated: 2019/04/10 18:23:54 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		gradiant(t_line *line, t_pos pos, t_pos min, t_pos max)
{
	line->p = fabs((float)((pos.x - min.x) + (float)((pos.y - min.y) / 2))
		/ ((max.x - min.x) + (float)((max.y - min.y) / 2)));
	if (line->p > 1)
		line->p = 1;
	line->color = 0x00000000 * line->p + 0x0000FF00 * (1 - line->p);
	line->color += 0xFFFF0000;
}

static void	new_line1(t_sdl sdl, t_line line, t_pos min, t_pos max)
{
	int		i;

	i = 1;
	line.cumul = line.d.x / 2;
	while (i <= line.d.x)
	{
		line.pos.x += line.inc.x;
		line.cumul += line.d.y;
		if (line.cumul >= line.d.x)
		{
			line.cumul -= line.d.x;
			line.pos.y += line.inc.y;
		}
		gradiant(&line, line.pos, max, min);
		fill_pixel(&sdl, line.pos.x, line.pos.y, 0xFFFF00FF);
		i++;
	}
	fill_pixel(&sdl, line.pos.x, line.pos.y, 0xFFFF00FF);
}

static void	new_line2(t_sdl sdl, t_line line, t_pos min, t_pos max)
{
	int		i;

	i = 1;
	line.cumul = line.d.y / 2;
	while (i <= line.d.y)
	{
		line.pos.y += line.inc.y;
		line.cumul += line.d.x;
		if (line.cumul >= line.d.y)
		{
			line.cumul -= line.d.y;
			line.pos.x += line.inc.x;
		}
		gradiant(&line, line.pos, max, min);
		fill_pixel(&sdl, line.pos.x, line.pos.y, 0xFFFF00FF);
		i++;
	}
	fill_pixel(&sdl, line.pos.x, line.pos.y, 0xFFFF00FF);
}

void		new_line(t_sdl sdl, t_pos min, t_pos max)
{
	t_line	line;

	line.pos.x = min.x;
	line.pos.y = min.y;
	line.d.x = max.x - min.x;
	line.d.y = max.y - min.y;
	line.inc.x = (line.d.x > 0) ? 1 : -1;
	line.inc.y = (line.d.y > 0) ? 1 : -1;
	line.d.x = fabs(line.d.x);
	line.d.y = fabs(line.d.y);
	fill_pixel(&sdl, line.pos.x, line.pos.y, 0xFFFF00FF);
	if (line.d.x > line.d.y)
		new_line1(sdl, line, min, max);
	if (line.d.x <= line.d.y)
		new_line2(sdl, line, min, max);
}
