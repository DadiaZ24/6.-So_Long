/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colide_utils_colects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:28:09 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/06/04 15:39:23 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_up(t_event *event)
{
	if (!check_right(event))
	{
		
		if ((event->map[(event->y / MAP_RES)][((event->x + 5) / MAP_RES)] == '1')
				|| (event->map[(event->y / MAP_RES)][((event->x + 5) / MAP_RES)] == 'E'))
			return(0);
	}
	else if (!check_left(event))
	{
		if ((event->map[(event->y / MAP_RES)][((event->x - 5) / MAP_RES) + 1] == '1')
				|| (event->map[(event->y / MAP_RES)][((event->x - 5) / MAP_RES) + 1] == 'E'))
			return(0);
	}
	else
	{
		if (((event->map[(event->y) / MAP_RES][((event->x - 2) / MAP_RES) + 1] == '1')
				|| (event->map[(event->y) / MAP_RES][((event->x - 2) / MAP_RES) + 1] == 'E'))
				|| ((event->map[(event->y) / MAP_RES][((event->x - 2) / MAP_RES)] == '1')
				|| (event->map[(event->y) / MAP_RES][((event->x - 2) / MAP_RES)] == 'E')))
			return (0);
	}	
	return (1);
}

int	check_down(t_event *event)
{
	if (!check_right(event))
	{
		if ((event->map[(event->y / MAP_RES) + 1][((event->x) / MAP_RES)] == '1')
				|| (event->map[(event->y / MAP_RES) + 1][((event->x) / MAP_RES)] == 'E'))
			return(0);
	}
	else if (!check_left(event))
	{
		if ((event->map[(event->y / MAP_RES) + 1][((event->x - 5) / MAP_RES) + 1] == '1')
				|| (event->map[(event->y / MAP_RES) + 1][((event->x - 5) / MAP_RES) + 1] == 'E'))
			return(0);
	}
	else
	{
		if (((event->map[((event->y + 2) / MAP_RES) + 1][((event->x - 2 )/ MAP_RES) + 1] == '1')
				|| (event->map[((event->y + 2) / MAP_RES) + 1][((event->x - 2 )/ MAP_RES) + 1] == 'E'))
				|| ((event->map[((event->y + 2) / MAP_RES) + 1][((event->x - 2) / MAP_RES)] == '1')
				|| (event->map[((event->y + 2) / MAP_RES) + 1][((event->x - 2) / MAP_RES)] == 'E')))
			return (0);
	}
	return (1);
}

int	check_right(t_event *event)
{
	if (!temp_check_up(event))
	{
		if ((event->map[(event->y + 5) / MAP_RES][(event->x / MAP_RES) + 1] == '1')
				|| (event->map[(event->y + 5) / MAP_RES][(event->x / MAP_RES) + 1] == 'E'))
			return(0);
	}
	else if (!temp_check_down(event))
	{
		if ((event->map[(event->y - 5) / MAP_RES + 1][(event->x / MAP_RES) + 1] == '1')
				|| (event->map[(event->y - 5) / MAP_RES + 1][(event->x / MAP_RES) + 1] == 'E'))
			return(0);
	}
	else
	{
		if (((event->map[(event->y / MAP_RES)][(event->x / MAP_RES)] == '1')
				|| (event->map[(event->y / MAP_RES)][(event->x / MAP_RES)] == 'E'))
				|| ((event->map[(event->y / MAP_RES) + 1][(event->x / MAP_RES) + 1] == '1')
				|| (event->map[(event->y / MAP_RES) + 1][(event->x / MAP_RES) + 1] == 'E')))
			return (0);
	}
	return (1);
}

int	check_left(t_event *event)
{
	if (!temp_check_up(event))
	{
		if ((event->map[(event->y + 5) / MAP_RES][(event->x / MAP_RES)] == '1')
				|| (event->map[(event->y + 5) / MAP_RES][(event->x / MAP_RES)] == 'E'))
			return(0);
	}
	else if (!temp_check_down(event))
	{
		if ((event->map[((event->y - 5) / MAP_RES) + 1][(event->x / MAP_RES)] == '1')
				|| (event->map[((event->y - 5) / MAP_RES) + 1][(event->x / MAP_RES)] == 'E'))
			return(0);
	}
	else
	{
		if (((event->map[(event->y / MAP_RES)][(event->x / MAP_RES)] == '1')
				|| (event->map[(event->y / MAP_RES)][(event->x / MAP_RES)] == 'E'))
				|| ((event->map[(event->y / MAP_RES) + 1][(event->x / MAP_RES)] == '1')
				|| (event->map[(event->y / MAP_RES) + 1][(event->x / MAP_RES)] == 'E')))
			return (0);
	}
	return (1);
}
