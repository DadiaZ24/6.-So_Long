/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:37:13 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/04 17:05:14 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long_bonus.h"

void	exit_sprite(t_event *event, int x, int y)
{
	int i;
	char	path[24];

	i = 0;
	while (i < 7)
	{
		snprintf(path, sizeof(path), "img/exit_sprite/%d.xpm", i + 1);
		put_tile(path, event, x, y);
		usleep(100000);
		i++;
	}
}
