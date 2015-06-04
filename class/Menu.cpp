//
// Menu.cpp for menu in /home/marsil_g/rendu/cpp_bomberman
// 
// Made by Gabriele Marsili
// Login   <marsil_g@epitech.net>
// 
// Started on  Thu Jun  4 17:05:18 2015 Gabriele Marsili
// Last update Thu Jun  4 17:05:18 2015 Gabriele Marsili
//

#include        "../header/Menu.hpp"

MyMenu::MyMenu() {
}

MyMenu::~MyMenu() {
}
bool	MyMenu::initialize(){
    
  _speed = 10.0f;

  std::string   imgMenu;

  imgMenu = "./img/menu.tga";
  if (_texture.load(imgMenu) == false)
    {
      std::cerr << "Cannot load the texture " << imgMenu << " needed for the menu."<< std::endl;
      return (false);
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
  return (true);
}

void MyMenu::update(gdl::Clock const &clock, gdl::Input &input)
{

  if (input.getKey(SDLK_DOWN))
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_RIGHT))
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_LEFT))
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
}

void MyMenu::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  
  _texture.bind();
  
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
