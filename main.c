
#include "so_long.h"

int deal_key(int key, void *param)
{
	if (key == ESC)
		close_window(param);
	ft_putchar_fd(key, 1);
	return (0);
}

int main(/*int ac, char **av*/)
{
	t_win	tutorial;
	t_my_img	token;

	//(void)ac;
	tutorial = new_program(600, 600, "tutorial");

	if (!tutorial.mlx_ptr || !tutorial.win_ptr)
	{
		ft_putstr_fd("Error\nThe window failed to be created\n", ERROR);
		return (ERROR);
	}

	token = new_img(300, 300, tutorial);
	printf("img_ptr		: [%p]\n", token.img_ptr); // address of the image
	printf("bpp		: [%d]\n", token.bpp); // bits per pixel
	printf("line_len	: [%d]\n", token.line_len); //number of bytes one line holds(in the address)
	printf("endian		: [%d]\n", token.endian);
	printf("addr		: [%p]\n", token.addr); // address where the where the chain of bytes starts

	// token.img_ptr = mlx_xpm_file_to_image(tutorial.mlx_ptr, "textures/purple.xpm", &token.w, &token.h);
	// mlx_put_image_to_window(token.win.mlx_ptr, token.win.win_ptr, token.img_ptr, 10, 10);

	//set_up_map(av[1], &tutorial);
	print_map("1111111111111\n10010000000C1\n1000011111001\n1P0011E000001\n1111111111111", &tutorial);

	mlx_key_hook(tutorial.win_ptr, read_keys, &tutorial);
	mlx_hook(tutorial.win_ptr, 17, 0L, close_window, tutorial.mlx_ptr);

	mlx_loop(tutorial.mlx_ptr);
	return (0);
}
