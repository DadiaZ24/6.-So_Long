/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colectible_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:50:08 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 15:17:43 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"
/**
 * @brief Checks if player is in collectible space right.
 * 
 * Checks if player moves right (`event->move_right_trigger`):
 * - Collects 'C', updates count, map, and visual if found.
 * 
 * @param event The event struct containing player position.
 */
void	is_in_colectible_space_right(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->move_right_trigger)
	{
		if (event->map[(event->y + 2) / RES]
			[(event->x + 40) / RES] == 'C')
		{
			x = (event->x + 40) / RES;
			y = (event->y + 2) / RES;
			update_colectible_status(event, x, y);
		}
		else if (event->map[(event->y + 44) / RES]
			[(event->x + 40) / RES] == 'C')
		{
			x = (event->x + 40) / RES;
			y = (event->y + 44) / RES;
			update_colectible_status(event, x, y);
		}
	}
}

/**
 * @brief Checks collectibles to the left and collects if present.
 * 
 * Checks if player moves left (`event->move_left_trigger`):
 * - Collects 'C', updates count, map, and visual if found.
 * 
 * @param event The event struct with player position and game state.
 */
void	is_in_colectible_space_left(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->move_left_trigger)
	{
		if (event->map[(event->y + 2) / RES]
			[(event->x - 40) / RES] == 'C')
		{
			x = (event->x - 40) / RES;
			y = (event->y + 2) / RES;
			update_colectible_status(event, x, y);
		}
		else if (event->map[(event->y + 44) / RES]
			[(event->x - 40) / RES] == 'C')
		{
			x = (event->x - 40) / RES;
			y = (event->y + 44) / RES;
			update_colectible_status(event, x, y);
		}
	}
}

/**
 * @brief Checks collectibles above and collects if found.
 * 
 * Checks if player moves up (`event->move_up_trigger`):
 * - Collects 'C', updates count, map, and visual if found.
 * 
 * @param event The event struct containing player position.
 */
void	is_in_colectible_space_up(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->move_up_trigger)
	{
		if (event->map[(event->y - 40) / RES]
			[(event->x + 2) / RES] == 'C')
		{
			x = (event->x + 2) / RES;
			y = (event->y - 40) / RES;
			update_colectible_status(event, x, y);
		}
		else if (event->map[(event->y - 40) / RES]
			[(event->x + 44) / RES] == 'C')
		{
			x = (event->x + 44) / RES;
			y = (event->y - 40) / RES;
			update_colectible_status(event, x, y);
		}
	}
}

/**
 * @brief Checks collectibles below and collects if found.
 * 
 * Checks if player moves down (`event->move_down_trigger`):
 * - Collects 'C', updates count, map, and visual if found.
 * 
 * @param event The event struct containing player position.
 */
void	is_in_colectible_space_down(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (event->move_down_trigger)
	{
		if (event->map[(event->y + 40) / RES]
			[(event->x + 2) / RES] == 'C')
		{
			x = (event->x + 2) / RES;
			y = (event->y + 40) / RES;
			update_colectible_status(event, x, y);
		}
		else if (event->map[(event->y + 40) / RES]
			[(event->x + 44) / RES] == 'C')
		{
			x = (event->x + 44) / RES;
			y = (event->y + 40) / RES;
			update_colectible_status(event, x, y);
		}
	}
}
