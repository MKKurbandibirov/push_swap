# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 10:27:31 by nfarfetc          #+#    #+#              #
#    Updated: 2021/12/18 14:59:40 by nfarfetc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS		=	push_swap.c split.c validator_helper.c validator.c initializer.c commands.c indexation.c markup.c sort1.c sort2.c

HEADER		=	push_swap.h
OBJS		=	push_swap.o split.o validator_helper.o validator.o initializer.o commands.o indexation.o markup.o sort1.o sort2.o

CC			=	gcc
CFLAGS		=	-g -Wall -Wextra -Werror -I$(HEADER)

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(OBJS)		:	$(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)

$(NAME) 	:	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o  $(NAME)

clean		:	
	@rm -f $(OBJS) 

fclean		:	clean
	@rm -f $(NAME)

re:			fclean all