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
  std::vector < std::vector<AObject *> >	tmp(height, std::vector<AObject *>(width));
  map = tmp;
  setMap(object);
}

Map::Map(int height, int width, int diff, std::string name, std::vector<AObject *> &object) {
    this->height = height;
    this->width = width;
    this->difficulty = diff;
    this->name = name;
    std::vector < std::vector<AObject *> >	tmp(height, std::vector<AObject *>(width));
    map = tmp;
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

int		Map::solid_block_pos()
{
  int		k = 0;

  if (this->width / 10 > 0)
    {
      k = this->width / 10;
      while (k != 0)
	{
	  if (k / 10 <= 0)
	    return (k);
	  else if (k / 10 > 0)
	    k = k / 10;
	}
    }
  else
    return (1);
  return (0);
}
  
void		Map::setMap(std::vector<AObject *> &object) {
  int		i;
  int		j;
  int		solid_pos;
  int		block_pos;
  AObject	*obj;
    
  i = -1;
  solid_pos = solid_block_pos();
  while (++i != this->height)
    {
      j = -1;
      block_pos = rand() % this-> width;
      while (++j != this->width)
	{
	  if (i == 0 || j == 0 || i == this->height - 1 || j == this->width - 1)
	    {
	      obj = new Cube(i, j);
	      obj->initialize();
	      object.push_back(obj);
	      this->map[i][j] = obj;
	    }
	  else if (solid_pos != 1 && j % solid_pos == 0 && i % solid_pos == 0)
	    {
	      obj = new Cube(i, j);
	      obj->initialize();
	      object.push_back(obj);
	      this->map[i][j] = obj;
	    }
	  else
	    {
	      obj = new Grass(i, j);
	      obj->initialize();
	      object.push_back(obj);
	    }
	  if (j == block_pos)
	    {
	      obj = new Block(i, j);
	      obj->initialize();
	      object.push_back(obj);
	      this->map[i][j] = obj;
	      block_pos = rand() % this-> width;
	    }
	}
    }
}

std::vector<AObject*>	Map::operator[](size_t i)
{
  if (i < this->map.size())
    return (this->map[i]);
}
