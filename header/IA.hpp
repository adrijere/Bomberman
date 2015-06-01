//
// IA.hpp for bomberman in /home/cardon_v/Documents/CPP/cpp_bomberman/class
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Thu May 28 17:01:48 2015 Valentin Cardon
// Last update Mon Jun  1 17:48:46 2015 Valentin Cardon
//

#ifndef		_IA_HPP_
#define		_IA_HPP_

#include	<unistd.h>
#include	<SdlContext.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<Model.hh>
#include	"AObject.hpp"

class		IA : public AObject
{
private:
  gdl::Model	_ia;
  float		_speed;

public:
  IA() { }
  virtual ~IA() { }  
  bool		initialize();
  void		update(gdl::Clock const& clock, gdl::Input &input);
  void		move(gdl::Clock const& clock, int const& input);
  void		draw(gdl::AShader &shader, gdl::Clock const& clock);
};

#endif		/*_IA_HPP_*/
