/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:13:29 by ehamza            #+#    #+#             */
/*   Updated: 2024/09/17 23:14:46 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_lines(char *input)
{
	int	i;
	int	nb;

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
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	return (i);
}

void	z_fill_margin(int **arr, int l, int n_l, char *inp)
{
	int	j;

	j = 0;
	while (j < l + 2)
	{
		arr[0][j] = 0;
		arr[j][0] = 0;
		arr[n_l - 1][j] = 0;
		arr[j][l - 1] = 0;
		j++;
	}
}

void	fill_map(int **arr, int l, int n_l, char *inp)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 5;
	j = 1;
	z_fill_margin(arr, l, n_l, inp);
	while (i < n_l)
	{
		while (j < l)
		{
			if (inp[k] == inp[1])
				arr[i][j] = 1;
			else if (inp[k] == inp[2])
				arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	**read_map01(char *input)
{
	int	**arr_int;
	int	len;
	int	nb_lines;

	nb_lines = count_lines(input);
	len = line_len(&input[5]);
	arr_int = (int **) malloc (sizeof(int *) * nb_lines);
	if (*arr_int == NULL)
		return (NULL);
	fill_map(arr_int, len, nb_lines, input);
	return (arr_int);
}


int main()
{
	int i, j;
	i = j = 0;
	int **arr = read_map01("9.xo\n......\n.o..o.\n..oo..\n..o..o");
	while (arr[i])
	{
		/* code */
	}
	
}