//
// Save.cpp for save in /home/hure_s/tek2/rendu/cpp_bomberman/class
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Mon May 18 17:53:28 2015 simon hure
// Last update Mon May 18 18:22:51 2015 simon hure
//

#include "../header/Save.hpp"

Save::Save()
{
  _file_number = 1;
  _counter = 0;
  //init state and file counter to 1
}

Save::~Save()
{
  //check for tmp file that should be deleted
}

std::string	Save::file_number()
{
  std::string	path;
  std::stringstream ss;

  ss << _file_number;
  path += "save_";
  path += ss.str();
  path += ".data";
  std::ifstream f(path.c_str());
  if (!f.good())
      return (path);
  else
    {
      _file_number++;
      path = "NULL";
    }
  return (path);
}

void	Save::save()
{
  std::string path;

  //check state
  //write to tmp file
  //use specific function for parts such as header,maps...
  //include time reference to each save

  //get file number
  while (1)
    {
      if ((path = file_number()) != "NULL")
	{
	  std::ofstream file(path.c_str());
	  //encrypt and write to definive file
	  //encrypt with +12 rotone
	  file << "hello world !\n";
	  file.close();
	  return ;
	}
    }
}

void	Save::get_save()
{
  //read file by incresing number
  //if found write and decrypt data to tmp
  //decrypt with -12 rotone
  //add element to list of data
  //class by time (if possible)
  //delete tmp file after use
  //else search for next file if 5 time in a row no valid file exits
}

void	Save::score()
{
  //get highscore at begining and store them in list
  //store score and events in file
  //need encryption too
}
