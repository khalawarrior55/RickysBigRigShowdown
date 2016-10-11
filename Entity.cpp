#include <SFML/Graphics.hpp>
#include "Entity.h"

Entity::Entity(){}

Entity::Entity(sf::Texture & texture){
    sprite.setTexture(texture);
}

Entity::Entity(sf::Texture & texture, sf::RenderWindow & window){
    sprite.setTexture(texture);
    this->window = &window;
}

void Entity::draw(){
    window->draw(rect);
}

void Entity::draw(sf::RenderWindow & window){
    window.draw(rect);
}

sf::Vector2f Entity::getPosition(){
   return sprite.getPosition(); 
}

void Entity::setPosition(const float & x, const float & y){
    sprite.setPosition(x, y);
}

void Entity::setPosition(const sf::Vector2f & pos){
    sprite.setPosition(pos);
}

void Entity::setWindow(sf::RenderWindow & window){
    this->window = &window;
}
