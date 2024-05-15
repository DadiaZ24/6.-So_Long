# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 21:05:41 by ddias-fe          #+#    #+#              #
#    Updated: 2024/01/23 21:05:41 by ddias-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./libs/minilibx_linux -lm -lmlx -Ilmlx -lXext -lX11
RM = rm -f

NAME = so_long
NAME_BNS = so_long_bonus

SRC =	src/main.c \
		src/img.c \
			
OBJ = $(SRC:.c=.o)

LIBFT = libs/libft/libft.a

all: deps $(NAME)

deps: 
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/minilibx_linux

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean: 
	$(MAKE) clean -C ./libs/libft
	$(MAKE) clean -C ./libs/minilibx_linux
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(LIBFT) $(NAME)

download:
	@wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz -C libs
	@rm minilibx-linux.tgz

re: fclean all