/*
** AObject.hpp for AObject in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed May  6 15:43:00 2015 Jérémy MATHON
** Last update Tue Jun  9 11:14:11 2015 Jérémy MATHON
*/

#ifndef AOBJECT_HPP_
# define AOBJECT_HPP_

#include	<iostream>
#include	<SdlContext.hh>
#include	<AShader.hh>
#include	<BasicShader.hh>
#include	<Game.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>

// La classe abstraite representant un objet avec sa position, sa rotation et son echelle
class AObject
{
protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;
  int       _img;

public:
  AObject();
  virtual ~AObject(){};
  virtual bool initialize();
  // La fonction update sert a gerer le comportement de l'objet
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  // La fonction draw sert a dessiner l'objet
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  // La fonction play sert au lancement de l'IA
   void	translate(glm::vec3 const &v);
  void	rotate(glm::vec3 const &axis, float angle);
  void	scale(glm::vec3 const &scale);
  glm::mat4	getTransformation();
};

#endif /* !AOBJECT_HPP_ */
