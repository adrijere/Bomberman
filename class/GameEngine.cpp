/*
** GameEngine.cpp for GameEngine in /home/mathon_j/rendu/cpp_bomberman/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed May  6 15:34:08 2015 Jérémy MATHON
** Last update Fri May 15 17:25:03 2015 Jérémy MATHON
*/

#include	"GameEngine.hpp"

GameEngine::GameEngine()
{}

bool	GameEngine::initialize()
{
  if (!_context.start(1280, 720, "Bomberman 0.0.1")) // on cree une fenetre
    return false;
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./lib/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./lib/shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build()) // on charge ici la libraire pour les shaders
    return false;
  glm::mat4 projection;
  glm::mat4 transformation;
  projection = glm::perspective(60.0f, 1280.0f / 720.0f, 0.1f, 100.0f); // on définit ici le frustum
  transformation = glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // et ici la position
  // on doit TOUJOURS binder le shader AVANT d'appeler les methodes setUniform
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
 // on creer un cube qu'on ajoute a la suite de la liste d'objets
  AObject *model = new Model();
  if (model->initialize() == false)
    return (false);
  _objects.push_back(model);
  return true;
}

bool	GameEngine::update()
{
  // Si la touche ECHAP est appuyee ou si l'utilisateur ferme la fenetre, on quitte les programmes
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  // Mise a jour des inputs et de l'horloge de jeu
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  // Mise a jour des differents objets
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);
  return true;
}


void	GameEngine::draw()
{
  // On clear l'ecran
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // pour utiliser un shader (pour que ce soit ce dernier qui dessine la geometrie) il faut les binder.
  // Un seul shader peut etre actif en meme temps
  _shader.bind();// On dessine tous les objets composant la scene
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  // On met ensuite a jour l'ecran pour que ce que l'on a dessine s'affiche
  _context.flush();
}

GameEngine::~GameEngine()
{
  // N'oublions pas de supprimer les objets une fois le programme termine!
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];
}