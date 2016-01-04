##
## Makefile for 105torus in /home/VEYSSI_B/rendu/105torus
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Mon Jan  4 10:48:13 2016 Baptiste veyssiere
## Last update Mon Jan  4 11:00:35 2016 Baptiste veyssiere
##

NAME	= 105torus

SRCS	= main.c \
	105torus.c

OBJS	= $(SRCS:.c=.o)

LDFLAGS	= -lm

CC	= gcc

RM	= rm -f

CFLAGS	= -I./include

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
