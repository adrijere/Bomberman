/*
** Camera.hpp for Camera in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Jun  9 17:13:20 2015 Jérémy MATHON
** Last update Tue Jun  9 17:18:43 2015 Jérémy MATHON
*/

#ifndef CAMERA_HPP_
# define CAMERA_HPP_

#include	"AObject.hpp"

class	Camera : public AObject
{
protected:
  float		_speed;
public:
  Camera() { }
  virtual ~Camera() { }
  bool	initialize();
  void	update(gdl::Clock const &clock, gdl::Input &input);
  void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* !CAMERA_HPP_ */
