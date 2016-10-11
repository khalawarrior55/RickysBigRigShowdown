#ifndef _ENTITY_H
#define _ENTITY_H
#include <SFML/Graphics.hpp>

class Entity
{
protected:
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;
    sf::RenderWindow * window; 
public:
    Entity();
    Entity(sf::Texture & texture);
    Entity(sf::Texture & texture, sf::RenderWindow & window);
    void draw();
    void draw(sf::RenderWindow & window);
    sf::Vector2f getPosition();
    void setPosition(const float & x, const float & y);
    void setPosition(const sf::Vector2f & pos);
    void setWindow(sf::RenderWindow & window);


};

#endif
