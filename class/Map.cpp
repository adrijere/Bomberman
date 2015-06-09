/*
** Created by marsil_g on 15/05/15.
*/

#include "../header/Map.hpp"
#include "../header/Cube.hpp"

Map::Map(std::vector<AObject *> &object)
{
  srand(time(NULL));
  this->height = rand() % 100;
  this->width = rand() % 100;
  this->difficulty = 0;
  this->name = "";
  setMap(object);
}

Map::Map(int height, int width, int diff, std::string name, std::vector<AObject *> &object) {
    this->height = height;
    this->width = width;
    this->difficulty = diff;
    this->name = name;
    setMap(object);
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

void		Map::setMap(std::vector<AObject *> &object) {
    int		i;
    int		j;
    AObject	*obj;

    i = -1;
    while (++i != this->height)
    {
        j = -1;
        while (++j != this->width)
	  {
	    //	  this->map[i][j] = new Cube();
	    obj = new Cube(i, j);
	    obj->initialize();
	    object.push_back(obj);
	  }
    }
}

std::vector<AObject*>	Map::operator[](size_t i)
{
  if (i < this->map.size())
    return (this->map[i]);
} 
