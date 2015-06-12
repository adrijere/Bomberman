/*
** Cube.cpp for Cube in /home/mathon_j/rendu/cpp_bomberman/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed May  6 15:57:46 2015 Jérémy MATHON
** Last update Fri Jun 12 18:05:59 2015 Jérémy MATHON
*/

#include	"Flame.hpp"

Flame::Flame(int x, int y)
{
  _x = x;
  _y = y;
  _time = 50;
}

Flame::~Flame()
{

}

bool	Flame::initialize()
{
  // On charge la texture qui sera affichee sur chaque face du Cube
  if (_texture.load("./lib/assets/flame.tga") == false)
    {
      std::cerr << "Cannot load the Flame texture" << std::endl;
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
  
  //Face de devant ou de derriere
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 0, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0, -0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //face de droite ou de gauche
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 0, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0, 0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  
  //face de droite ou de gauche
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(-0.5, 0, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0, -0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //face de dessus
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, 0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //face de dessous
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

void Flame::update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*> &object)
{
  int		j;
  int		cpt;

  cpt = 0;
  if (this->_time > 0)
    _time--;
  if (this->_time == 0)
    {
      j = 0;
      std::vector<AObject*>::iterator i = object.begin();
      while (i != object.end())
	{
	  if (dynamic_cast<Flame *>(object[j]))
	    {
	      object.erase(i);
	      j--;
	      cpt++;
	      if (cpt == 4)
		break;
	      continue;
	    }
	  j++;
	  ++i;
	}
    }
}

void Flame::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  // On bind la texture pour dire que l'on veux l'utiliser
  _texture.bind();
  // Et on dessine notre cube
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
