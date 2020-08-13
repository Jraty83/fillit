# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 16:20:49 by jraty             #+#    #+#              #
#    Updated: 2020/08/13 11:37:12 by jraty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = tetri_validator.c

OBJS = $(SRCS:.c=.o)

LIB = /Users/jraty/libft/

HDRS = $(LIB)libft.h $(LIB)get_next_line.h

GCH = $(HDRS:.h=.h.gch)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIB) re
	@gcc $(FLAGS) -I $(LIB) -o $(OBJS) -c $(SRCS)
	@gcc -o $(NAME) $(OBJS) -I $(LIB) -L $(LIB) -lft

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(GCH)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(GCH)

re: fclean all
