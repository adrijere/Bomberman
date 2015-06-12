/*
// IA.cpp for bomberman.cpp in /home/cardon_v/Documents/CPP/cpp_bomberman/class
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Thu May 28 17:02:21 2015 Valentin Cardon
// Last update Fri Jun 12 23:25:40 2015 hures
*/

#include	"IA.hpp"

IA::IA(int x, int y, std::vector< std::vector<AObject *> > &map)
{
  _x = x;
  _y = y;
  _map = map;
  _height = map.size();
  _widht = map[0].size();
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
  this->scale(glm::vec3(0.0018, 0.0018, 0.0018));
  translate(glm::vec3(_x, 0, _y));
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

void		IA::move(gdl::Clock const& clock, int input, std::vector<AObject*>&object)
{
  float move_val;

  move_val = 1 * static_cast<float>(clock.getElapsed()) * _speed;
  if (input == 0)
    {
      if (_map[round(_x)][round(_y + move_val + 0.4)] != NULL)
	return ;
      _y += 1 * static_cast<float>(clock.getElapsed()) * _speed;
      if (_y >= _height - 2)
	{
	  _y = _height - 2;
	  return ;
	}
      translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  if (input == 1)
    {
      if (_y > 2)
	if (_map[round(_x)][round(_y - move_val - 0.4)] != NULL)
	  return ;
      _y -= 1 * static_cast<float>(clock.getElapsed()) * _speed;
      if (_y < 1)
	{
	  _y = 1;
	  return ;
	}
      translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  if (input == 2)
    {
      if (_map[round(_x + move_val + 0.4)][round(_y)] != NULL)
	return ;
      _x += 1 * static_cast<float>(clock.getElapsed()) * _speed;
      if (_x >= _widht - 2)
	{
	  _x = _widht - 2;
	  return ;
	}
      translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    }    
  if (input == 3)
    {
      if (_map[round(_x - move_val - 0.4)][round(_y)] != NULL)
	return ;
      _x -= 1 * static_cast<float>(clock.getElapsed()) * _speed;
      if (_x < 1)
	{
	  _x = 1;
	  return;
	}
      translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  if (input == 4)
    {
      AObject *bomb = new Bomb(round(_x), round(_y));
      if(bomb->initialize() == false)
	{
	  std::cerr << "Cannot load the bomb" << std::endl;
	  return ;
	}
      object.push_back(bomb);
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
  move(clock, i, object);
  usleep(5000);
}
