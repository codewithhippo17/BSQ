/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:12:42 by ehamza            #+#    #+#             */
/*   Updated: 2024/09/17 23:06:54 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_lines(char *input)
{
	int i;
	int nb;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

int	line_len(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		i++;
	}
	return (i);
}

int **read_map01(char *input)
{
	int	**arr_int;
	int	i;
	int	j;
	int	k;
	int line_len;
	int nb_lines;

	i = 1;
	k = 5;
	nb_lines = count_lines(input);
	line_len = line_len(&input[5]);
	arr_int = (int **) malloc (sizeof(int *) * nb_lines);
	j = 0;
	while (j < line_len + 2)
	{
		arr_int[0][j] = 0;
		arr_int[j][0] = 0;
		arr_int[nb_lines - 1][j] = 0;
		arr_int[j][line_len - 1] = 0;
		j++;
	}
	j = 1;
	while (i < nb_lines)
	{
		while (j < line_len)
		{
			if (input[k] == input[1])
				arr_int[i][j] = 1;
			else if (input[k] == input[2])
				arr_int[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr_int);
}
