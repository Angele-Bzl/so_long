/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:01:47 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/31 13:29:48 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*return the number of occurence of the chosen character*/
int	count_char(char *map, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == c)
			count++;
		i++;
	}
	return (count);
}

/*return 1 if the chosen character has been found*/
int	find_char(char *map, char c)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	skip_line(t_my_img *img, int *i, size_t *len)
{
	while (img->win.map[*i] != '\n')
	{
		(*len)++;
		(*i)++;
	}
}
