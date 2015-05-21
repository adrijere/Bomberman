//
// Score.cpp for score in /home/hure_s/tek2/rendu/cpp_bomberman/class
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Thu May 21 10:05:44 2015 simon hure
// Last update Thu May 21 12:25:30 2015 simon hure
//

#include "../header/Score.hpp"

Score::Score()
{

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
      //c -= 15; //crypt with 15 rotone here
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
      sub.clear();
      sub = line.substr(pos + 1, line.find_last_of(" "));
      temp.name = sub;
      temp.date =  "01/01/70";
      i++;
      _all.push_back(temp);
    }
  tmp.close();
  std::remove("s_tmp");
}

void	Score::load_score()
{
  std::ifstream file("highscore.data");

  if (!file.good())
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
      std::cout << it->position << " " << it->score << " " << it->name << " " << it->date << std::endl;
    }
}

void	Score::edit_score()
{
  std::ofstream	file("highscore.data");
}
