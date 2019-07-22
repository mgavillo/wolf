/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:56:02 by mgavillo          #+#    #+#             */
/*   Updated: 2019/06/11 20:56:05 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

SDL_Texture	*load_image(const char path[], t_sdl *sdl)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = SDL_LoadBMP(path);
	if (surface == NULL)
		sdlerror();
	SDL_SetColorKey(surface, SDL_TRUE, 4783872);
	texture = SDL_CreateTextureFromSurface(sdl->rend, surface);
	if (!texture)
		sdlerror();
	SDL_FreeSurface(surface);
	return (texture);
}

static void	*createtexture(t_sdl *sdl, char *file)
{
	int			i;
	int			j;
	SDL_Texture	*texture;
	int			pitch;
	void		*text;

	texture = load_image(file, sdl);
	if (SDL_QueryTexture(texture, NULL, NULL, &i, &j) < 0)
		sdlerror();
	text = malloc(sizeof(void) * i * j * 4);
	SDL_LockTexture(texture, NULL, &text, &pitch);
	return (text);
}

void		create_textures(t_sdl *sdl)
{
	sdl->text = malloc(sizeof(void *) * 6);
	sdl->text[5] = createtexture(sdl, "flr.bmp");
	sdl->text[0] = createtexture(sdl, "test.bmp");
	sdl->text[1] = createtexture(sdl, "crystal.bmp");
	sdl->text[2] = createtexture(sdl, "floor.bmp");
	sdl->text[3] = createtexture(sdl, "test3.bmp");
	sdl->text[4] = createtexture(sdl, "marbre.bmp");
	sdl->pist[0] = load_image("pist.bmp", sdl);
	sdl->pist[1] = load_image("pist1.bmp", sdl);
	sdl->pist[2] = load_image("pist2.bmp", sdl);
	sdl->pist[3] = load_image("pist3.bmp", sdl);
	sdl->pist[4] = load_image("pist4.bmp", sdl);
	sdl->pist[6] = load_image("cible.bmp", sdl);
	sdl->pist[7] = load_image("testt.bmp", sdl);
}
