/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:35:55 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/28 19:41:58 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_img_data(t_event *event)
{
	event->bg.path = "img/bg.xpm";
	event->player_right.path = "img/player_right.xpm";
	event->player_up.path = "img/player_up.xpm";
	event->player_down.path = "img/player_down.xpm";
	event->player_left.path = "img/player_left.xpm";
}

void	init_get_img(t_event *event)
{
	init_img_data(event);
	event->player_right.img = mlx_xpm_file_to_image(event->mlx,
			event->player_right.path, &event->player_right.width,
			&event->player_right.height);
	event->player_up.img = mlx_xpm_file_to_image(event->mlx,
			event->player_up.path, &event->player_up.width,
			&event->player_up.height);
	event->player_down.img = mlx_xpm_file_to_image(event->mlx,
			event->player_down.path, &event->player_down.width,
			&event->player_down.height);
	event->player_left.img = mlx_xpm_file_to_image(event->mlx,
			event->player_left.path, &event->player_left.width,
			&event->player_left.height);
	event->bg.img = mlx_xpm_file_to_image(event->mlx, event->bg.path,
			&event->bg.width, &event->bg.height);
}

void	init_pixelize_img(t_event *event)
{
	event->bg.data = mlx_get_data_addr(event->bg.img, &event->bg.bpp,
			&event->bg.size_line, &event->bg.endian);
	event->player_right.data = mlx_get_data_addr(event->player_right.img,
			&event->player_right.bpp, &event->player_right.size_line,
			&event->player_right.endian);
	event->tile.data = mlx_get_data_addr(event->mlx, &event->tile.bpp,
			&event->tile.size_line, &event->tile.endian);
}

void	init_put_img(t_event *event)
{
	init_get_img(event);
	init_pixelize_img(event);
	mlx_put_image_to_window(event->mlx, event->window, event->bg.img, 0, 0);
}

void	init_loop(t_event *event)
{
	mlx_hook(event->window, KeyPress, KeyPressMask, on_key_press, event);
	mlx_hook(event->window, KeyRelease, KeyReleaseMask, on_key_release, event);
	mlx_loop_hook(event->mlx, update_key_press, event);
	check_up(event);
	mlx_loop(event->mlx);
}
