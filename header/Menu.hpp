/*
// Menu.hpp for menu in /home/marsil_g/rendu/cpp_bomberman
// 
// Made by Gabriele Marsili
// Login   <marsil_g@epitech.net>
// 
// Started on  Thu Jun  4 17:05:27 2015 Gabriele Marsili
** Last update Tue Jun  9 16:29:13 2015 Jérémy MATHON
*/

#ifndef			MENU_HPP_
# define		MENU_HPP_

#include	<unistd.h>
#include	<SdlContext.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<Model.hh>
#include	<Texture.hh>
#include	<Geometry.hh>
#include	"AObject.hpp"
# include	<iostream>
# include	<string>
# include	<cstdlib>

class		MyMenu : public AObject
{
  gdl::Texture        _texture;
  gdl::Geometry       _geometry;
  gdl::Model          _Menu;
  float		          _speed;
  int                 _img;

public:
  int			_players;
  std::string		_map;
  MyMenu();
  ~MyMenu();
  bool	Check(int, char **);

  bool		initialize();
  void		update(gdl::Clock const& clock, gdl::Input &input);
  void		draw(gdl::AShader &shader, gdl::Clock const& clock);
};

#endif		/*_MENU_HPP_*/
