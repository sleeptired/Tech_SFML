#include "Particle.h"

Particle::Particle() : mShape(3.f), mIsAlive(false) 
{
}

void Particle::init(sf::Vector2f position, sf::Vector2f velocity, float lifetime) 
{
    mShape.setPosition(position);
    mVelocity = velocity;
    mLifetime = lifetime;
    mIsAlive = true;
    mShape.setFillColor(sf::Color(rand() % 255, rand() % 255, 255));
}

bool Particle::isAlive() const 
{
    return mIsAlive;
}

void Particle::update(sf::Time dt) 
{
    if (!mIsAlive) return;

    mLifetime -= dt.asSeconds();
    if (mLifetime <= 0.f) 
    {
        mIsAlive = false;
        return;
    }

    // 간단한 물리: 이동 및 중력
    mVelocity.y += 100.f * dt.asSeconds(); // 중력
    mShape.move(mVelocity * dt.asSeconds());

    float lifePercent = mLifetime / 2.f; // 수명에 맞춰 조절
    sf::Color color = mShape.getFillColor();
    color.a = static_cast<sf::Uint8>(lifePercent * 255);
    mShape.setFillColor(color);
}

void Particle::render(sf::RenderWindow& window) 
{
    if (mIsAlive) 
    {
        window.draw(mShape);
    }
}