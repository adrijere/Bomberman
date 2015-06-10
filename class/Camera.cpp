/*
** Camera.cpp for Camera in /home/mathon_j/rendu/cpp_bomberman/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Jun  9 17:10:58 2015 Jérémy MATHON
** Last update Wed Jun 10 09:54:23 2015 Jérémy MATHON
*/

#include	"Camera.hpp"

bool	Camera::initialize()
{
  projection = glm::perspective(60.0f, 1280.0f / 720.0f, 0.1f, 100.0f); // on définit ici le frustum
  // 0 2 -5     0 0 0     0 1 0
  transformation = glm::lookAt(glm::vec3((width / 2), 4, -10), glm::vec3((width / 2), 0, 0), glm::vec3(0, 1, 0));
  //et ici la position      

  // on doit TOUJOURS binder le shader AVANT d'appeler les methodes setUniform
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);

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
