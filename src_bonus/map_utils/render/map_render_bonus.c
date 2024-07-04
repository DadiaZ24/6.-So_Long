/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:48:48 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/04 16:08:34 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long_bonus.h"

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
				return(ft_printf(ERROR_FILE_PATH, BLUE, ERROR_TOP, RED,
					DEFAULT_COLOR, BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
			if (!render_sides(event, x, y))
				return(ft_printf(ERROR_FILE_PATH, BLUE, ERROR_TOP, RED,
					DEFAULT_COLOR, BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
			if (!render_stuff(event, x, y))
				return(ft_printf(ERROR_FILE_PATH, BLUE, ERROR_TOP, RED,
					DEFAULT_COLOR, BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
			x++;
		}
		y++;
	}
	return (1);
}

int		render_stuff(t_event *event, int x, int y)
{
	if (x != 0 && x != event->map_columns - 1 && y != 0
		&& y != event->map_lines - 1)
	{
		if (event->map[y][x] == '1')
			if (!put_tile("img/tile.xpm", event, x * MAP_RES, y * MAP_RES))
				return(0);
		if (event->map[y][x] == 'C')
			if (!put_colectible("img/colect.xpm", event, x * MAP_RES, y * MAP_RES))
				return(0);
		if (event->map[y][x] == 'E')
			if (!put_tile("img/exit.xpm", event, x * MAP_RES, y * MAP_RES))
				return(0);
		if (event->map[y][x] == 'X')
			if (!put_tile("img/enemy.xpm", event, x * MAP_RES, y * MAP_RES))
				return(0);
		if (event->map[y][x] == 'P')
		{
			replace_black_pixels(&event->player, &event->bg, x * MAP_RES, y * MAP_RES);
			mlx_put_image_to_window(event->mlx, event->window,
				event->player.img, x * MAP_RES, y * MAP_RES);
			event->x = x * MAP_RES;
			event->y = y * MAP_RES;
		}
	}
	return (1);
}

int	render_corners(t_event *event, int x, int y)
{
	if (x == 0 && y == 0)
		if (!put_tile("img/tiletl.xpm", event, x * MAP_RES, y * MAP_RES))
			return (0);
	if (x == 0 && y == event->map_lines - 1)
		if (!put_tile("img/tilebl.xpm", event, x * MAP_RES, y * MAP_RES))
			return (0);
	if (x == event->map_columns - 1 && y == 0)
		if (!put_tile("img/tiletr.xpm", event, x * MAP_RES, y * MAP_RES))
			return (0);
	if (x == event->map_columns - 1 && y == event->map_lines - 1)
		if (!put_tile("img/tilebr.xpm", event, x * MAP_RES, y * MAP_RES))
			return (0);
	return (1);
}

int	render_sides(t_event *event, int x, int y)
{
	if (x == 0 && y != 0 && (y != event->map_lines - 1))
		if (!put_tile("img/tilel.xpm", event, x * MAP_RES, y * MAP_RES))
			return (0);
	if (x == event->map_columns - 1 && y != 0 && (y != event->map_lines - 1))
		if (!put_tile("img/tiler.xpm", event, x * MAP_RES, y * MAP_RES))
			return (0);
	if (y == 0 && x != 0 && (x != event->map_columns - 1))
		if (!put_tile("img/tileu.xpm", event, x * MAP_RES, y * MAP_RES))
			return (0);
	if (y == event->map_lines - 1 && x != 0 && (x != event->map_columns - 1))
		if (!put_tile("img/tiled.xpm", event, x * MAP_RES, y * MAP_RES))
			return (0);
	return (1);
}
