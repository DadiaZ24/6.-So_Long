/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:21:02 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/05 15:26:57 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	flood_fill(int x, int y, t_event *event)
{
	if (x < 0 || x >= event->map_columns
		|| y < 0 || y >= event->map_lines)
		return ;
	if (event->parser.map[y][x] == 'F'
			|| event->parser.map[y][x] == '1')
		return ;
	if (event->parser.map[y][x] == 'C')
	{
		event->parser.map[y][x] = 'F';
		event->parser.path_colects -= 1;
	}
	if (event->parser.map[y][x] == 'E' && !event->parser.path_colects)
	{
		event->parser.map[y][x] = 'F';
		event->parser.path_exit -= 1;
		return ;
	}
	else if (event->parser.map[y][x] == 'E' && event->parser.path_colects)
		return ;
	else if (event->parser.map[y][x] == '0' || event->parser.map[y][x] == 'P')
		event->parser.map[y][x] = 'F';
	flood_fill(x + 1, y, event);
	flood_fill(x - 1, y, event);
	flood_fill(x, y + 1, event);
	flood_fill(x, y - 1, event);
}

int	free_parser(t_event *event)
{
	int	i;

	i = -1;
	while (++i < event->map_lines)
		free(event->parser.map[i]);
	free(event->parser.map);
	return (0);
}

int	check_square(t_event *event)
{
	if (event->map_columns == event->map_lines)
		return (0);
	return (1);
}

int	check_file_path(t_event *event)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(event->chosen_map, '/');
	while (split[i])
		i++;
	i -= 1;
	if (ft_strncmp(ft_strchr(event->chosen_map, '.'), FILE_EXTENSION, 4))
		return (free_split(split), 0);
	if (!ft_strncmp(ft_strchr(event->chosen_map, '.'),
			split[i], ft_strlen(event->chosen_map)))
		return (free_split(split), 0);
	return (free_split(split), 1);
}

int	check_sizes(t_event *event)
{
	int	i;

	i = 0;
	while (++i < event->map_lines)
		if (ft_strlen(event->map[i]) != ft_strlen(event->map[i - 1]))
			return (0);
	return (1);
}
