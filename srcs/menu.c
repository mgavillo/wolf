/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 02:50:59 by mgavillo          #+#    #+#             */
/*   Updated: 2019/07/20 15:16:01 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
/*void	delete_text(t_sdl *sdl)
{
	SDL_DestroyTexture(sdl->m.menu);
	SDL_DestroyTexture(sdl->m.new);
	SDL_DestroyTexture(sdl->m.n);
	SDL_DestroyTexture(sdl->m.quit);
	SDL_DestroyTexture(sdl->m.q);
}
*/

static void	quit_or_new(t_sdl *sdl, t_input *input, SDL_Event event, int bouton)
{
	if (input->key[SDL_SCANCODE_RETURN] == 1 && bouton == -1)
		close_win(sdl);
	if (input->key[SDL_SCANCODE_ESCAPE] == 1)
		close_win(sdl);
	if ((input->key[SDL_SCANCODE_RETURN] == 1 && bouton == 1))
	{
		sdl_init(sdl);
		input->quit = 1;
	}
	if (input->key[SDL_SCANCODE_P] == 1 && sdl->first == 0)
		input->quit = 1;
	else if (event.type == SDL_MOUSEBUTTONDOWN && input->quit == 0)
	{
		if (event.button.button == SDL_BUTTON_LEFT && event.button.clicks > 0
			&& event.motion.x >= 10 && event.motion.x <= 190
			&& event.motion.y >= 10 && event.motion.y <= 85)
		{
			sdl_init(sdl);
			input->quit = 1;
		}
		if (event.button.button == SDL_BUTTON_LEFT && event.button.clicks > 0
			&& event.motion.x >= 450 && event.motion.x <= 630
			&& event.motion.y >= 10 && event.motion.y <= 85)
			close_win(sdl);
	}
}

static void	rend_copy(t_sdl *sdl, SDL_Texture *menu, SDL_Texture *first,
	SDL_Texture *sec)
{
	SDL_Rect	r;
	SDL_Rect	s;

	r.x = 10;
	r.y = 10;
	r.w = 180;
	r.h = 75;
	s.x = 450;
	s.y = 10;
	s.w = 180;
	s.h = 75;
	if (SDL_RenderCopy(sdl->rend, menu, NULL, NULL))
		sdlerror();
	if (SDL_RenderCopy(sdl->rend, first, NULL, &r))
		sdlerror();
	if (SDL_RenderCopy(sdl->rend, sec, NULL, &s))
		sdlerror();
	SDL_RenderPresent(sdl->rend);
}

static void	which_bouton(t_sdl *sdl, t_input input, SDL_Event event
	, float *bouton)
{
	if (input.key[SDL_SCANCODE_RIGHT] == 1
		|| input.key[SDL_SCANCODE_LEFT] == 1)
		*bouton *= -1;
	else if (event.motion.x > 10 && event.motion.x < 190\
		&& event.motion.y > 10 && event.motion.y < 85)
		*bouton = 1;
	else if (event.motion.x > 450 && event.motion.x < 630\
		&& event.motion.y > 10 && event.motion.y < 85)
		*bouton = -1;
	if (*bouton == 1)
		rend_copy(sdl, sdl->m.menu, sdl->m.n, sdl->m.quit);
	else
		rend_copy(sdl, sdl->m.menu, sdl->m.new, sdl->m.q);
}

static void	create_menu(t_sdl *sdl)
{
	sdl->m.menu = load_image("wolf.bmp", sdl);
	sdl->m.new = load_image("new_n.bmp", sdl);
	sdl->m.quit = load_image("exit_n.bmp", sdl);
	sdl->m.n = load_image("new.bmp", sdl);
	sdl->m.q = load_image("exit.bmp", sdl);
}

void	menu(t_sdl *sdl)
{
	t_input		input;
	SDL_Event	event;
	float		bouton;

	bouton = 1;
	input.quit = 0;
	ft_bzero(input.key, SDL_NUM_SCANCODES);
	create_menu(sdl);
	SDL_SetRelativeMouseMode(SDL_FALSE);
	while (!input.quit)
	{
		if (!SDL_WaitEvent(&event))
			errorcase();
		if (event.type == SDL_QUIT)
			close_win(sdl);
		if (event.type == SDL_KEYDOWN)
			input.key[event.key.keysym.scancode] = 1;
		else if (event.type == SDL_KEYUP)
			input.key[event.key.keysym.scancode] = 0;
		which_bouton(sdl, input, event, &bouton);
		quit_or_new(sdl, &input, event, bouton);
	}
	sdl->first = 0;
	//delete_text(sdl);
	events(*sdl);
}
