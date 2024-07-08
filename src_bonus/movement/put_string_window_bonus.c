/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:47:07 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 16:19:26 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	put_string_window(t_event *event, int x, int y)
{
	snprintf(event->moves_string, sizeof(event->moves_string),
		"Movements == [%d]", event->moves);
	put_tile("textures/colected.xpm", event, x, y);
	put_tile("textures/colected.xpm", event, x * 2, y);
	put_tile("textures/colected.xpm", event, x * 3, y);
	mlx_string_put(event->mlx, event->window, RES,
		(event->map_lines * RES) + 20, GREEN, event->moves_string);
}
