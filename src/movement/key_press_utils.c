/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:42:45 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/22 19:18:52 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	key_press_down(t_event *event)
{
	event->move_down_trigger = 1;
	event->display = 1;
	return (0);
}

int	key_press_up(t_event *event)
{
	event->move_up_trigger = 1;
	event->display = 2;
	return (0);
}

int	key_press_right(t_event *event)
{
	event->move_right_trigger = 1;
	event->display = 3;
	return (0);
}

int	key_press_left(t_event *event)
{
	event->move_left_trigger = 1;
	event->display = 4;
	return (0);
}

int	key_press_space(t_event *event)
{
	if (event->display == 1)
		event->blast_active = 1;
	if (event->display == 2)
		event->blast_active = 2;
	if (event->display == 3)
		event->blast_active = 3;
	if (event->display == 4)
		event->blast_active = 4;
	event->blast_pos = 0;
	return (0);
}
