/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:50:38 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/06/25 16:14:32 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"
/**
 * @brief Checks if player collides when moving up, considering collectibles.
 * 
 * If there are collectibles:
 * - Calls check_up(event).
 * If no collectibles:
 * - Calls check_up_no_colects(event).
 * 
 * @param event The event struct containing player and game state.
 * @return 0 if collision blocks movement, 1 otherwise.
 */
int	colide_move_up(t_event *event)
{
	if (event->parser.colects)
		return (check_up(event));
	else
		return (check_up_no_colects(event));
	return (0);
}
/**
 * @brief Checks if player collides when moving down, considering collectibles.
 * 
 * If there are collectibles:
 * - Calls check_down(event).
 * If no collectibles:
 * - Calls check_down_no_colects(event).
 * 
 * @param event The event struct containing player and game state.
 * @return 0 if collision blocks movement, 1 otherwise.
 */
int	colide_move_down(t_event *event)
{
	if (event->parser.colects)
		return (check_down(event));
	else
		return (check_down_no_colects(event));
	return (0);
}
/**
 * @brief Checks if player collides when moving right, considering collectibles.
 * 
 * If there are collectibles:
 * - Calls check_right(event).
 * If no collectibles:
 * - Calls check_right_no_colects(event).
 * 
 * @param event The event struct containing player and game state.
 * @return 0 if collision blocks movement, 1 otherwise.
 */
int	colide_move_right(t_event *event)
{
	if (event->parser.colects)
		return (check_right(event));
	else
		return (check_right_no_colects(event));
	return (0);
}
/**
 * @brief Checks if player collides when moving left, considering collectibles.
 * 
 * If there are collectibles:
 * - Calls check_left(event).
 * If no collectibles:
 * - Calls check_left_no_colects(event).
 * 
 * @param event The event struct containing player and game state.
 * @return 0 if collision blocks movement, 1 otherwise.
 */
int	colide_move_left(t_event *event)
{
	if (event->parser.colects)
		return (check_left(event));
	else
		return (check_left_no_colects(event));
	return (0);
}
