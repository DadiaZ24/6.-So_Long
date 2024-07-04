/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:42:45 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/04 17:06:45 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	key_press_down(t_event *event)
{
	event->move_down_trigger = 1;
	event->move_left_trigger = 0;
	event->move_right_trigger = 0;
	event->move_up_trigger = 0;
	return (0);
}

int	key_press_up(t_event *event)
{
	event->move_up_trigger = 1;
	event->move_left_trigger = 0;
	event->move_right_trigger = 0;
	event->move_down_trigger = 0;
	return (0);
}

int	key_press_right(t_event *event)
{
	event->move_right_trigger = 1;
	event->move_left_trigger = 0;
	event->move_down_trigger = 0;
	event->move_up_trigger = 0;
	return (0);
}

int	key_press_left(t_event *event)
{
	event->move_left_trigger = 1;
	event->move_down_trigger = 0;
	event->move_right_trigger = 0;
	event->move_up_trigger = 0;
	return (0);
}
