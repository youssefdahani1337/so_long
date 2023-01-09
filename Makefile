# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 10:41:55 by yodahani          #+#    #+#              #
#    Updated: 2023/01/02 18:39:59 by yodahani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Wall -Wextra -Werror
NAME=so_long
DIR_UTILS=./utils/
UTILSFILES= ft_check_map.c \
			ft_check_map_2.c \
			ft_printmessage.c \
			ft_addons.c \
			ft_init_des.c \
			ft_create_map.c \
			ft_moves.c \
			ft_dir.c \
			so_long.c \
			ft_animition.c

SRCS= $(UTILSFILES:%.c=$(DIR_UTILS)%.c)

OBJS=$(SRCS:.c=.o)

all: libft $(NAME)
	@echo "\033[032m The game is ready \033[0m"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[032m the game is compiled succefuly !!\033[0m"

libft:
	@$(MAKE) -C libft -s

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C libft clean
	@echo "\033[034m Game files are cleaned !!\033[0m"

fclean:clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@echo "\033[034m Game cleaned !!\033[0m"

re:fclean all

.PHONY:all ,clean ,fclean , re, libft
.SILENT:$(OBJS)