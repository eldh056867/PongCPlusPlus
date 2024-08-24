#include "Ball.h" // Include the Ball header file
using namespace sf; // Use the SFML namespace

// Constructor to initialize the ball's position, shape, and initial velocity
Ball::Ball(float startX, float startY)
{
	position.x = startX;   // Set the initial X position
	position.y = startY;   // Set the initial Y position
	ballShape.setRadius(10.0f); // Set the radius of the ball shape
	ballShape.setPosition(position); // Set the initial position of the ball shape
	xVelocity = -100.0f;   // Initial horizontal velocity (moving left)
	yVelocity = 100.0f;    // Initial vertical velocity (moving down)
}

// Returns the current position and size of the ball as a FloatRect (for collision detection)
FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

// Returns the graphical shape of the ball
CircleShape Ball::getBallShape()
{
	return ballShape;
}

// Handles the bounce when the ball hits the left paddle
void Ball::bounceLeftPaddle()
{
	xVelocity = -xVelocity * 1.2; // Reverse and increase the x velocity
	position.x += xVelocity * 0.1f; // Small padding to prevent the ball from sticking to the paddle
}

// Handles the bounce when the ball hits the right paddle
void Ball::bounceRightPaddle()
{
	xVelocity = -xVelocity * 1.2; // Reverse and increase the x velocity
	position.x += xVelocity * 0.01f; // Small padding to prevent the ball from sticking to the paddle
}

// Handles the bounce when the ball hits the top of the window
void Ball::bounceTop()
{
	yVelocity = -yVelocity * 1.2; // Reverse and increase the y velocity
	position.y = 0; // Reset position to top of the screen
}

// Handles the bounce when the ball hits the bottom of the window
void Ball::bounceBottom()
{
	yVelocity = -1 * yVelocity * 1.2; // Reverse and increase the y velocity
	position.y = 800 - ballShape.getRadius() * 2; // Reset position to bottom of the screen
}

// Updates the ball's position based on its velocity and the time elapsed since the last update
void Ball::update(float deltaTime)
{
	position.y += yVelocity * deltaTime; // Update the Y position
	position.x += xVelocity * deltaTime; // Update the X position
	ballShape.setPosition(position); // Update the position of the ball shape
}

// Resets the ball's velocity and serves it in a random direction
void Ball::serve()
{
	xVelocity = 100.0f; // Reset initial horizontal velocity
	yVelocity = 100.0f; // Reset initial vertical velocity

	// Generate random numbers to determine the direction of the serve
	int number1 = rand() % 10 + 1;
	int number2 = rand() % 10 + 1;

	// Reverse x velocity randomly
	if (number1 % 2 == 0)
	{
		xVelocity = xVelocity * -1;
	}

	// Reverse y velocity randomly
	if (number2 % 2 == 0)
	{
		yVelocity = yVelocity * -1;
	}
}

// Resets the ball's position to the center of the screen and stops its movement
void Ball::resetPos()
{
	position.x = (900 / 2) - 10; // Reset X position to center
	position.y = 800 / 2; // Reset Y position to center
	xVelocity = 0.0f; // Stop horizontal movement
	yVelocity = 0.0f; // Stop vertical movement
}
