/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:01:29 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/20 21:20:55 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int closewindow(int key, t_event *event)
{
    if (key == XK_Escape)
    {
        mlx_clear_window(event->mlx, event->window);
        mlx_destroy_window(event->mlx, event->window);
        exit(0);
    }
    return (0);
}

int move_down(int key, t_event *event)
{
    if (key == XK_Down)
    {
        event->display = 1;
        event->y += 10;
        mlx_clear_window(event->mlx, event->window);
        mlx_put_image_to_window(event->mlx, event->window, event->fogd.img, event->x, event->y);
        usleep(1000);
    }
    return (0);
}

int move_up(int key, t_event *event)
{
    if (key == XK_Up)
    {
        event->display = 2;
        event->y -= 10;
        mlx_clear_window(event->mlx, event->window);
        mlx_put_image_to_window(event->mlx, event->window, event->fogu.img, event->x, event->y);
        usleep(1000);
    }
    return (0);
}

int move_right(int key, t_event *event)
{
    if (key == XK_Right)
    {
        event->display = 3;
        event->x += 10;
        mlx_clear_window(event->mlx, event->window);
        mlx_put_image_to_window(event->mlx, event->window, event->fogr.img, event->x, event->y);
        usleep(1000);
    }
    return (0);
}

int move_left(int key, t_event *event)
{
    if (key == XK_Left)
    {
        event->display = 4;
        event->x -= 10;
        mlx_clear_window(event->mlx, event->window);
        mlx_put_image_to_window(event->mlx, event->window, event->fogl.img, event->x, event->y);
        usleep(1000);
    }
    return (0);
}

int blastshot(int key, t_event *event)
{
    if (key == XK_space && event->display == 3)
    {
        event->blast_active = 1;
        event->blast_pos = 0;
    }
    return (0);
}

int animate_blast(t_event *event)
{
    if (event->blast_active)
    {
        if (event->blast_pos < 350)
        {
            mlx_clear_window(event->mlx, event->window);
            if (event->display == 3)
            {
                mlx_put_image_to_window(event->mlx, event->window, event->fogr.img, event->x, event->y);
                mlx_put_image_to_window(event->mlx, event->window, event->blast.img, event->x + event->blast_pos + 100, event->y + 45);
                event->blast_pos += 10;
                usleep(10000);
            }
        }
        else
        {
            event->blast_active = 0;
            mlx_clear_window(event->mlx, event->window);
            mlx_put_image_to_window(event->mlx, event->window, event->fogr.img, event->x, event->y);
        }
    }
    return (0);
}


int key_handler(int key, t_event *event)
{
    closewindow(key, event);
    move_down(key, event);
    move_up(key, event);
    move_right(key, event);
    move_left(key, event);
    blastshot(key, event);
    return (0);
}

int main(void)
{
    t_event event;
    
    event.x = 100;
    event.y = 30;
    event.fogr.path = "img/fogright.xpm";
    event.fogu.path = "img/fogup.xpm";
    event.fogd.path = "img/fogdown.xpm";
    event.fogl.path = "img/fogleft.xpm";
    event.blast.path = "img/blast.xpm";
    event.mlx = mlx_init();
    event.fogr.img = mlx_xpm_file_to_image(event.mlx, event.fogr.path, &event.fogr.width, &event.fogr.height);
    event.fogu.img = mlx_xpm_file_to_image(event.mlx, event.fogu.path, &event.fogu.width, &event.fogu.height);
    event.fogd.img = mlx_xpm_file_to_image(event.mlx, event.fogd.path, &event.fogd.width, &event.fogd.height);
    event.fogl.img = mlx_xpm_file_to_image(event.mlx, event.fogl.path, &event.fogl.width, &event.fogl.height);
    event.blast.img = mlx_xpm_file_to_image(event.mlx, event.blast.path, &event.blast.width, &event.blast.height);
    event.window = mlx_new_window(event.mlx, 1000, 500, "LINDOOOOOOO!!!!");
    mlx_put_image_to_window(event.mlx, event.window, event.fogr.img, event.x, event.y);
    mlx_key_hook(event.window, key_handler, &event);
    mlx_loop_hook(event.mlx, animate_blast, &event);
    mlx_loop(event.mlx);
    return (0);
}
