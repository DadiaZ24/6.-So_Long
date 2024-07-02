/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colide_utils_no_colects.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:53:16 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/02 18:20:25 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"
/**
 * @brief Checks obstacles above the player without any colectible to colect.
 * 
 * Checks if player can move up by verifying:
 * - No obstacle to the right.
 * - No obstacle to the left.
 * - No obstacles directly above.
 * 
 * @param event The event struct containing player position.
 * @return 0 if movement is blocked, 1 otherwise.
 */
int	check_up_no_colects(t_event *event)
{
	if (!check_right_no_colects(event))
	{
		
		if (event->map[(event->y / MAP_RES)][((event->x + 3) / MAP_RES)] == '1')
			return(0);
	}
	else if (!check_left_no_colects(event))
	{
		if (event->map[(event->y / MAP_RES)][((event->x - 3) / MAP_RES) + 1] == '1')
			return(0);
	}
	else
	{
		if ((event->map[(event->y) / MAP_RES][((event->x - 3) / MAP_RES) + 1] == '1')
				|| (event->map[(event->y) / MAP_RES][((event->x + 3) / MAP_RES)] == '1'))
			return (0);
	}	
	return (1);
}
/**
 * @brief Checks obstacles below the player without any collectible to collect.
 * 
 * Checks if the player can move down by verifying:
 * - No obstacle to the right.
 * - No obstacle to the left.
 * - No obstacles directly below.
 * 
 * @param event The event struct containing player position.
 * @return 0 if movement is blocked, 1 otherwise.
 */
int	check_down_no_colects(t_event *event)
{
	if (!check_right_no_colects(event))
	{
		if (event->map[(event->y / MAP_RES) + 1][((event->x + 3) / MAP_RES)] == '1')
			return(0);
	}
	else if (!check_left_no_colects(event))
	{
		if (event->map[(event->y / MAP_RES) + 1][((event->x - 3) / MAP_RES) + 1] == '1')
			return(0);
	}
	else
	{
		if ((event->map[((event->y + 2) / MAP_RES) + 1][((event->x - 3)/ MAP_RES) + 1] == '1')
				|| (event->map[((event->y + 2) / MAP_RES) + 1][((event->x + 3) / MAP_RES)] == '1'))
			return (0);
	}
	return (1);
}
/**
 * @brief Checks obstacles to the right of the player without any collectible to collect.
 * 
 * Checks if the player can move right by verifying:
 * - No obstacle above.
 * - No obstacle below.
 * - No obstacles directly to the right.
 * 
 * @param event The event struct containing player position.
 * @return 0 if movement is blocked, 1 otherwise.
 */
int	check_right_no_colects(t_event *event)
{
	if (!temp_check_up_no_colect(event))
	{
		if (event->map[(event->y + 3) / MAP_RES][(event->x / MAP_RES) + 1] == '1')
			return(0);
	}
	else if (!temp_check_down_no_colect(event))
	{
		if (event->map[(event->y - 3) / MAP_RES + 1][(event->x / MAP_RES) + 1] == '1')
			return(0);
	}
	else
	{
		if ((event->map[((event->y + 3) / MAP_RES)][(event->x / MAP_RES)] == '1')
				|| (event->map[((event->y - 3) / MAP_RES) + 1][(event->x / MAP_RES) + 1] == '1'))
			return (0);
	}
	return (1);
}
/**
 * @brief Checks obstacles to the left of the player without any collectible to collect.
 * 
 * Checks if the player can move left by verifying:
 * - No obstacle above.
 * - No obstacle below.
 * - No obstacles directly to the left.
 * 
 * @param event The event struct containing player position.
 * @return 0 if movement is blocked, 1 otherwise.
 */
int	check_left_no_colects(t_event *event)
{
	if (!temp_check_up_no_colect(event))
	{
		if (event->map[(event->y + 3) / MAP_RES][(event->x / MAP_RES)] == '1')
			return(0);
	}
	else if (!temp_check_down_no_colect(event))
	{
		if (event->map[((event->y - 3) / MAP_RES) + 1][(event->x / MAP_RES)] == '1')
			return(0);
	}
	else
	{
		if ((event->map[((event->y + 3) / MAP_RES)][(event->x / MAP_RES)] == '1')
				|| (event->map[((event->y - 3) / MAP_RES) + 1][(event->x / MAP_RES)] == '1'))
			return (0);
	}
	return (1);
}
