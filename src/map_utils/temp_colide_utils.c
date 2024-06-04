/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_colide_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:02:32 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/06/04 15:35:44 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	temp_check_up_no_colect(t_event *event)
{
	if ((event->map[(event->y) / MAP_RES][(event->x / MAP_RES) + 1] == '1')
			|| (event->map[(event->y) / MAP_RES][(event->x / MAP_RES)] == '1'))
		return (0);
	return (1);
}

int	temp_check_down_no_colect(t_event *event)
{
	if (((event->map[((event->y + 2) / MAP_RES) + 1][(event->x / MAP_RES) + 1] == '1'))
			|| (event->map[((event->y + 2) / MAP_RES) + 1][(event->x / MAP_RES)] == '1'))
		return (0);
	return (1);
}

int	temp_check_down(t_event *event)
{
	if (((event->map[((event->y + 2) / MAP_RES) + 1][(event->x / MAP_RES) + 1] == '1')
			|| (event->map[((event->y + 2) / MAP_RES) + 1][(event->x / MAP_RES) + 1] == 'E'))
			|| ((event->map[((event->y + 2) / MAP_RES) + 1][(event->x / MAP_RES)] == '1')
			|| (event->map[((event->y + 2) / MAP_RES) + 1][(event->x / MAP_RES)] == 'E')))
		return (0);
	return (1);
}

int	temp_check_up(t_event *event)
{
	if (((event->map[(event->y) / MAP_RES][(event->x / MAP_RES) + 1] == '1')
			|| (event->map[(event->y) / MAP_RES][(event->x / MAP_RES) + 1] == 'E'))
			|| ((event->map[(event->y) / MAP_RES][(event->x / MAP_RES)] == '1')
			|| (event->map[(event->y) / MAP_RES][(event->x / MAP_RES)] == 'E')))
		return (0);
	return (1);
}
