/*
** Camera.hpp for Camera in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Jun  9 17:13:20 2015 Jérémy MATHON
** Last update Thu Jun 11 10:58:50 2015 Jérémy MATHON
*/

#ifndef CAMERA_HPP_
# define CAMERA_HPP_

# include	"Model.hpp"
# include	"AObject.hpp"

class	Camera : public AObject
{
protected:
  glm::mat4		projection;
  glm::mat4		transformation;
  float			_speed;
  int			width;
  gdl::BasicShader	_shader;
  Model*		_model;
  float         x;
public:
  Camera(int, gdl::BasicShader &);
  virtual ~Camera();
  bool	initialize();
  void	update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*> &object);
  void	draw(gdl::AShader &shader, gdl::Clock const &clock);
  void  zoom();
  void  dezoom();
};

#endif /* !CAMERA_HPP_ */
