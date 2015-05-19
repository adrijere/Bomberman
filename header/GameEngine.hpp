/*
** GameEngine.hpp for GameEngine in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed May  6 15:33:59 2015 Jérémy MATHON
** Last update Tue May 12 15:36:48 2015 Jérémy MATHON
*/

#ifndef GAMEENGINE_HPP_
# define GAMEENGINE_HPP_

#pragma	once
#include	<SdlContext.hh>
#include	<BasicShader.hh>
#include	<Game.hh>
#include	<Clock.hh>
#include	<vector>
#include	"AObject.hpp"
#include	"Cube.hpp"
#include	"Model.hpp"

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

public:
  GameEngine();
  bool  initialize();
  bool  update();
  void  draw();
  bool  Menu();
  ~GameEngine();
};
#endif /* !GAMEENGINE_HPP_ */
