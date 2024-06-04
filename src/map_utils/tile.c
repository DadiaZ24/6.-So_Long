/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:44:34 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/31 17:54:46 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	put_tile(char *path, t_event *event, int x, int y)
{
	if (event->tile.img)
	{
		mlx_destroy_image(event->mlx, event->tile.img);
		event->tile.img = NULL;
	}
	event->tile.img = mlx_xpm_file_to_image(event->mlx,
			path, &event->tile.width, &event->tile.height);
	event->tile.data = mlx_get_data_addr(event->tile.img,
			&event->tile.bpp, &event->tile.size_line,
			&event->tile.endian);
	if (!event->tile.data)
	{
		mlx_destroy_image(event->mlx, event->tile.img);
		return (-1);
	}
	replace_black_pixels(&event->tile, &event->bg, x, y);
	mlx_put_image_to_window(event->mlx, event->window,
		event->tile.img, x, y);
	return (0);
}
int	put_colectible(char *path, t_event *event, int x, int y)
{
	if (event->colect.img)
	{
		mlx_destroy_image(event->mlx, event->colect.img);
		event->colect.img = NULL;
	}
	event->colect.img = mlx_xpm_file_to_image(event->mlx,
			path, &event->colect.width, &event->colect.height);
	event->colect.data = mlx_get_data_addr(event->colect.img,
			&event->colect.bpp, &event->colect.size_line,
			&event->colect.endian);
	if (!event->colect.data)
	{
		mlx_destroy_image(event->mlx, event->colect.img);
		return (-1);
	}
	//replace_black_pixels(&event->colect, &event->bg, x, y);
	mlx_put_image_to_window(event->mlx, event->window,
		event->colect.img, x, y);
	event->colect.x = x + 32;
	event->colect.y = y + 32;
	return (0);
}