//
// IA.cpp for bomberman.cpp in /home/cardon_v/Documents/CPP/cpp_bomberman/class
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Thu May 28 17:02:21 2015 Valentin Cardon
// Last update Fri May 29 15:58:06 2015 Valentin Cardon
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

void		IA::move(gdl::Clock const& clock, int const& input)
{
  if (input == 0)
    {
      translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
      std::cout << "Je move UP" << std::endl;
    }
  if (input == 1)
    {
      translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
      std::cout << "Je move DOWN" << std::endl;
    }
  if (input == 2)
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input == 3)
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
}

void		IA::draw(gdl::AShader &shader, gdl::Clock const& clock)
{
  this->_model.draw(shader, getTransformation(), clock.getElapsed());
}

void		IA::play(gdl::Clock const& clock, gdl::AShader &shader)
{
  while (1)
    {
      move(clock, 1);
      draw(shader, clock);
    }
}
