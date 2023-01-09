# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 16:02:51 by yodahani          #+#    #+#              #
#    Updated: 2022/12/30 21:55:23 by yodahani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS =  -Wall -Wextra -Werror 

SRC = ft_itoa.c \
	ft_strdup.c \
	ft_split.c \
	ft_strchr.c \
	ft_strlen.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_printf.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_substr.c \
	ft_putbase.c \
	ft_strcmp.c

OBJ= $(SRC:.c=.o)
NAME = libft.a

all: $(NAME)
	
$(NAME): $(OBJ)
	@echo "\033[032m Compiling libft ...\033[0m"
	@ar -rcs $(NAME) $(OBJ)
clean:
	@rm -f ${OBJ}
fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY:clean, re, fclean, all,mess