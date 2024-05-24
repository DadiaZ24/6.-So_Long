/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:51:15 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/05/24 20:05:03 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
}