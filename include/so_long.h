/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:02:57 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/22 21:02:19 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/minilibx_linux/mlx.h"
# include "../libs/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_data
{
	void	*img;
	char	*path;
	int		width;
	int		height;
	char	*data;
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
	char	r;
	char	g;
	char	b;
	int		bg_x;
	int		bg_y;
	int		bg_pi;
}	t_byte;

typedef struct g_event
{
	t_data	player_up;
	t_data	player_down;
	t_data	player_right;
	t_data	player_left;
	t_data	blast;
	t_data	bg;
	t_data	icon;
	void	*mlx;
	void	*window;
	int		x;
	int		y;
	int		display;
	int		blast_active;
	int		blast_pos;
	int		move_down_trigger;
	int		move_up_trigger;
	int		move_right_trigger;
	int		move_left_trigger;
}	t_event;

int		closewindow(int key, t_event *closing);
int		move_down(int key, t_event *event);
int		move_up(int key, t_event *event);
int		animatedblast(t_event *event);
int		init_key_press(t_event *event);
int		on_key_press(int key, t_event *event);
int		on_key_release(int key, t_event *event);
int		update_key_press(t_event *event);
int		shot_blast_down(t_event *event);
int		shot_blast_up(t_event *event);
int		shot_blast_right(t_event *event);
int		shot_blast_left(t_event *event);
int		animate_blast(t_event *event);
int		shot_blast_down_inactivate(t_event *event);
int		shot_blast_up_inactivate(t_event *event);
int		shot_blast_right_inactivate(t_event *event);
int		shot_blast_left_inactivate(t_event *event);
int		key_press_down(t_event *event);
int		key_press_up(t_event *event);
int		key_press_right(t_event *event);
int		key_press_left(t_event *event);
int		key_press_space(t_event *event);
int		trigger_move_down(t_event *event);
int		trigger_move_up(t_event *event);
int		trigger_move_right(t_event *event);
int		trigger_move_left(t_event *event);

void	replace_black_pixels(t_data *foreground, t_data *background,
			int offset_x, int offset_y);

//void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif