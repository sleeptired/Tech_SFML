#pragma once
#include <SFML/Graphics.hpp>

class Game;

// 씬의 종류추가하는 부분
enum class SceneType {
    MainMenu,
    TestScene 
};

class Scene {
public:

    virtual ~Scene() {}

    virtual void init(Game* game, sf::Font& font) = 0;

    virtual void handleInput(sf::Event event) = 0;

    virtual void update(sf::Time dt) = 0;

    virtual void render(sf::RenderWindow& window) = 0;

protected:
    Game* mGame = nullptr;     // 씬을 교체하기 위한 Game 객체 포인터
    sf::Font* mFont = nullptr; // UI 텍스트를 위한 폰트 포인터
};