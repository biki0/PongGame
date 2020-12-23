#include "Game.hpp"

Game::Game() {
	initVar();
	initWin();

	player1.setPlayer(20, 300);
	player2.setPlayer(760, 300);

	ball.setBall(window.getSize().x / 2, window.getSize().y / 2);
	setFont();
	setScores();
}

void Game::initVar() {

}


void Game::initWin() {
	window.create(sf::VideoMode(800, 600), "Pong");
	window.setFramerateLimit(60);
}


bool Game::isRunning() {
	return window.isOpen();
}

void Game::userInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		player1.moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		player1.moveDown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
		player2.moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
		player2.moveDown();
	}

}

void Game::setFont() {
	if (!font.loadFromFile("assets/old_school_united_regular.ttf")) { std::cout << "Error! not loaded" << std::endl; }
}

void Game::setScores() {
	score1.setFont(font);
	score2.setFont(font);

	score1.setFillColor(sf::Color::White);
	score1.setString(std::to_string(ball.score2));
	score1.setPosition(50, 50);

	score2.setFillColor(sf::Color::White);
	score2.setString(std::to_string(ball.score2));
	score2.setPosition(750, 50);

}




void Game::update() {

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}

	userInput();
	ball.collison(window,player1,player2);

	score1.setString(std::to_string(ball.score1));
	score2.setString(std::to_string(ball.score2));
	


}

void Game::render() {

	window.clear(sf::Color::Black);

	//draw here
	window.draw(score1);
	window.draw(score2);

	player1.render(window);
	player2.render(window);

	ball.render(window);

	window.display();

}