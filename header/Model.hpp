/*
** Model.hpp for Model in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue May 12 10:00:00 2015 Jérémy MATHON
// Last update Thu Jun  4 14:42:43 2015 Valentin Cardon
*/

#ifndef MODEL_HPP_
# define MODEL_HPP_

#include	<SdlContext.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<Model.hh>
#include	"AObject.hpp"

class Model : public AObject
{
private:
  gdl::Model	_model;
  float		_speed;
public:
  Model() { }
  virtual ~Model() { }
  bool	initialize();
  void	update(gdl::Clock const &clock, gdl::Input &input);
  void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* !MODEL_HPP_ */
