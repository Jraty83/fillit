# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 16:20:49 by jraty             #+#    #+#              #
#    Updated: 2020/08/10 12:58:30 by jraty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = fillit_disp.c

SRCS2 = fillit_gnl.c

SRCS3 = fillit_checker.c

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

2: fclean
	@make -C $(LIB) re
	@gcc $(FLAGS) -I $(LIB) -o $(OBJS) -c $(SRCS2)
	@gcc -o $(NAME) $(OBJS) -I $(LIB) -L $(LIB) -lft

checker: fclean
	@make -C $(LIB) re
	@gcc $(FLAGS) -I $(LIB) -o $(OBJS) -c $(SRCS3)
	@gcc -o $(NAME) $(OBJS) -I $(LIB) -L $(LIB) -lft
