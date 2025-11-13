#include "MainMenu.h"
#include "Game.h" 

void MainMenu::init(Game* game, sf::Font& font) {
    mGame = game;
    mFont = &font;


    mTestButton.setSize({ 300, 80 });
    mTestButton.setPosition(250, 260); 
    mTestButton.setFillColor(sf::Color(70, 70, 70));

    mTestText.setFont(*mFont);
    mTestText.setString("Go to Test Scene");
    mTestText.setCharacterSize(24);

    sf::FloatRect textBounds = mTestText.getLocalBounds();
    mTestText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    mTestText.setPosition(250 + 300 / 2.0f, 260 + 80 / 2.0f);
}

void MainMenu::handleInput(sf::Event event) 
{
    if (event.type == sf::Event::MouseButtonPressed) 
    {
        if (event.mouseButton.button == sf::Mouse::Left) 
        {
            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

            
            if (mTestButton.getGlobalBounds().contains(mousePos)) 
            {
                mGame->changeScene(SceneType::TestScene);
            }
        }
    }
}

void MainMenu::update(sf::Time dt) 
{
}

void MainMenu::render(sf::RenderWindow& window) 
{
    window.draw(mTestButton);
    window.draw(mTestText);
}