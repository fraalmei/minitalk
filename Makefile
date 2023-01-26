# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 08:46:38 by fraalmei          #+#    #+#              #
#    Updated: 2022/08/05 16:05:04 by fraalmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	files
FUNCTIONS_S = server.c

OBJS_S = $(FUNCTIONS_S:.c=.o)

COMMON_FUNCTIONS = send_utils.c utils.c receive_utils.c\

COMMON_OBJS = $(COMMON_FUNCTIONS:.c=.o)

FUNCTIONS_C = client.c

OBJS_C = $(FUNCTIONS_C:.c=.o)

#	file's name
NAME_S = server

NAME_C = client

#	flags
FLAGS = -Wall -Werror -Wextra #-fsanitize=address

#	options to create the library
AR = ar -rc

#	options to force the remove
RM = rm -f

#	compilation
CC = gcc

all: $(NAME_S) $(NAME_C)

$(NAME_S):	$(OBJS_S) $(COMMON_OBJS)
	@$(CC) $(FLAGS) $(FUNCTIONS_S) $(COMMON_FUNCTIONS) ../libft/libft.a -o $(NAME_S)

$(NAME_C):	$(OBJS_C) $(COMMON_OBJS)
	@$(CC) $(FLAGS) $(FUNCTIONS_C) $(COMMON_FUNCTIONS) ../libft/libft.a -o $(NAME_C)

libft:
	@make -C ../libft

clean:
	$(RM) $(OBJS_S) $(OBJS_C) $(COMMON_OBJS)
	@make clean -C ../libft

fclean: clean
	@$(RM) $(NAME_C) $(NAME_S) ../libft/libft.a

re: fclean libft all

.PHONY: all clean fclean re libft
