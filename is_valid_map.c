/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:52:34 by ehamza            #+#    #+#             */
/*   Updated: 2024/09/17 22:55:38 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_dups(char *input)
{
	int	i;
	int	j;

	i = 1;
	while (i < 3)
	{
		j = i + 1;
		while (j <= 3)
		{
			if (input[i] == input[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_char(char c, char *input)
{
	if (c == input[1] || c == input[2] || c == input[3] || c == '\n')
		return (1);
	return (0);
}

int	check_str(char *input)
{
	int	i;

	i = 5;
	while (input[i])
	{
		if (check_char(input[i], input) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_len(char *input)
{
	int	i;
	int	len;
	int	line;

	i = 5;
	len = 0;
	line = 0;
	while (input[i] != '\n' && input[i])
	{
		line++;
		i++;
	}
	while (input[i])
	{
		i++;
		len = 0;
		while (input[i] != '\n' && input[i])
		{
			len++;
			i++;
		}
		if (len != line)
			return (0);
	}
	return (1);
}

int	is_valid_map(char *input)
{
	if (input[0] < '0' || input[0] > '9')
		return (0);
	if (check_dups(input) == 0 || input[4] != '\n')
		return (0);
	if (check_len(input) == 0)
		return (0);
	if (check_str(input) == 0)
		return (0);
	return (1);
}
