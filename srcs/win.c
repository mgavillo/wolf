/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:24:11 by mgavillo          #+#    #+#             */
/*   Updated: 2019/05/30 20:43:47 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	close_win(t_sdl *sdl)
{
	SDL_DestroyTexture(sdl->image);
	SDL_DestroyRenderer(sdl->rend);
	SDL_DestroyWindow(sdl->win);
	SDL_Quit();
	exit(0);
}

void	create_win(t_sdl *sdl)
{
	//sdl->win = NULL;
	//sdl->rend = NULL;
	SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		errorcase();
	if (SDL_CreateWindowAndRenderer(WIN_WIDTH, WIN_HEIGHT, 0, &sdl->win,
		&sdl->rend))
		errorcase();
	sdl->image = SDL_CreateTexture(sdl->rend, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STREAMING, WIN_WIDTH, WIN_HEIGHT);
	if (sdl->image == NULL)
		errorcase();
	sdl->pixel = malloc(sizeof(char) * WIN_WIDTH * WIN_HEIGHT * 4);
}
