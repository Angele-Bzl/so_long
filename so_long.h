/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:28:34 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/31 13:30:01 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

# define ERROR 2
# define PX_SIZE 32
# define SPACE "textures/blue.xpm"
# define WALL "textures/gate_green.xpm"
# define PLAY "textures/player.xpm"
# define COL "textures/dog_purple.xpm"
# define EXIT "textures/exit.xpm"

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
	int			h;
	int			w;
	int			step;
	int			exit_status;
}				t_my_img;

/*set_up_struct.c*/
t_win		new_program(char *str, char *map);
void		set_up_img(t_my_img *img);
/*utils.c*/
int			find_char(char *map, char c);
int			count_char(char *map, char c);
void		skip_line(t_my_img *img, int *i, size_t *len);
/*exit.c*/
void		free_window(t_win *param);
int			close_window(t_my_img *img);
void		exit_error(t_my_img *img);
/*move.c*/
int			read_keys(int key_pressed, t_my_img *t);
/*set_up_map.c*/
int			print_map(t_win wi, char *map, t_my_img *t);
/*extract_map.c*/
char		*set_up_map(char *map);
/*map_check_0.c*/
int			map_ok(char *map);
/*map_check_1*/
int			check_one_e(char *map, char exit);
int			check_one_p(char *map, char person);
int			check_min_c(char *map, char collect);
/*flood_fill.c*/
void		flood_fill(char *flood, int target);

#endif
