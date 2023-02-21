##
## EPITECH PROJECT, 2022
## Script: makefile
## File description:
## Email: matthieu1.martin@epitech.eu
## Made by: Matthieu MARTIN
##

SRC     =       $(shell find . -type f -name '*.c')

OBJ	=	$(SRC:.c=.o)

LIB	=	./libmy.a

BIN	=	./menu

CC	=	gcc

CFLAGS	+=	-Wall -Wundef -lncurses

all:	$(OBJ)
	ar rc $(LIB) $(OBJ)
	$(CC) -o $(BIN) ./src/master.c $(LIB) $(CFLAGS)

install:all
	rm -rf $(OBJ) $(LIB)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIB) $(BIN)

re:     clean all
