/*
// main.cpp for bomberman in /home/cardon_v/Documents/CPP/cpp_bomberman/source
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Thu Apr 30 13:38:09 2015 Valentin Cardon
** Last update Tue Jun  9 16:27:36 2015 Jérémy MATHON
*/

#include	<cstdlib>
#include	"../header/GameEngine.hpp"

int main(int ac, char **av)
{
  GameEngine	engine;
  MyMenu		menu;

/*  if (menu.Check(ac, av) == false)
    return (EXIT_FAILURE);
  menu._players = engine._players;
  menu._map = engine._map;*/

  if (engine.initialize() == false)
    return (EXIT_FAILURE);
  while (engine.update() == true)
    engine.draw();
  return EXIT_SUCCESS;
}
