//
// Grass.hpp for bomberman in /home/cardon_v/Documents/CPP/cpp_bomberman/class
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Tue Jun  9 15:17:13 2015 Valentin Cardon
// Last update Wed Jun 10 17:18:34 2015 Valentin Cardon
//

#ifndef		_GRASS_HPP_
#define		_GRASS_HPP_

#include	<SdlContext.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<Texture.hh>
#include	<Geometry.hh>
#include	"AObject.hpp"


class	Grass : public AObject
{
private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  int		_x;
  int		_y;

public:
  Grass(int, int);
  virtual ~Grass();
  bool	initialize();
  void	update(gdl::Clock const& clock, gdl::Input &input, std::vector<AObject*>&);
  void	draw(gdl::AShader &shader, gdl::Clock const& clock);
};

#endif		/* _GRASS_HPP_ */
