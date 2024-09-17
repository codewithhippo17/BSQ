/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoutou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:02:26 by daoutou           #+#    #+#             */
/*   Updated: 2024/09/17 11:46:50 by daoutou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

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
	while (buf && idx < size)
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

#define	PATH_MAX 4096
char	*read_stdin()
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
		int i = 0;
		while (i < ac - 1)
		{
			ft_putstr(files[i]);
			if (files[i])
				free(files[i]);
			i += 1;
		}

		if (interactive)
			free(av[1]);
		else
			break ;
	}
}
