// Game.cpp
#include "Game.h"
#include <iostream> 
#include "MainMenu.h"
#include "TestScene.h" 

Game::Game()
    : mWindow(sf::VideoMode(800, 600), "Scene Manager Demo")
{
    if (!mFont.loadFromFile("C:/Windows/Fonts/arial.ttf")) 
    {
        std::cerr << "Error: Font load failed! Check font path." << std::endl;
        mWindow.close();
    }

    changeScene(SceneType::MainMenu);
}

void Game::changeScene(SceneType newSceneType) 
{
    std::unique_ptr<Scene> newScene;

    if (newSceneType == SceneType::MainMenu) 
    {
        newScene = std::make_unique<MainMenu>();
    }
    else if (newSceneType == SceneType::TestScene) 
    {
        newScene = std::make_unique<ParticleTestScene>();
    }

    if (newScene) 
    {
        newScene->init(this, mFont);
        mCurrentScene = std::move(newScene);
    }
}

void Game::run() 
{
    sf::Clock clock;
    while (mWindow.isOpen()) 
    {
        sf::Time dt = clock.restart();
        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() 
{
    sf::Event event;
    while (mWindow.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();

        if (mCurrentScene)
            mCurrentScene->handleInput(event);
    }
}

void Game::update(sf::Time dt) 
{
    if (mCurrentScene)
        mCurrentScene->update(dt);
}

void Game::render() 
{
    mWindow.clear(sf::Color(30, 30, 30)); 
    if (mCurrentScene)
        mCurrentScene->render(mWindow);
    mWindow.display();
}