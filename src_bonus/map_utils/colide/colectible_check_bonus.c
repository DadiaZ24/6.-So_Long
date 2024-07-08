/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colectible_check_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:50:08 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 15:56:29 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long_bonus.h"

void	is_in_colectible_space_right(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->move_right_trigger)
	{
		if (event->map[(event->y + 2) / RES][(event->x + 40) / RES] == 'C')
		{
			x = (event->x + 40) / RES;
			y = (event->y + 2) / RES;
			event->parser.colects -= 1;
			event->map[y][x] = '0';
			put_tile("textures/colected.xpm", event, x * RES, y * RES);
		}
		else if (event->map[(event->y + 44) / RES]
			[(event->x + 40) / RES] == 'C')
		{
			x = (event->x + 40) / RES;
			y = (event->y + 44) / RES;
			event->parser.colects -= 1;
			event->map[y][x] = '0';
			put_tile("textures/colected.xpm", event, x * RES, y * RES);
		}
	}
}

void	is_in_colectible_space_left(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->move_left_trigger)
	{
		if (event->map[(event->y + 2) / RES][(event->x - 40) / RES] == 'C')
		{
			x = (event->x - 40) / RES;
			y = (event->y + 2) / RES;
			event->parser.colects -= 1;
			event->map[y][x] = '0';
			put_tile("textures/colected.xpm", event, x * RES, y * RES);
		}
		else if (event->map[(event->y + 44) / RES]
			[(event->x - 40) / RES] == 'C')
		{
			x = (event->x - 40) / RES;
			y = (event->y + 44) / RES;
			event->parser.colects -= 1;
			event->map[y][x] = '0';
			put_tile("textures/colected.xpm", event, x * RES, y * RES);
		}
	}
}

void	is_in_colectible_space_up(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->move_up_trigger)
	{
		if (event->map[(event->y - 40) / RES][(event->x + 2) / RES] == 'C')
		{
			x = (event->x + 2) / RES;
			y = (event->y - 40) / RES;
			event->parser.colects -= 1;
			event->map[y][x] = '0';
			put_tile("textures/colected.xpm", event, x * RES, y * RES);
		}
		else if (event->map[(event->y - 40) / RES]
			[(event->x + 44) / RES] == 'C')
		{
			x = (event->x + 44) / RES;
			y = (event->y - 40) / RES;
			event->parser.colects -= 1;
			event->map[y][x] = '0';
			put_tile("textures/colected.xpm", event, x * RES, y * RES);
		}
	}
}

void	is_in_colectible_space_down(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->move_down_trigger)
	{
		if (event->map[(event->y + 40) / RES][(event->x + 2) / RES] == 'C')
		{
			x = (event->x + 2) / RES;
			y = (event->y + 40) / RES;
			event->parser.colects -= 1;
			event->map[y][x] = '0';
			put_tile("textures/colected.xpm", event, x * RES, y * RES);
		}
		else if (event->map[(event->y + 40) / RES]
			[(event->x + 44) / RES] == 'C')
		{
			x = (event->x + 44) / RES;
			y = (event->y + 40) / RES;
			event->parser.colects -= 1;
			event->map[y][x] = '0';
			put_tile("textures/colected.xpm", event, x * RES, y * RES);
		}
	}
}
