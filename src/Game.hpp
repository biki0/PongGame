#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>

#include "Player.hpp"
#include "Ball.hpp"

class Game {

private:
	sf::RenderWindow window;
	sf::Event event;

	sf::Font font;
	sf::Text score1, score2;

	Player player1;
	Player player2;

	Ball ball;

	bool p1Won;
	bool p2Won;

	void initVar();
	void initWin();


public:

	Game();

	bool isRunning();

	void userInput();

	void setFont();
	void setScores();


	void update();
	void render();






};

