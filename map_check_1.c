/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:41:38 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/20 17:40:53 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_one_e(char *map, char exit)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (map[i])
	{
		if (map[i] == exit)
			e++;
		i++;
	}
	if (e != 1)
	{
		ft_putstr_fd("Error\nIncorrect number of exit (expected : 1)\n", ERROR);
		return (0);
	}
	return (1);
}

int	check_one_p(char *map, char person)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		if (map[i] == person)
			p++;
		i++;
	}
	if (p != 1)
	{
		ft_putstr_fd("Error\nIncorrect number of player\n", ERROR);
		return (0);
	}
	return (1);
}

int	check_min_c(char *map, char collect)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		if (map[i] == collect)
			c++;
		i++;
	}
	if (c == 0)
	{
		ft_putstr_fd("Error\nYour map is invalid : no collectible\n", ERROR);
		return (0);
	}
	return (c);
}
