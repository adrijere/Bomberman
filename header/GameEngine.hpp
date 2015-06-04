/*
** GameEngine.hpp for GameEngine in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed May  6 15:33:59 2015 Jérémy MATHON
// Last update Mon Jun  1 18:48:12 2015 Valentin Cardon
*/

#ifndef GAMEENGINE_HPP_
# define GAMEENGINE_HPP_

#pragma	once
#include	<unistd.h>
#include	<SdlContext.hh>
#include	<BasicShader.hh>
#include	<Game.hh>
#include	<Clock.hh>
#include	<vector>
#include	"AObject.hpp"
#include	"Cube.hpp"
#include	"Model.hpp"
#include	"IA.hpp"
#include	"Menu.hpp"

/*
On cree sa class GameEngine qui herite de Game
*/
class GameEngine : public gdl::Game
{

private:
  gdl::SdlContext       _context;
  gdl::Clock            _clock;
  gdl::Input            _input;
  std::vector<AObject*> _objects;
  gdl::BasicShader      _shader;
  int                   _pause;

public:
  GameEngine();
  bool  initialize();
  bool  update();
  void  draw();
  bool  Menu();
  ~GameEngine();
};
#endif /* !GAMEENGINE_HPP_ */
