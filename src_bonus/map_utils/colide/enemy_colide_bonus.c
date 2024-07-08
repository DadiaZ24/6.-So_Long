/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_colide_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:46:28 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 17:00:36 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long_bonus.h"

int	check_enemy(t_event *event)
{
	if (event->parser.colects)
		return (check_enemy_colectible(event));
	else
		return (check_enemy_no_colectible(event));
	return (0);
}

int	check_enemy_no_colectible(t_event *event)
{
	if (event->map[event->y / RES][event->x / RES] == 'X'
			|| event->map[event->y / RES][(event->x / RES) + 1] == 'X')
		return (lose_game(event));
	if (event->map[(event->y / RES) + 1][event->x / RES] == 'X'
			|| event->map[(event->y / RES) + 1][(event->x / RES) + 1] == 'X')
		return (lose_game(event));
	if (event->map[(event->y / RES) + 1][(event->x / RES) + 1] == 'X'
			|| event->map[(event->y / RES)][(event->x / RES) + 1] == 'X')
		return (lose_game(event));
	if (event->map[(event->y / RES) + 1][(event->x / RES)] == 'X'
			|| event->map[(event->y / RES)][(event->x / RES)] == 'X')
		return (lose_game(event));
	return (0);
}

int	check_enemy_colectible(t_event *event)
{
	if ((event->map[event->y / RES][event->x / RES] == 'X'
		|| event->map[event->y / RES][(event->x / RES) + 1] == 'X')
			|| (event->map[event->y / RES][event->x / RES] == 'E'
			|| event->map[event->y / RES][(event->x / RES) + 1] == 'E'))
		return (lose_game(event));
	if ((event->map[(event->y / RES) + 1][event->x / RES] == 'X'
		|| event->map[(event->y / RES) + 1][(event->x / RES) + 1] == 'X')
			|| (event->map[(event->y / RES) + 1][event->x / RES] == 'E'
			|| event->map[(event->y / RES) + 1][(event->x / RES) + 1] == 'E'))
		return (lose_game(event));
	if ((event->map[(event->y / RES) + 1][(event->x / RES) + 1] == 'X'
		|| event->map[(event->y / RES)][(event->x / RES) + 1] == 'X')
			|| (event->map[(event->y / RES) + 1][(event->x / RES) + 1] == 'E'
			|| event->map[(event->y / RES)][(event->x / RES) + 1] == 'E'))
		return (lose_game(event));
	if ((event->map[(event->y / RES) + 1][(event->x / RES)] == 'X'
		|| event->map[(event->y / RES)][(event->x / RES)] == 'X')
			|| (event->map[(event->y / RES) + 1][(event->x / RES)] == 'E'
			|| event->map[(event->y / RES)][(event->x / RES)] == 'E'))
		return (lose_game(event));
	return (0);
}

int	lose_game(t_event *event)
{
	exit_sprite(event, event->x, event->y);
	ft_printf(GAME_OVER, BLUE, ERROR_TOP, RED, DEFAULT_COLOR, BLUE,
		ERROR_BOT, DEFAULT_COLOR);
	return (destroy_stuff(event));
}
