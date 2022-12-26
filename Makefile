##
## EPITECH PROJECT, 2022
## Script: makefile
## File description:
## Email: matthieu1.martin@epitech.eu
## Made by: Matthieu MARTIN
##
##

SRC     =       $(shell find . -type f -name '*.c')

CC	=	gcc

CFLAGS	+=	-Wall -Wundef

all:
	$(CC) -o ./terminal_ui ./src/*c -lncurses

clean:
	rm -r ./terminal_ui

re:	clean all
