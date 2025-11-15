// Particle.h
#pragma once
#include <SFML/Graphics.hpp>

class Particle {
public:
    Particle();

    // 오브젝트 풀에서 재사용할 때마다 호출될 초기화 함수
    void init(sf::Vector2f position, sf::Vector2f velocity, float lifetime);

    bool isAlive() const;
    void update(sf::Time dt);
    void render(sf::RenderWindow& window);

private:
    sf::CircleShape mShape;
    sf::Vector2f mVelocity;
    float mLifetime; // 수명 (초)
    bool mIsAlive;
};