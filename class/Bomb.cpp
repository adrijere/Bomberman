/*
** Bomb.cpp for Bomb in /home/mathon_j/rendu/cpp_bomberman/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed Jun  3 18:00:47 2015 Jérémy MATHON
// Last update Fri Jun  5 13:11:26 2015 Valentin Cardon
*/

#include	"Bomb.hpp"

bool	Bomb::initialize()
{
  if (_texture.load("./lib/assets/grass.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
  return (true);
}

void	Bomb::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->_time > 0)
    _time--;
  if (this->_time == 0)
    delete (this);
}

/*void	Bomb::update(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
  }*/

void	Bomb::draw(gdl::AShader& shader, gdl::Clock const& clock)
{}
