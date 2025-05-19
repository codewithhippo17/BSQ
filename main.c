/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoutou <daoutou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:02:26 by daoutou           #+#    #+#             */
/*   Updated: 2024/09/18 21:54:57 by daoutou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"
#include "main.h"
#include <stdlib.h>

void	start(char	**files, int size)
{
	int		i;
	t_map	*map;
	t_sq	sq;

	i = 0;
	while (i < size)
	{
		if (i != 0)
			ft_putstr("\n");
		if (!(files[i] && is_valid_map(files[i])))
		{
			ft_putstr(MAP_ERROR);
			if (files[i])
				free(files[i]);
			i += 1;
			continue ;
		}
		map = read_map01(files[i]);
		sq = find_bsq(map);
		print_map(map, sq);
		free(files[i]);
		free_mem(map->arr);
		free(map);
		i += 1;
	}
}

int	main(int ac, char *av[])
{
	char	**files;
	int		interactive;

	interactive = ac == 1;
	while (1)
	{
		if (interactive)
		{
			ac = 2;
			av[1] = read_stdin();
		}
		files = read_files(ac, av);
		start(files, ac - 1);
		if (interactive)
			free(av[1]);
		else
			break ;
	}
	return (0);
}
