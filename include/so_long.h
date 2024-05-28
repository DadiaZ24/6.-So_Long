/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:02:57 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/28 19:21:03 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//________________________________________________________________
//|_____________________________[LIBS]____________________________|
//|_______________________________________________________________|

# include "../libs/minilibx_linux/mlx.h"
# include "../libs/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

//________________________________________________________________
//|____________________[DINAMIC MAP RESOLUTION]___________________|
//|_______________________________________________________________|

# ifndef MAP_RES
#  define MAP_RES 64
# endif

//________________________________________________________________
//|________________________[DATA STRUCTURES]______________________|
//|_______________________________________________________________|

typedef struct s_data
{
	void	*img;
	char	*path;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	int		erase;
}	t_data;

typedef struct p_byte
{
	int		y;
	int		x;
	int		pi;
	int		bg_x;
	int		bg_y;
	int		bg_pi;
	char	r;
	char	g;
	char	b;
}	t_byte;

typedef struct g_event
{
	t_data		player_up;
	t_data		player_down;
	t_data		player_right;
	t_data		player_left;
	t_data		bg;
	t_data		tile;
	void		*mlx;
	void		*window;
	int			x;
	int			y;
	int			display;
	int			move_down_trigger;
	int			move_up_trigger;
	int			move_right_trigger;
	int			move_left_trigger;
	int			is_moving;
	int			map_lines;
	int			map_columns;
	char		**map;
	char		*chosen_map;
}	t_event;

//________________________________________________________________
//|______________________[FUNCTION PROTOTYPES]____________________|
//|_______________________________________________________________|

//|--------------MOVEMENT UTILS----------------

int		trigger_move_down(t_event *event);
int		trigger_move_up(t_event *event);
int		trigger_move_right(t_event *event);
int		trigger_move_left(t_event *event);

//|--------------KEY PRESS UTILS----------------

int		on_key_press(int key, t_event *event);
int		on_key_release(int key, t_event *event);
int		update_key_press(t_event *event);
int		key_press_down(t_event *event);
int		key_press_up(t_event *event);
int		key_press_right(t_event *event);
int		key_press_left(t_event *event);

//|--------------INIT UTILS----------------

int		init_key_press(t_event *event);
void	init_data(t_event *event);
void	init_byte_data(t_byte *byte);
void	init_t_data_data(t_event *event);
void	init_player_data(t_data *player);
void	init_int_data(t_event *event);
void	init_img_data(t_event *event);
void	init_get_img(t_event *event);
void	init_put_img(t_event *event);
void	init_loop(t_event *event);

//|--------------MAP UTILS----------------

void	set_map_size(t_event *event);
int		put_tile(char *path, t_event *event, int x, int y);
void	load_map(t_event *event);
void	render_map(t_event *event);
int		check_up(t_event *event);
int		check_down(t_event *event);
int		check_left(t_event *event);
int		check_right(t_event *event);
void	render_corners(t_event *event, int x, int y);
void	render_sides(t_event *event, int x, int y);
void	render_stuff(t_event *event, int x, int y);

//|--------------OTHER UTILS----------------

void	replace_black_pixels(t_data *foreground, t_data *background,
			int offset_x, int offset_y);
void	destroy_stuff(t_event *event);

#endif