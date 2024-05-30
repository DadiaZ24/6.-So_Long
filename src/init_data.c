/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:28:03 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/30 16:55:20 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_data(t_event *event)
{
	event->mlx = mlx_init();
	init_int_data(event);
	init_t_data_data(event);
	init_img_data(event);
	set_map_size(event);
	event->window = mlx_new_window(event->mlx, event->map_columns * MAP_RES,
			event->map_lines * MAP_RES, "SO_LONG");
	init_put_img(event);
	if (!render_map(event))
		return (0);
	return (1);
}

void	init_byte_data(t_byte *byte)
{
	byte->y = 0;
	byte->x = 0;
	byte->pi = 0;
	byte->bg_x = 0;
	byte->bg_y = 0;
	byte->bg_pi = 0;
}

void	init_t_data_data(t_event *event)
{
	init_player_data(&event->player_down);
	init_player_data(&event->player_up);
	init_player_data(&event->player_right);
	init_player_data(&event->player_left);
	init_player_data(&event->bg);
	init_player_data(&event->tile);
}

void	init_player_data(t_data *player)
{
	player->width = 0;
	player->height = 0;
	player->bpp = 0;
	player->size_line = 0;
	player->endian = 0;
	player->erase = 0;
	player->img = 0;
}

void	init_int_data(t_event *event)
{
	event->display = 0;
	event->move_down_trigger = 0;
	event->move_up_trigger = 0;
	event->move_right_trigger = 0;
	event->move_left_trigger = 0;
	event->is_moving = 0;
	event->map_lines = 0;
	event->map_columns = 0;
	event->x = 0;
	event->y = 0;
	event->parser.colects = 0;
	event->parser.exit = 0;
	event->parser.i = 0;
	event->parser.players = 0;
	event->parser.x = 0;
	event->parser.y = 0;
	event->moves = 0;
}
