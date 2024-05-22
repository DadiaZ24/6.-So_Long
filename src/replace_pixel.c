/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:46:55 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/22 20:57:22 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	replace_black_pixels(t_data *icon, t_data *bg,
	int offset_x, int offset_y)
{
	t_byte	byte;

	byte.y = -1;
	while (++byte.y < icon->height)
	{
		byte.x = -1;
		while (++byte.x < icon->width)
		{
			byte.pi = (byte.y * icon->size_line) + (byte.x * 4);
			byte.r = icon->data[byte.pi + 2];
			byte.g = icon->data[byte.pi + 1];
			byte.b = icon->data[byte.pi];
			byte.bg_x = byte.x + offset_x;
			byte.bg_y = byte.y + offset_y;
			byte.bg_pi = (byte.bg_y * bg->size_line) + (byte.bg_x * 4);
			if ((byte.r == 0 && byte.g == 0 && byte.b == 0) || icon->erase == 1)
			{
				icon->data[byte.pi + 2] = bg->data[byte.bg_pi + 2];
				icon->data[byte.pi + 1] = bg->data[byte.bg_pi + 1];
				icon->data[byte.pi] = bg->data[byte.bg_pi];
			}
		}
	}
}
