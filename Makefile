##
## Makefile for bomberman in /home/cardon_v/Documents/CPP/cpp_bomberman
##
## Made by Valentin Cardon
## Login   <cardon_v@epitech.net>
##
## Started on  Thu Apr 30 13:35:19 2015 Valentin Cardon
## Last update Thu Jun  4 16:46:21 2015 Gabriele Marsili
##

NAME		=	bomberman

TMP		=	$(SRC:.cpp=.cpp~)

CXXFLAGS	=	-I ./header -I ./lib/includes

LDFLAGS		=	-ldl -fPIC -lpthread -lrt -lGL -L./lib/libs/ -lgdl_gl -lGLEW -lfbxsdk -lSDL2 -ldl -lSDL -lSDLmain -lSDL_image

include		source.mk

OBJ		=	$(SRC:.cpp=.o)


all		:	$(NAME)

$(NAME)		:	$(OBJ)
			g++ $(OBJ) -o $(NAME) $(LDFLAGS)

clean		:
			rm -rf $(OBJ) $(TMP)

fclean		:	clean
			rm -rf $(NAME)

re		:	fclean all
