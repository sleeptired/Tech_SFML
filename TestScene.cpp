#pragma once
// TestScene.cpp
#include "TestScene.h"
#include "Game.h" // mGame->changeScene()을 호출하기 위해

/*void TestScene::init(Game* game, sf::Font& font) {
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
}*/

// ParticleTestScene.cpp
#include "TestScene.h"
#include "Game.h"
#include <iostream> // 디버깅용

ParticleTestScene::~ParticleTestScene() {
    // 씬이 파괴될 때 (예: 메인 메뉴로 돌아갈 때)
    // 화면에 남아있는 모든 파티클의 메모리를 해제합니다. (메모리 누수 방지)
    std::cout << "ParticleTestScene destroyed. Cleaning up "
        << mActiveParticles.size() << " particles." << std::endl;
    cleanupParticles();
}

void ParticleTestScene::init(Game* game, sf::Font& font) {
    mGame = game;
    mFont = &font;

    mTitle.setFont(*mFont);
    mTitle.setString("Particle Test Scene (Using new/delete)");
    mTitle.setCharacterSize(30);
    mTitle.setPosition(100, 250);

    mInstructions.setFont(*mFont);
    mInstructions.setString("Click screen to spawn particles.\nPress 'M' to go back to Main Menu.");
    mInstructions.setCharacterSize(20);
    mInstructions.setPosition(100, 350);
}

void ParticleTestScene::handleInput(sf::Event event) {
    // 'M' 키를 누르면 메인 메뉴로
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::M) {
            mGame->changeScene(SceneType::MainMenu);
            // (참고: 씬이 바뀌면 ~ParticleTestScene() 소멸자가 호출되어
            // cleanupParticles()가 자동으로 실행됩니다.)
        }
    }
    // 마우스 클릭 시 파티클 생성
    else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            spawnParticles({ (float)event.mouseButton.x, (float)event.mouseButton.y });
        }
    }
}

void ParticleTestScene::spawnParticles(sf::Vector2f position) {
    int particleCount = 100; // 한 번에 100개 생성

    for (int i = 0; i < particleCount; ++i) {
        // 랜덤 속도/수명
        float angle = (rand() % 360) * 3.14159f / 180.f;
        float speed = 100.f + (rand() % 100);
        sf::Vector2f velocity = { std::cos(angle) * speed, std::sin(angle) * speed };
        float lifetime = 1.f + (rand() % 100) / 100.f; // 1~2초 수명

        // **[테스트 핵심 1]**
        // 오브젝트 풀 없이 매번 'new'로 메모리 할당
        Particle* p = new Particle();
        p->init(position, velocity, lifetime);

        mActiveParticles.push_back(p);
    }
}

void ParticleTestScene::update(sf::Time dt) {
    // std::list 순회 중 삭제 (안전한 방식)
    for (auto it = mActiveParticles.begin(); it != mActiveParticles.end(); /* 증감 없음 */) {
        Particle* p = *it;
        p->update(dt); // 파티클 로직 업데이트

        if (!p->isAlive()) {
            // **[테스트 핵심 2]**
            // 파티클이 죽으면 'delete'로 메모리 해제
            delete p;

            // 리스트에서 제거
            it = mActiveParticles.erase(it);
        }
        else {
            // 다음 파티클로 이동
            ++it;
        }
    }
}

void ParticleTestScene::render(sf::RenderWindow& window) {
    // 살아있는 모든 파티클 그리기
    for (Particle* p : mActiveParticles) {
        p->render(window);
    }

    // UI 그리기
    window.draw(mTitle);
    window.draw(mInstructions);
}

// 모든 파티클을 강제로 delete 하는 정리 함수
void ParticleTestScene::cleanupParticles() {
    for (Particle* p : mActiveParticles) {
        delete p;
    }
    mActiveParticles.clear();
}