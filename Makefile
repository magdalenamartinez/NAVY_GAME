##
## June 2024
## Magdalena Martinez Sanchez
## NAVY_GAME
## Makefile
##

NAME	=	navy_game



INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/file.c	\
		src/connect.c	\
		src/signal.c	\
		src/game.c	\
		src/map.c	\
		src/boat.c	\
		src/utilities.c	\
		src/attack.c	\
	

OBJ	=	$(SRC:.c=.o)


all: 	$(NAME)

$(NAME): 	$(OBJ)

		gcc -g $(OBJ) -o $(NAME) $(INCLUDE) 

clean:
	rm -f $(NAME)


fclean: clean
	rm -f ./src/*.o

re: 	fclean all

library: fclean

exec:	re
	./$(NAME)
