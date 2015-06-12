/*
** Cube.cpp for Cube in /home/mathon_j/rendu/cpp_bomberman/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed May  6 15:57:46 2015 Jérémy MATHON
// Last update Fri Jun 12 15:57:49 2015 Valentin Cardon
*/

#include	"Block.hpp"

Block::Block(int x, int y)
{
  _x = x;
  _y = y;
}

Block::~Block()
{

}

bool	Block::initialize()
{
    
  _speed = 10.0f;
  // On charge la texture qui sera affichee sur chaque face du Cube
  if (_texture.load("./lib/assets/block.tga") == false)
    {
      std::cerr << "Cannot load the Block texture" << std::endl;
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

  
  //Face de devant/derriere
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 0, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0, -0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //face droite/gauche
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 0, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0, 0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  
  //face droite/gauche
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(-0.5, 0, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0, -0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //face dessus/dessous
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 1, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 1, 0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //face dessous/dessus
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

void Block::update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*>& object)
{}

void Block::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  // On bind la texture pour dire que l'on veux l'utiliser
  _texture.bind();
  // Et on dessine notre cube
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
