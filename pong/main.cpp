#include <SFML/Graphics.hpp>
#include "ball.h"
#include "Paddle.h"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>
using namespace sf;

int main()
{
    int height = 800;
    int width = 900;
    int left_side_points = 0;
    int right_side_points = 0;
    SoundBuffer buffer;
    if (!buffer.loadFromFile("pong_sound_effect.mp3"))
    {
        std::cerr << "Error loading sound file!" << std::endl;
        return -1;
    }
    sf::Font font;
    if (!font.loadFromFile("Michelin_Bold.ttf"))
    {
        std::cerr << "Error loading font file!" << std::endl;
        return -1;
    }
    // Set up text for scores
    Text left_side_score_text;
    Text right_side_score_text;

    left_side_score_text.setFont(font);  // Set the font
    right_side_score_text.setFont(font); // Set the font

    left_side_score_text.setString("0");  // Initialize score
    right_side_score_text.setString("0"); // Initialize score

    left_side_score_text.setPosition((width / 6) * 2, height / 8);
    right_side_score_text.setPosition((width / 6) * 4, height / 8);

    left_side_score_text.setCharacterSize(24); // Set text size
    right_side_score_text.setCharacterSize(24); // Set text size

    left_side_score_text.setFillColor(Color::White); // Set text color
    right_side_score_text.setFillColor(Color::White); // Set text color
   


    Sound pong_beep;
    pong_beep.setBuffer(buffer);

    bool round_happening = true;
    Texture background;
    background.loadFromFile("background_image.png");
    Sprite sprite_background(background);
    sprite_background.setScale(1.875, 2.5);
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
            if (left_paddle.getPosition().top >= 0)
            {
                left_paddle.moveUp(deltaTime);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) //S key for left paddle to move down
        {
            if (left_paddle.getPosition().top + left_paddle.getPosition().height <= height)
            {
                left_paddle.moveDown(deltaTime);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) //Up key for right paddle to move up
        {
            if (right_paddle.getPosition().top >= 0)
            {
                right_paddle.moveUp(deltaTime);
            }

        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) //Down key for right paddle to move down
        {
            if (right_paddle.getPosition().top + right_paddle.getPosition().height <= height)
            {
                right_paddle.moveDown(deltaTime);
            }

        }
        if (Keyboard::isKeyPressed(sf::Keyboard::Escape)) //Close application
        {
            window.close();
        }

        if (ball.getPosition().top <= 0)
        {
            ball.bounceTop();
            pong_beep.play();

        }

        if (ball.getPosition().top + ball.getPosition().height >= height)
        {
            ball.bounceBottom();
            pong_beep.play();

        }
        if (ball.getPosition().intersects(left_paddle.getPosition()))
        {
            ball.bounceLeftPaddle();
            pong_beep.play();
        }
        if (ball.getPosition().intersects(right_paddle.getPosition()))
        {
            ball.bounceRightPaddle();
            pong_beep.play();

            
        }
        if (ball.getPosition().left <= 0)
        {
            right_side_points+=1;
            right_side_score_text.setString(std::to_string(right_side_points));
            ball.resetPos();
            window.clear();
            ball.update(1.0f);
            window.draw(sprite_background);
            window.draw(left_side_score_text);
            window.draw(right_side_score_text);
            window.draw(left_paddle.getPaddleShape());
            window.draw(right_paddle.getPaddleShape());
            window.draw(ball.getBallShape());
            window.display();
            sleep(seconds(2));
            deltaTime = deltaTime - 2.0f;
            ball.serve();
            window.clear();
            
        }
        if (ball.getPosition().left + ball.getPosition().width >= width)
        {
            left_side_points+=1;
            left_side_score_text.setString(std::to_string(left_side_points));
            ball.resetPos();
            window.clear();
            ball.update(1.0f);
            window.draw(sprite_background);
            window.draw(left_side_score_text);
            window.draw(right_side_score_text);
            window.draw(left_paddle.getPaddleShape());
            window.draw(right_paddle.getPaddleShape());
            window.draw(ball.getBallShape());
            window.display();
            sleep(seconds(2));
            deltaTime = deltaTime - 2.0f;
            ball.serve();
            window.clear();
        }

        window.clear();
        window.draw(sprite_background);
        window.draw(left_side_score_text);
        window.draw(right_side_score_text);
        window.draw(left_paddle.getPaddleShape());
        window.draw(right_paddle.getPaddleShape());
        window.draw(ball.getBallShape());
        window.display();
        ball.update(deltaTime);
        left_paddle.update();
        right_paddle.update();
        
            
            
            
    }
        
        

    

    return 0;
}