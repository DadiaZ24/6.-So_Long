/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:54:06 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/02 18:13:32 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"
/**
 * @brief Checks if player is in the exit space to the right without collectibles.
 * 
 * If no collectibles and player triggers right movement:
 * - Checks if 'E' tile is at (event->y) / MAP_RES][(event->x + 64) / MAP_RES] or
 *   [(event->y + 44) / MAP_RES][(event->x + 64) / MAP_RES], then calls destroy_stuff(event).
 * 
 * @param event The event struct containing player and game state.
 */
void	is_in_exit_space_right(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->parser.colects == 0 && event->move_right_trigger)
	{
		if (event->map[(event->y) / MAP_RES][(event->x + 59) / MAP_RES] == 'E')
			destroy_stuff(event);
		else if (event->map[(event->y + 44) / MAP_RES][(event->x + 59) / MAP_RES] == 'E')
			destroy_stuff(event);
	}
}
/**
 * @brief Checks if player is in the exit space to the left without collectibles.
 * 
 * If no collectibles and player triggers left movement:
 * - Checks if 'E' tile is at (event->y) / MAP_RES][(event->x - 64) / MAP_RES] or
 *   [(event->y + 44) / MAP_RES][(event->x - 64) / MAP_RES], then calls destroy_stuff(event).
 * 
 * @param event The event struct containing player and game state.
 */
void	is_in_exit_space_left(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->parser.colects == 0 && event->move_left_trigger)
	{
		if (event->map[(event->y) / MAP_RES][(event->x + 5) / MAP_RES] == 'E')
			destroy_stuff(event);
		else if (event->map[(event->y + 44) / MAP_RES][(event->x + 5) / MAP_RES] == 'E')
			destroy_stuff(event);
	}
}
/**
 * @brief Checks if player is in exit space above without collectibles.
 * 
 * If no collectibles and player moves up:
 * - Checks 'E' tile at [(event->y - 64) / MAP_RES][(event->x) / MAP_RES] or
 *   [(event->y - 64) / MAP_RES][(event->x + 44) / MAP_RES], then calls destroy_stuff(event).
 * 
 * @param event The event struct with player and game state.
 */
void	is_in_exit_space_up(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->parser.colects == 0 && event->move_up_trigger)
	{
		if (event->map[(event->y + 5) / MAP_RES][(event->x) / MAP_RES] == 'E')
			destroy_stuff(event);
		else if (event->map[(event->y + 5) / MAP_RES][(event->x + 44) / MAP_RES] == 'E')
			destroy_stuff(event);
	}
}
/**
 * @brief Checks if player is in exit space below without collectibles.
 * 
 * If no collectibles and player moves down:
 * - Checks 'E' tile at [(event->y + 64) / MAP_RES][(event->x) / MAP_RES] or
 *   [(event->y + 64) / MAP_RES][(event->x + 44) / MAP_RES], then calls destroy_stuff(event).
 * 
 * @param event The event struct with player and game state.
 */
void	is_in_exit_space_down(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->parser.colects == 0 && event->move_down_trigger)
	{
		if (event->map[(event->y + 59) / MAP_RES][(event->x) / MAP_RES] == 'E')
			destroy_stuff(event);
		else if (event->map[(event->y + 59) / MAP_RES][(event->x + 44) / MAP_RES] == 'E')
			destroy_stuff(event);
	}
}
