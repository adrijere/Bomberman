/*
** Created by marsil_g on 11/05/15.
*/

#ifndef MAP_H
# define MAP_H

#include <iostream>

class Map {

    int             height;
    int             width;
    int             difficulty;
    std::string     name;
    char            **map;

public:
    Map(int, int, int, std::string);
    ~Map();

    int             getHeight() const;
    int             getWidth() const;
    int             getDiff() const;
    std::string     getName() const;
    void            setMap(char **);
};

# endif /* ! MAP_H */
