/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:01:29 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/22 20:56:31 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_img_data(t_event *event)
{
	event->x = 100;
	event->y = 30;
	event->player_right.path = "img/mfalcon.xpm";
	event->player_up.path = "img/player_upp.xpm";
	event->player_down.path = "img/player_downown.xpm";
	event->player_left.path = "img/player_lefteft.xpm";
	event->blast.path = "img/blast.xpm";
}

void	init_put_img(t_event *event)
{
	event->player_right.img = mlx_xpm_file_to_image(event->mlx,
			event->player_right.path, &event->player_right.width,
			&event->player_right.height);
	event->player_up.img = mlx_xpm_file_to_image(event->mlx,
			event->player_up.path, &event->player_up.width,
			&event->player_up.height);
	event->player_down.img = mlx_xpm_file_to_image(event->mlx,
			event->player_down.path, &event->player_down.width,
			&event->player_down.height);
	event->player_left.img = mlx_xpm_file_to_image(event->mlx,
			event->player_left.path, &event->player_left.width,
			&event->player_left.height);
	event->blast.img = mlx_xpm_file_to_image(event->mlx,
			event->blast.path, &event->blast.width, &event->blast.height);
}

int	main(void)
{
	t_event	event;

	init_key_press(&event);
	init_img_data(&event);
	event.mlx = mlx_init();
	event.window = mlx_new_window(event.mlx, 1024, 820, "TESTEEEEEEEE");
	event.bg.path = "img/bg.xpm";
	event.bg.img = mlx_xpm_file_to_image(event.mlx, event.bg.path,
			&event.bg.width, &event.bg.height);
	event.bg.data = mlx_get_data_addr(event.bg.img, &event.bg.bpp,
			&event.bg.size_line, &event.bg.endian);
	event.player_right.data = mlx_get_data_addr(event.player_right.img,
			&event.player_right.bpp, &event.player_right.size_line,
			&event.player_right.endian);
	replace_black_pixels(&event.player_right, &event.bg, event.x, event.y);
	mlx_put_image_to_window(event.mlx, event.window, event.bg.img, 0, 0);
	mlx_put_image_to_window(event.mlx, event.window,
		event.player_right.img, event.x, event.y);
	mlx_hook(event.window, KeyPress, KeyPressMask, on_key_press, &event);
	mlx_hook(event.window, KeyRelease, KeyReleaseMask, on_key_release, &event);
	mlx_loop_hook(event.mlx, update_key_press, &event);
	mlx_loop(event.mlx);
	return (0);
}
