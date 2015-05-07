##
## Makefile for bomberman in /home/cardon_v/Documents/CPP/cpp_bomberman
## 
## Made by Valentin Cardon
## Login   <cardon_v@epitech.net>
## 
## Started on  Thu Apr 30 13:35:19 2015 Valentin Cardon
## Last update Thu May  7 20:47:00 2015 Valentin Cardon
##

NAME		=	bomberman

SRC		=	source/main.cpp		\
			class/GameEngine.cpp	\
			class/AObject.cpp	\
			class/Cube.cpp

OBJ		=	$(SRC:.cpp=.o)

TMP		=	$(SRC:.cpp=.cpp~)

CXXFLAGS	=	-I ./header -I ./lib/includes

LDFLAGS		=	-ldl -fPIC -lpthread -lrt -lGL -L./lib/libs/ -lgdl_gl -lGLEW -lfbxsdk -lSDL2

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			clang++ $(OBJ) -o $(NAME) $(LDFLAGS)

clean		:
			rm -rf $(OBJ) $(TMP)

fclean		:	clean
			rm -rf $(NAME)

re		:	fclean all
