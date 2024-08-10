#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Paddle
{
	
	private:
		String paddleType;
		Vector2f position;
		RectangleShape paddleShape;
		float paddleSpeed = .1f;
	public:
		String getPaddleType();
		Paddle(float startX, float startY, String paddle_type);
		FloatRect getPosition();
		RectangleShape getPaddleShape();
		void moveUp(float deltaTime);
		void moveDown(float deltaTime);
		void update();

};