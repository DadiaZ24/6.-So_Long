/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:01:29 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/18 21:39:18 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(void)
{
    void    *mlx;
    void    *mlx_window;
    t_data  img;
    int     i = 100;
    int     j = -10;
    int     k = 3;
    
    img.path = "img/fog2.xpm";
    mlx = mlx_init();
    img.img = mlx_xpm_file_to_image(mlx, img.path, &img.width, &img.height);
    mlx_window = mlx_new_window(mlx, 1000, 500, "LINDOOOOOOO!!!!");
    mlx_put_image_to_window(mlx, mlx_window, img.img, j, 50);
    while (k--)
    {
        while (i--)
        {
            j += 10;
            //mlx_clear_window(mlx, mlx_window);
            mlx_put_image_to_window(mlx, mlx_window, img.img, j, 50);
            usleep(10000);
        }
        while (i++ < 100)
        {
            j -= 10;
            //mlx_clear_window(mlx, mlx_window);
            mlx_put_image_to_window(mlx, mlx_window, img.img, j, 50);
            usleep(10000);
        }
    }
    mlx_loop(mlx);
    return (0);
}