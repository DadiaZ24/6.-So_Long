/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:35:07 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/22 20:58:08 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	trigger_move_down(t_event *event)
{
	event->y += 3;
	event->display = 1;
	mlx_destroy_image(event->mlx, event->player_down.img);
	event->player_down.img = mlx_xpm_file_to_image(event->mlx,
			event->player_down.path, &event->player_down.width,
			&event->player_down.height);
	event->player_down.data = mlx_get_data_addr(event->player_down.img,
			&event->player_down.bpp, &event->player_down.size_line,
			&event->player_down.endian);
	replace_black_pixels(&event->player_down, &event->bg, event->x, event->y);
	mlx_put_image_to_window(event->mlx, event->window,
		event->player_down.img, event->x, event->y);
	return (0);
}

int	trigger_move_up(t_event *event)
{
	event->display = 2;
	event->y -= 3;
	mlx_destroy_image(event->mlx, event->player_up.img);
	event->player_up.img = mlx_xpm_file_to_image(event->mlx,
			event->player_up.path, &event->player_up.width,
			&event->player_up.height);
	event->player_up.data = mlx_get_data_addr(event->player_up.img,
			&event->player_up.bpp, &event->player_up.size_line,
			&event->player_up.endian);
	replace_black_pixels(&event->player_up, &event->bg, event->x, event->y);
	mlx_put_image_to_window(event->mlx, event->window,
		event->player_up.img, event->x, event->y);
	return (0);
}

int	trigger_move_right(t_event *event)
{
	event->display = 3;
	event->x += 3;
	mlx_destroy_image(event->mlx, event->player_right.img);
	event->player_right.img = mlx_xpm_file_to_image(event->mlx,
			event->player_right.path, &event->player_right.width,
			&event->player_right.height);
	event->player_right.data = mlx_get_data_addr(event->player_right.img,
			&event->player_right.bpp, &event->player_right.size_line,
			&event->player_right.endian);
	replace_black_pixels(&event->player_right, &event->bg, event->x, event->y);
	mlx_put_image_to_window(event->mlx, event->window,
		event->player_right.img, event->x, event->y);
	return (0);
}

int	trigger_move_left(t_event *event)
{
	event->display = 4;
	event->x -= 3;
	mlx_destroy_image(event->mlx, event->player_left.img);
	event->player_left.img = mlx_xpm_file_to_image(event->mlx,
			event->player_left.path, &event->player_left.width,
			&event->player_left.height);
	event->player_left.data = mlx_get_data_addr(event->player_left.img,
			&event->player_left.bpp, &event->player_left.size_line,
			&event->player_left.endian);
	replace_black_pixels(&event->player_left, &event->bg, event->x, event->y);
	mlx_put_image_to_window(event->mlx, event->window,
		event->player_left.img, event->x, event->y);
	return (0);
}
