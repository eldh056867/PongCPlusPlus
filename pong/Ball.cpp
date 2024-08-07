#include "Ball.h"
using namespace sf;

Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	ballShape.setRadius(10.0f);
	ballShape.setPosition(position);

}

FloatRect Ball::getPosition()
{
	return ballShape.getLocalBounds();
}

CircleShape Ball::getBallShape()
{
	return ballShape;
}

void Ball::bounceLeftPaddle()
{
	xVelocity = 1*xVelocity;
	position.x += (yVelocity * 10); //Padding for preventing ball glitching into paddle
}

void Ball::bounceRightPaddle()
{
	xVelocity = -1 * xVelocity;
	position.x -= (yVelocity * 10);
}

void Ball::bounceTop()
{
	yVelocity = -1 * yVelocity;
	position.y -= (yVelocity * 10);
}

void Ball::bounceBottom()
{
	yVelocity = 1 * yVelocity;
	position.y += (yVelocity * 10);
}

void Ball::update(float deltaTime)
{
	position.y += yVelocity * deltaTime;
	position.x += xVelocity * deltaTime;
	ballShape.setPosition(position);
}

void Ball::serve()
{
	yVelocity = 5;
	xVelocity = 5;
}






