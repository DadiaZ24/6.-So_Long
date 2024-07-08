/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:35:07 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 16:18:41 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	trigger_move_down(t_event *event)
{
	is_in_colectible_space_down(event);
	is_in_exit_space_down(event);
	if (colide_move_down(event) == 1)
	{
		event->y += 1;
		mlx_destroy_image(event->mlx, event->player.img);
		event->player.path = "textures/player_down.xpm";
		event->player.img = mlx_xpm_file_to_image(event->mlx,
				event->player.path, &event->player.width,
				&event->player.height);
		event->player.data = mlx_get_data_addr(event->player.img,
				&event->player.bpp, &event->player.size_line,
				&event->player.endian);
		replace_black_pixels(&event->player, &event->bg, event->x,
			event->y);
		mlx_put_image_to_window(event->mlx, event->window,
			event->player.img, event->x, event->y);
		event->moves += 1;
		ft_printf("Movements == [%d]\n", event->moves);
		put_string_window(event, RES, (event->map_lines * RES) + 10);
	}
	return (check_enemy(event));
}

int	trigger_move_up(t_event *event)
{
	is_in_colectible_space_up(event);
	is_in_exit_space_up(event);
	if (colide_move_up(event) == 1)
	{
		event->y -= 1;
		mlx_destroy_image(event->mlx, event->player.img);
		event->player.path = "textures/player_up.xpm";
		event->player.img = mlx_xpm_file_to_image(event->mlx,
				event->player.path, &event->player.width,
				&event->player.height);
		event->player.data = mlx_get_data_addr(event->player.img,
				&event->player.bpp, &event->player.size_line,
				&event->player.endian);
		replace_black_pixels(&event->player, &event->bg, event->x,
			event->y);
		mlx_put_image_to_window(event->mlx, event->window,
			event->player.img, event->x, event->y);
		event->moves += 1;
		ft_printf("Movements == [%d]\n", event->moves);
		put_string_window(event, RES, (event->map_lines * RES) + 10);
	}
	return (check_enemy(event));
}

int	trigger_move_right(t_event *event)
{
	is_in_colectible_space_right(event);
	is_in_exit_space_right(event);
	if (colide_move_right(event) == 1)
	{
		event->x += 1;
		mlx_destroy_image(event->mlx, event->player.img);
		event->player.path = "textures/player_right.xpm";
		event->player.img = mlx_xpm_file_to_image(event->mlx,
				event->player.path, &event->player.width,
				&event->player.height);
		event->player.data = mlx_get_data_addr(event->player.img,
				&event->player.bpp, &event->player.size_line,
				&event->player.endian);
		replace_black_pixels(&event->player, &event->bg, event->x,
			event->y);
		mlx_put_image_to_window(event->mlx, event->window,
			event->player.img, event->x, event->y);
		event->moves += 1;
		ft_printf("Movements == [%d]\n", event->moves);
		put_string_window(event, RES, (event->map_lines * RES) + 10);
	}
	return (check_enemy(event));
}

int	trigger_move_left(t_event *event)
{
	is_in_colectible_space_left(event);
	is_in_exit_space_left(event);
	if (colide_move_left(event) == 1)
	{
		event->x -= 1;
		mlx_destroy_image(event->mlx, event->player.img);
		event->player.path = "textures/player_left.xpm";
		event->player.img = mlx_xpm_file_to_image(event->mlx,
				event->player.path, &event->player.width,
				&event->player.height);
		event->player.data = mlx_get_data_addr(event->player.img,
				&event->player.bpp, &event->player.size_line,
				&event->player.endian);
		replace_black_pixels(&event->player, &event->bg, event->x,
			event->y);
		mlx_put_image_to_window(event->mlx, event->window,
			event->player.img, event->x, event->y);
		event->moves += 1;
		ft_printf("Movements == [%d]\n", event->moves);
		put_string_window(event, RES, (event->map_lines * RES) + 10);
	}
	return (check_enemy(event));
}
