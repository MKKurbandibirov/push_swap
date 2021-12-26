# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magomed <magomed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 10:27:31 by nfarfetc          #+#    #+#              #
#    Updated: 2021/12/26 17:46:08 by magomed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS		=	push_swap.c split.c validator_helper.c validator.c initializer.c commands.c commands_wrap.c utils_func.c methods.c settings.c

#HEADER		=	push_swap.h
OBJS		=	push_swap.o split.o validator_helper.o validator.o initializer.o commands.o commands_wrap.o utils_func.o methods.o settings.o
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror #-I$(HEADER)

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