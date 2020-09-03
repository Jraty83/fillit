# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 16:20:49 by jraty             #+#    #+#              #
#    Updated: 2020/09/03 09:57:15 by jraty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = tetri_validator.c shape_makers.c struct_processing.c move_coordinates.c \
		grid.c main.c end_result.c solver_shorteners.c

LIB = libft

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@gcc -o $(NAME) $(FLAGS) $(SRCS) -I $(LIB) -L $(LIB) -lft

clean:
	@make clean -C $(LIB)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB)
	
re: fclean all
