/*
** Bomb.hpp for Bomb in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed Jun  3 18:01:08 2015 Jérémy MATHON
** Last update Tue Jun  9 10:30:08 2015 Jérémy MATHON
*/

#ifndef BOMB_HPP_
# define BOMB_HPP_

#include	<Texture.hh>
#include	<Geometry.hh>
#include	"AObject.hpp"

class Bomb : public AObject
{
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  int           _time;
public:
  Bomb() : _time(3) { }
  virtual ~Bomb() { }
  bool  initialize();
  void  update(gdl::Clock const &clock, gdl::Input &input);
  void	draw(gdl::AShader&, gdl::Clock const& clock);
};

#endif /* !BOMB_HPP_ */

