/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:01:47 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/06 16:35:32 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
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

/*create a window*/
t_win new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
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
/*put a pixel into an image*/
void	put_pixel_img(t_my_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *) dst = color;
}

/*draw a square into an image*/
void	draw_square(t_square square, t_my_img img)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (i < square.size && i  + square.y < img.h)
	{
		j = 0;
		while (j < square.size && j + square.x < img.w)
		{
			put_pixel_img(img, j + square.x, i + square.y, square.color);
			j++;
		}
		i++;
	}
}

#include <stdio.h>
/*read the keys*/
// int	read_keys(int key_pressed, void *param)
// {
// 	t_my_img	*img;

// 	img = (t_my_img *)param;
// 	if (key_pressed == UP)
// 	{
// 		printf("up\n");
// 		draw_square((t_square){0, 0, img->w, 0x000000FF}, *img);
//     	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->img_ptr, 0, 0);
// 	}
// 	else if (key_pressed == ESC)
// 		close_window(param);
// 	ft_putchar_fd(key_pressed, 1);
// 	return (0);
// }
int	read_keys(int key_pressed, void *param)
{
	t_my_img	t;
	t_win	*test;
	static int	n = 10;

	test = param;

	t = new_img(300, 300, *test);
	if (key_pressed == ESC)
		close_window(test);
	else if (key_pressed == RIGHT)
	{
		n += 10;
		printf("right\n");
		printf("%d", n);
		t.img_ptr = mlx_xpm_file_to_image(test->mlx_ptr, "textures/green.xpm", &t.w, &t.h);
		mlx_put_image_to_window(t.win.mlx_ptr, t.win.win_ptr, t.img_ptr, n, n);
	}
	(void)param;
	ft_putchar_fd(key_pressed, 1);
	return (0);
}
