##
## Makefile for stumper2 in /home/remi.verny/EPiC/rush/CPE_2016_stumper2
## 
## Made by Remi Verny
## Login   <remi.verny@epitech.net>
## 
## Started on  Wed Apr 26 14:38:09 2017 Remi Verny
## Last update Wed Apr 26 17:06:50 2017 Remi Verny
##

CC	=	gcc

RM	=	rm -f

NAME	=	my_ginger

CFLAGS	=	-I./include -W -Wall -Wextra

SRCS	=	./src/main.c		\
		./src/tools.c		\
		./src/arg_handling.c	\
		./src/my_getnbr.c	\
		./src/my_error.c	\
		./src/get_map.c		\
		./src/in_map.c		\
		./src/game.c		\
		./src/put_nbr.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
