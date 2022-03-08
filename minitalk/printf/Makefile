# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: dmerrill <dmerrill@student.21-school.ru>   +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2022/01/09 18:27:07 by dmerrill          #+#    #+#             #
#   Updated: 202#   Updated: 2022/01/12 16:45:34 by                  ###   ########.fr       #                                              #									 #
# ************************************************************************** #

CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -c

SRCS=./*.c ./libft/ft*.c

OBJECTS=*.o
LIB_PATH = ./libft
INCLUDES=./ft_printf.h

all: 	
	@make re -C $(LIB_PATH)
	@$(CC) -g3 $(CFLAGS) $(SRCS) -I$(INCLUDES)
	@ar rc $(NAME) $(OBJECTS) $(LIB_PATH)/*.o

$(NAME):
	@make re -C $(LIB_PATH)
	@$(CC) -g3 $(CFLAGS) $(SRCS) -I$(INCLUDES)
	@ar rc $(NAME) $(OBJECTS) $(LIB_PATH)/*.o
	@ranlib $(NAME)
	@make fclean -C $(LIB_PATH)
	
clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C $(LIB_PATH)


fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re: fclean all

.PHONY:	all clean fclean re

norm:
	norminette
