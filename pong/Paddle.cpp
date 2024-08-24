#include "Paddle.h"
using namespace sf;

// Constructor for the Paddle class
Paddle::Paddle(float startX, float startY, String paddle_type)
{
    // Set the initial position of the paddle
    position.x = startX;
    position.y = startY;

    // Set the type of paddle (left or right)
    paddleType = paddle_type;

    // Set the size of the paddle
    paddleShape.setSize(Vector2f(5, 50));

    // Position the paddle at the specified start position
    paddleShape.setPosition(position);

    // Set the movement speed of the paddle
    paddleSpeed = 400.0f;
}

// Method to get the position and size of the paddle as a FloatRect
FloatRect Paddle::getPosition()
{
    // Returns the bounding box of the paddle for collision detection
    return paddleShape.getGlobalBounds();
}

// Method to return the graphical representation of the paddle
RectangleShape Paddle::getPaddleShape()
{
    // Returns the shape of the paddle for rendering
    return paddleShape;
}

// Method to move the paddle up
void Paddle::moveUp(float deltaTime)
{
    // Decrease the y-coordinate based on speed and time
    position.y -= paddleSpeed * deltaTime;
}

// Method to move the paddle down
void Paddle::moveDown(float deltaTime)
{
    // Increase the y-coordinate based on speed and time
    position.y += paddleSpeed * deltaTime;
}

// Method to update the paddle's position on the screen
void Paddle::update()
{
    // Set the new position of the paddle based on its updated coordinates
    paddleShape.setPosition(position);
}

// Method to return the type of paddle (left or right)
String Paddle::getPaddleType()
{
    // Returns the type of the paddle (for example, "left" or "right")
    return paddleType;
}
