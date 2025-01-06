/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:28:34 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/06 16:13:03 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H

# define SO_LONG_H

#include <unistd.h>
#include "minilibx_linux/mlx.h"
#include "minilibx_linux/mlx_int.h"
#include "libft/libft.h"

# define ESC 65307
# define ENTER 65293
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ERROR 2


/*structure of a window*/
typedef	struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}			t_win;

/*structure of an image*/
typedef	struct s_my_img
{
	t_win		win;
	void		*img_ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			endian;
	int			line_len;
}				t_my_img;

/*structure of a pixel's square*/
typedef	struct s_square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int					color;
}						t_square;

t_win new_program(int w, int h, char *str);
t_my_img	new_img(int w, int h, t_win window);
void	put_pixel_img(t_my_img img, int x, int y, int color);
void	draw_square(t_square square, t_my_img img);
int	read_keys(int key_pressed, void *param);
int	close_window(void *param);\
void	print_map(char *map, void *param);

#endif
