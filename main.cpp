#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Entity.h"
#include "Player.h"

using namespace std;

int main(int argc, char ** argv)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("shit.png"))
        return EXIT_FAILURE;
    // Create a graphical text to display
    // Load a music to play
    // sf::Music music;
    // if (!music.openFromFile("nice_music.ogg"))
    //     return EXIT_FAILURE;
    // Play the music
    // music.play();
    // Start the game loop
    Player pizza(texture);
    pizza.setWindow(window);
    sf::RectangleShape floor(sf::Vector2f(800, 10));
    floor.setFillColor(sf::Color::Blue);
    floor.setPosition(sf::Vector2f(0, 450));
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        // Clear screen
        window.clear();
        window.draw(floor);
        pizza.update();
        pizza.draw();

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;

}
