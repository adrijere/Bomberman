##
## Makefile for bomberman in /home/cardon_v/Documents/CPP/cpp_bomberman
## 
## Made by Valentin Cardon
## Login   <cardon_v@epitech.net>
## 
## Started on  Thu Apr 30 13:35:19 2015 Valentin Cardon
## Last update Thu May  7 15:45:33 2015 Valentin Cardon
##

NAME		=	bomberman

SRC		=	source/main.cpp		\
			class/GameEngine.cpp	\
			class/AObject.cpp	\
			class/Cube.cpp

OBJ		=	$(SRC:.cpp=.o)

TMP		=	$(SRC:.cpp=.cpp~)

CXXFLAGS	=	-I ./header -I ./lib/includes

LDFLAGS		=	-L ./lib/libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			g++ $(OBJ) -o $(NAME) $(LDFLAGS)

clean		:
			rm -rf $(OBJ) $(TMP)

fclean		:	clean
			rm -rf $(NAME)

re		:	fclean all
