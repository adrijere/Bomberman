//
// Created by marsil_g on 19/05/15.
//

#include        "../header/GameEngine.hpp"

bool	GameEngine::Menu(){
/*    if (!_context.start(1280, 720, "Bomberman 0.0.1")) // on cree une fenetre
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
    return true;*/
}
