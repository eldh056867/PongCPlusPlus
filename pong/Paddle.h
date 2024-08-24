#pragma once // Ensure the file is included only once during compilation
#include <SFML/Graphics.hpp> // Include the SFML graphics module
using namespace sf; // Use the SFML namespace

// Paddle class declaration
class Paddle
{
private:
	String paddleType;       // Stores the type of the paddle (left or right)
	Vector2f position;       // Stores the position of the paddle on the screen
	RectangleShape paddleShape; // The graphical shape of the paddle
	float paddleSpeed = .1f; // The speed at which the paddle moves

public:
	// Method to get the type of paddle (left or right)
	String getPaddleType();

	// Constructor to initialize the paddle with a starting position and type
	Paddle(float startX, float startY, String paddle_type);

	// Method to get the current position and size of the paddle as a FloatRect (for collision detection)
	FloatRect getPosition();

	// Method to get the graphical shape of the paddle
	RectangleShape getPaddleShape();

	// Method to move the paddle up
	void moveUp(float deltaTime);

	// Method to move the paddle down
	void moveDown(float deltaTime);

	// Method to update the paddle's position on the screen
	void update();
};
