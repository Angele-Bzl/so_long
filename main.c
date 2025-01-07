/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:19:13 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/07 16:33:25 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_win		solong;
	char		*map;

	(void)ac;
	map = set_up_map(av[1]);
	solong = new_program("so_long", map);
	if (!solong.mlx_ptr || !solong.win_ptr)
	{
		ft_putstr_fd("Error\nThe window failed to be created\n", ERROR);
		return (ERROR);
	}
	if (!print_map(map, &solong) || !map_ok(map))
		return (ERROR);
	mlx_key_hook(solong.win_ptr, read_keys, &solong);
	mlx_hook(solong.win_ptr, DestroyNotify, 0L, close_window, solong.mlx_ptr);
	mlx_loop(solong.mlx_ptr);
	return (0);
}
