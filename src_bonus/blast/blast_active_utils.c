/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blast_active_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:41:12 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/22 20:57:31 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	shot_blast_down(t_event *event)
{
	mlx_destroy_image(event->mlx, event->blast.img);
	event->blast.img = mlx_xpm_file_to_image(event->mlx,
			event->blast.path, &event->blast.width, &event->blast.height);
	event->blast.data = mlx_get_data_addr(event->blast.img,
			&event->blast.bpp, &event->blast.size_line, &event->blast.endian);
	replace_black_pixels(&event->blast, &event->bg, event->x,
		event->y);
	mlx_put_image_to_window(event->mlx, event->window,
		event->blast.img, event->x, event->y + event->blast_pos + 100);
	event->blast_pos += 4;
	return (0);
}

int	shot_blast_up(t_event *event)
{
	mlx_destroy_image(event->mlx, event->blast.img);
	event->blast.img = mlx_xpm_file_to_image(event->mlx,
			event->blast.path, &event->blast.width, &event->blast.height);
	event->blast.data = mlx_get_data_addr(event->blast.img,
			&event->blast.bpp, &event->blast.size_line, &event->blast.endian);
	replace_black_pixels(&event->blast, &event->bg, event->x,
		event->y);
	mlx_put_image_to_window(event->mlx, event->window,
		event->blast.img, event->x, event->y - event->blast_pos - 100);
	event->blast_pos += 4;
	return (0);
}

int	shot_blast_right(t_event *event)
{
	mlx_destroy_image(event->mlx, event->blast.img);
	event->blast.img = mlx_xpm_file_to_image(event->mlx,
			event->blast.path, &event->blast.width, &event->blast.height);
	event->blast.data = mlx_get_data_addr(event->blast.img,
			&event->blast.bpp, &event->blast.size_line, &event->blast.endian);
	replace_black_pixels(&event->blast, &event->bg,
		event->x + event->blast_pos + 100, event->y + 45);
	mlx_put_image_to_window(event->mlx, event->window,
		event->blast.img, event->x + event->blast_pos + 100, event->y + 45);
	event->blast_pos += 10;
	return (0);
}

int	shot_blast_left(t_event *event)
{
	mlx_destroy_image(event->mlx, event->blast.img);
	event->blast.img = mlx_xpm_file_to_image(event->mlx,
			event->blast.path, &event->blast.width, &event->blast.height);
	event->blast.data = mlx_get_data_addr(event->blast.img,
			&event->blast.bpp, &event->blast.size_line, &event->blast.endian);
	replace_black_pixels(&event->blast, &event->bg,
		event->x, event->y);
	mlx_put_image_to_window(event->mlx, event->window,
		event->blast.img, event->x - event->blast_pos - 100, event->y + 45);
	event->blast_pos += 10;
	return (0);
}

int	animate_blast(t_event *event)
{
	if (event->blast_active == 1 && event->blast_pos < 350)
		shot_blast_down(event);
	else if (event->blast_active == 2 && event->blast_pos < 350)
		shot_blast_up(event);
	else if (event->blast_active == 3 && event->blast_pos < 350)
		shot_blast_right(event);
	else if (event->blast_active == 4 && event->blast_pos < 350)
		shot_blast_left(event);
	else
	{
		if (event->blast_active == 1)
			shot_blast_down_inactivate(event);
		if (event->blast_active == 2)
			shot_blast_up_inactivate(event);
		if (event->blast_active == 3)
			shot_blast_right_inactivate(event);
		if (event->blast_active == 4)
			shot_blast_left_inactivate(event);
	}
	return (0);
}
