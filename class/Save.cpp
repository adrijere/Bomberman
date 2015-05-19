//
// Save.cpp for save in /home/hure_s/tek2/rendu/cpp_bomberman/class
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Mon May 18 17:53:28 2015 simon hure
// Last update Tue May 19 17:16:47 2015 simon hure
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

void	Save::output_file(std::string &path)
{
  std::ofstream file(path.c_str());
  std::ifstream temp("tmp");
  char	c;

  while (!temp.eof())
    {
      temp.get(c);
      //encrypt and write to definive file
      //encrypt with +12 rotone
      c += 12;
      file << c;
    }
  temp.close();
  std::remove("tmp");
  file.close();
  return ;
}

void	Save::build_tmp()
{
  std::ofstream tmp("tmp");
  std::time_t	t_time;
  std::stringstream ss;
  
  ss << _file_number;
  t_time = time(NULL);
  tmp << ss.str();
  tmp << std::endl;
  tmp << "DATE: ";
  tmp << std::asctime(std::localtime(&t_time)); //add current time
  tmp << std::endl;
  tmp << "toto" << std::endl;
  tmp.close();
  //add futher information if needed
}

void	Save::save()
{
  std::string path;

  //get file number
  while (1)
    {
      if ((path = file_number()) != "NULL")
	{
	  //check state
	  //write to tmp file
	  build_tmp();

	  //use specific function for parts such as header,maps...
	  //include time reference to each save

	  output_file(path);
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
