/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:16:42 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/21 08:24:19 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_texture(char c, t_win *p, t_my_img *i)
{
	if (i->img_ptr)
		mlx_destroy_image(i->win.mlx_ptr, i->img_ptr);
	if (c == '1')
		i->img_ptr = mlx_xpm_file_to_image(p->mlx_ptr, WALL, &i->w, &i->h);
	else if (c == '0')
		i->img_ptr = mlx_xpm_file_to_image(p->mlx_ptr, SPACE, &i->w, &i->h);
	else if (c == 'C')
		i->img_ptr = mlx_xpm_file_to_image(p->mlx_ptr, COL, &i->w, &i->h);
	else if (c == 'P')
		i->img_ptr = mlx_xpm_file_to_image(p->mlx_ptr, PLAY, &i->w, &i->h);
	else if (c == 'E')
		i->img_ptr = mlx_xpm_file_to_image(p->mlx_ptr, EXIT, &i->w, &i->h);
	if (!i->img_ptr)
		exit_error(i);
}

static void	new_line(int *x, int *y)
{
	*x = -PX_SIZE;
	*y = *y + PX_SIZE;
}

/*displays the map to the window*/
int	print_map(t_win wi, char *map, t_my_img *img)
{
	int			i;
	int			x;
	int			y;
	int			len;

	i = 0;
	x = 0;
	y = 0;
	len = ft_strlen(map);
	while (i < len)
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == 'C'
			|| map[i] == 'P' || map[i] == 'E')
			put_texture(map[i], &wi, img);
		else if (map[i] == '\n')
			new_line(&x, &y);
		else
			return (ft_putstr_fd("Error\nUnknown char in map\n", ERROR), 0);
		if (map[i] != '\n')
			mlx_put_image_to_window(wi.mlx_ptr, wi.win_ptr, img->img_ptr, x, y);
		x += PX_SIZE;
		i++;
	}
	return (1);
}
