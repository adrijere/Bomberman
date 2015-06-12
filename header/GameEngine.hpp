/*
** GameEngine.hpp for GameEngine in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed May  6 15:33:59 2015 Jérémy MATHON
** Last update Wed Jun 10 09:53:59 2015 Jérémy MATHON
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
#include	<string>
#include	"AObject.hpp"
#include	"Cube.hpp"
#include	"Model.hpp"
#include	"IA.hpp"
#include	"Map.hpp"
#include	"Menu.hpp"
#include	"Camera.hpp"

/*
On cree sa class GameEngine qui herite de Game
*/

class GameEngine : public gdl::Game
{

protected:
  gdl::SdlContext       _context;
  gdl::Clock            _clock;
  gdl::Input            _input;
  std::vector<AObject*> _objects;
  gdl::BasicShader      _shader;
  int                   _pause;
  MyMenu               *_menu;
  int                   _used;

public:
  int			_players;
  std::string		_map;
  GameEngine();
  ~GameEngine();
  bool  initialize();
  bool  update();
  void  draw();
  bool  Menu();
  bool  startGame();
};

#endif /* !GAMEENGINE_HPP_ */
