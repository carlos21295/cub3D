# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/23 16:56:30 by cmunoz-r          #+#    #+#              #
#    Updated: 2020/01/18 16:30:15 by cmunoz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D

LIBFT_PATH=libft/

SRC_PATH=sources/

CC=-@gcc

SRCS= programa.c parse_file.c events.c draw.c check_map.c check_elements.c texture_check.c sprite.c utils.c init.c movement.c fill_textures.c dda.c sprite_list.c sprite_utils.c screenshot.c

LIBFT_DIR= libft
LIBS= libft/libft.a

SRC+=$(addprefix $(SRC_PATH), $(SRCS))

C_FLAGS+=-Werror -Wextra -Wall -I./

MLX_FLAGS+=-L minilibx -lmlx -framework OpenGL -framework AppKit

$(NAME):	$(SRC) $(LIBS)
		-@$(CC) $(C_FLAGS) $(MLX_FLAGS) $(SRC) $(LIBS)  -o cub3D
		-@echo Help: run ./cub3D

$(LIBS): 
	-@$(MAKE) -C $(LIBFT_DIR) bonus

all: libft $(NAME)

clean:
		-@rm -f $(OBJ)
		-@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		-@rm -f $(NAME)
		-@$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all clean fclean re