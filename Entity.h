#ifndef _ENTITY_H
#define _ENTITY_H
#include <SFML/Graphics.hpp>

class Entity()
{
protected:
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;
    sf::Window * window; 
public:
    Entity(sf::Window & window);
    void draw();
    void getPosition();


}

#endif
