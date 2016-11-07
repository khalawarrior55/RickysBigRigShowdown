#include <SFML/Graphics.hpp>
#include "Banjo.h"
#include "Entity.h"
#define SPEED 4


Banjo::Banjo() : Entity() {}

Banjo::Banjo(sf::Texture & texture) : Entity(texture)
{
    rect.setSize(sf::Vector2f(50, 50));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(sf::Vector2f(801, 400));
    movementSpeed = SPEED;
}

Banjo::Banjo(sf::Texture & texture, sf::RenderWindow & window) : Entity(texture, window)
{
    rect.setSize(sf::Vector2f(50, 50));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(sf::Vector2f(801, 400));
    movementSpeed = SPEED;
}

float Banjo::getXpos()
{
    return rect.getPosition().x;
}

void Banjo::update()
{
    rect.move(-movementSpeed, 0);
    Entity::draw();
}

void Banjo::update(sf::RenderWindow & window)
{
    rect.move(-movementSpeed, 0);
    Entity::draw(window);
}
