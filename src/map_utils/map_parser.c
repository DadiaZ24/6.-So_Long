/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:30:03 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/29 10:30:41 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	map_parser(t_event *event)
{
	if (!parse_stuff(event))
		return (0);
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
	event->parser.y = -1;
	while (++event->parser.y < event->map_lines)
	{
		event->parser.x = -1;
		while (++event->parser.x < event->map_columns)
		{
			if (event->map[event->parser.y][event->parser.x] == 'P')
			{
				if (!parse_check_access(event, 'P'))
					return (0);
			}
			else if (event->map[event->parser.y][event->parser.x] == 'E')
			{
				if (!parse_check_access(event, 'E'))
					return (0);
			}
			else if (event->map[event->parser.y][event->parser.x] == 'C')
			{
				if (!parse_check_access(event, 'C'))
					return (0);
			}
		}
	}
	if (event->parser.players != 1 || event->parser.colects < 1 || event->parser.exit != 1)
		return (0);
	return (1);
}

int	parse_check_access(t_event *event, char etype)
{
	if ((event->map[event->parser.y - 1][event->parser.x] != '0')
			&& (event->map[event->parser.y + 1][event->parser.x] != '0')
			&& (event->map[event->parser.y][event->parser.x + 1] != '0')
			&& (event->map[event->parser.y][event->parser.x - 1] != '0'))
		return (0);
	if (etype == 'P')
		event->parser.players += 1;
	else if (etype == 'E')
		event->parser.exit += 1;
	else if (etype == 'C')
		event->parser.colects += 1;
	else
	{
		printf("//PARSE_CHECK_ACCESS ERROR\\: Type not found");
		return (0);
	}
	return (1);
}