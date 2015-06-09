/*
** Camera.cpp for Camera in /home/mathon_j/rendu/cpp_bomberman/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Jun  9 17:10:58 2015 Jérémy MATHON
** Last update Tue Jun  9 17:17:58 2015 Jérémy MATHON
*/

#include	"Camera.hpp"

bool	Camera::initalize()
{
  this->_speed = 10.0f;
  return (true);
}

void	Camera::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_DOWN))
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_LEFT))
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_RIGHT))
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
}

void	Camera::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  (void)shader;
}
