/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:16:31 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 15:30:47 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	destroy_stuff(t_event *event)
{
	int	i;

	i = 0;
	if (event->player.img)
		mlx_destroy_image(event->mlx, event->player.img);
	if (event->tile.img)
		mlx_destroy_image(event->mlx, event->tile.img);
	if (event->bg.img)
		mlx_destroy_image(event->mlx, event->bg.img);
	if (event->colect.img)
		mlx_destroy_image(event->mlx, event->colect.img);
	if (event->window)
	{
		mlx_clear_window(event->mlx, event->window);
		mlx_destroy_window(event->mlx, event->window);
	}
	while (i < event->map_lines)
		free(event->map[i++]);
	free(event->map);
	mlx_destroy_display(event->mlx);
	free(event->mlx);
	exit(0);
	return (0);
}

void	free_after_parser(t_event *event)
{
	int	i;

	i = 0;
	while (i < event->map_lines)
		free(event->map[i++]);
	mlx_destroy_display(event->mlx);
	free(event->map);
	free(event->mlx);
	exit(0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	while (i--)
		free(split[i]);
	free(split);
}
