/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:12:13 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/21 09:42:45 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*set up window's features*/
t_win	new_program(char *str, char *map)
{
	t_win	window;
	int		i;
	int		w;
	int		h;

	i = 0;
	while (map[i] != '\n')
		i++;
	w = i * PX_SIZE;
	h = count_char(map, '\n') * PX_SIZE;
	window.mlx_ptr = mlx_init();
	window.width = w;
	window.height = h;
	window.win_ptr = mlx_new_window(window.mlx_ptr, w, h, str);
	window.map = map;
	return (window);
}

/*set up images features*/
void	set_up_img(t_my_img *img)
{
	img->img_ptr = NULL;
	img->w = 0;
	img->h = 0;
	img->step = -1;
	img->exit_status = 0;
}
