/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoutou <daoutou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:13:29 by ehamza            #+#    #+#             */
/*   Updated: 2024/09/18 20:57:00 by daoutou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

char	**create_map(int x, int y);
int		line_len(char *line);
int		count_lines(char *input);

void	z_fill_margin(t_map *map)
{
	int	j;

	map->arr[map->nb_lines] = malloc(map->len + 2);
	map->arr[map->nb_lines][map->len + 1] = 0;
	j = 0;
	while (j < map->len + 1)
	{
		map->arr[map->nb_lines][j] = '0';
		j++;
	}
	j = 0;
	while (j < map->nb_lines + 1)
	{
		map->arr[j][map->len] = '0';
		j++;
	}
}

void	fill_map(t_map *map, char *inp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 5;
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->len)
		{
			map->arr[i][j] = inp[k];
			k++;
			j++;
		}
		map->arr[i][map->len + 1] = 0;
		k++;
		i++;
	}
	z_fill_margin(map);
}

t_map	*read_map01(char *input)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->nb_lines = count_lines(input);
	map->len = line_len(&input[5]);
	map->empty = input[1];
	map->obstacle = input[2];
	map->full = input[3];
	map->arr = create_map(map->len + 1, map->nb_lines + 1);
	if (!map->arr)
		return (0);
	fill_map(map, input);
	return (map);
}
