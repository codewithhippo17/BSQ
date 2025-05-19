/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoutou <daoutou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:37:16 by ehamza            #+#    #+#             */
/*   Updated: 2024/09/18 21:07:57 by daoutou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"

int		min(int a, int b, int c);
char	**create_map(int x, int y);

int	check(t_map *map, char **cache, int x, int y)
{
	char	current;
	char	right;
	char	bottom_right;
	char	bottom;

	if (x >= map->len || y >= map->nb_lines)
		return (0);
	current = cache[y][x];
	if (current >= '0' && current <= '9')
		return (current - '0');
	right = check(map, cache, x, y + 1);
	bottom_right = check(map, cache, x + 1, y + 1);
	bottom = check(map, cache, x + 1, y);
	cache[y][x] = 0;
	if (map->arr[y][x] == map->obstacle)
		cache[y][x] = '0';
	else
		cache[y][x] = 1 + min(right, bottom_right, bottom) + '0';
	return (cache[y][x] - '0');
}

t_sq	locate_biggest(char **cache, int size)
{
	int		i;
	int		j;
	int		max;
	t_sq	square;

	max = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (cache[i][j])
		{
			if (cache[i][j] - '0' > max)
			{
				max = cache[i][j] - '0';
				square.y = i;
				square.x = j;
				square.len = max;
			}
			j += 1;
		}
		i += 1;
	}
	return (square);
}

t_sq	find_bsq(t_map *map)
{
	char	**cache;
	t_sq	square;

	cache = create_map(map->len, map->nb_lines);
	check(map, cache, 0, 0);
	square = locate_biggest(cache, map->nb_lines);
	return (square);
}
