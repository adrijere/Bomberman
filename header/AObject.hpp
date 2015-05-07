/*
** AObject.hpp for AObject in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed May  6 15:43:00 2015 Jérémy MATHON
// Last update Thu May  7 13:05:17 2015 Valentin Cardon
*/

#ifndef AOBJECT_HPP_
# define AOBJECT_HPP_

#include <iostream>
#include <SdlContext.hh>
#include <AShader.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// La classe abstraite representant un objet avec sa position, sa rotation et son echelle
class AObject
{
public:
  AObject();
  virtual ~AObject(){};
  virtual bool initialize();
  // La fonction update sert a gerer le comportement de l'objet
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  // La fonction draw sert a dessiner l'objet
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  void	translate(glm::vec3 const &v);
  void	rotate(glm::vec3 const &axis, float angle);
  void	scale(glm::vec3 const &scale);
  glm::mat4	getTransformation();
protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;
};

#endif /* !AOBJECT_HPP_ */
