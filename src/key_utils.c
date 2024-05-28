/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:08:53 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/28 18:54:41 by ddias-fe         ###   ########.fr       */
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
	//mlx_destroy_image(event->mlx, event->tile.img);
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

int	init_key_press(t_event *event)
{
	event->move_down_trigger = 0;
	event->move_up_trigger = 0;
	event->move_right_trigger = 0;
	event->move_left_trigger = 0;
	return (0);
}

int	on_key_press(int key, t_event *event)
{
	if (key == XK_Down && event->is_moving == 0)
		key_press_down(event);
	if (key == XK_Up && event->is_moving == 0)
		key_press_up(event);
	if (key == XK_Right && event->is_moving == 0)
		key_press_right(event);
	if (key == XK_Left && event->is_moving == 0)
		key_press_left(event);
	if (key == XK_Escape)
		destroy_stuff(event);
	return (0);
}

int	on_key_release(int key, t_event *event)
{
	if (key == XK_Down)
	{
		event->move_down_trigger = 0;
		event->is_moving = 0;
	}
	if (key == XK_Up)
	{
		event->move_up_trigger = 0;
		event->is_moving = 0;
	}
	if (key == XK_Right)
	{
		event->move_right_trigger = 0;
		event->is_moving = 0;
	}
	if (key == XK_Left)
	{
		event->move_left_trigger = 0;
		event->is_moving = 0;
	}
	return (0);
}

int	update_key_press(t_event *event)
{
	if (event->move_down_trigger)
		trigger_move_down(event);
	if (event->move_up_trigger)
		trigger_move_up(event);
	if (event->move_right_trigger)
		trigger_move_right(event);
	if (event->move_left_trigger)
		trigger_move_left(event);
	usleep(3000);
	return (0);
}
