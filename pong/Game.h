#include <SFML/Graphics.hpp>
#include "ball.h"
#include "Paddle.h"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>

using namespace sf;

class Game
{
public:
    // Main function to run the game
    void main();

private:
    // Dimensions of the game window
    int height = 800;   // Height of the game window
    int width = 900;    // Width of the game window

    // Score tracking for both sides
    int left_side_points = 0;  // Points for the left side
    int right_side_points = 0; // Points for the right side

    // Sound buffer for storing sound data
    SoundBuffer buffer;  // Buffer to hold the pong sound effect

    // Text objects to display scores on the screen
    Text left_side_score_text;  // Text object for the left side score
    Text right_side_score_text; // Text object for the right side score

    // Sound object to play pong sound effect
    Sound pong_beep;  // Sound object to play the beep sound during collisions

    // Flag to determine if a round is currently happening
    bool round_happening = true; // Boolean to track the state of the round

    // Texture for the background image
    Texture background;  // Texture to hold the background image
};
