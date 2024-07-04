/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:47:07 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/04 15:52:15 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	clear_string(t_event *event, int x, int y)
{
	put_tile("img/colected.xpm", event, x, y);
	put_tile("img/colected.xpm", event, x * 2, y);
	put_tile("img/colected.xpm", event, x * 3, y);
}