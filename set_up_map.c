/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:16:42 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/07 16:37:07 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	count_exit(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			count++;
		i++;
	}
	return (count);
}

/*convert the .ber file into a character string*/
char	*set_up_map(char *map)
{
	int		fd;
	char	*str;
	char	*tmp;

	fd = open (map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nCheck file input.", ERROR);
		exit(ERROR);
	}
	str = "";
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		str = ft_strjoin(str, tmp);
		if (!str)
		{
			ft_putstr_fd("Error\nMalloc failed.", ERROR);
			exit(ERROR);
		}
	}
	close(fd);
	return (str);
}

/*displays the map to the window (param)*/
int	print_map(char *map, void *param)
{
	t_my_img	t;
	t_win		*test;
	int			i = 0;
	int			len;
	int			n_x = 0 ;
	int			n_y = 0;

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
        else
        {
            ft_putstr_fd("Error\nUnknown character in map.", ERROR);
            return (0);
        }
		if (map[i] != '\n')
			mlx_put_image_to_window(t.win.mlx_ptr, t.win.win_ptr, t.img_ptr, n_x, n_y);
		n_x += 32;
		i++;
	}
	return (1);
}
