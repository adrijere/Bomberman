/*
** Model.cpp for Model in /home/mathon_j/rendu/cpp_bomberman/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue May 12 09:59:55 2015 Jérémy MATHON
** Last update Wed Jun 10 17:19:55 2015 Jérémy MATHON
*/


#include	"Model.hpp"

Model::Model(int x, int y, std::vector<AObject *> &object)
{
  _x = x;
  _y = y;
  _object = object;
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

void	Model::update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*>&object)
{
  if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_DOWN))
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_LEFT))
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_RIGHT))
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_SPACE))
    {
      //ajoute la bombe a _object directement
      
      //pose une bombe
    }
  this->_model.setCurrentAnim(0);
}

void	Model::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  this->_model.draw(shader, getTransformation(), clock.getElapsed());
}
