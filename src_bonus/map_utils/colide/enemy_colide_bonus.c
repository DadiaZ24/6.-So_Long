/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_colide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:46:28 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/04 17:02:55 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long_bonus.h"

int	check_enemy(t_event *event)
{
	if (event->map[event->y / MAP_RES][event->x / MAP_RES] == 'X'
			|| event->map[event->y / MAP_RES][(event->x / MAP_RES) + 1] == 'X')
		return (lose_game(event));
	if (event->map[(event->y / MAP_RES) + 1][event->x / MAP_RES] == 'X'
			|| event->map[(event->y / MAP_RES) + 1][(event->x / MAP_RES) + 1] == 'X')
		return (lose_game(event));
	if (event->map[(event->y / MAP_RES) + 1][(event->x / MAP_RES) + 1] == 'X'
			|| event->map[(event->y / MAP_RES)][(event->x / MAP_RES) + 1] == 'X')
		return (lose_game(event));
	if (event->map[(event->y / MAP_RES) + 1][(event->x / MAP_RES)] == 'X'
			|| event->map[(event->y / MAP_RES)][(event->x / MAP_RES)] == 'X')
		return (lose_game(event));
	return (0);
}

int	lose_game(t_event *event)
{
	exit_sprite(event, event->x, event->y);
	printf("%sYOU DIED!\n", RED);
	return (destroy_stuff(event));
}