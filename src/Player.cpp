#include "Player.hpp"

Player::Player() {
	setBorders();
	speed = 8;
}

void Player::setPlayer(int xPos, int yPos) {

	player.setFillColor(sf::Color::White);
	player.setSize(sf::Vector2f(15, 70));
	player.setPosition(sf::Vector2f(xPos, yPos));

}

void Player::setBorders() {

	borderTop.setFillColor(sf::Color::Black);
	borderTop.setPosition(0, 10);
	borderTop.setSize(sf::Vector2f(800, 15));

	borderBot.setFillColor(sf::Color::Black);
	borderBot.setPosition(0, 575);
	borderBot.setSize(sf::Vector2f(800, 15));

}



void Player::moveUp() {
	player.move(sf::Vector2f(0, -speed));
	if (player.getGlobalBounds().intersects(borderTop.getGlobalBounds()) || player.getGlobalBounds().intersects(borderBot.getGlobalBounds())) {
		player.move(sf::Vector2f(0, speed));
	}
}

void Player::moveDown() {
	player.move(sf::Vector2f(0, speed));
	if (player.getGlobalBounds().intersects(borderTop.getGlobalBounds()) || player.getGlobalBounds().intersects(borderBot.getGlobalBounds())) {
		player.move(sf::Vector2f(0, -speed));
	}
}

void Player::render(sf::RenderWindow &window) {
	window.draw(player);
	window.draw(borderTop);
	window.draw(borderBot);
}