#pragma once
#include "Scene.h"
/*
class TestScene : public Scene {
public:
    virtual void init(Game* game, sf::Font& font) override;
    virtual void handleInput(sf::Event event) override;
    virtual void update(sf::Time dt) override;
    virtual void render(sf::RenderWindow& window) override;

private:
    sf::Text mTitle;
    sf::Text mInstructions;
};*/

// ParticleTestScene.h
#pragma once
#include "Scene.h"
#include "Particle.h"
#include <list> // ** new/delete로 관리할 활성 파티클 리스트 **

class ParticleTestScene : public Scene {
public:
    // ** 중요: 씬이 파괴될 때 모든 파티클을 delete 하기 위한 소멸자
    virtual ~ParticleTestScene();

    virtual void init(Game* game, sf::Font& font) override;
    virtual void handleInput(sf::Event event) override;
    virtual void update(sf::Time dt) override;
    virtual void render(sf::RenderWindow& window) override;

private:
    void spawnParticles(sf::Vector2f position);
    void cleanupParticles(); // 메모리 정리를 위한 함수

    // 이 씬이 new로 생성한 모든 파티클을 관리
    std::list<Particle*> mActiveParticles;

    sf::Text mTitle;
    sf::Text mInstructions;
};