/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:35:55 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 15:47:59 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_img_data(t_event *event)
{
	event->bg.path = "textures/bg.xpm";
	event->player.path = "textures/player_right.xpm";
}

int	init_get_img(t_event *event)
{
	init_img_data(event);
	event->player.img = mlx_xpm_file_to_image(event->mlx,
			event->player.path, &event->player.width,
			&event->player.height);
	if (!event->player.img)
		return (ft_printf(ERROR_FILE_PATH, BLUE, ERROR_TOP,
				RED, DEFAULT_COLOR,
				BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
	event->bg.img = mlx_xpm_file_to_image(event->mlx, event->bg.path,
			&event->bg.width, &event->bg.height);
	if (!event->bg.img)
		return (ft_printf(ERROR_FILE_PATH, BLUE, ERROR_TOP,
				RED, DEFAULT_COLOR,
				BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
	return (1);
}

void	init_pixelize_img(t_event *event)
{
	event->bg.data = mlx_get_data_addr(event->bg.img, &event->bg.bpp,
			&event->bg.size_line, &event->bg.endian);
	event->player.data = mlx_get_data_addr(event->player.img,
			&event->player.bpp, &event->player.size_line,
			&event->player.endian);
	event->tile.data = mlx_get_data_addr(event->mlx, &event->tile.bpp,
			&event->tile.size_line, &event->tile.endian);
}

void	init_put_img(t_event *event)
{
	if (!init_get_img(event))
		destroy_stuff(event);
	init_pixelize_img(event);
	mlx_put_image_to_window(event->mlx, event->window, event->bg.img, 0, 0);
}

void	init_loop(t_event *event)
{
	mlx_hook(event->window, KeyPress, KeyPressMask, on_key_press, event);
	mlx_hook(event->window, KeyRelease, KeyReleaseMask, on_key_release, event);
	mlx_hook(event->window, DestroyNotify, 0, destroy_stuff, event);
	mlx_loop_hook(event->mlx, update_key_press, event);
	mlx_loop(event->mlx);
}
