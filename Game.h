#pragma once
#include "Scene.h"
#include <memory> 

class Game {
public:
    Game();
    void run(); 


    void changeScene(SceneType newSceneType);

private:
    void processEvents();
    void update(sf::Time dt);
    void render();

    sf::RenderWindow mWindow;
    std::unique_ptr<Scene> mCurrentScene; 

    sf::Font mFont; 
};