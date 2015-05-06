##
## Makefile for bomberman in /home/cardon_v/Documents/CPP/cpp_bomberman
## 
## Made by Valentin Cardon
## Login   <cardon_v@epitech.net>
## 
## Started on  Thu Apr 30 13:35:19 2015 Valentin Cardon
## Last update Wed May  6 15:04:08 2015 Jérémy MATHON
##

NAME		=	bomberman

SRC		=	source/main.cpp		\
			class/init.cpp

OBJ		=	$(SRC:.cpp=.o)

TMP		=	$(SRC:.cpp=.cpp~)

CXXFLAGS	=	-I ./header - –Ilib/includes/ -Llib/libs/ -lgdl_gl –lGL –lGLEW –ldl –lrt –lfbxsdk –lSDL2 –lpthread

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			g++ $(OBJ) -o $(NAME)

clean		:
			rm -rf $(OBJ) $(TMP)

fclean		:	clean
			rm -rf $(NAME)

re		:	fclean all
