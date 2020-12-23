#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "Player.hpp"

class Ball {


public:


	sf::CircleShape ball;

	int ballSpeed;
	int angle;

	int score1;
	int score2;

	Ball();

	void setBall(int xPos, int yPos);


	void collison(sf::RenderWindow &window, Player &player1, Player &player2);


	void render(sf::RenderWindow& window);


};

