/*
** GameEngine.hpp for GameEngine in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed May  6 15:33:59 2015 Jérémy MATHON
// Last update Thu May  7 13:08:05 2015 Valentin Cardon
*/

#ifndef GAMEENGINE_HPP_
# define GAMEENGINE_HPP_

#pragma once
#include <Game.hh>
#include <SdlContext.hh>
#include <vector>
#include <BasicShader.hh>
#include "AObject.hpp"

/*
On cree sa class GameEngine qui herite de Game
*/
class GameEngine : public gdl::Game
{
private:
  gdl::SdlContext _context;
  gdl::Clock _clock;
  gdl::Input _input;
  gdl::BasicShader _shader;
  std::vector<AObject*> _objects;
public:
  GameEngine();
  bool initialize();
  bool update();
  void draw();
  ~GameEngine();
};
#endif /* !GAMEENGINE_HPP_ */
