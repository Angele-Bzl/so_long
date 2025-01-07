/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:18:08 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/07 16:38:03 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

static void	go_right(t_win *solong, int count)
{
	int	i;

	i = 0;
	while (solong->map[i] && solong->map[i] != 'P')
		i++;
	if (solong->map[i + 1] != '1')
	{
		if (solong->map[i + 1] == 'E' && count == 0)
			close_window(solong);
		if (!count_char(solong->map, 'E'))
			solong->map[i] = 'E';
		else
			solong->map[i] = '0';
		solong->map[i + 1] = 'P';
	}
	if (!print_map(solong->map, solong))
		exit(ERROR);
}

static void	go_left(t_win *solong, int count)
{
	int	i;

	i = 0;
	while (solong->map[i] && solong->map[i] != 'P')
		i++;
	if (solong->map[i - 1] != '1')
	{
		if (solong->map[i - 1] == 'E' && count == 0)
			close_window(solong);
		if (!count_char(solong->map, 'E'))
			solong->map[i] = 'E';
		else
			solong->map[i] = '0';
		solong->map[i - 1] = 'P';
	}
	if (!print_map(solong->map, solong))
		exit(ERROR);
}

static void	go_up(t_win *solong, int count)
{
	int	i;
	size_t	len;

	i = 0;
	len = 0;
	while (solong->map[i] != '\n')
	{
		len++;
		i++;
	}
	while (solong->map[i] && solong->map[i] != 'P')
		i++;
	if (solong->map[i - (len + 1)] != '1')
	{
		if (solong->map[i - (len + 1)] == 'E' && count == 0)
			close_window(solong);
		if (!count_char(solong->map, 'E'))
			solong->map[i] = 'E';
		else
			solong->map[i] = '0';
		solong->map[i - (len + 1)] = 'P';
	}
	if (!print_map(solong->map, solong))
		exit(ERROR);
}

static void	go_down(t_win *solong, int count)
{
	int	i;
	size_t	len;

	i = 0;
	len = 0;
	while (solong->map[i] != '\n')
	{
		len++;
		i++;
	}
	while (solong->map[i] && solong->map[i] != 'P')
		i++;
	if (solong->map[i + (len + 1)] != '1')
	{
		if (solong->map[i + (len + 1)] == 'E' && count == 0)
			close_window(solong);
		if (!count_char(solong->map, 'E'))
			solong->map[i] = 'E';
		else
			solong->map[i] = '0';
		solong->map[i + (len + 1)] = 'P';
	}
	if (!print_map(solong->map, solong))
		exit(ERROR);
}

int	read_keys(int key_pressed, void *param)
{
	t_my_img	t;
	t_win		*solong;
	int			count;

	solong = param;
	count = count_char(solong->map, 'C');
	t = new_img(300, 300, *solong);
	if (key_pressed == XK_Escape)
		close_window(solong);
	else if (key_pressed == XK_Right)
		go_right(solong, count);
	else if (key_pressed == XK_Left)
		go_left(solong, count);
	else if (key_pressed == XK_Up)
		go_up(solong, count);
	else if (key_pressed == XK_Down)
		go_down(solong, count);
	return (0);
}
