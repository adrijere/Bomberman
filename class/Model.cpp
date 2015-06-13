/*
** Model.cpp for Model in /home/mathon_j/rendu/cpp_bomberman/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue May 12 09:59:55 2015 Jérémy MATHON
// Last update Sat Jun 13 16:13:00 2015 Valentin Cardon
*/


#include	"Model.hpp"

Model::Model(int x, int y, std::vector< std::vector<AObject *> > &map)
{
  _x = x;
  _y = y;
  _map = map;
  _height = _map.size();
  _widht = _map[0].size();
  _nbbomb = 1;
  _time = 999;
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
  this->scale(glm::vec3(0.0018, 0.0018, 0.0018));
  translate(glm::vec3(_x, 0, _y)); //===> changer les coordonéees en fonction de la map
  return (true);
}

void	Model::destroy_block(std::vector<AObject *>&object)
{
  AObject *tmp;
  AObject *obj;
  int		x;
  int		y;

  x = _bomb_x;
  y = _bomb_y;

  //NEED BOMB TIME TO REMOVE AT THE SAME TIME
  tmp = NULL;
  if (dynamic_cast<Block *>(_map[round(x + 1)][round(y)]))
    {
      tmp = _map[round(x + 1)][round(y)];
      this->_map[round(x + 1)][round(y)] = NULL;
    }
  if (dynamic_cast<Block *>(_map[round(x - 1)][round(y)]))
    {
      tmp = _map[round(x - 1)][round(y)];
      this->_map[round(x - 1)][round(y)] = NULL;
    }
  if (dynamic_cast<Block *>(_map[round(x)][round(y + 1)]))
    {
      tmp = _map[round(x)][round(y + 1)];
      this->_map[round(x)][round(y + 1)] = NULL;
    }
  if (dynamic_cast<Block *>(_map[round(x)][round(y - 1)]))
    {
      tmp = _map[round(x)][round(y - 1)];
      this->_map[round(x)][round(y - 1)] = NULL;
    }
  if (tmp != NULL)
    {
      std::vector<AObject*>::iterator i = object.begin();
      while(i != object.end())
	{
	  if (tmp == *i)
	    object.erase(i);
	  ++i;
	}
    }
  _time = 999;
}

void	Model::update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*>&object)
{
  float move_val;

  if (this->_time != 999)
    {
      if (this->_time > 0)
	_time--;
      if (this->_time == 0)
	destroy_block(object);
    }
  
  if (this->_bomb.empty())
    this->_nbbomb = 1;
  move_val = 1 * static_cast<float>(clock.getElapsed()) * _speed;
  if (input.getKey(SDLK_UP))
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
  if (input.getKey(SDLK_DOWN))
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
  if (input.getKey(SDLK_LEFT))
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
  if (input.getKey(SDLK_RIGHT))
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
  if (input.getKey(SDLK_SPACE) && this->_nbbomb != 0)
    {
      //ajoute la bombe a _object directement      
      //pose une bombe
      this->_nbbomb = 0;
      AObject *bombe = new Bomb(round(_x), round(_y));
      _bomb_x = round(_x);
      _bomb_y = round(_y);
      _time = 70;
      this->_bomb.push_back(bombe);
      if (bombe->initialize() != false)
	object.push_back(bombe);
    }
  this->_model.setCurrentAnim(0); // FULL ANIMATION NEED TO CREATE SUB ANIM
  this->_nbbomb = 1;
}

void	Model::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  this->_model.draw(shader, getTransformation(), clock.getElapsed());
}
