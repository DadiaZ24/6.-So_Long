/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colectible_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:50:08 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/06/04 17:16:16 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	is_in_colectible_space(t_event *event)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("EVENT->Y == [%d]\n", (event->y + 32) / MAP_RES);
	printf("EVENT->X == [%d]\n", (event->x + 32) / MAP_RES);
	if(event->map[(event->y + 32) / MAP_RES][(event->x + 32) / MAP_RES] == 'C')
	{
		x = (event->x + 32) / 64;
		y = (event->y + 32) / 64;
		printf("ENTREI!!!\n");
		put_tile("img/colected.xpm", event, x * MAP_RES, y * MAP_RES);
		event->parser.colects -= 1;
		event->map[(event->y + 32) / MAP_RES][(event->x + 32) / MAP_RES] = '0';
	}
}