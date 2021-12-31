NAME		=	push_swap

CHECK_NAME	=	checker

#HEADER		=	push_swap.h

SRCS		=	push_swap.c split.c validator_helper.c validator.c initializer.c commands.c \
				commands_wrap.c utils_func.c methods.c settings.c sorting.c sort_start.c \

OBJS		=	$(SRCS:.c=.o)
				
CHECK_SRCS	=	checker.c validator.c validator_helper.c split.c initializer.c commands.c \
				sorting.c methods.c commands_wrap.c settings.c utils_func.c get_next_line/*.c
				
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror #-I$(HEADER)

.PHONY		:	all bonus clean fclean re

all			:	$(NAME) printpush

bonus		:	printcheck
	@$(CC) $(CFLAGS) -o $(CHECK_NAME) $(CHECK_SRCS)

%.o:			%.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) 	:	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o  $(NAME)

clean		:	
	@rm -f $(OBJS)

fclean		:	clean
	@rm -f $(NAME) $(CHECK_NAME)

re:			fclean all

printpush:
	@echo "╭━━━┳╮╱╭┳━━━┳╮╱╭┳━━━┳╮╭╮╭┳━━━┳━━━╮"
	@echo "┃╭━╮┃┃╱┃┃╭━╮┃┃╱┃┃╭━╮┃┃┃┃┃┃╭━╮┃╭━╮┃"
	@echo "┃╰━╯┃┃╱┃┃╰━━┫╰━╯┃╰━━┫┃┃┃┃┃┃╱┃┃╰━╯┃"
	@echo "┃╭━━┫┃╱┃┣━━╮┃╭━╮┣━━╮┃╰╯╰╯┃╰━╯┃╭━━╯"
	@echo "┃┃╱╱┃╰━╯┃╰━╯┃┃╱┃┃╰━╯┣╮╭╮╭┫╭━╮┃┃"
	@echo "╰╯╱╱╰━━━┻━━━┻╯╱╰┻━━━╯╰╯╰╯╰╯╱╰┻╯"

printcheck:
	@echo "╭━━━┳╮╱╭┳━━━┳━━━┳╮╭━┳━━━┳━━━╮"
	@echo "┃╭━╮┃┃╱┃┃╭━━┫╭━╮┃┃┃╭┫╭━━┫╭━╮┃"
	@echo "┃┃╱╰┫╰━╯┃╰━━┫┃╱╰┫╰╯╯┃╰━━┫╰━╯┃"
	@echo "┃┃╱╭┫╭━╮┃╭━━┫┃╱╭┫╭╮┃┃╭━━┫╭╮╭╯"
	@echo "┃╰━╯┃┃╱┃┃╰━━┫╰━╯┃┃┃╰┫╰━━┫┃┃╰╮"
	@echo "╰━━━┻╯╱╰┻━━━┻━━━┻╯╰━┻━━━┻╯╰━╯"