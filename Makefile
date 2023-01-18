##
## EPITECH PROJECT, 2022
## Script: makefile
## File description:
## Email: matthieu1.martin@epitech.eu
## Made by: Matthieu MARTIN
##

SRC     =       $(shell find . -type f -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	./libmy.a

CC	=	gcc

CFLAGS	+=	-Wall -Wundef -g -lncurses

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CC) -o menu ./src/master.c ./libmy.a $(CFLAGS)
	rm -r $(OBJ) ./libmy.a

re:     fclean all
