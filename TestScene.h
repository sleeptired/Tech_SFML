#pragma once
#include "Scene.h"

class TestScene : public Scene {
public:
    virtual void init(Game* game, sf::Font& font) override;
    virtual void handleInput(sf::Event event) override;
    virtual void update(sf::Time dt) override;
    virtual void render(sf::RenderWindow& window) override;

private:
    sf::Text mTitle;
    sf::Text mInstructions;
};