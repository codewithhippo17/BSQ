/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoutou <daoutou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:27:26 by ehamza            #+#    #+#             */
/*   Updated: 2024/09/18 21:11:59 by daoutou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str && str[idx])
	{
		write(1, &str[idx], 1);
		idx += 1;
	}
}

int	line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	return (i);
}

int	count_lines(char *input)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

int	min(int a, int b, int c)
{
	int	n;

	n = a;
	if (b < n)
		n = b;
	if (c < n)
		n = c;
	return (n);
}
