/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:21:56 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/08 11:32:06 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

void	flood_fill(char *flood, int target)
{
	int	n_line;

	n_line = find_char(flood, '\n') + 1;
	if (flood[target] != '1')
	{
		flood[target] = '1';
		flood_fill(flood, target + 1);
		flood_fill(flood, target - 1);
		flood_fill(flood, target + n_line);
		flood_fill(flood, target - n_line);
	}
}
