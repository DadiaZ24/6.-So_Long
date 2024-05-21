/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:01:29 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/21 21:04:57 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int initkeypress(t_event *event)
{
    event->move_down_trigger = 0;
    event->move_up_trigger = 0;
    event->move_right_trigger = 0;
    event->move_left_trigger = 0;
    return (0);
}

int OnKeyPress(int key, t_event *event)
{
    if (key == XK_Down)
    {
        event->move_down_trigger = 1;
        event->display = 1;
    }
    if (key == XK_Up)
    {
        event->move_up_trigger = 1;
        event->display = 2;
    }
    if (key == XK_Right)
    {
        event->move_right_trigger = 1;
        event->display = 3;
    }
    if (key == XK_Left)
    {
        event->move_left_trigger = 1;
        event->display = 4;
    }
    if (key == XK_space)
    {
        if (event->display == 1)
            event->blast_active = 1;
        if (event->display == 2)
            event->blast_active = 2;
        if (event->display == 3)
            event->blast_active = 3;
        if (event->display == 4)
            event->blast_active = 4;
        event->blast_pos = 0;
    }
    if (key == XK_Escape)
    {
        mlx_clear_window(event->mlx, event->window);
        mlx_destroy_window(event->mlx, event->window);
        exit(0);
    }
    return (0);
}

int OnKeyNotPress(int key, t_event *event)
{
    if (key == XK_Down)
        event->move_down_trigger = 0;
    if (key == XK_Up)
        event->move_up_trigger = 0;
    if (key == XK_Right)
        event->move_right_trigger = 0;
    if (key == XK_Left)
        event->move_left_trigger = 0;
    return (0);
}

int UpdateKeyPress(t_event *event)
{
    if (event->move_down_trigger)
    {
        event->y += 3;
        event->display = 1;
        mlx_destroy_image(event->mlx, event->fogd.img);
        event->fogd.img = mlx_xpm_file_to_image(event->mlx, event->fogd.path, &event->fogd.width, &event->fogd.height);
        event->fogd.data = mlx_get_data_addr(event->fogd.img, &event->fogd.bpp, &event->fogd.size_line, &event->fogd.endian);
        replace_black_pixels(&event->fogd, &event->bg, event->x, event->y, 1);
        mlx_put_image_to_window(event->mlx, event->window, event->fogd.img, event->x, event->y);
    }
    if (event->move_up_trigger)
    {
        event->display = 2;
        event->y -= 3;
        mlx_destroy_image(event->mlx, event->fogu.img);
        event->fogu.img = mlx_xpm_file_to_image(event->mlx, event->fogu.path, &event->fogu.width, &event->fogu.height);
        event->fogu.data = mlx_get_data_addr(event->fogu.img, &event->fogu.bpp, &event->fogu.size_line, &event->fogu.endian);
        replace_black_pixels(&event->fogu, &event->bg, event->x, event->y, 0);
        mlx_put_image_to_window(event->mlx, event->window, event->fogu.img, event->x, event->y);
    }
    if (event->move_right_trigger)
    {
        event->display = 3;
        event->x += 3;
        mlx_destroy_image(event->mlx, event->fogr.img);
        event->fogr.img = mlx_xpm_file_to_image(event->mlx, event->fogr.path, &event->fogr.width, &event->fogr.height);
        event->fogr.data = mlx_get_data_addr(event->fogr.img, &event->fogr.bpp, &event->fogr.size_line, &event->fogr.endian);
        replace_black_pixels(&event->fogr, &event->bg, event->x, event->y, 0);
        mlx_put_image_to_window(event->mlx, event->window, event->fogr.img, event->x, event->y);
    }
    if (event->move_left_trigger)
    {
        event->display = 4;
        event->x -= 3;
        mlx_destroy_image(event->mlx, event->fogl.img);
        event->fogl.img = mlx_xpm_file_to_image(event->mlx, event->fogl.path, &event->fogl.width, &event->fogl.height);
        event->fogl.data = mlx_get_data_addr(event->fogl.img, &event->fogl.bpp, &event->fogl.size_line, &event->fogl.endian);
        replace_black_pixels(&event->fogl, &event->bg, event->x, event->y, 0);
        mlx_put_image_to_window(event->mlx, event->window, event->fogl.img, event->x, event->y);
    }
    animate_blast(event);
    usleep(23000);
    return (0);
}

