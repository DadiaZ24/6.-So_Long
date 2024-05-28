/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:44:34 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/28 19:26:11 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	put_tile(char *path, t_event *event, int x, int y)
{
	mlx_destroy_image(event->mlx, event->tile.img);
	event->tile.img = mlx_xpm_file_to_image(event->mlx,
			path, &event->tile.width, &event->tile.height);
	event->tile.data = mlx_get_data_addr(event->tile.img,
			&event->tile.bpp, &event->tile.size_line,
			&event->tile.endian);
	replace_black_pixels(&event->tile, &event->bg, x, y);
	mlx_put_image_to_window(event->mlx, event->window,
		event->tile.img, x, y);
	return (0);
}