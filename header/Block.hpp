/*
** Cube.hpp for Cube in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed May  6 15:57:15 2015 Jérémy MATHON
// Last update Tue Jun  9 17:36:52 2015 Valentin Cardon
*/

#ifndef BLOCK_HPP_
# define BLOCK_HPP_

#include	<SdlContext.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<Texture.hh>
#include	<Geometry.hh>
#include	"AObject.hpp"

class Block : public AObject
{
private:
  gdl::Texture _texture;   // La texture utilisee pour le Cube
  gdl::Geometry _geometry;   // La geometrie du Cube
  float _speed; // La vitesse de deplacement du Cube
  int	_x;
  int	_y;
  
public:
  Block(int, int);
  virtual ~Block();
  bool	initialize();
  void	update(gdl::Clock const &clock, gdl::Input &input);
  void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* !CUBE_HPP_ */
