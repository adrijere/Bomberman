/*
** Created by marsil_g on 11/05/15.
*/

#ifndef MAP_H
# define MAP_H

#include <iostream>
#include <vector>
#include "AObject.hpp"

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
  std::vector<AObject *>		operator[](size_t);
};


#endif /* ! MAP_H */
