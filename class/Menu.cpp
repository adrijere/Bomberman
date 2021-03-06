//
/* Menu.cpp for menu in /home/marsil_g/rendu/cpp_bomberman
//
// Made by Gabriele Marsili
// Login   <marsil_g@epitech.net>
//
// Started on  Thu Jun  4 17:05:18 2015 Gabriele Marsili
// Last update Sat Jun 13 13:03:48 2015 Gabriele Marsili
*/

#include        <sstream>
#include        "../header/Menu.hpp"
#include "../lib/includes/Input.hh"
#include "../lib/includes/glm/core/type.hpp"

MyMenu::MyMenu() : _players(0), _map("")
{
	this->_img = 1;
	this->_lvMenu = 0;
}

MyMenu::~MyMenu()
{
}

bool	MyMenu::Check(int ac, char **av)
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


bool	MyMenu::initialize(){

  _speed = 10.0f;

  std::string   imgMenu;

  imgMenu = "./img/menu";
  imgMenu += "1";
  imgMenu += ".tga";

  BuildImg(imgMenu);
  return (true);
}

void MyMenu::update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*>& object)
{
  std::string   imgMenu;

  if (input.getKey(SDLK_DOWN) && this->_lvMenu == 0) {

    int i = 0;
    while (++i != 17500000);

    this->_img += 1;

    if (_img == 6)
      _img = 1;
    std::stringstream s;
    s << _img;
    std::string converted(s.str());

    imgMenu = "./img/menu";
    imgMenu += converted;
    imgMenu += ".tga";

    BuildImg(imgMenu);

  }

  if (input.getKey(SDLK_UP) && this->_lvMenu == 0){
    int i = 0;
    while (++i != 17500000);

    _img -= 1;

    if (_img == 0)
      _img = 5;

    std::stringstream s;

    s << _img;

    std::string converted(s.str());

    imgMenu = "./img/menu";
    imgMenu += converted;
    imgMenu += ".tga";

    BuildImg(imgMenu);
  }

  if (input.getKey(SDLK_RETURN) && this->_lvMenu == 0) {
    if (this->_img == 5)
      exit(EXIT_SUCCESS);

    if (this->_img == 1){
      this->_players = 1;
      this->_ddd = true;
    }

    if (this->_img == 2){
      this->_players = 2;
      this->_ddd = false;
    }
    this->_lvMenu = 1;
  }
}

bool		MyMenu::getDdd(){
  return (this->_ddd);
}

void MyMenu::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

void		MyMenu::BuildImg(std::string imgMenu){

  if (_texture.load(imgMenu) == false)
    {
      std::cerr << "Cannot load the texture " << imgMenu << " needed for the menu."<< std::endl;
      exit (0);
    }

  _geometry.pushVertex(glm::vec3(0.5, -0.9, 9.15));
  _geometry.pushVertex(glm::vec3(0.5, 0.9, 9.15));
  _geometry.pushVertex(glm::vec3(-0.5, 0.9, 9.15));
  _geometry.pushVertex(glm::vec3(-0.5, -0.9, 9.15));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.build();
}
