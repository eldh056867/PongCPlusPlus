#include "Game.h"
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "Paddle.h"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>

// Main function for the game
void Game::main()
{
    // Load sound effect for the game
    if (!buffer.loadFromFile("pong_sound_effect.mp3"))
    {
        std::cerr << "Error loading sound file!" << std::endl;
        return;
    }

    // Load font for displaying scores
    sf::Font font;
    if (!font.loadFromFile("Michelin_Bold.ttf"))
    {
        std::cerr << "Error loading font file!" << std::endl;
        return;
    }

    // Set up text for scores
    left_side_score_text.setFont(font);  // Set the font for left side score
    right_side_score_text.setFont(font); // Set the font for right side score

    left_side_score_text.setString("0");  // Initialize left side score to 0
    right_side_score_text.setString("0"); // Initialize right side score to 0

    left_side_score_text.setPosition((width / 6) * 2, height / 8);  // Position for left score
    right_side_score_text.setPosition((width / 6) * 4, height / 8); // Position for right score

    left_side_score_text.setCharacterSize(24); // Set text size for left score
    right_side_score_text.setCharacterSize(24); // Set text size for right score

    left_side_score_text.setFillColor(Color::White); // Set text color for left score
    right_side_score_text.setFillColor(Color::White); // Set text color for right score

    // Set the sound buffer for the pong beep sound
    pong_beep.setBuffer(buffer);

    // Load the background image
    background.loadFromFile("background_image.png");
    Sprite sprite_background(background); // Create a sprite for the background
    sprite_background.setScale(1.875, 2.5); // Scale the background to fit the window

    // Initialize the ball and paddles with their positions
    Ball ball(width / 2, height / 2);
    Paddle left_paddle((width / 6) * 1, height / 2, "left");
    Paddle right_paddle((width / 6) * 5, height / 2, "right");

    // Create the game window with specified width and height
    sf::RenderWindow window(sf::VideoMode(width, height), "Pong in C++ by Eldho Rajan");

    // Main game loop - runs as long as the window is open
    while (window.isOpen())
    {
        static Clock clock; // Create a clock to track delta time
        float deltaTime = clock.restart().asSeconds(); // Calculate delta time (time since last frame)

        // Handle window events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window event
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle left paddle movement (W and S keys)
        if (Keyboard::isKeyPressed(Keyboard::W)) // W key for left paddle to move up
        {
            if (left_paddle.getPosition().top >= 0)
            {
                left_paddle.moveUp(deltaTime);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) // S key for left paddle to move down
        {
            if (left_paddle.getPosition().top + left_paddle.getPosition().height <= height)
            {
                left_paddle.moveDown(deltaTime);
            }
        }

        // Handle right paddle movement (Up and Down arrow keys)
        if (Keyboard::isKeyPressed(Keyboard::Up)) // Up arrow key for right paddle to move up
        {
            if (right_paddle.getPosition().top >= 0)
            {
                right_paddle.moveUp(deltaTime);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) // Down arrow key for right paddle to move down
        {
            if (right_paddle.getPosition().top + right_paddle.getPosition().height <= height)
            {
                right_paddle.moveDown(deltaTime);
            }
        }

        // Handle escape key to close the application
        if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        // Handle ball collision with top of the window
        if (ball.getPosition().top <= 0)
        {
            ball.bounceTop(); // Bounce the ball off the top
            pong_beep.play(); // Play sound
        }

        // Handle ball collision with bottom of the window
        if (ball.getPosition().top + ball.getPosition().height >= height)
        {
            ball.bounceBottom(); // Bounce the ball off the bottom
            pong_beep.play(); // Play sound
        }

        // Handle ball collision with the left paddle
        if (ball.getPosition().intersects(left_paddle.getPosition()))
        {
            ball.bounceLeftPaddle(); // Bounce the ball off the left paddle
            pong_beep.play(); // Play sound
        }

        // Handle ball collision with the right paddle
        if (ball.getPosition().intersects(right_paddle.getPosition()))
        {
            ball.bounceRightPaddle(); // Bounce the ball off the right paddle
            pong_beep.play(); // Play sound
        }

        // Handle ball going out on the left side (point for right player)
        if (ball.getPosition().left <= 0)
        {
            right_side_points += 1; // Increment right side points
            right_side_score_text.setString(std::to_string(right_side_points)); // Update right side score
            ball.resetPos(); // Reset the ball position
            window.clear(); // Clear the window

            // Update the game state and redraw the scene
            ball.update(1.0f);
            window.draw(sprite_background);
            window.draw(left_side_score_text);
            window.draw(right_side_score_text);
            window.draw(left_paddle.getPaddleShape());
            window.draw(right_paddle.getPaddleShape());
            window.draw(ball.getBallShape());
            window.display();

            sleep(seconds(2)); // Pause for 2 seconds before next serve
            deltaTime = deltaTime - 2.0f; // Adjust delta time
            ball.serve(); // Serve the ball again
            window.clear(); // Clear the window
        }

        // Handle ball going out on the right side (point for left player)
        if (ball.getPosition().left + ball.getPosition().width >= width)
        {
            left_side_points += 1; // Increment left side points
            left_side_score_text.setString(std::to_string(left_side_points)); // Update left side score
            ball.resetPos(); // Reset the ball position
            window.clear(); // Clear the window

            // Update the game state and redraw the scene
            ball.update(1.0f);
            window.draw(sprite_background);
            window.draw(left_side_score_text);
            window.draw(right_side_score_text);
            window.draw(left_paddle.getPaddleShape());
            window.draw(right_paddle.getPaddleShape());
            window.draw(ball.getBallShape());
            window.display();

            sleep(seconds(2)); // Pause for 2 seconds before next serve
            deltaTime = deltaTime - 2.0f; // Adjust delta time
            ball.serve(); // Serve the ball again
            window.clear(); // Clear the window
        }

        // Update game objects and render the scene
        window.clear();
        window.draw(sprite_background);
        window.draw(left_side_score_text);
        window.draw(right_side_score_text);
        window.draw(left_paddle.getPaddleShape());
        window.draw(right_paddle.getPaddleShape());
        window.draw(ball.getBallShape());
        window.display();

        ball.update(deltaTime); // Update the ball position based on delta time
        left_paddle.update(); // Update the left paddle
        right_paddle.update(); // Update the right paddle
    }
}
