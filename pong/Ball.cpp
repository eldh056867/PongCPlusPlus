#include "Ball.h"
using namespace sf;

Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	ballShape.setRadius(10.0f);
	ballShape.setPosition(position);
	xVelocity = -100.0f; // Initial horizontal velocity
	yVelocity = 100.0f;  // Initial vertical velocity

}

FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

CircleShape Ball::getBallShape()
{
	return ballShape;
}

void Ball::bounceLeftPaddle()
{
	xVelocity = -xVelocity; // Reverse x direction
	position.x += xVelocity * 0.1f; // Small padding to prevent sticking
}

void Ball::bounceRightPaddle()
{
	xVelocity = -xVelocity;
	position.x += xVelocity * 0.01f;
}

void Ball::bounceTop()
{
	yVelocity = -yVelocity; // Reverse y direction
	position.y = 0;
}

void Ball::bounceBottom()
{
	yVelocity = -1 * yVelocity;
	position.y = 800 - ballShape.getRadius() * 2;
}

void Ball::update(float deltaTime)
{
	position.y += yVelocity * deltaTime;
	position.x += xVelocity * deltaTime;
	ballShape.setPosition(position);
}








