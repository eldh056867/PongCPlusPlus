#include <SFML/Graphics.hpp>
#include "ball.h"
#include "Paddle.h"
using namespace sf;
int main()
{
    int height = 800;
    int width = 900;
    Ball ball(width / 2, height / 2);
    Paddle left_paddle((width / 6) * 1, height / 2, "left");
    Paddle right_paddle((width / 6) * 5, height / 2, "right");

    // create the window
    sf::RenderWindow window(sf::VideoMode(width, height), "Pong in C++ by Eldho Rajan");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        static Clock clock;
        float deltaTime = clock.restart().asSeconds();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::W)) //W Key for left paddle to move up
        {
            
            left_paddle.moveUp(deltaTime);
        }
        else if (Keyboard::isKeyPressed(Keyboard::S)) //S key for left paddle to move down
        {
            
            left_paddle.moveDown(deltaTime);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up)) //Up key for right paddle to move up
        {
            
            right_paddle.moveUp(deltaTime);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down)) //Down key for right paddle to move down
        {
            
            right_paddle.moveDown(deltaTime);
        }
        else if (Keyboard::isKeyPressed(sf::Keyboard::Escape)) //Close application
        {
            window.close();
        }

        
    }

    return 0;
}