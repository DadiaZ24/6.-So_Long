/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:01:29 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/18 21:30:54 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(void)
{
    void    *mlx;
    void    *mlx_window;
    t_data  img;
    int     i = 1000;
    int     j = -100;
    
    img.path = "img/fog2.xpm";
    mlx = mlx_init();
    img.img = mlx_xpm_file_to_image(mlx, img.path, &img.width, &img.height);
    mlx_window = mlx_new_window(mlx, 1920, 1080, "LINDOOOOOOO!!!!");
    mlx_put_image_to_window(mlx, mlx_window, img.img, j, 100);
    while (i--)
    {
        j += 10;
        mlx_clear_window(mlx, mlx_window);
        mlx_put_image_to_window(mlx, mlx_window, img.img, j, 100);
        usleep(10000);
    }
    mlx_loop(mlx);
    return (0);
}