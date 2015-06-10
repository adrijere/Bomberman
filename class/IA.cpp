/*
// IA.cpp for bomberman.cpp in /home/cardon_v/Documents/CPP/cpp_bomberman/class
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Thu May 28 17:02:21 2015 Valentin Cardon
** Last update Wed Jun 10 17:19:00 2015 Jérémy MATHON
*/

#include	"IA.hpp"

IA::IA(std::vector<AObject *> &object)
{
  _object = object;
}

IA::~IA()
{

}

bool		IA::initialize()
{
  this->_speed = 5.0f;
  if(_ia.load("./lib/assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load the model texture" << std::endl;
      return (false);
    }
  this->scale(glm::vec3(0.0015, 0.0015, 0.0015));
  //translate(glm::vec3(20, 0, 1)); ===> changer les coordonées en fonction de la map
  return (true);
}

void		IA::go_back(gdl::Clock const& clock, int input)
{
  if (input == 0)
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input == 1)
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input == 2)
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input == 3)
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
}

void		IA::move(gdl::Clock const& clock, int input)
{
  if (input == 0)
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input == 1)
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input == 2)
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input == 3)
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input == 4)
    {
      std::cout << "BOOM !!" << std::endl;
      AObject *bomb = new Bomb();
      if(bomb->initialize() == false)
	{
	  std::cerr << "Cannot load the bomb" << std::endl;
	  return ;
	}
      // _object.push_back(bomb); //Ajout dans liste d'object
      go_back(clock, input);
    }
}

void		IA::draw(gdl::AShader &shader, gdl::Clock const& clock)
{
  this->_ia.draw(shader, getTransformation(), clock.getElapsed());
}

void		IA::update(gdl::Clock const& clock, gdl::Input &input, std::vector<AObject*>&object)
{
  static int	i = rand() % 5;
  static int	time = 25;

  if (i == 4 || time == 0)
    {
      i = rand() % 5;
      time = 25;
    }
  else
    time--;
  move(clock, i);
  usleep(5000);
}
