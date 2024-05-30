/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colide_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:53:16 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/30 17:19:04 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_up(t_event *event)
{
	if (!check_right(event))
	{
		if (event->map[(event->y / MAP_RES)][((event->x + 2) / MAP_RES)] == '1')
			return(0);
	}
	else if (!check_left(event))
	{
		if (event->map[(event->y / MAP_RES)][((event->x - 2) / MAP_RES) + 1] == '1')
			return(0);
	}
	else
	{
		if ((event->map[(event->y) / MAP_RES][(event->x / MAP_RES) + 1] == '1')
				|| (event->map[(event->y) / MAP_RES][(event->x / MAP_RES)] == '1'))
			return (0);
	}
	return (1);
}

int	check_down(t_event *event)
{
	printf("CHECK RIGHT == [%d]\n", check_right(event));
	char *str = "(event->y / MAP_RES) + 1";
	int i = (event->y / MAP_RES) + 1;
	printf("%s == [%d]\n", str, i);
	str = "(event->x + 2 / MAP_RES)";
	i = ((event->x - 2) / MAP_RES);
	printf("%s == [%d]\n", str, i);
	if (!check_right(event))
	{
		if (event->map[(event->y / MAP_RES) + 1][((event->x + 2) / MAP_RES)] == '1')
			return(0);
	}
	else if (!check_left(event))
	{
		if (event->map[(event->y / MAP_RES) + 1][((event->x - 2) / MAP_RES) + 1] == '1')
			return(0);
	}
	else
	{
		if ((event->map[((event->y + 2) / MAP_RES) + 1][(event->x / MAP_RES) + 1] == '1')
				|| (event->map[((event->y + 2) / MAP_RES) + 1][(event->x / MAP_RES)] == '1'))
			return (0);
	}
	return (1);
}

int	check_right(t_event *event)
{
	if (!temp_check_up(event))
	{
		if (event->map[(event->y + 2) / MAP_RES][(event->x / MAP_RES) + 1] == '1')
			return(0);
	}
	else if (!temp_check_down(event))
	{
		if (event->map[(event->y - 2) / MAP_RES + 1][(event->x / MAP_RES) + 1] == '1')
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

int	check_left(t_event *event)
{
	if (!temp_check_up(event))
	{
		if (event->map[(event->y + 2) / MAP_RES][(event->x / MAP_RES)] == '1')
			return(0);
	}
	else if (!temp_check_down(event))
	{
		if (event->map[((event->y - 2) / MAP_RES) + 1][(event->x / MAP_RES)] == '1')
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
