#ifndef _BANJO_H
#define _BANJO_H
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Banjo : public Entity
{
protected:
    float movementSpeed;
    float xPos;
public:
    Banjo();
    Banjo(sf::Texture & texture);
    Banjo(sf::Texture & texture, sf::RenderWindow & window);
    float getXpos();
    void update();
    void update(sf::RenderWindow & window);
};

#endif
