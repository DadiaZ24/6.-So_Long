/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blast_inactive_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:02:50 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/22 20:50:17 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	shot_blast_down_inactivate(t_event *event)
{
	event->blast_active = 0;
	mlx_destroy_image(event->mlx, event->blast.img);
	event->blast.img = mlx_xpm_file_to_image(event->mlx,
			event->blast.path, &event->blast.width, &event->blast.height);
	mlx_clear_window(event->mlx, event->window);
	event->blast.erase = 1;
	replace_black_pixels(&event->blast, &event->bg, event->x, event->y);
	mlx_put_image_to_window(event->mlx, event->window, event->bg.img, 0, 0);
	return (0);
}

int	shot_blast_up_inactivate(t_event *event)
{
	event->blast_active = 0;
	mlx_destroy_image(event->mlx, event->blast.img);
	event->blast.img = mlx_xpm_file_to_image(event->mlx, event->blast.path,
			&event->blast.width, &event->blast.height);
	mlx_clear_window(event->mlx, event->window);
	event->blast.erase = 1;
	replace_black_pixels(&event->blast, &event->bg, event->x, event->y);
	mlx_put_image_to_window(event->mlx, event->window, event->bg.img, 0, 0);
	return (0);
}

int	shot_blast_right_inactivate(t_event *event)
{
	event->blast_active = 0;
	mlx_destroy_image(event->mlx, event->blast.img);
	event->blast.img = mlx_xpm_file_to_image(event->mlx, event->blast.path,
			&event->blast.width, &event->blast.height);
	event->blast.erase = 1;
	replace_black_pixels(&event->blast, &event->bg,
		event->x + event->blast_pos + 100, event->y + 45);
	mlx_put_image_to_window(event->mlx, event->window,
		event->blast.img, event->x + event->blast_pos + 100, event->y + 45);
	return (0);
}

int	shot_blast_left_inactivate(t_event *event)
{
	event->blast_active = 0;
	mlx_destroy_image(event->mlx, event->blast.img);
	event->blast.img = mlx_xpm_file_to_image(event->mlx,
			event->blast.path, &event->blast.width, &event->blast.height);
	mlx_clear_window(event->mlx, event->window);
	event->blast.erase = 1;
	replace_black_pixels(&event->blast, &event->bg,
		event->x, event->y);
	mlx_put_image_to_window(event->mlx, event->window,
		event->bg.img, 0, 0);
	mlx_put_image_to_window(event->mlx, event->window,
		event->player_left.img, event->x, event->y);
	return (0);
}
