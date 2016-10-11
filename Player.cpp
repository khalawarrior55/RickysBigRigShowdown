#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(sf::Texture & texture) : Entity(texture){
    rect.setSize(sf::Vector2f(50, 50));
    rect.setFillColor(sf::Color::Green);
    onGround = true;
    movementSpeed = 1;
    yAccel = 0;
    xCord = 400;
    yCord = 400;
    rect.setPosition(sf::Vector2f(400, 400));
}

Player::Player(sf::Texture & texture, sf::RenderWindow & window) : Entity(texture, window){
    rect.setSize(sf::Vector2f(50, 50));
    rect.setFillColor(sf::Color::Green);
    onGround = true;
    movementSpeed = 1;
    yAccel = 0;       
    xCord = 400;
    yCord = 400;
    rect.setPosition(sf::Vector2f(400, 400));
}

void Player::controls(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && yCord == 400){
        yAccel = .01;
        onGround = false;
    }
}

void Player::updatePos(){
    sf::Vector2f pos(rect.getPosition());
    xCord = pos.x;
    yCord = pos.y;
}   

void Player::jump(){
    updatePos();
    if (!onGround){
        rect.move(0, -yAccel);
        yAccel -= .00001;
        if (yCord > 400.0){
            onGround = true;
            rect.setPosition(400, 400);
        }
    }
}

void Player::update(){
    updatePos();
    controls();
    jump();
    sprite.setPosition(rect.getPosition());
    cout << yCord << endl;
    
}
