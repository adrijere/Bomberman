//
// IA.hpp for bomberman in /home/cardon_v/Documents/CPP/cpp_bomberman/class
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Thu May 28 17:01:48 2015 Valentin Cardon
// Last update Fri May 29 15:55:55 2015 Valentin Cardon
//

#ifndef		_IA_HPP_
#define		_IA_HPP_

#include	<SdlContext.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<Model.hh>
#include	"AObject.hpp"

class		IA : public AObject
{
private:
  gdl::Model	_model;
  float		_speed;

public:
  IA() { }
  virtual ~IA() { }  
  bool		initialize();
  void		play(gdl::Clock const& clock, gdl::AShader &shader);
  void		move(gdl::Clock const& clock, int const& input);
  void		draw(gdl::AShader &shader, gdl::Clock const& clock);
};

#endif		/*_IA_HPP_*/
