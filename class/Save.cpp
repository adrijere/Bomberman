//
// Save.cpp for save in /home/hure_s/tek2/rendu/cpp_bomberman/class
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Mon May 18 17:53:28 2015 simon hure
// Last update Wed May 20 19:44:18 2015 simon hure
//

#include "../header/Save.hpp"

Save::Save()
{
  _file_number = 1;
  _counter = 1;
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
      c += 12; //encrypt with +12 rotone
      file << c;
    }
  temp.close();
  std::remove("tmp"); //remove tmp file
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
	  build_tmp(); //write to tmp file

	  //use specific function for parts such as header,maps...
	  //include time reference to each save

	  output_file(path);
	  return ;
	}
    }
}

void	Save::read_file(std::string &path)
{
  std::ifstream in(path.c_str());
  std::ofstream temp("temp");
  char	c;

  while (!in.eof())
    {
      in.get(c);
      c -= 12; //decrypt file with -12 rotone
      temp << c; //add to temporary file
    }
  temp.close();
  in.close();
}

void	Save::store_data() //actually only display on stdout
{
  std::string line;
  std::ifstream temp("temp");

  while (getline(temp, line))
    {
      std::cout << "DATA: " << line << std::endl;
    }
  temp.close();
  std::remove("temp");
}

std::string	Save::read_number()
{
  std::string	path;
  std::stringstream ss;

  ss << _file_number;
  path += "save_";
  path += ss.str();
  path += ".data";
  std::ifstream f(path.c_str());
  if (f.good())
    {
      _file_number++;
      return (path);
    }
  else
    {
      _counter++;
      path = "NULL";
    }
  return (path);
}

void	Save::get_save()
{
  int	k = 0;
  std::string path;

  _file_number = 1;
  while (1)
    {
      if (_counter > 10)
	break; //end loop if no file found 10 times in a row
      if ((path = read_number()) != "NULL") //read file by incresing number
	{
	  _counter = 0;
	  //std::cout << "file number" << _file_number << " k "<< k << std::endl;
	  read_file(path);
	  store_data();   //add element to list of data
	}
      std::cout << "K " << _counter << std::endl;
    }
}

void	Save::score()
{
  //get highscore at begining and store them in list
  //store score and events in file
  //need encryption too
}
