/*
** Model.cpp for Model in /home/mathon_j/rendu/cpp_bomberman/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue May 12 09:59:55 2015 Jérémy MATHON
// Last update Thu Jun 11 19:47:55 2015 hures
*/


#include	"Model.hpp"

Model::Model(int x, int y, std::vector< std::vector<AObject *> > &map)
{
  _x = x;
  _y = y;
  _map = map;
  _height = _map.size();
  _widht = _map[0].size();
}

Model::~Model()
{

}

bool	Model::initialize()
{
  this->_speed = 5.0f;
  if (_model.load("./lib/assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load the model texture" << std::endl;
      return (false);
    }
  this->_model.setCurrentAnim(0); // FULL ANIMATION NEED TO CREATE SUB ANIM
  this->scale(glm::vec3(0.0018, 0.0018, 0.0018));
  translate(glm::vec3(_x, 0, _y)); //===> changer les coordonéees en fonction de la map
  return (true);
}

void	Model::update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*>&object)
{
  if (input.getKey(SDLK_UP))
    {
      _x += 1 * static_cast<float>(clock.getElapsed()) * _speed;
      if (_x >= _height - 2)
	{
	  _x = _height - 2;
	  return ;
	}
      if (_map[_x + 1][_y] != NULL)
	{
	  _x -= 1 * static_cast<float>(clock.getElapsed()) * _speed;
	  return ;
	}
      translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  if (input.getKey(SDLK_DOWN))
    {
      _x -= 1 * static_cast<float>(clock.getElapsed()) * _speed;
      if (_x < 1)
	{
	  _x = 1;
	  return ;
	}
      if (_map[_x - 1][_y] != NULL)
	{
	  _x += 1 * static_cast<float>(clock.getElapsed()) * _speed;
	  return ;
	}
      translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  if (input.getKey(SDLK_LEFT))
    {
      _y += 1 * static_cast<float>(clock.getElapsed()) * _speed;
      if (_y >= _widht - 2)
	{
	  _y = _widht - 2;
	  return ;
	}
      if (_map[_x][_y + 1] != NULL)
	{
	  _y -= 1 * static_cast<float>(clock.getElapsed()) * _speed;
	  return ;
	}
      translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  if (input.getKey(SDLK_RIGHT))
    {
      _y -= 1 * static_cast<float>(clock.getElapsed()) * _speed;
      if (_y < 1)
	{
	  _y = 1;
	  return;
	}
      if (_map[_x][_y - 1] != NULL)
	{
	  _y += 1 * static_cast<float>(clock.getElapsed()) * _speed;
	  return ;
	}
      translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    }
  if (input.getKey(SDLK_SPACE))
    {
      //ajoute la bombe a _object directement      
      //pose une bombe
      AObject *bombe = new Bomb(_y, _x);
      if (bombe->initialize() != false)
	object.push_back(bombe);
    }
}

void	Model::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  this->_model.draw(shader, getTransformation(), clock.getElapsed());
}
