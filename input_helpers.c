/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoutou <daoutou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:31:39 by ehamza            #+#    #+#             */
/*   Updated: 2024/09/18 21:26:19 by daoutou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		is_valid_map(char *input);
t_map	*read_map01(char *input);
t_sq	find_bsq(t_map *map);
void	ft_putstr(char *str);

int	calc_file_size(char	*path)
{
	char	*buf;
	int		fd;
	int		size;
	int		n;

	fd = open(path, O_RDONLY);
	buf = malloc(16);
	size = 0;
	while (fd > -1 && buf)
	{
		n = read(fd, buf, 16);
		if (n < 0)
			return (-1);
		if (n == 0)
			break ;
		size += n;
	}
	if (fd > -1)
		close(fd);
	if (buf)
		free(buf);
	if (fd < 0 || !buf)
		return (-1);
	return (size);
}

char	*read_file(char *path)
{
	char	*buf;
	int		fd;
	int		size;
	int		idx;

	fd = open(path, O_RDONLY);
	size = calc_file_size(path);
	buf = 0;
	if (size >= 0 && fd > -1)
		buf = malloc(size + 1);
	idx = -16;
	while (buf && idx < size - 16)
	{
		idx += 16;
		if (read(fd, (buf + idx), 16) > -1)
			continue ;
		free(buf);
		buf = 0;
	}
	if (fd > -1)
		close(fd);
	if (buf)
		buf[size] = 0;
	return (buf);
}

char	**read_files(int ac, char *av[])
{
	char	**files;
	int		idx;

	files = malloc(sizeof(char *) * (ac - 1));
	idx = 1;
	while (idx < ac)
	{
		files[idx - 1] = read_file(av[idx]);
		idx += 1;
	}
	return (files);
}

char	*read_stdin(void)
{
	char	*buf;
	int		size;

	buf = malloc(PATH_MAX);
	if (!buf)
		return (0);
	size = 0;
	while (size < PATH_MAX)
	{
		read(0, buf + size, 1);
		if (buf[size] == 10)
		{
			buf[size] = 0;
			if (!size)
				continue ;
			else
				break ;
		}
		size += 1;
	}
	return (buf);
}
