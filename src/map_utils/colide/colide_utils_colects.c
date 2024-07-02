/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colide_utils_colects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:28:09 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/02 16:37:16 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

/**
 * @brief Checks obstacles above player.
 * 
 * Checks if player can move up by verifying:
 * - No obstacle on the right.
 * - No obstacle on the left.
 * - No obstacles directly above.
 * 
 * @param event The event struct containing player position.
 * @return 0 if movement is blocked, 1 otherwise.
 */
int	check_up(t_event *event)
{
	if (!check_right(event))
	{
		
		if ((event->map[(event->y / MAP_RES)][((event->x + 3) / MAP_RES)] == '1')
				|| (event->map[(event->y / MAP_RES)][((event->x + 3) / MAP_RES)] == 'E'))
			return(0);
	}
	else if (!check_left(event))
	{
		if ((event->map[(event->y / MAP_RES)][((event->x - 3) / MAP_RES) + 1] == '1')
				|| (event->map[(event->y / MAP_RES)][((event->x - 3) / MAP_RES) + 1] == 'E'))
			return(0);
	}
	else
		if (((event->map[(event->y) / MAP_RES][((event->x + 3) / MAP_RES)] == '1')
				|| (event->map[(event->y) / MAP_RES][((event->x + 3) / MAP_RES)] == 'E'))
				|| ((event->map[(event->y) / MAP_RES][((event->x - 3) / MAP_RES) + 1] == '1')
				|| (event->map[(event->y) / MAP_RES][((event->x - 3) / MAP_RES) + 1] == 'E')))
			return (0);
	return (1);
}
/**
 * @brief Checks obstacles below player.
 * 
 * Checks if player can move down by verifying:
 * - No obstacle on the right.
 * - No obstacle on the left.
 * - No obstacles directly below.
 * 
 * @param event The event struct containing player position.
 * @return 0 if movement is blocked, 1 otherwise.
 */
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
		if ((event->map[(event->y / MAP_RES) + 1][((event->x - 3) / MAP_RES) + 1] == '1')
				|| (event->map[(event->y / MAP_RES) + 1][((event->x - 3) / MAP_RES) + 1] == 'E'))
			return(0);
	}
	else
	{
		if (((event->map[((event->y + 2) / MAP_RES) + 1][((event->x - 3)/ MAP_RES) + 1] == '1')
				|| (event->map[((event->y + 2) / MAP_RES) + 1][((event->x - 3)/ MAP_RES) + 1] == 'E'))
				|| ((event->map[((event->y + 2) / MAP_RES) + 1][((event->x + 3) / MAP_RES)] == '1')
				|| (event->map[((event->y + 2) / MAP_RES) + 1][((event->x  + 3) / MAP_RES)] == 'E')))
			return (0);
	}
	return (1);
}
/**
 * @brief Checks obstacles to the right of the player.
 * 
 * Checks if player can move right by verifying:
 * - No obstacle above.
 * - No obstacle below.
 * - No obstacles directly to the right.
 * 
 * @param event The event struct containing player position.
 * @return 0 if movement is blocked, 1 otherwise.
 */
int	check_right(t_event *event)
{
	if (!temp_check_up(event))
	{
		if ((event->map[(event->y + 3) / MAP_RES][(event->x / MAP_RES) + 1] == '1')
				|| (event->map[(event->y + 3) / MAP_RES][(event->x / MAP_RES) + 1] == 'E'))
			return(0);
	}
	else if (!temp_check_down(event))
	{
		if ((event->map[(event->y - 3) / MAP_RES + 1][(event->x / MAP_RES) + 1] == '1')
				|| (event->map[(event->y - 3) / MAP_RES + 1][(event->x / MAP_RES) + 1] == 'E'))
			return(0);
	}
	else
	{
		if (((event->map[((event->y + 3) / MAP_RES)][(event->x / MAP_RES)] == '1')
				|| (event->map[((event->y + 3) / MAP_RES)][(event->x / MAP_RES)] == 'E'))
				|| ((event->map[((event->y - 3) / MAP_RES) + 1][(event->x / MAP_RES) + 1] == '1')
				|| (event->map[((event->y - 3) / MAP_RES) + 1][(event->x / MAP_RES) + 1] == 'E')))
			return (0);
	}
	return (1);
}
/**
 * @brief Checks obstacles to the left of the player.
 * 
 * Checks if player can move left by verifying:
 * - No obstacle above.
 * - No obstacle below.
 * - No obstacles directly to the left.
 * 
 * @param event The event struct containing player position.
 * @return 0 if movement is blocked, 1 otherwise.
 */
int	check_left(t_event *event)
{
	if (!temp_check_up(event))
	{
		if ((event->map[(event->y + 3) / MAP_RES][(event->x / MAP_RES)] == '1')
				|| (event->map[(event->y + 3) / MAP_RES][(event->x / MAP_RES)] == 'E'))
			return(0);
	}
	else if (!temp_check_down(event))
	{
		if ((event->map[((event->y - 3) / MAP_RES) + 1][(event->x / MAP_RES)] == '1')
				|| (event->map[((event->y - 3) / MAP_RES) + 1][(event->x / MAP_RES)] == 'E'))
			return(0);
	}
	else
	{
		if (((event->map[((event->y + 3) / MAP_RES)][(event->x / MAP_RES)] == '1')
				|| (event->map[((event->y + 3) / MAP_RES)][(event->x / MAP_RES)] == 'E'))
				|| ((event->map[((event->y - 3) / MAP_RES) + 1][(event->x / MAP_RES)] == '1')
				|| (event->map[((event->y - 3) / MAP_RES) + 1][(event->x / MAP_RES)] == 'E')))
			return (0);
	}
	return (1);
}
