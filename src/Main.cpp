#include <iostream>

#include "Game.hpp"

int main() {

	
	Game game;

	while (game.isRunning()) {

		game.update();
		game.render();

	}




	return 0;
}