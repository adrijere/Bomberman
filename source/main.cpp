/*
// main.cpp for bomberman in /home/cardon_v/Documents/CPP/cpp_bomberman/source
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Thu Apr 30 13:38:09 2015 Valentin Cardon
** Last update Wed May  6 15:32:57 2015 Jérémy MATHON
*/

#include	<cstdlib>
#include	"GameEngine.hpp"

int main()
{
  // On cree son engine
  GameEngine engine;
  if (engine.initialize() == false)
    return (EXIT_FAILURE);
  while (engine.update() == true)
    engine.draw();
  return EXIT_SUCCESS;
}

