//
// Score.hpp for score in /home/hure_s/tek2/rendu/cpp_bomberman/header
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Thu May 21 10:04:23 2015 simon hure
// Last update Thu May 21 12:20:07 2015 simon hure
//

#ifndef _SCORE_HH_
#define _SCORE_HH_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <list>
#include <iomanip>

typedef struct	s_high
{
  int		position;
  std::string	score;
  std::string	name;
  std::string	date;
  //add other information to score board
}		t_high;

class	Score
{
private:
  std::list<t_high> _all;
public:
  Score();
  ~Score();

  void	load_score();
  void	edit_score();

  void	decrypt_data();
  void	load_data();

  void display(); //debug
};

#endif
