#include "Paddle.h"
using namespace sf;

Paddle::Paddle(float startX, float startY, String paddle_type)
{
	position.x = startX;
	position.y = startY;
	paddleType = paddle_type;
	paddleShape.setSize(Vector2f(5, 50));
	paddleShape.setPosition(position);
}

FloatRect Paddle::getPosition()
{
	return paddleShape.getLocalBounds();
}
RectangleShape Paddle::getPaddleShape()
{
	return paddleShape;
}
void Paddle::moveUp(float deltaTime)
{
	position.y++*paddleSpeed*deltaTime*paddleSpeed;
}
void Paddle::moveDown(float deltaTime)
{
	position.y--*paddleSpeed*deltaTime*paddleSpeed;
}
void Paddle::update()
{
	paddleShape.setPosition(position);
}
String Paddle::getPaddleType()
{
	return paddleType;
}