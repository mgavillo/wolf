/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:22:48 by mgavillo          #+#    #+#             */
/*   Updated: 2019/03/28 18:50:41 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	right(t_sdl *sdl, const unsigned char *state)
{
	t_pos		diag;

	if (state[SDL_SCANCODE_RIGHT])
	{
		diag.x = sdl->dir.x * sdl->cos[3] - sdl->dir.y * sdl->sin[3];
		diag.y = sdl->dir.x * sdl->sin[3] + sdl->dir.y * sdl->cos[3];
		if (sdl->pos.y - diag.y * sdl->speed < sdl->map_height - 0.1
			&& sdl->pos.y - diag.y * sdl->speed >= 0.1
			&& sdl->pos.x + diag.x * sdl->speed < sdl->map_width
			&& sdl->pos.x + diag.x * sdl->speed >= 0.1)
		{
			if (sdl->map[(int)(sdl->pos.y - diag.y * sdl->speed)]
				[(int)sdl->pos.x] <= sdl->pos.z - 0.1
				&& sdl->map[(int)sdl->pos.y][(int)(sdl->pos.x
				- diag.x * sdl->speed)] <= sdl->pos.z - 0.1)
			{
				sdl->pos.y -= diag.y * sdl->speed;
				sdl->pos.x -= diag.x * sdl->speed;
			}
		}
	}
}

void	left(t_sdl *sdl, const unsigned char *state)
{
	t_pos		diag;

	if (state[SDL_SCANCODE_LEFT])
	{
		diag.x = sdl->dir.x * sdl->cos[2] - sdl->dir.y * sdl->sin[2];
		diag.y = sdl->dir.x * sdl->sin[2] + sdl->dir.y * sdl->cos[2];
		if (sdl->pos.y - diag.y * sdl->speed < sdl->map_height - 0.1
			&& sdl->pos.y - diag.y * sdl->speed >= 0.1
			&& sdl->pos.x + diag.x * sdl->speed < sdl->map_width
			&& sdl->pos.x + diag.x * sdl->speed >= 0.1)
		{
			if (sdl->map[(int)(sdl->pos.y - diag.y * sdl->speed)]
				[(int)sdl->pos.x] <= sdl->pos.z - 0.1
				&& sdl->map[(int)sdl->pos.y][(int)(sdl->pos.x - diag.x
				* sdl->speed)] <= sdl->pos.z - 0.1)
			{
				sdl->pos.y -= diag.y * sdl->speed;
				sdl->pos.x -= diag.x * sdl->speed;
			}
		}
	}
}

void	up(t_sdl *sdl, const unsigned char *state)
{
	if (state[SDL_SCANCODE_UP])
	{
		if (sdl->pos.y + sdl->dir.y * sdl->speed < sdl->map_height - 0.1
			&& sdl->pos.y + sdl->dir.y * sdl->speed >= 0.1
			&& sdl->pos.x + sdl->dir.x * sdl->speed < sdl->map_width - 0.1
			&& sdl->pos.x + sdl->dir.x * sdl->speed >= 0.1)
		{
			if (sdl->map[(int)(sdl->pos.y + sdl->dir.y
				* sdl->speed)][(int)sdl->pos.x] <= sdl->pos.z - 0.1
				&& sdl->map[(int)sdl->pos.y][(int)(sdl->pos.x + sdl->dir.x
				* sdl->speed)] <= sdl->pos.z - 0.1)
			{
				sdl->pos.y += sdl->dir.y * sdl->speed;
				sdl->pos.x += sdl->dir.x * sdl->speed;
			}
		}
	}
}

void	down(t_sdl *sdl, const unsigned char *state, t_input *input)
{
	if (state[SDL_SCANCODE_DOWN])
	{
		if (sdl->pos.y - sdl->dir.y * sdl->speed < sdl->map_height - 0.1
			&& sdl->pos.y - sdl->dir.y * sdl->speed >= 0.1
			&& sdl->pos.x + sdl->dir.x * sdl->speed < sdl->map_width
			&& sdl->pos.x + sdl->dir.x * sdl->speed >= 0.1)
		{
			if (sdl->map[(int)(sdl->pos.y - sdl->dir.y * sdl->speed)]
				[(int)sdl->pos.x] <= sdl->pos.z - 0.1
				&& sdl->map[(int)sdl->pos.y][(int)(sdl->pos.x
				- sdl->dir.x * sdl->speed)] <= sdl->pos.z - 0.1)
			{
				sdl->pos.y -= sdl->dir.y * sdl->speed;
				sdl->pos.x -= sdl->dir.x * sdl->speed;
			}
		}
	}
	if (state[SDL_SCANCODE_ESCAPE])
		input->quit = 1;
}

void	keyboard(t_sdl *sdl, t_input *input)
{
	SDL_Event	event;

	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN)
		input->key[event.key.keysym.scancode] = 1;
	else if (event.type == SDL_KEYUP)
		input->key[event.key.keysym.scancode] = 0;
	if (input->key[SDL_SCANCODE_Q])
	{
		if (sdl->pos.z < 0.9)
			sdl->pos.z += 0.01;
	}
	if (input->key[SDL_SCANCODE_W])
	{
		if (sdl->pos.z - 0.01 >= sdl->map[(int)sdl->pos.y]
			[(int)sdl->pos.x] + 0.1)
			sdl->pos.z -= 0.01;
	}
	if (input->key[SDL_SCANCODE_P])
		menu(sdl);
	if (input->key[SDL_SCANCODE_T])
		SDL_SetWindowFullscreen(sdl->win, SDL_WINDOW_FULLSCREEN);
	if (input->key[SDL_SCANCODE_Y])
		SDL_SetWindowFullscreen(sdl->win, 0);
}
