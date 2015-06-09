//
/* Menu.cpp for menu in /home/marsil_g/rendu/cpp_bomberman
// 
// Made by Gabriele Marsili
// Login   <marsil_g@epitech.net>
// 
// Started on  Thu Jun  4 17:05:18 2015 Gabriele Marsili
** Last update Tue Jun  9 16:30:05 2015 Jérémy MATHON
*/

#include        "../header/Menu.hpp"

Menu::Menu() : _players(0), _map("")
{
}

Menu::~Menu() 
{
}

bool	Menu::Check(int ac, char **av)
{
  std::string		player;
  std::string		ret("T\n");
  std::string		name;
  size_t		size;

  if (ac == 1)
    {
      std::cout << std::endl;
      std::cout << " > Nombre de joueurs ? "; 
      std::cin >> player;
      if (!atoi(player.c_str()))
	{
	  std::cout << std::endl;
	  std::cout << "Vous devez rentrer un nombre." << std::endl;
	  std::cout << std::endl;
	  return (false);
	}
      this->_players = atoi(player.c_str());
      std::cout << std::endl;
      while ((ret.compare("R") != 0) || (ret.compare("P") != 0))
	{
	  std::cout << " > Map [R]andom ou Map [P]rédéfinie ? ";
	  std::cin >> ret;
	  std::cout << std::endl;
	  if (ret.compare("R") == 0)
	    {
	      this->_map = "";
	      std::cout << "Map random générée" << std::endl;
	      std::cout << std::endl;
	      break;
	    }
	  else if (ret.compare("P") == 0)
	    {
	      std::cout << "> Nom de la map ? (doit se trouver obligatoirement dans le répertoire map) ";
	      std::cin >> name;
	      std::cout << std::endl;
	      size = name.size();
	      this->_map = name;
	      break;
	    }
	}
    }
  else
    {
      std::cout << "Aucune option gérée" << std::endl;
      return (false);
    }
  return (true);
}
