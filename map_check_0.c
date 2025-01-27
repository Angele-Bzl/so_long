/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:09:21 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/20 17:43:02 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_tab(char **tab, int i)
{
	i--;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static int	check_square(char *map)
{
	int		i;
	size_t	size;
	char	**lines;

	i = 0;
	lines = ft_split(map, '\n');
	if (!lines)
		return (ft_putstr_fd("Error\nNo map\n", ERROR), 0);
	size = ft_strlen(lines[i]);
	while (lines[i])
	{
		if (size != ft_strlen(lines[i]))
		{
			free_tab(lines, i);
			return (ft_putstr_fd("Error\nMap is not rectangular\n", ERROR), 0);
		}
		i++;
	}
	free_tab(lines, i);
	return (1);
}

static int	check_border(char *map, char wall)
{
	int		i;
	int		j;
	char	**lines;

	i = 0;
	lines = ft_split(map, '\n');
	if (!lines)
		return (ft_putstr_fd("Error\nNo map\n", ERROR), 0);
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if ((j == 0 || !lines[i][j + 1] || i == 0 || !lines[i + 1])
				&& lines[i][j] != wall)
			{
				free_tab(lines, i);
				return (ft_putstr_fd("Error\nNot enough borders\n", ERROR), 0);
			}
			j++;
		}
		i++;
	}
	free_tab(lines, i);
	return (1);
}

static int	check_space(char *flood)
{
	if (find_char(flood, 'C') || find_char(flood, 'E'))
	{
		ft_putstr_fd("Error\nYour map is not doable\n", ERROR);
		return (0);
	}
	return (1);
}

int	map_ok(char *map)
{
	char	*flood;

	if (!check_square(map))
		return (0);
	if (!check_border(map, '1'))
		return (0);
	if (!check_one_e(map, 'E'))
		return (0);
	if (!check_one_p(map, 'P'))
		return (0);
	if (!check_min_c(map, 'C'))
		return (0);
	flood = ft_strdup(map);
	if (!flood)
		return (ft_putstr_fd("Error\n", ERROR), 0);
	flood_fill(flood, find_char(flood, 'P'));
	if (!check_space(flood))
		return (free(flood), 0);
	free(flood);
	return (1);
}
