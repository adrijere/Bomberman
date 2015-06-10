//
// Grass.cpp for bomberman in /home/cardon_v/Documents/CPP/cpp_bomberman/class
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Tue Jun  9 15:17:03 2015 Valentin Cardon
// Last update Wed Jun 10 17:18:45 2015 Valentin Cardon
//


#include	"Grass.hpp"

Grass::Grass(int x, int y)
{
  _x = x;
  _y = y;
}

Grass::~Grass()
{}


bool		Grass::initialize()
{
  if (_texture.load("./lib/assets/grass.tga") == false)
    {
      std::cerr << "Cannot load the grass texture" << std::endl;
      return false;
    }
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 0, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0, 0.5));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  translate(glm::vec3(_x, 0, _y));
  _geometry.build();
  return true;
}

void		Grass::update(gdl::Clock const& clock, gdl::Input &input, std::vector<AObject*>&)
{}

void		Grass::draw(gdl::AShader &shader, gdl::Clock const& clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
