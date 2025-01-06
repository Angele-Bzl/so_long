# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 16:11:34 by abarzila          #+#    #+#              #
#    Updated: 2025/01/06 16:31:41 by abarzila         ###   ########.fr        #
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
DMLX		=	minilibx_linux
DLIBFT		=	libft

#####################################################
#					FLAGS							#
#####################################################
CFLAGS		=	-Wall -Wextra -Werror -g3
CPPFLAGS	=	-I $(DMLX)/
MLXFLAGS	=	-lX11 -lXext

#####################################################
#					FILES							#
#####################################################
SRC			=	main.c \
				utils.c\
				set_up_map.c

HEADERS		=	so_long.h \
				$(DMLX)/mlx.h \
				$(DMLX)/mlx_int.h
OBJ			=	$(SRC:.c=.o)

#####################################################
#					ARCHIVES						#
#####################################################
AR			=	ar
AFLAG		=	rcs
LIBMLX		=	$(DMLX)/libmlx.a
LIBFT		=	libft/libft.a

all : lib
	$(MAKE) $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LIBMLX) $(MLXFLAGS)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

lib :
	$(MAKE) -C $(DLIBFT)/
	$(MAKE) -C $(DMLX)/ 2>/dev/null

re: fclean
	$(MAKE) all

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(DLIBFT)/

clean :
	rm -rf $(OBJ)
	$(MAKE) clean -C $(DLIBFT)/
	$(MAKE) clean -C $(DMLX)/
