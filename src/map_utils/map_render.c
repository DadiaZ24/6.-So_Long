/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:48:48 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/28 19:21:30 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	render_map(t_event *event)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < event->map_lines)
	{
		x = 0;
		while (x < event->map_columns)
		{
			render_corners(event, x, y);
			render_sides(event, x, y);
			render_stuff(event, x, y);
			x++;
		}
		y++;
	}
}

void	render_stuff(t_event *event, int x, int y)
{
	if (x != 0 && x != event->map_columns - 1 && y != 0 && y != event->map_lines - 1)
	{
		if (event->map[y][x] == '1')
			put_tile(event->tile.path, event, x * MAP_RES, y * MAP_RES);
		else if (event->map[y][x] == 'P')
		{
			mlx_put_image_to_window(event->mlx, event->window,
				event->player_right.img, x * MAP_RES, y * MAP_RES);
			event->x = x * MAP_RES;
			event->y = y * MAP_RES;
		}
	}
}

void	render_corners(t_event *event, int x, int y)
{
	if (x == 0 && y == 0)
		put_tile("img/tiletl.xpm", event, x * MAP_RES, y * MAP_RES);
	else if (x== 0 && y == event->map_lines - 1)
		put_tile("img/tilebl.xpm", event, x * MAP_RES, y * MAP_RES);
	else if (x == event->map_columns - 1 && y == 0)
		put_tile("img/tiletr.xpm", event, x * MAP_RES, y * MAP_RES);
	else if (x == event->map_columns - 1 && y == event->map_lines - 1)
		put_tile("img/tilebr.xpm", event, x * MAP_RES, y * MAP_RES);
}

void	render_sides(t_event *event, int x, int y)
{
	if (x == 0 && y != 0 && (y != event->map_lines - 1))
		put_tile("img/tilel.xpm", event, x * MAP_RES, y * MAP_RES);
	else if (x== event->map_columns - 1 && y != 0 && (y != event->map_lines - 1))
		put_tile("img/tiler.xpm", event, x * MAP_RES, y * MAP_RES);
	else if (y == 0 && x != 0 && (x != event->map_columns - 1))
		put_tile("img/tileu.xpm", event, x * MAP_RES, y * MAP_RES);
	else if (y == event->map_lines - 1 && x != 0 && (x != event->map_columns - 1))
		put_tile("img/tiled.xpm", event, x * MAP_RES, y * MAP_RES);
}
