/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:50:38 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/06/04 15:52:51 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	colide_move_up(t_event *event)
{
	if (event->parser.colects)
		return (check_up(event));
	else
		return (check_up_no_colects(event));
	return (0);
}

int	colide_move_down(t_event *event)
{
	if (event->parser.colects)
		return (check_down(event));
	else
		return (check_down_no_colects(event));
	return (0);
}

int	colide_move_right(t_event *event)
{
	if (event->parser.colects)
		return (check_right(event));
	else
		return (check_right_no_colects(event));
	return (0);
}

int	colide_move_left(t_event *event)
{
	if (event->parser.colects)
		return (check_left(event));
	else
		return (check_left_no_colects(event));
	return (0);
}
