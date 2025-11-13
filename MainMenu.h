#pragma once
#include "Scene.h"

class MainMenu : public Scene {
public:
    virtual void init(Game* game, sf::Font& font) override;
    virtual void handleInput(sf::Event event) override;
    virtual void update(sf::Time dt) override;
    virtual void render(sf::RenderWindow& window) override;

private:
    // 간단한 버튼 UI
    sf::RectangleShape mTestButton;
    sf::Text mTestText;
};