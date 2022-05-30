# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 19:32:35 by mvavasso          #+#    #+#              #
#    Updated: 2022/05/30 21:31:21 by mvavasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= gnl
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -D BUFFER_SIZE=42 -g

RM			= rm -rf
AR			= ar rc

SRCS		= get_next_line.c get_next_line_utils.c
			
HEADER		= get_next_line.h
OBJS		= $(SRCS:.c=.o)

BONUS_SRC	= get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJS	= get_next_line_bonus.h
BONUS_NAME	= gnl_bonus

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

bonus:	$(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

$(BONUS_OBJS): $(BONUS_SRCS)
	$(CC) $(CFLAGS) -c $(BONUS_SRCS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus