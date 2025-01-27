# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 16:11:34 by abarzila          #+#    #+#              #
#    Updated: 2025/01/21 09:41:24 by abarzila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
#####################################################
#					PROGRAM							#
#####################################################
NAME		=	so_long

#####################################################
#					COMPILING						#
#####################################################
CC			=	cc

#####################################################
#					DIRECTORY						#
#####################################################
DMLX		=	minilibx
DLIBFT		=	libft
DPRINTF		=	printf

#####################################################
#					FLAGS							#
#####################################################
CFLAGS		=	-Wall -Wextra -Werror -g3
CPPFLAGS	=	-I $(DMLX)/
MLXFLAGS	=	-lX11 -lXext

#####################################################
#					FILES							#
#####################################################
SRC			=	main.c\
				utils.c\
				set_up_map.c\
				map_check_0.c\
				map_check_1.c\
				move.c\
				flood_fill.c\
				exit.c\
				extract_map.c\
				set_up_struct.c

HEADERS		=	so_long.h \
				$(DMLX)/mlx.h \
				$(DMLX)/mlx_int.h

#####################################################
#					ARCHIVES						#
#####################################################
AR			=	ar
AFLAG		=	rcs
LIBMLX		=	$(DMLX)/libmlx.a
LIBFT		=	$(DLIBFT)/libft.a
PRINTF		=	$(DPRINTF)/libftprintf.a

all: $(LIBFT) $(PRINTF) $(LIBMLX) $(NAME)

$(LIBFT): $(DLIBFT)/*.c
	$(MAKE) -C $(DLIBFT)

$(PRINTF): $(DPRINTF)/*.c
	$(MAKE) -C $(DPRINTF)

$(LIBMLX):
	$(MAKE) -C $(DMLX)

$(NAME): $(HEADERS) Makefile $(SRC)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRC) $(LIBFT) $(PRINTF)  $(LIBMLX) $(MLXFLAGS) -o $(NAME)

re: fclean
	$(MAKE) all

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(DLIBFT)
	$(MAKE) fclean -C $(DPRINTF)
	$(MAKE) clean -C $(DMLX)

clean:
	$(MAKE) clean -C $(DLIBFT)
	$(MAKE) clean -C $(DPRINTF)
	$(MAKE) clean -C $(DMLX)


# .PHONY: all clean fclean re
# #####################################################
# #					PROGRAM							#
# #####################################################
# NAME		=	so_long

# #####################################################
# #					COMPILING						#
# #####################################################
# CC			=	cc

# #####################################################
# #					DIRECTORY						#
# #####################################################
# DMLX		=	minilibx
# DSRC		=	src
# DLIBFT		=	$(DSRC)/libft
# DPRINTF		=	$(DSRC)/printf

# #####################################################
# #					FLAGS							#
# #####################################################
# CFLAGS		=	-Wall -Wextra -Werror -g3
# CPPFLAGS	=	-I $(DMLX)/
# MLXFLAGS	=	-lX11 -lXext

# #####################################################
# #					FILES							#
# #####################################################
# SRC		=		$(DSRC)/main.c\
# 				$(DSRC)/utils.c\
# 				$(DSRC)/set_up_map.c\
# 				$(DSRC)/map_check_0.c\
# 				$(DSRC)/map_check_1.c\
# 				$(DSRC)/move.c\
# 				$(DSRC)/flood_fill.c\
# 				$(DSRC)/exit.c\
# 				$(DSRC)/extract_map.c\
# 				$(DSRC)/set_up_struct.c

# HEADERS		=	$(DSRC)/so_long.h \
# 				$(DMLX)/mlx.h \
# 				$(DMLX)/mlx_int.h

# #####################################################
# #					ARCHIVES						#
# #####################################################
# AR			=	ar
# AFLAG		=	rcs
# LIBMLX		=	$(DMLX)/libmlx.a
# LIBFT		=	$(DLIBFT)/libft.a
# PRINTF		=	$(DPRINTF)/libftprintf.a

# all: $(LIBFT) $(PRINTF) $(LIBMLX) $(NAME)

# $(LIBFT): $(DLIBFT)/*.c
# 	$(MAKE) -C $(DLIBFT)

# $(PRINTF): $(DPRINTF)/*.c
# 	$(MAKE) -C $(DPRINTF)

# $(LIBMLX):
# 	$(MAKE) -C $(DMLX)

# $(NAME): $(HEADERS) Makefile $(SRC)
# 	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRC) $(LIBFT) $(PRINTF)  $(LIBMLX) $(MLXFLAGS) -o $(NAME)

# re: fclean
# 	$(MAKE) all

# fclean: clean
# 	rm -f $(NAME)
# 	$(MAKE) fclean -C $(DLIBFT)
# 	$(MAKE) fclean -C $(DPRINTF)
# 	$(MAKE) clean -C $(DMLX)

# clean:
# 	$(MAKE) clean -C $(DLIBFT)
# 	$(MAKE) clean -C $(DPRINTF)
# 	$(MAKE) clean -C $(DMLX)
