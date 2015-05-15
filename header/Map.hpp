/*
** Created by marsil_g on 11/05/15.
*/

#ifndef MAP_H
# define MAP_H

class Map {

    int             height;
    int             width;
    int             difficulty;
    std::string     name;

public:
    Map(int, int, int, std::string);
    ~Map();
    int             getHeight();
    int             getWidth();
    int             getDiff();
    std::string     getName();

};


# endif /* ! MAP_H */