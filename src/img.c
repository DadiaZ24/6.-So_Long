/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:35:01 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/15 18:57:25 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* typedef struct	s_data {
	void	*img;
	char	*adress;
	int		bpp;
	int		line_len;
	int		endian;
}   t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->adress + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
} */