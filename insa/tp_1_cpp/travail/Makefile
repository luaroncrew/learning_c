##
## INSA, 2023
## TP1 CPP Basics
## File description:
## Makefile
##

SRC		=	./Ensemble.cpp							\
			./TEnsemble.cpp							\


OBJ		=	$(SRC:.cpp=.o)

NAME	=	classe

CFLAGS	=	-W -Wall -Wextra -g

all:	$(NAME)
		@echo -e "\033[0;34m<$(NAME) is now ready to use>\033[00m"

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME)
	@echo -e "\033[0;34m<useless file has been deleted -> .o>\033[00m"
	rm -f $(OBJ)

clean:
	@echo -e "\033[0;34m<Deleting useless files>\033[00m"
	rm -f $(OBJ)

fclean:    clean
	rm -f $(NAME)

re:	fclean all