#include "Ball.hpp"

Ball::Ball() {
	ballSpeed = 10;
	angle = 75;
	score1 = 0;
	score2 = 0;
}

void Ball::setBall(int xPos, int yPos) {
	ball.setRadius(12);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(xPos, yPos);
}

void Ball::collison(sf::RenderWindow& window, Player& player1, Player& player2) {

	float xSpeed = std::cos(angle) * ballSpeed;
	float ySpeed = std::sin(angle) * ballSpeed;

	ball.move(xSpeed, ySpeed);

	if (ball.getGlobalBounds().intersects(player2.player.getGlobalBounds()) || ball.getGlobalBounds().intersects(player1.player.getGlobalBounds())) {
		ball.move(-xSpeed, ySpeed);
		ballSpeed = -ballSpeed;
		angle = -angle;
	}
	if (ball.getGlobalBounds().intersects(player1.borderTop.getGlobalBounds()) || ball.getGlobalBounds().intersects(player1.borderBot.getGlobalBounds())) {
		angle = -angle;
	}

	if (ball.getPosition().x < 0) {
		ball.setPosition(window.getSize().x / 2, window.getSize().y / 2);
		ballSpeed = -ballSpeed;
		score2 += 1;
		//std::cout << "P2 " << score2 << std::endl;
		
	}
	if (ball.getPosition().x > window.getSize().x) {
		ball.setPosition(window.getSize().x / 2, window.getSize().y / 2);
		ballSpeed = -ballSpeed;
		score1 += 1;
		//std::cout << "P1 " << score1 << std::endl;
	}
	


}


void Ball::render(sf::RenderWindow& window) {
	window.draw(ball);
}
