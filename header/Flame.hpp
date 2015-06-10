//
// Flame.hpp for bomberman in /home/cardon_v/Documents/CPP/cpp_bomberman/header
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Tue Jun  9 19:40:37 2015 Valentin Cardon
// Last update Wed Jun 10 17:57:33 2015 Valentin Cardon
//

#ifndef FLAME_HPP_
# define FLAME_HPP_

#include	<SdlContext.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<Texture.hh>
#include	<Geometry.hh>
#include	"AObject.hpp"

class Flame : public AObject
{
private:
  gdl::Texture _texture;   // La texture utilisee pour le Cube
  gdl::Geometry _geometry;   // La geometrie du Cube
  int	_x;
  int	_y;
  
public:
  Flame(int x, int y);
  virtual ~Flame();
  bool	initialize();
  void	update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*>&);
  void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* !FLAME_HPP_ */
