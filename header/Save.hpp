//
// Save.hpp for save in /home/hure_s/tek2/rendu/cpp_bomberman/header
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Mon May 18 18:04:53 2015 simon hure
// Last update Wed May 20 11:32:14 2015 simon hure
//

#ifndef _SAVE_HH_
#define _SAVE_HH_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <list>
#include <iomanip>

class	Save
{
private:
  int	_file_number;
  int	_counter;
public:
  Save();
  ~Save();

  void	save();
  void	get_save();
  void	score();

  std::string file_number();
  std::string read_number();
  void	output_file(std::string &);
  void	read_file(std::string &);
  void	store_data();
  void	build_tmp();
};

#endif
