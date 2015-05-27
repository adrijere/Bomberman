/*
** Created by marsil_g on 15/05/15.
*/

#include "../header/Map.hpp"

Map::Map(int height, int width, int diff, std::string name) {
    this->height = height;
    this->width = width;
    this->difficulty = diff;
    this->name = name;
    setMap();
}

Map::~Map() {
}

int             Map::getHeight() const {
    return (this->height);
}

int             Map::getWidth() const {
    return (this->width);
}

int             Map::getDiff() const {
    return (this->difficulty);
}

std::string     Map::getName() const {
    return (this->name);
}

void		Map::setMap() {
  int		i;
  int		j;

  i = 0;
  while (i != this->height)
    {
      j = 0;
      while (j != this->width)
	{
	  map[i][j] = new Cube;
	  j++;
	}      
      i++;
    }
}
