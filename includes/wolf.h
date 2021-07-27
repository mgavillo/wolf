/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <mgavillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:12:14 by mgavillo          #+#    #+#             */
/*   Updated: 2021/07/27 20:17:29 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "SDL2/SDL.h"
# include "math.h"
# include <unistd.h>
# include "stdlib.h"
# include "fcntl.h"
# include "stdio.h"
# include <pthread.h>
# include "../libft/libft.h"
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define NB_THREADS 4

typedef struct	s_pars
{
	int		fd;
	int		ret;
	char	*line;
	double	b;
	int		word;
	int		first;
}				t_pars;

typedef struct	s_nb
{
	float		nb;
	struct s_nb	*next;
}				t_nb;

typedef struct	s_pos
{
	double	x;
	double	y;
	double	z;
}				t_pos;

typedef struct	s_pint
{
	int		i;
	int		j;
	int		k;
}				t_pint;

typedef struct	s_menu
{
	SDL_Texture	*menu;
	SDL_Texture	*new;
	SDL_Texture	*quit;
	SDL_Texture	*n;
	SDL_Texture	*q;
}				t_menu;

typedef struct	s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_l;
	int		endian;
}				t_img;

typedef struct		s_line
{
	t_pos			d;
	t_pos			inc;
	int				cumul;
	t_pos			pos;
	float			p;
	unsigned int	color;
}					t_line;

typedef struct	s_input
{
	int		key[SDL_NUM_SCANCODES];
	int		quit;
	t_pos	mouse;
	t_pos	rmouse;
	t_pos	wheel;
	int		bmouse[6];
}				t_input;

typedef struct	s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*image;
	t_menu			m;
	t_pos			pos;
	t_pos			dir;
	t_pos			plane;
	t_pos			raydir;
	float			cos[4];
	float			sin[4];
	float			**map;
	float			start;
	float			realstart;
	float			end;
	int				fill[481];
	float			speed;
	int				map_width;
	int				map_height;
	int				side;
	t_pint			step;
	t_pint			square;
	t_pos			d;
	float			wa;
	float			dist;
	t_pos			deltadist;
	t_nb			*list;
	void			*pixel;
	void			**text;
	SDL_Texture		*pist[10];
	t_pos			wall;
	t_pos			tex;
	int				first;
	double			t;
}				t_sdl;

void	errorcase(void);
void	mallocerror(void);
void	sdlerror(void);
void	sdl_init(t_sdl *sdl);

void	fill_list(t_sdl *sdl, t_pars p);

void	fillmap(t_sdl *sdl);
void	testmap(t_sdl *sdl);

void	close_win(t_sdl	*sdl);
void	create_win(t_sdl *sdl);

void	create_textures(t_sdl *sdl);
SDL_Texture	*load_image(const char path[], t_sdl *sdl);

void	menu(t_sdl *sdl);

void	events(t_sdl sdl);

void	right(t_sdl *sdl, const unsigned char *state);
void	left(t_sdl *sdl, const unsigned char *state);
void	up(t_sdl *sdl, const unsigned char *state);
void	down(t_sdl *sdl, const unsigned char *state, t_input *input);
void	keyboard(t_sdl *sdl, t_input *input);

void	raycasting(t_sdl *sdl);

void	start(t_sdl *sdl, int x);
void	init_dda(t_sdl *sdl);
void	dda(t_sdl *sdl, int x);
void	mini_wall(t_sdl *sdl, int x);
void	distance(t_sdl *sdl, int x, float w, int back);

void	floor_ceiling(t_sdl *sdl, int x);
void	wall(t_sdl *sdl, int x, int floor);
void	target(t_sdl *sdl);

void	if_fill_pixel(t_sdl *sdl, int x, int y, unsigned int color);
void	fill_pixel(t_sdl *sdl, int x, int y, unsigned int color);
unsigned int	getpixel(void *pixel, int x, int y, int width);

void	vision(t_sdl *sdl, t_pos min, float c);
void	map(t_sdl *sdl);

void	new_line(t_sdl sdl, t_pos min, t_pos max);
#endif
