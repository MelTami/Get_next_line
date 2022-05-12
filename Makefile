# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 19:32:35 by mvavasso          #+#    #+#              #
#    Updated: 2022/05/12 21:23:52 by mvavasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= gnl.a
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -D BUFFER_SIZE=42

RM		= rm -rf
AR		= ar rc

SRCS	= get_next_line.c \
			# get_next_line_utils.c
			
HEADER	= get_next_line.h
OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAG) -c $(SRCS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re		