/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:05:58 by daoutou           #+#    #+#             */
/*   Updated: 2024/09/18 20:43:16 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_H
# define GLOBALS_H

# define PATH_MAX 4096
# define MAP_ERROR "map error\n"

typedef struct s_map
{
	char	**arr;
	int		len;
	int		nb_lines;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

typedef struct s_sq
{
	int	x;
	int	y;
	int	len;
}	t_sq;

#endif