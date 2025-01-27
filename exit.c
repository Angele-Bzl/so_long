/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:28:06 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/27 15:53:32 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(t_my_img *img)
{
	img->exit_status = ERROR;
	close_window(img);
}

void	free_window(t_win *param)
{
	if (!param)
		return ;
	if (param->map)
		free(param->map);
	if (param->mlx_ptr)
		free(param->mlx_ptr);
}

int	close_window(t_my_img *img)
{
	if (img->win.mlx_ptr)
		mlx_loop_end(img->win.mlx_ptr);
	if (img->img_ptr)
		mlx_destroy_image(img->win.mlx_ptr, img->img_ptr);
	if (img->win.win_ptr)
		mlx_destroy_window(img->win.mlx_ptr, img->win.win_ptr);
	if (img->win.mlx_ptr)
		mlx_destroy_display(img->win.mlx_ptr);
	free_window(&(img->win));
	exit(img->exit_status);
}
