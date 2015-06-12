/*
** Cube.cpp for Cube in /home/mathon_j/rendu/cpp_bomberman/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed May  6 15:57:46 2015 Jérémy MATHON
// Last update Fri Jun 12 15:58:25 2015 Valentin Cardon
*/

#include	"Cube.hpp"

Cube::Cube(int x, int y)
{
  _x = x;
  _y = y;
}

Cube::~Cube()
{

}

bool	Cube::initialize()
{
  // On charge la texture qui sera affichee sur chaque face du Cube
  if (_texture.load("./lib/assets/images.tga") == false)
    {
      std::cerr << "Cannot load the Cube texture" << std::endl;
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

  //Face de droite ou de gauche
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 0, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0, 0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  
  //Face de droite ou de gauche
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(-0.5, 0, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0, -0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //Face de dessus
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, 0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //Face de dessous
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

void Cube::update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*>&object)
{}

void Cube::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  // On bind la texture pour dire que l'on veux l'utiliser
  _texture.bind();
  // Et on dessine notre cube
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
