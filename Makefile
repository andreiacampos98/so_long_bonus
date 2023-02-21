# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:23:18 by anaraujo          #+#    #+#              #
#    Updated: 2023/02/21 18:43:03 by anaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
BONUS := so_long_bonus

CC := cc
CFLAGS := -Wall -Werror -Wextra -g
MLXFLAGS := -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

LIBFT := ./libft/libft.a

SRCS := main.c				\
			map_check.c		map_check_2.c		\
			map_read.c		utils.c				\
			game_init.c		game_handler.c		\
			game_move.c		game_images.c	

SRCS_BONUS := bonus/main.c				bonus/game_render.c		\
				bonus/map_check.c		bonus/map_check_2.c		\
				bonus/map_read.c		bonus/utils.c			\
				bonus/game_init.c		bonus/game_handler.c	\
				bonus/game_move.c		bonus/game_images.c		\
				bonus/game_move_2.c		bonus/game_follower.c	\
				bonus/map_check_3.c


OBJS := $(SRCS:.c=.o)

OBJS_BONUS := $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
	echo "\033[1m LIBFT done \033[0m"

$(MINILIBX):
	$(MAKE) -C ./minilibx-linux
	echo "\033[1m MiniLibX done \033[0m"

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -lm $(OBJS) $(MLXFLAGS) $(LIBFT) $(MINILIBX) -o $(NAME)
	echo "\033[1m $(NAME) ready \033[0m"

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS) $(LIBFT) $(MINILIBX)
		$(CC) $(CFLAGS) -lm $(OBJS_BONUS) $(MLXFLAGS) $(LIBFT) $(MINILIBX) -o $(BONUS)
		echo "\033[1m $(BONUS) ready \033[0m"

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS)
		rm -rf $(OBJS_BONUS)
		echo "OBJS deleted"

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)
		rm -rf $(BONUS)
		echo "$(NAME) deleted"
		echo "$(BONUS) deleted"

re: fclean all

.SILENT: