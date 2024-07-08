/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:54:06 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 16:06:33 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long_bonus.h"

void	is_in_exit_space_right(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->parser.colects == 0 && event->move_right_trigger)
	{
		if (event->map[(event->y) / RES][(event->x + 59) / RES] == 'E')
		{
			x = (event->x + 59) / RES;
			y = (event->y) / RES;
			exit_sprite(event, x * RES, y * RES);
			destroy_stuff(event);
		}
		else if (event->map[(event->y + 44) / RES]
			[(event->x + 59) / RES] == 'E')
		{
			x = (event->x + 59) / RES;
			y = (event->y + 44) / RES;
			exit_sprite(event, x * RES, y * RES);
			destroy_stuff(event);
		}
	}
}

void	is_in_exit_space_left(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->parser.colects == 0 && event->move_left_trigger)
	{
		if (event->map[(event->y) / RES][(event->x + 5) / RES] == 'E')
		{
			x = (event->x + 5) / RES;
			y = (event->y) / RES;
			exit_sprite(event, x * RES, y * RES);
			destroy_stuff(event);
		}
		else if (event->map[(event->y + 44) / RES][(event->x + 5) / RES] == 'E')
		{
			x = (event->x + 5) / RES;
			y = (event->y + 44) / RES;
			exit_sprite(event, x * RES, y * RES);
			destroy_stuff(event);
		}
	}
}

void	is_in_exit_space_up(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->parser.colects == 0 && event->move_up_trigger)
	{
		if (event->map[(event->y + 5) / RES][(event->x) / RES] == 'E')
		{
			x = (event->x) / RES;
			y = (event->y + 5) / RES;
			exit_sprite(event, x * RES, y * RES);
			destroy_stuff(event);
		}
		else if (event->map[(event->y + 5) / RES][(event->x + 44) / RES] == 'E')
		{
			x = (event->x + 44) / RES;
			y = (event->y + 5) / RES;
			exit_sprite(event, x * RES, y * RES);
			destroy_stuff(event);
		}
	}
}

void	is_in_exit_space_down(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->parser.colects == 0 && event->move_down_trigger)
	{
		if (event->map[(event->y + 59) / RES][(event->x) / RES] == 'E')
		{
			x = (event->x) / RES;
			y = (event->y + 59) / RES;
			exit_sprite(event, x * RES, y * RES);
			destroy_stuff(event);
		}
		else if (event->map[(event->y + 59) / RES]
			[(event->x + 44) / RES] == 'E')
		{
			x = (event->x + 44) / RES;
			y = (event->y + 59) / RES;
			exit_sprite(event, x * RES, y * RES);
			destroy_stuff(event);
		}
	}
}
