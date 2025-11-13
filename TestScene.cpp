#pragma once
// TestScene.cpp
#include "TestScene.h"
#include "Game.h" // mGame->changeScene()을 호출하기 위해

void TestScene::init(Game* game, sf::Font& font) {
    mGame = game;
    mFont = &font;


    mTitle.setFont(*mFont);
    mTitle.setString("Test Scene");
    mTitle.setCharacterSize(40);
    mTitle.setPosition(280, 250);

    // 메인 메뉴
    mInstructions.setFont(*mFont);
    mInstructions.setString("Press 'M' to go back to Main Menu");
    mInstructions.setCharacterSize(20);
    mInstructions.setPosition(220, 350);
}

void TestScene::handleInput(sf::Event event) 
{
    // M키 누르면 메인 메뉴 (테스트)
    if (event.type == sf::Event::KeyPressed) 
    {
        if (event.key.code == sf::Keyboard::M) 
        {
            mGame->changeScene(SceneType::MainMenu);
        }
    }
}

void TestScene::update(sf::Time dt) 
{
}

void TestScene::render(sf::RenderWindow& window) 
{
    window.draw(mTitle);
    window.draw(mInstructions);
}