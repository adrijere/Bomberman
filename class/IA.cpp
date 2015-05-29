//
// IA.cpp for bomberman.cpp in /home/cardon_v/Documents/CPP/cpp_bomberman/class
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Thu May 28 17:02:21 2015 Valentin Cardon
// Last update Fri May 29 14:14:36 2015 Valentin Cardon
//

#include	"IA.hpp"

bool		IA::initialize()
{
  this->_speed = 10.0f;
  if(_model.load("./lib/assets/grass.tga") == false)
    {
      std::cerr << "Cannot load the model texture" << std::endl;
      return (false);
    }
  this->scale(glm::vec3(0.01, 0.1, 0.01));
  return (true);
}

void		IA::update(gdl::Clock const& clock, gdl::Input &input)
{
  if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
}

void		IA::draw(gdl::AShader &shader, gdl::Clock const& clock)
{
  this->_model.draw(shader, getTransformation(), clock.getElapsed());
}
