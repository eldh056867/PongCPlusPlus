#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Paddle
{
	
	private:
		String paddletype;
		Vector2f position;
		RectangleShape paddleShape;
		float paddleSpeed = .3f;
	public:

		Paddle(float startX, float startY);
		FloatRect getPosition();
		RectangleShape getPaddleShape();
		void moveUp(float deltaTime);
		void moveDown(float deltaTime);
		void update();

};