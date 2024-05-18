/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:01:29 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/18 22:09:39 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(void)
{
    void    *mlx;
    void    *mlx_window;
    t_data  img;
    t_data  img2;
    t_data  barney;
    int     i = 150;
    int     j = -375;
    int     k = 3;
    int     baixo = 30;
    int     bney = 44;
    
    img.path = "img/fog.xpm";
    img2.path = "img/fog2.xpm";
    barney.path = "img/barney.xpm";
    mlx = mlx_init();
    img.img = mlx_xpm_file_to_image(mlx, img.path, &img.width, &img.height);
    img2.img = mlx_xpm_file_to_image(mlx, img2.path, &img2.width, &img2.height);
    barney.img = mlx_xpm_file_to_image(mlx, barney.path, &barney.width, &barney.height);
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
        baixo += 70;
        while (i++ < 150)
        {
            j -= 10;
            //mlx_clear_window(mlx, mlx_window);
            mlx_put_image_to_window(mlx, mlx_window, img2.img, j, baixo);
            usleep(10000);
        }
        baixo += 70;
    }
    //mlx_clear_window(mlx, mlx_window);
    mlx_put_image_to_window(mlx, mlx_window, barney.img, 0, baixo);
    while (bney--)
    {
        baixo -= 10;
        mlx_put_image_to_window(mlx, mlx_window, barney.img, 0, baixo);
        usleep(10000);
    }
    mlx_loop(mlx);
    return (0);
}