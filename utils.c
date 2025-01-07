/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:01:47 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/07 16:37:18 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	t_win	*test;

	printf("close");
	test = param;
	mlx_loop_end(test->mlx_ptr);
	mlx_destroy_window(test->mlx_ptr, test->win_ptr);
	mlx_destroy_display(test->mlx_ptr);
	//IL FAUT LIBERER LES IMAGES
	exit(0);
}

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

/*create a window*/
t_win	new_program(char *str, char *map)
{
	void	*mlx_ptr;
	int		width;
	int		height;
	char	**lines;

	lines = ft_split(map, '\n');
	width = ft_strlen(lines[0]) * 32;
	height = count_char(map, '\n') * 32;
	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, width, height, str), width, height, map});
}

/*create an image*/
t_my_img	new_img(int w, int h, t_win window)
{
	t_my_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), &(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}
