//
// IA.hpp for bomberman in /home/cardon_v/Documents/CPP/cpp_bomberman/class
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Thu May 28 17:01:48 2015 Valentin Cardon
// Last update Wed Jun 10 17:29:53 2015 Valentin Cardon
//

#ifndef		_IA_HPP_
#define		_IA_HPP_

#include	<unistd.h>
#include	<SdlContext.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<Model.hh>
#include	"AObject.hpp"
#include	"Bomb.hpp"
#include	"Block.hpp"

class		IA : public AObject
{
private:
  gdl::Model	 _ia;
  float		 _speed;
  std::list<int> last_moves;
  std::vector<AObject *> &_object;
  
public:
  IA(std::vector<AObject *> &);
  virtual ~IA();
  bool		initialize();
  void		update(gdl::Clock const& clock, gdl::Input &input, std::vector<AObject*>&);
  void		move(gdl::Clock const& clock, int input);
  void		go_back(gdl::Clock const& clock, int input);
  void		draw(gdl::AShader &shader, gdl::Clock const& clock);
};

#endif		/*_IA_HPP_*/
