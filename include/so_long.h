/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:02:57 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/21 20:48:35 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/minilibx_linux/mlx.h"
# include "../libs/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct  s_data
{
    void	*img;
	char	*path;
	int		width;
	int		height;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_data;

typedef struct  p_byte
{
    int     y;
    int     x;
    int     pi;
    char    r;
    char    g;
    char    b;
	int		bg_x;
	int		bg_y;
	int		bg_pi;
}	t_byte;

typedef struct g_event
{
	void	*mlx;
	void	*window;
	int		x;
	int		y;
	t_data	fogu;
	t_data	fogd;
	t_data	fogr;
	t_data	fogl;
	t_data	blast;
	t_data	bg;
	t_data	icon;
	int		display;
	int		blast_active;
	int		blast_pos;
	int		move_down_trigger;
	int		move_up_trigger;
	int		move_right_trigger;
	int		move_left_trigger;
}	t_event;

int closewindow(int key, t_event *closing);
int move_down(int key, t_event *event);
int move_up(int key, t_event *event);
int animatedblast(t_event *event);
int animate_blast(t_event *event);

void replace_black_pixels(t_data *foreground, t_data *background, int offset_x, int offset_y, int erase);

//void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif