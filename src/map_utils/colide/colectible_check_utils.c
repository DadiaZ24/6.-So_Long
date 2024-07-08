/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colectible_check_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:28:22 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 15:47:59 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	update_colectible_status(t_event *event, int x, int y)
{
	event->parser.colects -= 1;
	event->map[y][x] = '0';
	put_tile("textures/colected.xpm", event, x * RES, y * RES);
}
