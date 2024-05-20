/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:02:57 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/20 21:00:25 by ddias-fe         ###   ########.fr       */
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
}	t_data;

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
	int		display;
	int		blast_active;
	int		blast_pos;
}	t_event;

int closewindow(int key, t_event *closing);
int move_down(int key, t_event *event);
int move_up(int key, t_event *event);
int animatedblast(t_event *event);

//void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif