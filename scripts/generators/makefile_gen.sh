#!/bin/bash
today=$(date +%d/%m/%Y)
time=$(date +"%T")
div=##
div2=##
email=matthieu1.martin@epitech.eu
/usr/bin/clear
_select_name() {

	# User input.
	printf "Write delivery name: " ; read -r name

	# Remove spaces
	name=${name// /_}

}

_select_name

# Format output
printf "%-2s\n\
%-19s%-0s\n\
%-19s%-0s\n\
%s\n%s\n\
%-19s%-0s\n\
%-19s%-0s\n\
%s\n\
%s\n%s\n%s\n%s\n%s\n%s\n%s\n\
%s\n%s\n%s\n%s\n%s\n%s\n%s\n\
%s\n%s\n%s\n%s\n%s\n%s\n%s\n\
%s\n%s\n%s\n%s\n%s\n%s\n%s\n\
%s" \
"${div}" \
'## Language' ': C' \
'## Title' ': Makefile' \
'## File description:' \
'## <------------------------------------------->' \
'## Made by' ": $email" \
'## Creation date' ": $today at $time" \
"${div2}" \
'' 'SRC	=	$(shell find . -type f -name *.c)' \
'' 'OBJ	=	$(SRC:.c=.o)' \
'' "BIN	=	./$name" \
'' 'LIB	=	./libmy.a' \
'' 'CC	=	gcc' \
'' 'CFLAGS	+=	-g -Wall -Wextra -Wundef -Werror' \
'' 'all:		subsystem' \
'		$(CC) -o $(BIN) ./src/master.c $(LIB) $(CFLAGS)' \
'' 'subsystem:' \
'		$(MAKE) -C lib' \
'' 'ccc:		all' \
'		rm -rf $(OBJ) $(LIB)' \
'' 'clean:' \
'		rm -rf $(OBJ)' \
'' 'fclean:		clean' \
'		rm -rf $(LIB) $(BIN)' \
'' 're:		fclean all' > Makefile

/usr/bin/clear
