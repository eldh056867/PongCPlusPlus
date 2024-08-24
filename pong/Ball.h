#pragma once // Ensures the header file is only included once during compilation

#include <string> // Include string library (not used in this header but may be required elsewhere)
#include <SFML/Graphics.hpp> // Include SFML graphics library

using namespace sf; // Use the SFML namespace for easier access to SFML classes

// Definition of the Ball class
class Ball
{
private:
	CircleShape ballShape; // SFML CircleShape object representing the ball
	Vector2f position;     // Position of the ball (x, y coordinates)
	float xVelocity = 0.2f; // Initial horizontal velocity of the ball
	float yVelocity = 0.2f; // Initial vertical velocity of the ball
	float ballSpeed = 10.0f; // Base speed of the ball (can be adjusted for difficulty)

public:
	// Constructor to initialize the ball with a starting position
	Ball(float startX, float startY);

	// Method to get the current position and size of the ball for collision detection
	FloatRect getPosition();

	// Method to get the graphical shape of the ball for rendering
	CircleShape getBallShape();

	// Method to handle the ball bouncing off the left paddle
	void bounceLeftPaddle();

	// Method to handle the ball bouncing off the right paddle
	void bounceRightPaddle();

	// Method to handle the ball bouncing off the top of the window
	void bounceTop();

	// Method to handle the ball bouncing off the bottom of the window
	void bounceBottom();

	// Method to update the ball's position based on its velocity and the time elapsed
	void update(float deltaTime);

	// Method to serve the ball, setting it in motion in a random direction
	void serve();

	// Method to reset the ball's position to the center of the window
	void resetPos();
};
