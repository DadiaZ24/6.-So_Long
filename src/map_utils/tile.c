/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:44:34 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/24 19:55:22 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	close_map_tile(t_event *event)
{
	int	fd;
	int	i;

	i = 0;
	event->map = malloc(sizeof(char *) * (event->map_lines));
	fd = open(event->chosen_map, O_RDONLY);
	event->map[i] = get_next_line(fd);
	while (++i < event->map_lines)
		event->map[i] = get_next_line(fd);
	close(fd);
}

int	put_tile(t_event *event, int x, int y)
{
	mlx_destroy_image(event->mlx, event->tile.img);
	event->tile.img = mlx_xpm_file_to_image(event->mlx,
			event->tile.path, &event->tile.width,
			&event->tile.height);
	event->tile.data = mlx_get_data_addr(event->tile.img,
			&event->tile.bpp, &event->tile.size_line,
			&event->tile.endian);
	replace_black_pixels(&event->tile, &event->bg, x, y);
	mlx_put_image_to_window(event->mlx, event->window,
		event->tile.img, x, y);
	return (0);
}