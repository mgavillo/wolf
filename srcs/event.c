/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 01:22:19 by mgavillo          #+#    #+#             */
/*   Updated: 2019/07/03 01:24:11 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void	update(t_sdl *sdl)
{
	ft_bzero(sdl->pixel, (WIN_HEIGHT * WIN_WIDTH * 4) - 1);
	raycasting(sdl);
	map(sdl);
	if (SDL_UpdateTexture(sdl->image, NULL, sdl->pixel, WIN_WIDTH * 4))
		sdlerror();
	if (SDL_RenderCopy(sdl->rend, sdl->image, NULL, NULL))
		sdlerror();
	if (SDL_SetTextureBlendMode(sdl->pist[5], SDL_BLENDMODE_BLEND))
		sdlerror();
	if (SDL_SetTextureAlphaMod(sdl->pist[5], 255))
		sdlerror();
	if (SDL_RenderCopy(sdl->rend, sdl->pist[5], NULL, NULL))
		sdlerror();
	target(sdl);
	SDL_RenderPresent(sdl->rend);
}

static void	mouse(t_sdl *sdl, int x, int y)
{
	double		tmp;

	sdl->plane.z -= (float)y / WIN_WIDTH;
	sdl->plane.z = (sdl->plane.z < 0 ? 0 : sdl->plane.z);
	sdl->plane.z = (sdl->plane.z > 1 ? 1 : sdl->plane.z);
	if (x < 0)
	{
		tmp = sdl->dir.x;
		sdl->dir.x = sdl->dir.x * sdl->cos[1] - sdl->dir.y * sdl->sin[1];
		sdl->dir.y = tmp * sdl->sin[1] + sdl->dir.y * sdl->cos[1];
		tmp = sdl->plane.x;
		sdl->plane.x = sdl->plane.x * sdl->cos[1] - sdl->plane.y
			* sdl->sin[1];
		sdl->plane.y = tmp * sdl->sin[1] + sdl->plane.y * sdl->cos[1];
	}
	if (x > 0)
	{
		tmp = sdl->dir.x;
		sdl->dir.x = sdl->dir.x * sdl->cos[0] - sdl->dir.y * sdl->sin[0];
		sdl->dir.y = tmp * sdl->sin[0] + sdl->dir.y * sdl->cos[0];
		tmp = sdl->plane.x;
		sdl->plane.x = sdl->plane.x * sdl->cos[0] - sdl->plane.y
			* sdl->sin[0];
		sdl->plane.y = tmp * sdl->sin[0] + sdl->plane.y * sdl->cos[0];
	}
}

static void	ft_time(t_sdl *sdl)
{
	double	tbis;

	tbis = SDL_GetTicks();
	if (sdl->t > 0)
	{
		if (tbis - sdl->t > 0 && tbis - sdl->t < 50)
			sdl->pist[5] = sdl->pist[1];
		if (tbis - sdl->t >= 50 && tbis - sdl->t < 100)
			sdl->pist[5] = sdl->pist[2];
		if (tbis - sdl->t >= 100 && tbis - sdl->t < 150)
			sdl->pist[5] = sdl->pist[3];
		if (tbis - sdl->t >= 150 && tbis - sdl->t < 200)
			sdl->pist[5] = sdl->pist[4];
		if (tbis - sdl->t > 200)
		{
			sdl->t = 0;
			sdl->pist[5] = sdl->pist[0];
		}
	}
}

void		events(t_sdl sdl)
{
	t_input				input;
	const unsigned char	*state;
	unsigned int		button;
	t_pint				movmouse;

	
	ft_bzero(input.key, SDL_NUM_SCANCODES);
	input.quit = 0;
	SDL_SetRelativeMouseMode(SDL_TRUE);
	while (!input.quit)
	{
		state = SDL_GetKeyboardState(NULL);
		button = SDL_GetRelativeMouseState(&movmouse.i, &movmouse.j);
		if (button == 1)
			sdl.t = SDL_GetTicks();
		right(&sdl, state);
		left(&sdl, state);
		up(&sdl, state);
		down(&sdl, state, &input);
		mouse(&sdl, movmouse.i, movmouse.j);
		keyboard(&sdl, &input);
		ft_time(&sdl);
		update(&sdl);
	}
	close_win(&sdl);
}
