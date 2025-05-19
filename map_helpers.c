/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoutou <daoutou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:54:49 by ehamza            #+#    #+#             */
/*   Updated: 2024/09/18 21:54:03 by daoutou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"
#include <stdlib.h>
#include <unistd.h>

void	free_mem(char **map)
{
	int	idx;

	idx = 0;
	while (map[idx])
	{
		free(map[idx]);
		idx += 1;
	}
	free(map);
}

char	**create_map(int x, int y)
{
	char	**map;
	int		i;
	int		j;

	map = malloc((y + 2) * sizeof(char *));
	i = 0;
	while (map && i < y)
	{
		map[i] = malloc(x + 1);
		map[i + 1] = 0;
		if (!map[i])
		{
			free_mem(map);
			return (0);
		}
		j = 0;
		while (j < x + 1)
		{
			map[i][j] = 0;
			j += 1;
		}
		i += 1;
	}
	return (map);
}

void	print_map(t_map *map, t_sq sq)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->len)
		{
			if (i >= sq.y && i < sq.y + sq.len
				&& j >= sq.x && j < sq.x + sq.len)
				write(1, &map->full, 1);
			else
				write(1, &map->arr[i][j], 1);
			j += 1;
		}
		write(1, "\n", 1);
		i += 1;
	}
}
