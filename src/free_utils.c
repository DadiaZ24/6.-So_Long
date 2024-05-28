/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:16:31 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/28 19:41:12 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_stuff(t_event *event)
{
	int	i;

	i = 0;
	mlx_destroy_image(event->mlx, event->player_down.img);
	mlx_destroy_image(event->mlx, event->player_up.img);
	mlx_destroy_image(event->mlx, event->player_right.img);
	mlx_destroy_image(event->mlx, event->player_left.img);
	mlx_destroy_image(event->mlx, event->tile.img);
	mlx_destroy_image(event->mlx, event->bg.img);
	mlx_clear_window(event->mlx, event->window);
	mlx_destroy_window(event->mlx, event->window);
	mlx_destroy_display(event->mlx);
	while (i < event->map_lines)
		free(event->map[i++]);
	free(event->map);
	free(event->mlx);
	exit(0);
}
