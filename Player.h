#ifndef _PLAYER_H
#define _PLAYER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity
{
protected:
    bool onGround;
    float movementSpeed;
    float yAccel;
    float xCord;
    float yCord;
public:
    Player();
    Player(sf::Texture & texture);
    Player(sf::Texture & texture, sf::RenderWindow & window);
    void controls();
    void updatePos();
    void jump();
    void update();
};

#endif