int animate_blast(t_event *event)
{
    if (event->blast_active == 3 && event->blast_pos < 350)
    {
        mlx_destroy_image(event->mlx, event->blast.img);
        event->blast.img = mlx_xpm_file_to_image(event->mlx, event->blast.path, &event->blast.width, &event->blast.height);
        event->blast.data = mlx_get_data_addr(event->blast.img, &event->blast.bpp, &event->blast.size_line, &event->blast.endian);
        replace_black_pixels(&event->blast, &event->bg, event->x + event->blast_pos + 100, event->y + 45, 0);
        mlx_put_image_to_window(event->mlx, event->window, event->blast.img, event->x + event->blast_pos + 100, event->y + 45);
        event->blast_pos += 10;
    }
    else if (event->blast_active == 1 && event->blast_pos < 350)
    {
        mlx_destroy_image(event->mlx, event->blast.img);
        event->blast.img = mlx_xpm_file_to_image(event->mlx, event->blast.path, &event->blast.width, &event->blast.height);
        event->blast.data = mlx_get_data_addr(event->blast.img, &event->blast.bpp, &event->blast.size_line, &event->blast.endian);
        replace_black_pixels(&event->blast, &event->bg, event->x, event->y, 0);
        mlx_put_image_to_window(event->mlx, event->window, event->blast.img, event->x, event->y + event->blast_pos + 100);
        event->blast_pos += 10;
    }
    else if (event->blast_active == 2 && event->blast_pos < 350)
    {
        mlx_destroy_image(event->mlx, event->blast.img);
        event->blast.img = mlx_xpm_file_to_image(event->mlx, event->blast.path, &event->blast.width, &event->blast.height);
        event->blast.data = mlx_get_data_addr(event->blast.img, &event->blast.bpp, &event->blast.size_line, &event->blast.endian);
        replace_black_pixels(&event->blast, &event->bg, event->x, event->y, 0);
        mlx_put_image_to_window(event->mlx, event->window, event->blast.img, event->x, event->y - event->blast_pos - 100);
        event->blast_pos += 10;
    }
    else if (event->blast_active == 4 && event->blast_pos < 350)
    {
        mlx_destroy_image(event->mlx, event->blast.img);
        event->blast.img = mlx_xpm_file_to_image(event->mlx, event->blast.path, &event->blast.width, &event->blast.height);
        event->blast.data = mlx_get_data_addr(event->blast.img, &event->blast.bpp, &event->blast.size_line, &event->blast.endian);
        replace_black_pixels(&event->blast, &event->bg, event->x, event->y, 0);
        mlx_put_image_to_window(event->mlx, event->window, event->blast.img, event->x - event->blast_pos - 100, event->y + 45);
        event->blast_pos += 10;
    }
    else
    {
        if (event->blast_active == 3)
        {
            event->blast_active = 0;
            mlx_destroy_image(event->mlx, event->blast.img);
            event->blast.img = mlx_xpm_file_to_image(event->mlx, event->blast.path, &event->blast.width, &event->blast.height);
            replace_black_pixels(&event->blast, &event->bg, event->x + event->blast_pos + 100, event->y + 45, 1);
            mlx_put_image_to_window(event->mlx, event->window, event->blast.img, event->x + event->blast_pos + 100, event->y + 45);
        }
        if (event->blast_active == 1)
        {
            event->blast_active = 0;
            mlx_destroy_image(event->mlx, event->blast.img);
            event->blast.img = mlx_xpm_file_to_image(event->mlx, event->blast.path, &event->blast.width, &event->blast.height);
            mlx_clear_window(event->mlx, event->window);
            replace_black_pixels(&event->blast, &event->bg, event->x, event->y, 1);
            mlx_put_image_to_window(event->mlx, event->window, event->bg.img, 0, 0);
        }
        if (event->blast_active == 2)
        {
            event->blast_active = 0;
            mlx_destroy_image(event->mlx, event->blast.img);
            event->blast.img = mlx_xpm_file_to_image(event->mlx, event->blast.path, &event->blast.width, &event->blast.height);
            mlx_clear_window(event->mlx, event->window);
            replace_black_pixels(&event->blast, &event->bg, event->x, event->y, 1);
            mlx_put_image_to_window(event->mlx, event->window, event->bg.img, 0, 0);
        }
        if (event->blast_active == 4)
        {
            event->blast_active = 0;
            mlx_destroy_image(event->mlx, event->blast.img);
            event->blast.img = mlx_xpm_file_to_image(event->mlx, event->blast.path, &event->blast.width, &event->blast.height);
            mlx_clear_window(event->mlx, event->window);
            replace_black_pixels(&event->blast, &event->bg, event->x, event->y, 1);
            mlx_put_image_to_window(event->mlx, event->window, event->bg.img, 0, 0);
            mlx_put_image_to_window(event->mlx, event->window, event->fogl.img, event->x, event->y);
        }
    }
    return (0);
}

void replace_black_pixels(t_data *icon, t_data *bg, int offset_x, int offset_y, int erase)
{
    t_byte byte;
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
            if (erase == 1 && byte.x < 10)
                    printf("ENTREEIIIIIII!!!!");
            if ((byte.r == 0 && byte.g == 0 && byte.b == 0) || erase == 1) 
            {
                if (erase == 1 && byte.x < 10)
                    printf("ENTREEIIIIIII!!!!");
                icon->data[byte.pi + 2] = bg->data[byte.bg_pi + 2];
                icon->data[byte.pi + 1] = bg->data[byte.bg_pi + 1];
                icon->data[byte.pi] = bg->data[byte.bg_pi];
            }
        } 
    }
}

int main(void)
{
    t_event event;

    initkeypress(&event);
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
    
    event.window = mlx_new_window(event.mlx, 1024, 800, "TESTEEEEEEEE");
    event.bg.path = "img/starwars.xpm";
    event.bg.img = mlx_xpm_file_to_image(event.mlx, event.bg.path, &event.bg.width, &event.bg.height);
    event.bg.data = mlx_get_data_addr(event.bg.img, &event.bg.bpp, &event.bg.size_line, &event.bg.endian);
    event.fogr.data = mlx_get_data_addr(event.fogr.img, &event.fogr.bpp, &event.fogr.size_line, &event.fogr.endian);
    
    replace_black_pixels(&event.fogr, &event.bg, event.x, event.y, 0);
    mlx_put_image_to_window(event.mlx, event.window, event.bg.img, 0, 0);
    mlx_put_image_to_window(event.mlx, event.window, event.fogr.img, event.x, event.y);
    mlx_hook(event.window, KeyPress, KeyPressMask, OnKeyPress, &event);
    mlx_hook(event.window, KeyRelease, KeyReleaseMask, OnKeyNotPress, &event);
    mlx_loop_hook(event.mlx, UpdateKeyPress, &event);
    mlx_loop(event.mlx);
    return (0);    
}