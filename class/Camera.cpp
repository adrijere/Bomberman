/*
** Camera.cpp for Camera in /home/mathon_j/rendu/cpp_bomberman/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Jun  9 17:10:58 2015 Jérémy MATHON
// Last update Fri Jun 12 18:57:20 2015 hures
*/

#include	"Camera.hpp"

Camera::Camera(int new_width, gdl::BasicShader &shader)
{
  width = new_width;
  _shader = shader;
  _model = NULL;
}

Camera::~Camera()
{
}

bool	Camera::initialize()
{
  this->x = 0;
  projection = glm::perspective(60.0f, 1280.0f / 720.0f, 0.1f, 100.0f); // on définit ici le frustum
  transformation = glm::lookAt(glm::vec3((width / 2), 4, -10), glm::vec3((width / 2), 0, 0), glm::vec3(0, 1, 0));
  //et ici la position      
  _position = glm::vec3((float)(width / 2), 4.0, -10.0);

  // on doit TOUJOURS binder le shader AVANT d'appeler les methodes setUniform
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);

  this->_speed = 5.0f;
  return (true);
}

void	Camera::update(gdl::Clock const &clock, gdl::Input &input, std::vector<AObject*>&object)
{
  glm::vec3	_poscam;

  if (this->_model == NULL)
    {
      for (int i = 0; i != object.size(); i++)
	{
	  if (dynamic_cast<Model *>(object[i]))
	    this->_model = (Model *)object[i];
	}
    }
  _position =  glm::vec3((float)this->_model->_x, 4, this->_model->_y);
  _poscam = glm::vec3((float)this->_model->_x, 6, this->_model->_y - 10 + this->x);

  if (input.getKey(SDLK_KP_PLUS) && this->x <= 7)
    zoom();
  if (input.getKey(SDLK_KP_MINUS) && this->x >= -7)
    dezoom();
  if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_DOWN))
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_LEFT))
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_RIGHT))
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  transformation = glm::lookAt(_poscam, _position, glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
}

void	Camera::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  (void)shader;
}

void        Camera::zoom(){
  this->x += 0.1;
}

void        Camera::dezoom(){
  this->x -= 0.1;
}
