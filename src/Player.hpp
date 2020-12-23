#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player {

public:

	sf::RectangleShape player;

	sf::RectangleShape borderTop;
	sf::RectangleShape borderBot;

	int speed;

	Player();

	void setPlayer(int xPos, int yPos);

	void setBorders();

	void moveUp();
	void moveDown();

	void render(sf::RenderWindow &window);




};

