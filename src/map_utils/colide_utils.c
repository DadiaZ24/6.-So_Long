/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colide_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:53:16 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/28 17:19:58 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_up(t_event *event)
{
	if ((event->map[(event->y) / 64][(event->x / 64) + 1] == '1') || (event->map[(event->y) / 64][(event->x/ 64)] == '1'))
		return (0);
	return (1);
}

int	check_down(t_event *event)
{
	if ((event->map[(event->y / 64) + 1][(event->x / 64) + 1] == '1') || (event->map[(event->y / 64) + 1][(event->x/ 64)] == '1'))
		return (0);
	return (1);
}

int	check_right(t_event *event)
{
	if ((event->map[(event->y / 64)][(event->x / 64) + 1] == '1') || (event->map[(event->y / 64) + 1][(event->x/ 64) + 1] == '1'))
		return (0);
	return (1);
}

int	check_left(t_event *event)
{
	if ((event->map[(event->y / 64)][(event->x / 64)] == '1') || (event->map[(event->y / 64) + 1][(event->x/ 64)] == '1'))
		return (0);
	return (1);
}
