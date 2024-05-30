/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:35:07 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/30 17:11:04 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	trigger_move_down(t_event *event)
{
	if (check_down(event) == 1 || event->movement.trig_down == 1)
	{
		event->display = 1;
		event->y += 1;
		mlx_destroy_image(event->mlx, event->player_right.img);
		event->player_right.img = mlx_xpm_file_to_image(event->mlx,
				event->player_right.path, &event->player_right.width,
				&event->player_right.height);
		event->player_right.data = mlx_get_data_addr(event->player_right.img,
				&event->player_right.bpp, &event->player_right.size_line,
				&event->player_right.endian);
		replace_black_pixels(&event->player_right, &event->bg, event->x,
			event->y);
		mlx_put_image_to_window(event->mlx, event->window,
			event->player_right.img, event->x, event->y);
		event->moves += 1;
		//ft_printf("Movements == [%d]\n", event->moves);
	}
	return (0);
}

int	trigger_move_up(t_event *event)
{
	if (check_up(event) == 1 || event->movement.trig_up == 1)
	{
		event->display = 2;
		event->y -= 1;
		mlx_destroy_image(event->mlx, event->player_right.img);
		event->player_right.img = mlx_xpm_file_to_image(event->mlx,
				event->player_right.path, &event->player_right.width,
				&event->player_right.height);
		event->player_right.data = mlx_get_data_addr(event->player_right.img,
				&event->player_right.bpp, &event->player_right.size_line,
				&event->player_right.endian);
		replace_black_pixels(&event->player_right, &event->bg, event->x,
			event->y);
		mlx_put_image_to_window(event->mlx, event->window,
			event->player_right.img, event->x, event->y);
		event->moves += 1;
		//ft_printf("Movements == [%d]\n", event->moves);
	}
	return (0);
}

int	trigger_move_right(t_event *event)
{
	if (check_right(event) == 1 || event->movement.trig_right == 1)
	{
		event->display = 3;
		event->x += 1;
		mlx_destroy_image(event->mlx, event->player_right.img);
		event->player_right.img = mlx_xpm_file_to_image(event->mlx,
				event->player_right.path, &event->player_right.width,
				&event->player_right.height);
		event->player_right.data = mlx_get_data_addr(event->player_right.img,
				&event->player_right.bpp, &event->player_right.size_line,
				&event->player_right.endian);
		replace_black_pixels(&event->player_right, &event->bg, event->x,
			event->y);
		mlx_put_image_to_window(event->mlx, event->window,
			event->player_right.img, event->x, event->y);
		event->moves += 1;
		//ft_printf("Movements == [%d]\n", event->moves);
	}
	return (0);
}

int	trigger_move_left(t_event *event)
{
	if (check_left(event) == 1 || event->movement.trig_left == 1)
	{
		event->display = 4;
		event->x -= 1;
		mlx_destroy_image(event->mlx, event->player_right.img);
		event->player_right.img = mlx_xpm_file_to_image(event->mlx,
				event->player_right.path, &event->player_right.width,
				&event->player_right.height);
		event->player_right.data = mlx_get_data_addr(event->player_right.img,
				&event->player_right.bpp, &event->player_right.size_line,
				&event->player_right.endian);
		replace_black_pixels(&event->player_right, &event->bg, event->x,
			event->y);
		mlx_put_image_to_window(event->mlx, event->window,
			event->player_right.img, event->x, event->y);
		event->moves += 1;
		//ft_printf("Movements == [%d]\n", event->moves);
	}
	return (0);
}
