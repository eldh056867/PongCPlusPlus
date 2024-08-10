#pragma once
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
class Ball
{
	private:
		CircleShape ballShape;
		Vector2f position;
		float xVelocity = 0.2f;
		float yVelocity = 0.2f;
		float ballSpeed = 10.0f;
	public:
		Ball(float startX, float startY);
		FloatRect getPosition();
		CircleShape getBallShape();
		void bounceLeftPaddle();
		void bounceRightPaddle();
		void bounceTop();
		void bounceBottom();
		void update(float deltaTime);
		



};