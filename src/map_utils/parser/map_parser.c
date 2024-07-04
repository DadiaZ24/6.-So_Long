/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:30:03 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/04 17:40:59 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	map_parser(t_event *event)
{
	if (!check_file_path(event))
		return (ft_printf(ERROR_FILE_MAP_PATH, BLUE, ERROR_TOP, RED,
				DEFAULT_COLOR, BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
	if (!parse_close_map(event))
		return (ft_printf(ERROR_MAP_CLOSED, BLUE, ERROR_TOP, RED,
				DEFAULT_COLOR, BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
	if (!parse_stuff(event))
		return (ft_printf(ERROR_MAP_CHECK, BLUE, ERROR_TOP, RED,
				DEFAULT_COLOR, BLUE, DEFAULT_COLOR, BLUE, DEFAULT_COLOR,
				BLUE, DEFAULT_COLOR, BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
	if (!parse_check_path(event))
		return (ft_printf(ERROR_PATH, BLUE, ERROR_TOP, RED, DEFAULT_COLOR,
				BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
	if (!check_square(event))
		return (ft_printf(ERROR_MAP_SQUARE, BLUE, ERROR_TOP, RED,
				DEFAULT_COLOR, BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
	if (!check_sizes(event))
		return (ft_printf(ERROR_SIZES, BLUE, ERROR_TOP, RED, DEFAULT_COLOR,
				BLUE, ERROR_BOT, DEFAULT_COLOR), 0);
	return (1);
}

int	parse_close_map(t_event *event)
{
	int	i;

	i = 0;
	while (event->map[0][i])
		if (event->map[0][i++] != '1')
			return (0);
	i = 0;
	while (event->map[event->map_lines - 1][i])
		if (event->map[event->map_lines - 1][i++] != '1')
			return (0);
	i = 0;
	while (i < event->map_lines)
		if (event->map[i++][0] != '1')
			return (0);
	i = 0;
	while (i < event->map_lines)
		if (event->map[i++][event->map_columns - 1] != '1')
			return (0);
	return (1);
}

int	parse_stuff(t_event *event)
{
	while (++event->parser.y < event->map_lines)
	{
		event->parser.x = -1;
		while (++event->parser.x < event->map_columns)
		{
			if (event->map[event->parser.y][event->parser.x] == 'P')
				if (!parse_check_access(event, 'P'))
					return (0);
			if (event->map[event->parser.y][event->parser.x] == 'E')
				if (!parse_check_access(event, 'E'))
					return (0);
			if (event->map[event->parser.y][event->parser.x] == 'C')
				if (!parse_check_access(event, 'C'))
					return (0);
		}
	}
	if (event->parser.players != 1 || event->parser.colects < 1
		|| event->parser.exit != 1)
		return (0);
	return (1);
}

int	parse_check_access(t_event *event, char etype)
{
	if (etype == 'P')
	{
		event->parser.players += 1;
		event->x = event->parser.x;
		event->y = event->parser.y;
	}
	else if (etype == 'E')
	{
		event->parser.exit += 1;
		event->parser.path_exit += 1;
	}
	else if (etype == 'C')
	{
		event->parser.colects += 1;
		event->parser.path_colects += 1;
	}
	else
		return (printf("//PARSE_CHECK_ACCESS ERROR\\: Type not found"), 0);
	return (1);
}

int	parse_check_path(t_event *event)
{
	event->parser.y = -1;
	event->parser.map = (char **)malloc(sizeof(char *)
			* (event->map_lines + 1));
	while (++event->parser.y < event->map_lines)
		event->parser.map[event->parser.y] = ft_strdup(event->map[event->parser.y]);
	event->parser.y = event->y;
	event->parser.x = event->x;
	flood_fill(event->parser.x, event->parser.y, event);
	event->parser.y = -1;
	while (++event->parser.y < event->map_lines)
	{
		event->parser.x = -1;
		while (++event->parser.x < event->map_columns)
			if (event->parser.map[event->parser.y][event->parser.x] != 'F'
					&& event->parser.map[event->parser.y][event->parser.x] != '1')
				return (free_parser(event));
	}
	free_parser(event);
	return (1);
}
