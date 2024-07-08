/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colide_utils_colects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:28:09 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 15:32:29 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	check_up(t_event *event, int x, int y)
{
	if (!check_right(event, x, y) && !check_left(event, x, y))
		if ((event->map[(y / RES) + 1][(x / RES) + 1] == '1')
				|| (event->map[(y / RES) + 1][((x) / RES) + 1] == 'E'))
			return (0);
	if (!check_right(event, x, y))
		if ((event->map[(y / RES)][((x + 8) / RES)] == '1')
				|| (event->map[(y / RES)][((x + 8) / RES)] == 'E'))
			return (0);
	if (!check_left(event, x, y))
	{
		if ((event->map[(y / RES)][((x - 8) / RES) + 1] == '1')
				|| (event->map[(y / RES)][((x - 8) / RES) + 1] == 'E'))
			return (0);
	}
	else
		if (((event->map[(y) / RES][((x + 8) / RES)] == '1')
			|| (event->map[(y) / RES][((x + 8) / RES)] == 'E'))
			|| ((event->map[(y) / RES][((x - 8) / RES) + 1] == '1')
			|| (event->map[(y) / RES][((x - 8) / RES) + 1] == 'E')))
			return (0);
	return (1);
}

int	check_down(t_event *event, int x, int y)
{
	if (!check_right(event, x, y) && !check_left(event, x, y))
		if ((event->map[(y / RES) + 1][((x) / RES) + 1] == '1')
				|| (event->map[(y / RES) + 1][((x) / RES) + 1] == 'E'))
			return (0);
	if (!check_right(event, x, y))
		if ((event->map[(y / RES) + 1][((x + 8) / RES)] == '1')
				|| (event->map[(y / RES) + 1][((x + 8) / RES)] == 'E'))
			return (0);
	if (!check_left(event, x, y))
	{
		if ((event->map[(y / RES) + 1][((x - 8) / RES) + 1] == '1')
				|| (event->map[(y / RES) + 1]
				[((x - 8) / RES) + 1] == 'E'))
			return (0);
	}
	else
	{
		if (((event->map[((y + 2) / RES) + 1][((x - 8) / RES) + 1] == '1')
			|| (event->map[((y + 2) / RES) + 1][((x - 8) / RES) + 1] == 'E'))
			|| ((event->map[((y + 2) / RES) + 1][((x + 8) / RES)] == '1')
			|| (event->map[((y + 2) / RES) + 1][((x + 8) / RES)] == 'E')))
			return (0);
	}
	return (1);
}

int	check_right(t_event *event, int x, int y)
{
	if (!temp_check_up(event))
	{
		if ((event->map[(y + 8) / RES][(x / RES) + 1] == '1')
				|| (event->map[(y + 8) / RES][(x / RES) + 1] == 'E'))
			return (0);
	}
	else if (!temp_check_down(event))
	{
		if ((event->map[(y - 8) / RES + 1][(x / RES) + 1] == '1')
				|| (event->map[(y - 8) / RES + 1][(x / RES) + 1] == 'E'))
			return (0);
	}
	else
	{
		if (((event->map[((y + 8) / RES)][(x / RES)] == '1')
			|| (event->map[((y + 8) / RES)][(x / RES)] == 'E'))
			|| ((event->map[((y - 8) / RES) + 1][(x / RES) + 1] == '1')
			|| (event->map[((y - 8) / RES) + 1][(x / RES) + 1] == 'E')))
			return (0);
	}
	return (1);
}

int	check_left(t_event *event, int x, int y)
{
	if (!temp_check_up(event))
	{
		if ((event->map[(y + 8) / RES][(x / RES)] == '1')
				|| (event->map[(y + 8) / RES][(x / RES)] == 'E'))
			return (0);
	}
	else if (!temp_check_down(event))
	{
		if ((event->map[((y - 8) / RES) + 1][(x / RES)] == '1')
				|| (event->map[((y - 8) / RES) + 1][(x / RES)] == 'E'))
			return (0);
	}
	else
	{
		if (((event->map[((y + 8) / RES)][(x / RES)] == '1')
			|| (event->map[((y + 8) / RES)][(x / RES)] == 'E'))
			|| ((event->map[((y - 8) / RES) + 1][(x / RES)] == '1')
			|| (event->map[((y - 8) / RES) + 1][(x / RES)] == 'E')))
			return (0);
	}
	return (1);
}
