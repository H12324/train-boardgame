#include <iostream>
#include "Game.h"

int main() {
	std::cout << "Hello Game" << std::endl;
	auto game = new Game(1);
	game->run_game();
	return 0;
}