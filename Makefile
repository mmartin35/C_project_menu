SRC     =       $(shell find . -type f -name '*.c')

OBJ	=	$(SRC:.c=.o)

LIB	=	./precomp.a

BIN	=	./menu

CC	=	gcc

CFLAGS	+=	-Wall -Wundef -lncurses

all:	$(OBJ)
	ar rc $(LIB) $(OBJ)
	$(CC) -o $(BIN) ./src/*.c $(LIB) $(CFLAGS)

install:all
	rm -rf $(OBJ) $(LIB)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIB) $(BIN)

re:     clean all
