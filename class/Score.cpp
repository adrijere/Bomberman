//
// Score.cpp for score in /home/hure_s/tek2/rendu/cpp_bomberman/class
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Thu May 21 10:05:44 2015 simon hure
// Last update Wed May 27 18:20:04 2015 simon hure
//

#include "../header/Score.hpp"

Score::Score()
{
  std::ifstream my_f("highscore.data");

  if (!my_f.good() || my_f.peek() == std::ifstream::traits_type::eof())
    {
      std::remove("highscore.data");
      std::ofstream	file("highscore.data");
      std::ofstream otmp("tmp");
      std::ifstream intmp("tmp");
      char		c;
      int		i = 0;
      
      while (i < 9)
	{
	  otmp << "1000";
	  otmp << " ";
	  otmp << "AAA";
	  otmp << std::endl;
	  i++;
	}
      otmp.close();
      while (!intmp.eof())
	{
	  intmp.get(c);
	  c += 15; //rotone crypt
	  file << c;
	}
      file.close();
      intmp.close();
      std::remove("tmp");
    }
  my_f.close();
}

Score::~Score()
{

}

void	Score::decrypt_data()
{
  std::ifstream file("highscore.data");
  std::ofstream	tmp("s_tmp");
  char	c;

  while (!file.eof())
    {
      file.get(c);
      c -= 15; //crypt with 15 rotone here
      tmp << c;
    }
  file.close();
  tmp.close();
}

void	Score::load_data()
{
  std::ifstream tmp("s_tmp");
  std::string line;
  std::string sub;
  int	i = 1;
  int	pos;
  t_high temp;

  while (getline(tmp, line))
    {
      temp.position = i;
      pos = line.find(" ");
      sub = line.substr(0, pos);
      temp.score = sub;
      if (sub.empty())
	continue;
      sub.clear();
      sub = line.substr(pos + 1, line.find_last_of(" "));
      temp.name = sub;
      temp.date = "01/01/70"; //date maybe in file too
      i++;
      _all.push_back(temp);
    }
  tmp.close();
  std::remove("s_tmp");
}

void	Score::load_score()
{
  std::ifstream file("highscore.data");

  if (!file.good() || file.peek() == std::ifstream::traits_type::eof())
    {
      std::cerr << "Error can't load highscore !" << std::endl;
      return ;
    }
  decrypt_data();
  load_data();
}

void	Score::display() //debug function
{
  for (std::list<t_high>::iterator it = _all.begin(); it != _all.end(); ++it)
    {
      std::cout << it->position << " " << it->score << " \t" << it->name << " " << it->date << std::endl;
    }
}

void	Score::edit_score_file()
{
  std::remove("highscore.data");
  std::ofstream	file("highscore.data");
  std::ofstream otmp("tmp");
  std::ifstream intmp("tmp");
  char		c;
  int		i = 0;

  for (std::list<t_high>::iterator it = _all.begin(); it != _all.end(); ++it)
    {
      otmp << it->score;
      otmp << " ";
      otmp << it->name;
      otmp << std::endl;
      if (i > 9)
	break;
      ++i;
    }
  otmp.close();
  while (!intmp.eof())
    {
      intmp.get(c);
      c += 15; //rotone crypt
      file << c;
    }
  file.close();
  intmp.close();
  std::remove("tmp");
}

void	Score::append_in_list(int add_score, std::list<t_high>::iterator &it)
{
  std::stringstream as;
  std::string new_score;
  std::string name;
  t_high temp;

  as << add_score;
  new_score = as.str();
  name = "LOL";
  temp.position = it->position; //copy position
  temp.date = it->date;
  temp.score = new_score;
  temp.name = name; 
  _all.pop_back();
  _all.insert(it, temp);
}

void	Score::edit_score_list()
{
  int add_score = 99999; //example of score to add
  int compar;

  for (std::list<t_high>::iterator it = _all.begin(); it != _all.end(); ++it)
    {
      std::istringstream ss(it->score);
      ss >> compar;
      if (add_score >= compar)
	{
	  append_in_list(add_score, it);
	  return;
	}
    }
}
