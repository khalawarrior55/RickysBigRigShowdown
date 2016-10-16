#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Banjo.h"

using namespace std;

int main(int argc, char ** argv)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setFramerateLimit(60);

    // Create a clock for the framerate
    sf::Clock clockFPS;

    // Clock for banjo separation
    sf::Clock banjoClock;
    sf::Time banjoTime;
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("shit.png"))
        return EXIT_FAILURE;

    // Load the arial Font
    sf::Font arial;
    if (!arial.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;

    sf::Text fps;
    fps.setFont(arial);
    fps.setColor(sf::Color::White);

    // Creates the pizza texture
    Player pizza(texture);
    pizza.setWindow(window);

    // Creates a floor on screen
    sf::RectangleShape floor(sf::Vector2f(800, 10));
    floor.setFillColor(sf::Color::Blue);
    floor.setPosition(sf::Vector2f(0, 450));

    vector<Banjo> banjoVect;
    vector<Banjo>::iterator it;
    Banjo banjo(texture, window);

    int counter = 0;

    // Begin Game loop
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

        banjoTime = banjoClock.getElapsedTime();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && banjoTime.asSeconds() > 1)
        {
            Banjo * b = new Banjo(texture, window);
            banjoVect.push_back(*b);
            delete b;
            banjoClock.restart();
        }

        // Clear screen
        window.clear();

        // Draw Stuff
        window.draw(floor);
        pizza.update();
        pizza.draw();
        for( it = banjoVect.begin(); it != banjoVect.end(); ++it)
        {
            it->update();
        }

        // Calculate Framerate
        sf::Time frTime = clockFPS.getElapsedTime();
        int fpsFloat = 1.0f / frTime.asSeconds();
        string fpsString = "FPS: " + std::to_string(fpsFloat);
        fps.setString(fpsString);

        window.draw(fps);
        
        clockFPS.restart().asSeconds();
        //std::cout << banjoVect.size() << std::endl;

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;

}
