//
// IA.cpp for bomberman.cpp in /home/cardon_v/Documents/CPP/cpp_bomberman/class
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Thu May 28 17:02:21 2015 Valentin Cardon
// Last update Mon Jun  1 19:08:29 2015 Valentin Cardon
//

#include	"IA.hpp"

bool		IA::initialize()
{
  this->_speed = 10.0f;
  if(_ia.load("./lib/assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load the model texture" << std::endl;
      return (false);
    }
  this->scale(glm::vec3(0.01, 0.01, 0.01));
  return (true);
}

void		IA::move(gdl::Clock const& clock, int const& input)
{
  std::list<int>	last_move;

  last_move.push_back(input);
  if (input == 0)
    {
      //rotation(up)
      translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  if (input == 1)
    {
      //rotation(dowm)
      translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  if (input == 2)
    {
      //rotation(right);
      translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  if (input == 3)
    {
      //rotation(left);
      translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  if (input == 4)
    {
      //BOOOOOOOM TA MERE
      //recule pour ne pas se faire peter la tronche lui mê
      //attend que la bombe explose
    }
}

void		IA::draw(gdl::AShader &shader, gdl::Clock const& clock)
{
  this->_ia.draw(shader, getTransformation(), clock.getElapsed());
}

void		IA::update(gdl::Clock const& clock, gdl::Input &input)
{
  int		i;

  srand(time(NULL));
  i = rand() % 5;
  move(clock, i);
  usleep(5000);
}
