# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 10:27:31 by nfarfetc          #+#    #+#              #
#    Updated: 2021/12/27 11:27:52 by nfarfetc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS		=	push_swap.c split.c validator_helper.c validator.c initializer.c commands.c \
				commands_wrap.c utils_func.c methods.c settings.c sorting.c sort_start.c

HEADER		=	push_swap.h
OBJS		=	push_swap.o split.o validator_helper.o validator.o initializer.o commands.o \
				commands_wrap.o utils_func.o methods.o settings.o sorting.o sort_start.o
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I$(HEADER)

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