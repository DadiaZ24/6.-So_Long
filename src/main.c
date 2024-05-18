/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:01:29 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/18 21:44:40 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(void)
{
    void    *mlx;
    void    *mlx_window;
    t_data  img;
    t_data  img2;
    int     i = 100;
    int     j = -10;
    int     k = 3;
    int     baixo = 30;
    
    img.path = "img/fog.xpm";
    img2.path = "img/fog2.xpm";
    mlx = mlx_init();
    img.img = mlx_xpm_file_to_image(mlx, img.path, &img.width, &img.height);
    img2.img = mlx_xpm_file_to_image(mlx, img2.path, &img2.width, &img2.height);
    mlx_window = mlx_new_window(mlx, 1000, 500, "LINDOOOOOOO!!!!");
    mlx_put_image_to_window(mlx, mlx_window, img.img, j, baixo);
    while (k--)
    {
        while (i--)
        {
            j += 10;
            //mlx_clear_window(mlx, mlx_window);
            mlx_put_image_to_window(mlx, mlx_window, img.img, j, baixo);
            usleep(10000);
        }
        baixo += 50;
        while (i++ < 100)
        {
            j -= 10;
            //mlx_clear_window(mlx, mlx_window);
            mlx_put_image_to_window(mlx, mlx_window, img2.img, j, baixo);
            usleep(10000);
        }
        baixo += 50;
    }
    mlx_loop(mlx);
    return (0);
}