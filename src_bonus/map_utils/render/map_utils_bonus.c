/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:51:15 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/07/04 15:08:36 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long_bonus.h"

void	set_map_size(t_event *event)
{
	char	*tmp;
	int		fd;

	fd = open(event->chosen_map, O_RDONLY);
	tmp = get_next_line(fd);
	event->map_columns = ft_strclen(tmp, '\0');
	while (tmp)
	{
		free (tmp);
		tmp = get_next_line(fd);
		event->map_lines += 1;
	}
	close(fd);
	load_map(event);
}

void	load_map(t_event *event)
{
	int	fd;
	int	i;

	i = 0;
	if (!event->map_lines)
		return ;
	event->map = malloc(sizeof(char *) * (event->map_lines));
	if (!event->map)
		return ;
	fd = open(event->chosen_map, O_RDONLY);
	event->map[i] = get_next_line(fd);
	while (++i < event->map_lines)
		event->map[i] = get_next_line(fd);
	close(fd);
}
