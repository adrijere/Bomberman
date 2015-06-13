/*
** Model.hpp for Model in /home/mathon_j/rendu/cpp_bomberman/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue May 12 10:00:00 2015 Jérémy MATHON
// Last update Fri Jun 12 19:31:46 2015 hures
*/

#ifndef MODEL_HPP_
# define MODEL_HPP_

#include	<Model.hh>
#include	"Bomb.hpp"
#include	"Grass.hpp"
#include	"Block.hpp"
#include	"AObject.hpp"

class Model : public AObject
{
private:
  gdl::Model	_model;
  float		_speed;
  int		_time;
  std::vector< std::vector<AObject *> > _map;
  int           _height;
  int           _widht;
  //tmp for bomb vs block
  int		_bomb_x;
  int		_bomb_y;
  //
  int		_nbbomb;
  std::vector<AObject *>	_bomb;
public:
  float		_x; // test
  float		_y; // make getter
  Model(int, int, std::vector< std::vector<AObject *> > &);
  virtual ~Model();
  bool	initialize();
  void	update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*>&object);
  void	destroy_block(std::vector<AObject *>&);
  void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* !MODEL_HPP_ */
