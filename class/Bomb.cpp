/*
** Bomb.cpp for Bomb in /home/mathon_j/rendu/cpp_bomberman/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed Jun  3 18:00:47 2015 Jérémy MATHON
// Last update Fri Jun 12 13:07:22 2015 Valentin Cardon
*/

#include	"Bomb.hpp"

Bomb::Bomb(int x, int y)
{
  _x = x;
  _y = y;
  _time = 100;
}

Bomb::~Bomb()
{}

bool	Bomb::initialize()
{
  if (_texture.load("./lib/assets/bombe.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
  // on set la color d'une premiere face
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  // tout les pushVertex qui suivent seront de cette couleur
  // On y push les vertices d une premiere face
  _geometry.pushVertex(glm::vec3(0.5, 0, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0, 0.5));
  // Les UVs d'une premiere face
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  // ETC ETC
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 0, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0, -0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 0, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0, 0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(-0.5, 0, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0, -0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, 0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 0, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0, -0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  translate(glm::vec3(_x, 0, _y));
  // Tres important, on n'oublie pas de build la geometrie pour envoyer ses informations a la carte graphique
  _geometry.build();
  return (true);
}

void	Bomb::update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*>&object)
{
  if (this->_time > 0)
    _time--;
  if (this->_time == 0)
    {
      AObject *flame_up = new Flame(_x, (_y + 1));
      AObject *flame_down = new Flame(_x, (_y - 1));
      AObject *flame_left = new Flame((_x + 1), _y);
      AObject *flame_right = new Flame((_x -1), _y);

      for (int i = 0; i != object.size(); i++)
	{
	  if (dynamic_cast<Bomb *>(object[i]))
	    object.erase(object.begin() + i);
	}
      if (flame_up->initialize() == false)
   	return ;
      if (flame_down->initialize() == false)
   	return ;
      if (flame_left->initialize() == false)
   	return ;
      if (flame_right->initialize() == false)
  	return ;
      object.push_back(flame_up);
      object.push_back(flame_down);
      object.push_back(flame_right);
      object.push_back(flame_left);
      //delete le cube ou le perso que la flame touche
    }
}

void	Bomb::draw(gdl::AShader& shader, gdl::Clock const& clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
