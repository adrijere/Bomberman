/*
** Created by marsil_g on 11/05/15.
*/

#ifndef MAP_H
# define MAP_H

#include <iostream>
#include <vector>
#include "Grass.hpp"
#include "Block.hpp"
#include "IA.hpp"
#include "Model.hpp"
#include "Bomb.hpp"
#include "AObject.hpp"
#define P_X 1
#define P_Y 1
#define IA_TOP_LEFT_X this->height - 2
#define IA_TOP_LEFT_Y this->width - 2
#define IA_TOP_RIGHT_X 2
#define IA_TOP_RIGHT_Y this->width - 2
#define IA_BOT_LEFT_X this->height - 2
#define IA_BOT_LEFT_Y 2


class Map 
{
  int             height;
  int             width;
  int             difficulty;
  std::string     name;
  
  std::vector < std::vector<AObject *> >	map;
  
public:
  Map(std::vector<AObject *> &);
  Map(int, int, int, std::string, std::vector<AObject *> &);
  ~Map();

  int           getHeight() const;
  int           getWidth() const;
  int           getDiff() const;
  std::string   getName() const;
  void		setMap(std::vector<AObject *> &);
  int		solid_block_pos();
  
  std::vector<AObject *>		operator[](size_t);
};


#endif /* ! MAP_H */
