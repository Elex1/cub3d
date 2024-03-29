# ************************************************************************************************** #
#                                                                                                    #
#                                                         :::   ::::::::   ::::::::  :::::::::::     #
#    Makefile                                          :+:+:  :+:    :+: :+:    :+: :+:     :+:      #
#                                                       +:+         +:+        +:+        +:+        #
#    By: melghoud <melghoud@student.1337.ma>           +#+      +#++:      +#++:        +#+          #
#                                                     +#+         +#+        +#+      +#+            #
#    Created: 2021/04/21 14:01:36 by melghoud        #+#  #+#    #+# #+#    #+#     #+#              #
#    Updated: 2021/04/21 14:01:36 by melghoud     ####### ########   ########      ###.ma            #
#                                                                                                    #
# ************************************************************************************************** #

NAME = cub3D

SRC_PATH = primary
SRC_NAMES = cube3d_utils.c map_file_parser_utils.c sprite.c destruct.c sprite_utils.c events.c \
			parse_floor_ceilling_resolution.c sprite_utils2.c init_data.c parse_map.c utils.c \
			intersection.c parse_textures.c utils2.c main.c ray_casting.c wall_utils.c \
			map_error_handling.c render.c walls.c map_file_parser.c screenshot.c


LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
DEBUG = -g3
OPT = -Ofast -O3
LD_LIBS = -lm -framework OpenGL -framework AppKit libs/libmlx.a

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAMES))

all: $(NAME)

$(NAME): $(SRC)
	@ make -C $(LIBFT_PATH)
	@ $(CC) $(CFLAGS) $(SRC) $(OPT) -o $(NAME) $(LD_LIBS) $(LIBFT)


run:
	@./Cub3D "maps/map.cub"

save:
	@./Cub3D "maps/map.cub" "--save"

norm:
	@ norminette primary
	@ norminette include

clean:

fclean: clean
	@ rm -rf $(NAME)
	@ make fclean -C $(LIBFT_PATH)

re: fclean all