/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoutou <daoutou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:40:42 by ehamza            #+#    #+#             */
/*   Updated: 2024/09/18 21:19:44 by daoutou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "globals.h"

int		is_valid_map(char *input);
t_map	*read_map01(char *input);
t_sq	find_bsq(t_map *map);
void	ft_putstr(char *str);
int		calc_file_size(char	*path);
char	*read_file(char *path);
char	**read_files(int ac, char *av[]);
char	*read_stdin(void);
void	free_mem(char **map);
void	print_map(t_map *map, t_sq sq);

#endif