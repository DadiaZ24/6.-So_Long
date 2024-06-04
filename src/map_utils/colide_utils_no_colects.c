/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colide_utils_no_colects.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:53:16 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/06/04 15:40:30 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_up_no_colects(t_event *event)
{
	if (!check_right_no_colects(event))
	{
		
		if (event->map[(event->y / MAP_RES)][((event->x + 5) / MAP_RES)] == '1')
			return(0);
	}
	else if (!check_left_no_colects(event))
	{
		if (event->map[(event->y / MAP_RES)][((event->x - 5) / MAP_RES) + 1] == '1')
			return(0);
	}
	else
	{
		if ((event->map[(event->y) / MAP_RES][((event->x - 2) / MAP_RES) + 1] == '1')
				|| (event->map[(event->y) / MAP_RES][((event->x - 2) / MAP_RES)] == '1'))
			return (0);
	}	
	return (1);
}

int	check_down_no_colects(t_event *event)
{
	if (!check_right_no_colects(event))
	{
		if (event->map[(event->y / MAP_RES) + 1][((event->x) / MAP_RES)] == '1')
			return(0);
	}
	else if (!check_left_no_colects(event))
	{
		if (event->map[(event->y / MAP_RES) + 1][((event->x - 5) / MAP_RES) + 1] == '1')
			return(0);
	}
	else
	{
		if ((event->map[((event->y + 2) / MAP_RES) + 1][((event->x - 2 )/ MAP_RES) + 1] == '1')
				|| (event->map[((event->y + 2) / MAP_RES) + 1][((event->x - 2) / MAP_RES)] == '1'))
			return (0);
	}
	return (1);
}

int	check_right_no_colects(t_event *event)
{
	if (!temp_check_up_no_colect(event))
	{
		if (event->map[(event->y + 5) / MAP_RES][(event->x / MAP_RES) + 1] == '1')
			return(0);
	}
	else if (!temp_check_down_no_colect(event))
	{
		if (event->map[(event->y - 5) / MAP_RES + 1][(event->x / MAP_RES) + 1] == '1')
			return(0);
	}
	else
	{
		if ((event->map[(event->y / MAP_RES)][(event->x / MAP_RES)] == '1')
				|| (event->map[(event->y / MAP_RES) + 1][(event->x / MAP_RES) + 1] == '1'))
			return (0);
	}
	return (1);
}

int	check_left_no_colects(t_event *event)
{
	if (!temp_check_up_no_colect(event))
	{
		if (event->map[(event->y + 5) / MAP_RES][(event->x / MAP_RES)] == '1')
			return(0);
	}
	else if (!temp_check_down_no_colect(event))
	{
		if (event->map[((event->y - 5) / MAP_RES) + 1][(event->x / MAP_RES)] == '1')
			return(0);
	}
	else
	{
		if ((event->map[(event->y / MAP_RES)][(event->x / MAP_RES)] == '1')
				|| (event->map[(event->y / MAP_RES) + 1][(event->x / MAP_RES)] == '1'))
			return (0);
	}
	return (1);
}
