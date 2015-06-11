/*
** Model.hpp for Model in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue May 12 10:00:00 2015 Jérémy MATHON
// Last update Thu Jun 11 17:31:27 2015 hures
*/

#ifndef MODEL_HPP_
# define MODEL_HPP_

#include	<Model.hh>
#include	"Bomb.hpp"
#include	"AObject.hpp"

class Model : public AObject
{
private:
  gdl::Model	_model;
  float		_speed;
  std::vector< std::vector<AObject *> > _map;
  int		_x;
  int		_y;
  int           _height;
  int           _widht;
  
public:
  Model(int, int, std::vector< std::vector<AObject *> > &);
  virtual ~Model();
  bool	initialize();
  void	update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*>&object);
  void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* !MODEL_HPP_ */
