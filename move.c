/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:18:08 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/21 08:19:53 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	go_right(t_my_img *img, int count)
{
	int	i;

	i = 0;
	while (img->win.map[i] && img->win.map[i] != 'P')
		i++;
	if (img->win.map[i + 1] != '1')
	{
		if (img->win.map[i + 1] == 'E' && count == 0)
			close_window(img);
		if (!count_char(img->win.map, 'E'))
			img->win.map[i] = 'E';
		else
			img->win.map[i] = '0';
		img->win.map[i + 1] = 'P';
	}
	if (!print_map(img->win, img->win.map, img))
		exit_error(img);
}

static void	go_left(t_my_img *img, int count)
{
	int	i;

	i = 0;
	while (img->win.map[i] && img->win.map[i] != 'P')
		i++;
	if (img->win.map[i - 1] != '1')
	{
		if (img->win.map[i - 1] == 'E' && count == 0)
			close_window(img);
		if (!count_char(img->win.map, 'E'))
			img->win.map[i] = 'E';
		else
			img->win.map[i] = '0';
		img->win.map[i - 1] = 'P';
	}
	if (!print_map(img->win, img->win.map, img))
		exit_error(img);
}

static void	go_up(t_my_img *img, int count)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (img->win.map[i] != '\n')
	{
		len++;
		i++;
	}
	while (img->win.map[i] && img->win.map[i] != 'P')
		i++;
	if (img->win.map[i - (len + 1)] != '1')
	{
		if (img->win.map[i - (len + 1)] == 'E' && count == 0)
			close_window(img);
		if (!count_char(img->win.map, 'E'))
			img->win.map[i] = 'E';
		else
			img->win.map[i] = '0';
		img->win.map[i - (len + 1)] = 'P';
	}
	if (!print_map(img->win, img->win.map, img))
		exit_error(img);
}

static void	go_down(t_my_img *img, int count)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (img->win.map[i] != '\n')
	{
		len++;
		i++;
	}
	while (img->win.map[i] && img->win.map[i] != 'P')
		i++;
	if (img->win.map[i + (len + 1)] != '1')
	{
		if (img->win.map[i + (len + 1)] == 'E' && count == 0)
			close_window(img);
		if (!count_char(img->win.map, 'E'))
			img->win.map[i] = 'E';
		else
			img->win.map[i] = '0';
		img->win.map[i + (len + 1)] = 'P';
	}
	if (!print_map(img->win, img->win.map, img))
		exit_error(img);
}

int	read_keys(int key, t_my_img *param)
{
	int			count;

	count = count_char(param->win.map, 'C');
	if (key == XK_Escape)
		close_window(param);
	else
	{
		param->step += 1;
		ft_printf("steps : %d\n", param->step);
		if (key == XK_Right || key == XK_d)
			go_right(param, count);
		if (key == XK_Left || key == XK_a)
			go_left(param, count);
		if (key == XK_Up || key == XK_w)
			go_up(param, count);
		if (key == XK_Down || key == XK_s)
			go_down(param, count);
	}
	return (0);
}
