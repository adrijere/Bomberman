//
// Menu.hpp for menu in /home/marsil_g/rendu/cpp_bomberman
// 
// Made by Gabriele Marsili
// Login   <marsil_g@epitech.net>
// 
// Started on  Thu Jun  4 17:05:27 2015 Gabriele Marsili
// Last update Thu Jun  4 17:05:29 2015 Gabriele Marsili
//

#ifndef		    MENU_HPP_
# define		MENU_HPP_

#include	<unistd.h>
#include	<SdlContext.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<Model.hh>
#include	<Texture.hh>
#include	<Geometry.hh>
#include	"AObject.hpp"

class		MyMenu : public AObject
{
private:
    gdl::Texture        _texture;
    gdl::Geometry       _geometry;
    gdl::Model          _Menu;
    float		_speed;

public:
    MyMenu();
    virtual       ~MyMenu();

    bool		initialize();
    void		update(gdl::Clock const& clock, gdl::Input &input);
    void		draw(gdl::AShader &shader, gdl::Clock const& clock);
};

#endif		/*_MENU_HPP_*/
