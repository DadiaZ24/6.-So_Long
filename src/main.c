/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:01:29 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/15 19:45:43 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(void)
{
    void    *mlx;
    void    *mlx_window;
    t_data  img;
    t_data  img2;
    
    img.path = "img/starwars.xpm";
    img2.path = "img/teste.xpm";
    mlx = mlx_init();
    /* img.img = mlx_new_image(mlx, 1920, 1080);
    img.adress = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
    my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);
    my_mlx_pixel_put(&img, 49, 51, 0x00FF0000);
    my_mlx_pixel_put(&img, 51, 51, 0x00FF0000);
    my_mlx_pixel_put(&img, 48, 52, 0x00FF0000);
    my_mlx_pixel_put(&img, 52, 52, 0x00FF0000);
    my_mlx_pixel_put(&img, 47, 53, 0x00FF0000);
    my_mlx_pixel_put(&img, 53, 53, 0x00FF0000);
    my_mlx_pixel_put(&img, 46, 54, 0x00FF0000);
    my_mlx_pixel_put(&img, 54, 54, 0x00FF0000);
    my_mlx_pixel_put(&img, 45, 55, 0x00FF0000);
    my_mlx_pixel_put(&img, 55, 55, 0x00FF0000);
    my_mlx_pixel_put(&img, 44, 56, 0x00FF0000);
    my_mlx_pixel_put(&img, 56, 56, 0x00FF0000);
    my_mlx_pixel_put(&img, 43, 57, 0x00FF0000);
    my_mlx_pixel_put(&img, 57, 57, 0x00FF0000);
    mlx_put_image_to_window(mlx, mlx_window, img.img, 200, 0);     */
    img.img = mlx_xpm_file_to_image(mlx, img.path, &img.width, &img.height);
    img2.img = mlx_xpm_file_to_image(mlx, img2.path, &img2.width, &img2.height);
    mlx_window = mlx_new_window(mlx, img.width, img.height, "AAHAAAAAAAAAAAA!!!!!!");
    mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
    mlx_put_image_to_window(mlx, mlx_window, img2.img, 10, 10);
    usleep(1000000);
    mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
    mlx_put_image_to_window(mlx, mlx_window, img2.img, 50, 10);
    usleep(1000000);
    mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
    mlx_put_image_to_window(mlx, mlx_window, img2.img, 100, 10);
    usleep(1000000);
    mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
    mlx_loop(mlx);
    return (0);
}