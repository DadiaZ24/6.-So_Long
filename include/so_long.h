/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:02:57 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/08 15:17:43 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//________________________________________________________________
//|_____________________________[LIBS]____________________________|
//|_______________________________________________________________|

# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

//________________________________________________________________
//|____________________[DINAMIC MAP RESOLUTION]___________________|
//|_______________________________________________________________|

# ifndef RES
#  define RES 64
# endif

//________________________________________________________________
//|_________________________[DEFINE COLORS]_______________________|
//|_______________________________________________________________|

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define BLUE "\033[0;36m"
# define DEFAULT_COLOR "\033[0m"

//________________________________________________________________
//|________________________[DEFINE MESSAGES]______________________|
//|_______________________________________________________________|

# define ERROR_TOP "\n======================[SO_LONG]=============\
=============\n\n"
# define ERROR_BOT "==============================================\
===========\n\n"
# define ERROR_PATH "%s%s%sERROR\n%sPlease check your path.\n\
You need to have path to colectibles and to the exit!!!\n\n%s%s%s"
# define ERROR_MAP_CLOSED "%s%s%sERROR\n %sPlease check if your map\
 is closed!\n\n%s%s%s"
# define ERROR_MAP_CHECK "%s%s%sERROR\n %sDoes your map check all \
the criteria?\n\
 %sCheckpoints 	-> %sat least 1\n\
 %sPlayers 	-> %sexactly  1\n\
 %sExits 		-> %sexactly  1\n\n%s%s%s"
# define ERROR_MAP_SQUARE "%s%s%sERROR\n %sYour map needs to be a \
rectangle!\n\n%s%s%s"
# define ERROR_FILE_MAP_PATH "%s%s%sERROR\n %sInvalid map file path!\
\n\n%s%s%s"
# define ERROR_FILE_PATH "%s%s%sERROR\n %sInvalid asset file path! \
Check your files\n\n%s%s%s"
# define ERROR_SIZES "%s%s%sERROR\n %sYour lines does not have the \
same size!\n\n%s%s%s"

//________________________________________________________________
//|________________________[DEFINE OTHERS]________________________|
//|_______________________________________________________________|

# define FILE_EXTENSION ".ber"

//________________________________________________________________
//|________________________[DATA STRUCTURES]______________________|
//|_______________________________________________________________|

typedef struct s_data
{
	void	*img;
	char	*path;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	int		x;
	int		y;
}	t_data;

typedef struct p_byte
{
	int				y;
	int				x;
	int				pi;
	int				bg_x;
	int				bg_y;
	int				bg_pi;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_byte;

typedef struct g_parser
{
	int		x;
	int		y;
	int		i;
	int		players;
	int		colects;
	int		path_colects;
	int		path_exit;
	int		exit;
	char	**map;
}	t_parser;

typedef struct g_event
{
	t_data		player;
	t_data		bg;
	t_data		tile;
	t_data		colect;
	t_parser	parser;
	void		*mlx;
	void		*window;
	int			x;
	int			y;
	int			display;
	int			move_down_trigger;
	int			move_up_trigger;
	int			move_right_trigger;
	int			move_left_trigger;
	int			is_moving;
	int			map_lines;
	int			map_columns;
	int			moves;
	int			sleep;
	char		**map;
	char		*chosen_map;
}	t_event;

//________________________________________________________________
//|______________________[FUNCTION PROTOTYPES]____________________|
//|_______________________________________________________________|

//|--------------MOVEMENT UTILS----------------

int		trigger_move_down(t_event *event);
int		trigger_move_up(t_event *event);
int		trigger_move_right(t_event *event);
int		trigger_move_left(t_event *event);

//|--------------KEY PRESS UTILS----------------

int		on_key_press(int key, t_event *event);
int		on_key_release(int key, t_event *event);
int		update_key_press(t_event *event);
int		key_press_down(t_event *event);
int		key_press_up(t_event *event);
int		key_press_right(t_event *event);
int		key_press_left(t_event *event);

//|--------------INIT UTILS----------------

int		init_key_press(t_event *event);
int		init_data(t_event *event);
int		init_get_img(t_event *event);
void	init_byte_data(t_byte *byte);
void	init_t_data_data(t_event *event);
void	init_player_data(t_data *player);
void	init_int_data(t_event *event);
void	init_img_data(t_event *event);
void	init_put_img(t_event *event);
void	init_loop(t_event *event);

//|--------------MAP UTILS----------------
//MAP PARSER
int		map_parser(t_event *event);
int		parse_close_map(t_event *event);
int		parse_stuff(t_event *event);
int		parse_check_access(t_event *event, char etype);
int		parse_check_path(t_event *event);
int		check_square(t_event *event);
int		check_file_path(t_event *event);
int		check_sizes(t_event *event);
int		free_parser(t_event *event);
void	flood_fill(int x, int y, t_event *event);
void	free_after_parser(t_event *event);
//MAP RENDER
void	set_map_size(t_event *event);
void	load_map(t_event *event);
int		render_corners(t_event *event, int x, int y);
int		render_sides(t_event *event, int x, int y);
int		render_stuff(t_event *event, int x, int y);
int		put_tile(char *path, t_event *event, int x, int y);
int		render_map(t_event *event);
int		put_colectible(char *path, t_event *event, int x, int y);
//MAP COLIDE
int		check_up_no_colects(t_event *event);
int		check_down_no_colects(t_event *event);
int		check_left_no_colects(t_event *event);
int		check_right_no_colects(t_event *event);
int		check_up(t_event *event, int x, int y);
int		check_down(t_event *event, int x, int y);
int		check_left(t_event *event, int x, int y);
int		check_right(t_event *event, int x, int y);
int		temp_check_up(t_event *event);
int		temp_check_down(t_event *event);
int		temp_check_up_no_colect(t_event *event);
int		temp_check_down_no_colect(t_event *event);
int		colide_move_up(t_event *event);
int		colide_move_down(t_event *event);
int		colide_move_right(t_event *event);
int		colide_move_left(t_event *event);
void	is_in_colectible_space_right(t_event *event);
void	is_in_colectible_space_up(t_event *event);
void	is_in_colectible_space_down(t_event *event);
void	is_in_colectible_space_left(t_event *event);
void	is_in_exit_space_down(t_event *event);
void	is_in_exit_space_up(t_event *event);
void	is_in_exit_space_left(t_event *event);
void	is_in_exit_space_right(t_event *event);
void	update_colectible_status(t_event *event, int x, int y);

//|--------------OTHER UTILS----------------

void	replace_black_pixels(t_data *foreground, t_data *background,
			int offset_x, int offset_y);
int		destroy_stuff(t_event *event);
void	free_split(char **split);

#endif