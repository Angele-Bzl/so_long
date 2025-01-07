/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:28:34 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/07 16:36:16 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "minilibx_linux/mlx.h"
# include "minilibx_linux/mlx_int.h"
# include "libft/libft.h"

# define ENTER 65293
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ERROR 2

/*structure of a window*/
typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	char	*map;
}			t_win;

/*structure of an image*/
typedef struct s_my_img
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
typedef struct s_square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int					color;
}						t_square;

t_win		new_program(char *str, char *map);
t_my_img	new_img(int w, int h, t_win window);
int			read_keys(int key_pressed, void *param);
int			close_window(void *param);
int			print_map(char *map, void *param);
char		*set_up_map(char *map);
int			map_ok(char *map);
int			count_char(char *map, char c);

#endif
