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
MLXFLAGS = -L ./libs/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
RM = rm -f
SRC_DIR = ./src
BONUS_DIR = ./src_bonus

NAME = so_long
NAME_BNS = so_long_bonus

SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/inits/init_data.c \
		$(SRC_DIR)/inits/init_data2.c \
		$(SRC_DIR)/map_utils/colide/colectible_check.c \
		$(SRC_DIR)/map_utils/colide/colectible_check_utils.c \
		$(SRC_DIR)/map_utils/colide/colide_utils_colects.c \
		$(SRC_DIR)/map_utils/colide/colide_utils_no_colects.c \
		$(SRC_DIR)/map_utils/colide/colide.c \
		$(SRC_DIR)/map_utils/colide/exit_check.c\
		$(SRC_DIR)/map_utils/colide/temp_colide_utils.c \
		$(SRC_DIR)/map_utils/parser/map_parser_utils.c \
		$(SRC_DIR)/map_utils/parser/map_parser.c \
		$(SRC_DIR)/map_utils/render/map_render.c \
		$(SRC_DIR)/map_utils/render/map_utils.c \
		$(SRC_DIR)/map_utils/render/tile.c \
		$(SRC_DIR)/movement/key_press_utils.c \
		$(SRC_DIR)/movement/key_utils.c \
		$(SRC_DIR)/movement/movement.c \
		$(SRC_DIR)/others/free_utils.c \
		$(SRC_DIR)/others/replace_pixel.c

BONUS =	$(BONUS_DIR)/main_bonus.c \
		$(BONUS_DIR)/inits/init_data_bonus.c \
		$(BONUS_DIR)/inits/init_data2_bonus.c \
		$(BONUS_DIR)/map_utils/colide/colectible_check_bonus.c \
		$(BONUS_DIR)/map_utils/colide/colide_utils_colects_bonus.c \
		$(BONUS_DIR)/map_utils/colide/colide_utils_no_colects_bonus.c \
		$(BONUS_DIR)/map_utils/colide/colide_bonus.c \
		$(BONUS_DIR)/map_utils/colide/enemy_colide_bonus.c \
		$(BONUS_DIR)/map_utils/colide/exit_check_bonus.c \
		$(BONUS_DIR)/map_utils/colide/exit_sprite_bonus.c \
		$(BONUS_DIR)/map_utils/colide/temp_colide_utils_bonus.c \
		$(BONUS_DIR)/map_utils/render/map_render_bonus.c \
		$(BONUS_DIR)/map_utils/render/map_utils_bonus.c \
		$(BONUS_DIR)/map_utils/render/tile_bonus.c \
		$(BONUS_DIR)/map_utils/parser/map_parser_utils_bonus.c \
		$(BONUS_DIR)/map_utils/parser/map_parser_bonus.c \
		$(BONUS_DIR)/movement/put_string_window_bonus.c \
		$(BONUS_DIR)/movement/key_press_utils_bonus.c \
		$(BONUS_DIR)/movement/key_utils_bonus.c \
		$(BONUS_DIR)/movement/movement_bonus.c \
		$(BONUS_DIR)/others/free_utils_bonus.c \
		$(BONUS_DIR)/others/replace_pixel_bonus.c
			
OBJ = $(SRC:.c=.o)
OBJ_B = $(BONUS:.c=.o)

LIBFT = libs/libft/libft.a

all: deps $(NAME)

deps: 
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/minilibx-linux

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean: 
	$(MAKE) clean -C ./libs/libft
	$(MAKE) clean -C ./libs/minilibx-linux
	@$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	@$(RM) $(LIBFT) $(NAME) $(NAME_BNS)

bonus: download deps $(NAME_BNS)

$(NAME_BNS): $(OBJ_B) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_B) $(LIBFT) $(MLXFLAGS) -o $(NAME_BNS)

download:
	@wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz -C libs
	@rm minilibx-linux.tgz

norm: 
	norminette libs/libft include src src_bonus

re: fclean all