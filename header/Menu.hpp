/*
// Menu.hpp for menu in /home/marsil_g/rendu/cpp_bomberman
// 
// Made by Gabriele Marsili
// Login   <marsil_g@epitech.net>
// 
// Started on  Thu Jun  4 17:05:27 2015 Gabriele Marsili
** Last update Tue Jun  9 15:43:28 2015 Jérémy MATHON
*/

#ifndef			MENU_HPP_
# define		MENU_HPP_

# include	<iostream>
# include	<string>
# include	<cstdlib>

class		Menu
{
protected:
  int			_players;
  std::string		_map;

public:
  Menu();
  ~Menu();
  bool	Check(int, char **);
};

#endif		/*_MENU_HPP_*/
