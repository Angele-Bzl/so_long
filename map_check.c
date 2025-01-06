/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:09:21 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/02 10:29:36 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	check_square(char **lines, int i)
{
	int	size;

	size = ft_strlen(lines[i]);
	while (lines[i])
	{
		if (size != ft_strlen(lines[i]))
		{
			ft_putstr_fd("Error\nYour map is invalid : not rectangular\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_border(char **lines, int i, char wall)
{
	int	j;

	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if ((j == 0 || !lines[i][j + 1] || i == 0 || !lines[i + 1]) && j != wall)
			{
				ft_putstr_fd("Error\nYour map is invalid : not surrounded by walls\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int check_one_e(char **lines, int i, char exit)
{
	int j;
	int e;

	j = 0;
	e = 0;
	while (lines[i])
	{
		while (lines[i][j])
		{
			if (lines[i][j] == exit && e == 0)
				e++;
			j++;
		}
		i++;
	}
	if (e != 1)
	{
		ft_putstr_fd("Error\nYour map is invalid : incorrect number of exit (expected : 1)\n", 2);
		return (0);
	}
	return (1);
}

int check_one_p(char **lines, int i, char person)
{
	int j;
	int p;

	j = 0;
	p = 0;
	while (lines[i])
	{
		while (lines[i][j])
		{
			if (lines[i][j] == person && p == 0)
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
	{
		ft_putstr_fd("Error\nYour map is invalid : incorrect number of character (expected : 1)\n", 2);
		return (0);
	}
	return (1);
}

int check_min_c(char **lines, int i, char collect)
{
	int j;
	int c;

	j = 0;
	c = 0;
	while (lines[i])
	{
		while (lines[i][j])
		{
			if (lines[i][j] == collect)
				c++;
			j++;
		}
		i++;
	}
	if (c == 0)
	{
		ft_putstr_fd("Error\nYour map is invalid : no collectible\n", 2);
		return (0);
	}
	return (c);
}

int check_space(char **lines, int i, char space)
{
	int j;

	j = 0;

	return (1);
}

int	map_ok(char *map)
{
	char **lines;
	size_t	i;

	i = 0;
	lines = ft_split(map, '\n');
	if (!lines || !check_square(lines, i))
	{
		ft_putstr_fd("Error\nYour map is invalid : no map or not rectangle\n", 2);
		return (0);
	}
	if (!check_border(lines, i, '1'))
		return (0); //check that there are border
	if (!check_one_e(lines, i, 'e'))
		return (0); // check that there is one exit
	if (!check_one_p(lines, i, 'p'))
		return (0); // check that there is one character
	if (!check_min_c(lines, i, 'c'))
		return (0); // check that there is minimum one collectible
	if (!check_space(lines, i, '0'))
		return (0); //check that you can move and pick every collectible and leave
	return (1);
}
