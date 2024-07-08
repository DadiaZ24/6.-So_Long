/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colide_utils_no_colects_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:53:16 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 16:04:57 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long_bonus.h"

int	check_up_no_colects(t_event *event)
{
	if (!check_right_no_colects(event))
	{
		if (event->map[(event->y / RES)][((event->x + 8) / RES)] == '1')
			return (0);
	}
	else if (!check_left_no_colects(event))
	{
		if (event->map[(event->y / RES)][((event->x - 8) / RES) + 1] == '1')
			return (0);
	}
	else
	{
		if ((event->map[(event->y) / RES][((event->x - 8) / RES) + 1] == '1')
				|| (event->map[(event->y) / RES]
				[((event->x + 8) / RES)] == '1'))
			return (0);
	}
	return (1);
}

int	check_down_no_colects(t_event *event)
{
	if (!check_right_no_colects(event))
	{
		if (event->map[(event->y / RES) + 1][((event->x + 8) / RES)] == '1')
			return (0);
	}
	else if (!check_left_no_colects(event))
	{
		if (event->map[(event->y / RES) + 1][((event->x - 8) / RES) + 1] == '1')
			return (0);
	}
	else
	{
		if ((event->map[((event->y + 2) / RES) + 1]
				[((event->x - 8) / RES) + 1] == '1')
			|| (event->map[((event->y + 2) / RES) + 1]
				[((event->x + 8) / RES)] == '1'))
			return (0);
	}
	return (1);
}

int	check_right_no_colects(t_event *event)
{
	if (!temp_check_up_no_colect(event))
	{
		if (event->map[(event->y + 8) / RES][(event->x / RES) + 1] == '1')
			return (0);
	}
	else if (!temp_check_down_no_colect(event))
	{
		if (event->map[(event->y - 8) / RES + 1][(event->x / RES) + 1] == '1')
			return (0);
	}
	else
	{
		if ((event->map[((event->y + 8) / RES)][(event->x / RES)] == '1')
				|| (event->map[((event->y - 8) / RES) + 1]
				[(event->x / RES) + 1] == '1'))
			return (0);
	}
	return (1);
}

int	check_left_no_colects(t_event *event)
{
	if (!temp_check_up_no_colect(event))
	{
		if (event->map[(event->y + 8) / RES][(event->x / RES)] == '1')
			return (0);
	}
	else if (!temp_check_down_no_colect(event))
	{
		if (event->map[((event->y - 8) / RES) + 1][(event->x / RES)] == '1')
			return (0);
	}
	else
	{
		if ((event->map[((event->y + 8) / RES)][(event->x / RES)] == '1')
				|| (event->map[((event->y - 8) / RES) + 1]
				[(event->x / RES)] == '1'))
			return (0);
	}
	return (1);
}
