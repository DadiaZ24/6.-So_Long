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
        mlx_clear_window(event->mlx, event->window);
        mlx_put_image_to_window(event->mlx, event->window, event->fogd.img, event->x, event->y);
    }
    if (event->move_up_trigger)
    {
        event->display = 2;
        event->y -= 3;
        mlx_clear_window(event->mlx, event->window);
        mlx_put_image_to_window(event->mlx, event->window, event->fogu.img, event->x, event->y);
        //usleep(1000);
    }
    if (event->move_right_trigger)
    {
        event->display = 3;
        event->x += 3;
        mlx_clear_window(event->mlx, event->window);
        mlx_put_image_to_window(event->mlx, event->window, event->fogr.img, event->x, event->y);
        //usleep(1000);
    }
    if (event->move_left_trigger)
    {
        event->display = 4;
        event->x -= 3;
        mlx_clear_window(event->mlx, event->window);
        mlx_put_image_to_window(event->mlx, event->window, event->fogl.img, event->x, event->y);
        //usleep(1000);
    }
    animate_blast(event);
    usleep(23000);
    return (0);
}

int animate_blast(t_event *event)
{
    if (event->blast_active == 3 && event->blast_pos < 350)
    {
        mlx_clear_window(event->mlx, event->window);
        mlx_put_image_to_window(event->mlx, event->window, event->fogr.img, event->x, event->y);
        mlx_put_image_to_window(event->mlx, event->window, event->blast.img, event->x + event->blast_pos + 100, event->y + 45);
        event->blast_pos += 10;
    }
    else if (event->blast_active == 1 && event->blast_pos < 350)
    {
        mlx_clear_window(event->mlx, event->window);
        mlx_put_image_to_window(event->mlx, event->window, event->fogd.img, event->x, event->y);
        mlx_put_image_to_window(event->mlx, event->window, event->blast.img, event->x, event->y + event->blast_pos + 100);
        event->blast_pos += 10;
    }
    else if (event->blast_active == 2 && event->blast_pos < 350)
    {
        mlx_clear_window(event->mlx, event->window);
        mlx_put_image_to_window(event->mlx, event->window, event->fogu.img, event->x, event->y);
        mlx_put_image_to_window(event->mlx, event->window, event->blast.img, event->x, event->y - event->blast_pos - 100);
        event->blast_pos += 10;
    }
    else if (event->blast_active == 4 && event->blast_pos < 350)
    {
        mlx_clear_window(event->mlx, event->window);
        mlx_put_image_to_window(event->mlx, event->window, event->fogl.img, event->x, event->y);
        mlx_put_image_to_window(event->mlx, event->window, event->blast.img, event->x  - event->blast_pos - 100, event->y + 45);
        event->blast_pos += 10;
    }
    else
    {
        if (event->blast_active == 3)
        {
            event->blast_active = 0;
            mlx_clear_window(event->mlx, event->window);
            mlx_put_image_to_window(event->mlx, event->window, event->fogr.img, event->x, event->y); 
        }
        if (event->blast_active == 1)
        {
            event->blast_active = 0;
            mlx_clear_window(event->mlx, event->window);
            mlx_put_image_to_window(event->mlx, event->window, event->fogd.img, event->x, event->y);
        }
        if (event->blast_active == 2)
        {
            event->blast_active = 0;
            mlx_clear_window(event->mlx, event->window);
            mlx_put_image_to_window(event->mlx, event->window, event->fogu.img, event->x, event->y);
        }
        if (event->blast_active == 4)
        {
            event->blast_active = 0;
            mlx_clear_window(event->mlx, event->window);
            mlx_put_image_to_window(event->mlx, event->window, event->fogl.img, event->x, event->y);
        }
    }
        
        /* else
        {
            event->blast_active = 0;
            mlx_clear_window(event->mlx, event->window);
            mlx_put_image_to_window(event->mlx, event->window, event->fogr.img, event->x, event->y);
        } */
    return (0);
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
    event.window = mlx_new_window(event.mlx, 1000, 500, "LINDOOOOOOO!!!!");
    mlx_put_image_to_window(event.mlx, event.window, event.fogr.img, event.x, event.y);
    mlx_hook(event.window, KeyPress, KeyPressMask, OnKeyPress, &event);
    mlx_hook(event.window, KeyRelease, KeyReleaseMask, OnKeyNotPress, &event);
    mlx_loop_hook(event.mlx, UpdateKeyPress, &event);
    mlx_loop(event.mlx);
    return (0);
}