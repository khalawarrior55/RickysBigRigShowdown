#ifndef _BANJO_H
#define _BANJO_H
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Banjo : public Entity
{
protected:
    float movementSpeed;
public:
    Banjo();
    Banjo(sf::Texture & texture);
    Banjo(sf::Texture & texture, sf::RenderWindow & window);
    void update();
    void update(sf::RenderWindow & window);
};

#endif
