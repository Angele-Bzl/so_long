/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:16:42 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/06 16:21:15 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static char	*ft_strnjoin(char *old_line, char const *buf, int size)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	str = malloc(sizeof (char) * (slen(old_line) + size + 1));
// 	if (!str || !buf)
// 	{
// 		free(old_line);
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (old_line && old_line[i])
// 	{
// 		str[i] = old_line[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (buf[j] && j < size)
// 	{
// 		str[i + j] = buf[j];
// 		j++;
// 	}
// 	str[i + j] = '\0';
// 	clear_line(old_line);
// 	return (str);
// }

// char	*set_up_map(int fd)
// {
// 	char	*map;

// 	map = ft_strnjoin(map, get_next_line(fd), 1);
// 	if (!map_ok(map))
// 	{
// 		ft_putstr_fd("Error\nPlease send a valid map.\n", 2);
// 		exit (0);
// 	}
// 	return (map);
// }

void	print_map(char *map, void *param)
{
	t_my_img	t;
	t_win	*test;
	int	i = 0;
	int	len;
	int	n_x = 0 ;
	int	n_y = 0;

	test = param;
	len = ft_strlen(map);
	t = new_img(300, 300, *test);
	while (i < len)
	{
		if (map[i] == '1')
			t.img_ptr = mlx_xpm_file_to_image(test->mlx_ptr, "textures/green.xpm", &t.w, &t.h);
		else if (map[i] == '0')
			t.img_ptr = mlx_xpm_file_to_image(test->mlx_ptr, "textures/blue.xpm", &t.w, &t.h);
		else if (map[i] == 'C')
			t.img_ptr = mlx_xpm_file_to_image(test->mlx_ptr, "textures/red.xpm", &t.w, &t.h);
		else if (map[i] == 'P')
			t.img_ptr = mlx_xpm_file_to_image(test->mlx_ptr, "textures/purple.xpm", &t.w, &t.h);
		else if (map[i] == 'E')
			t.img_ptr = mlx_xpm_file_to_image(test->mlx_ptr, "textures/white.xpm", &t.w, &t.h);
		else if (map[i] == '\n')
		{
			n_x = -32;
			n_y += 32;
		}
		if (map[i] != '\n')
			mlx_put_image_to_window(t.win.mlx_ptr, t.win.win_ptr, t.img_ptr, n_x, n_y);
		n_x += 32;
		i++;
	}
}
