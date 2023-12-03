NAME		=	editor

SRC			=	$(shell find . -name "*.cpp")

OBJ			=	$(SRC:.cpp=.o)

LDLIBS		=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

CXXFLAGS	=	-Wall -Wextra -std=c++11 -I./lib -g3

all: 		$(NAME)


$(NAME):	$(OBJ)
			g++ $(OBJ) -o $(NAME) $(LDLIBS)

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
