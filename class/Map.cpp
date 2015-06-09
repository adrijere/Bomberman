/*
** Created by marsil_g on 15/05/15.
*/

#include "../header/Map.hpp"
#include "../header/Cube.hpp"

Map::Map()
{
  srand(time(NULL));
  this->height = rand() % 100;
  this->width = rand() % 100;
  this->difficulty = 0;
  this->name = "";
  setMap();
}

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

    i = -1;
    while (++i != this->height)
    {
        j = -1;
        while (++j != this->width)
	  this->map[i][j] = new Cube();
    }
}

std::vector<AObject*>	Map::operator[](size_t i)
{
  if (i < this->map.size())
    return (this->map[i]);
} 
