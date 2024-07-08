/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:48:48 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 15:47:59 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	render_map(t_event *event)
{
	int	x;
	int	y;

	y = 0;
	while (y < event->map_lines)
	{
		x = 0;
		while (x < event->map_columns)
		{
			if (!render_corners(event, x, y))
				return (ft_printf(ERROR_FILE_PATH, BLUE, ERROR_TOP, RED,
						DEFAULT_COLOR, BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
			if (!render_sides(event, x, y))
				return (ft_printf(ERROR_FILE_PATH, BLUE, ERROR_TOP, RED,
						DEFAULT_COLOR, BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
			if (!render_stuff(event, x, y))
				return (ft_printf(ERROR_FILE_PATH, BLUE, ERROR_TOP, RED,
						DEFAULT_COLOR, BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
			x++;
		}
		y++;
	}
	return (1);
}

int	render_stuff(t_event *event, int x, int y)
{
	if (x != 0 && x != event->map_columns - 1 && y != 0
		&& y != event->map_lines - 1)
	{
		if (event->map[y][x] == '1')
			if (!put_tile("textures/tile.xpm", event, x * RES, y * RES))
				return (0);
		if (event->map[y][x] == 'C')
			if (!put_colectible("textures/colect.xpm", event, x * RES, y * RES))
				return (0);
		if (event->map[y][x] == 'E')
			if (!put_tile("textures/exit.xpm", event, x * RES, y * RES))
				return (0);
		if (event->map[y][x] == 'P')
		{
			replace_black_pixels(&event->player, &event->bg, x * RES, y * RES);
			mlx_put_image_to_window(event->mlx, event->window,
				event->player.img, x * RES, y * RES);
			event->x = x * RES;
			event->y = y * RES;
		}
	}
	return (1);
}

int	render_corners(t_event *event, int x, int y)
{
	if (x == 0 && y == 0)
		if (!put_tile("textures/tiletl.xpm", event, x * RES, y * RES))
			return (0);
	if (x == 0 && y == event->map_lines - 1)
		if (!put_tile("textures/tilebl.xpm", event, x * RES, y * RES))
			return (0);
	if (x == event->map_columns - 1 && y == 0)
		if (!put_tile("textures/tiletr.xpm", event, x * RES, y * RES))
			return (0);
	if (x == event->map_columns - 1 && y == event->map_lines - 1)
		if (!put_tile("textures/tilebr.xpm", event, x * RES, y * RES))
			return (0);
	return (1);
}

int	render_sides(t_event *event, int x, int y)
{
	if (x == 0 && y != 0 && (y != event->map_lines - 1))
		if (!put_tile("textures/tilel.xpm", event, x * RES, y * RES))
			return (0);
	if (x == event->map_columns - 1 && y != 0 && (y != event->map_lines - 1))
		if (!put_tile("textures/tiler.xpm", event, x * RES, y * RES))
			return (0);
	if (y == 0 && x != 0 && (x != event->map_columns - 1))
		if (!put_tile("textures/tileu.xpm", event, x * RES, y * RES))
			return (0);
	if (y == event->map_lines - 1 && x != 0 && (x != event->map_columns - 1))
		if (!put_tile("textures/tiled.xpm", event, x * RES, y * RES))
			return (0);
	return (1);
}
