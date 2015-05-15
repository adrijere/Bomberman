/*
** Created by marsil_g on 15/05/15.
*/

#include "../header/Map.hpp"


Map::Map(int, height, int width, int diff, std::string name) {
    this->height = height;
    this->width = width;
    this->difficulty = diff;
    this->name = name;
}

Map::~Map() {
}

int             Map::getHeight() {
    return (this->height);
}

int             Map::getWidth() {
    return (this->width);
}

int             Map::getDiff() {
    return (this->difficulty);
}

std::string     Map::getName() {
    return (this->name);
}
