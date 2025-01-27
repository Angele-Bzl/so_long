/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:19:13 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/21 08:15:48 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_win		solong;
	t_my_img	img;
	char		*map;

	if (ac != 2)
		return (ft_putstr_fd("Error\nWrong parameter\n", ERROR), ERROR);
	set_up_img(&img);
	map = set_up_map(av[1]);
	if (!map)
		return (ERROR);
	if (!map_ok(map))
		return (free(map), ERROR);
	solong = new_program("so_long", map);
	if (!solong.mlx_ptr || !solong.win_ptr)
		exit_error(&img);
	img.win = solong;
	if (!print_map(solong, map, &img))
		exit_error(&img);
	mlx_key_hook(solong.win_ptr, read_keys, &img);
	mlx_hook(solong.win_ptr, DestroyNotify, 0L, close_window, &img);
	mlx_loop(solong.mlx_ptr);
	return (0);
}
