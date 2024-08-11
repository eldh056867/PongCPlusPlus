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
	xVelocity = -xVelocity * 1.2; // Reverse x direction
	position.x += xVelocity * 0.1f; // Small padding to prevent sticking
}

void Ball::bounceRightPaddle()
{
	xVelocity = -xVelocity * 1.2;
	position.x += xVelocity * 0.01f;
}

void Ball::bounceTop()
{
	yVelocity = -yVelocity * 1.2; // Reverse y direction
	position.y = 0;
}

void Ball::bounceBottom()
{
	yVelocity = -1 * yVelocity * 1.2;
	position.y = 800 - ballShape.getRadius() * 2;
}

void Ball::update(float deltaTime)
{
	position.y += yVelocity * deltaTime;
	position.x += xVelocity * deltaTime;
	ballShape.setPosition(position);
}

void Ball::serve()
{
	xVelocity = 100.0f; // Initial horizontal velocity
	yVelocity = 100.0f;
	int number1 = rand() % 10 + 1;
	int number2 = rand() % 10 + 1;

	if (number1 % 2 == 0)
	{
		xVelocity = xVelocity * -1;
	}
	if (number1 % 2 == 0)
	{
		yVelocity = yVelocity * -1;
	}
	
}

void Ball::resetPos()
{
	position.x = (900 / 2)-10;
	position.y = 800 / 2;
	xVelocity = 0.0f; 
	yVelocity = 0.0f;
}








