/*
** Cube.hpp for Cube in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed May  6 15:57:15 2015 Jérémy MATHON
// Last update Fri Jun 12 16:54:39 2015 Valentin Cardon
*/

#ifndef SPEED_HPP_
# define SPEED_HPP_

#include	<SdlContext.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<Texture.hh>
#include	<Geometry.hh>
#include	"AObject.hpp"

class Speed : public AObject
{
private:
  gdl::Texture _texture;   // La texture utilisee pour le Cube
  gdl::Geometry _geometry;   // La geometrie du Cube
  int	_x;
  int	_y;
  
public:
  Speed(int, int);
  virtual ~Speed();
  bool	initialize();
  void	update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*>&object);
  void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* !SPEED_HPP_ */
