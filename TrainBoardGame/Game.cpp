#include "Game.h"
#include <iostream>
// Setup of game
Game::Game(int numPlayers)
{
	gameOver = false;
	
	// Setup Board
	gameBoard = Board(); 
	
	// Setup Players
	for (int i = 0; i < numPlayers; i++) { // Error handling for when players < 2 or > 5?
		players.push_back(Player(45)); // Everyone starts with 45 trains in this setup
		// Could be nice to add player names in here later	
	}

	// Setup Train Deck
	deck = generateTrains();
	// Setup front-view trains
	for (int i = 0; i < 5; i++) {
		face.push_back(deck.back());
		deck.pop_back();
	}
	// Should give players each some cards
	
	// Setup Destination Cards - player normally has choice, will forgo that for now and just give 2 or 3 
	dests = generateDests(gameBoard.cities);

	// Assign first player - will forgo for now maybe implement way later server-side
}

void Game::run_game() {
	while (!gameOver) {
		for (Player &player : players) { 
			player_turn(player);
		}
		gameOver = check_gameover(); // Move later to be more accurate
	}
	calculate_score();
	// Display score
}

void Game::player_turn(Player player) {
	// Eventually use timer for determining player action
	int action = player.chooseAction();
	// TODO: Add loop to aid selecting action 
	if (action == 1) {
		// Draw card from deck 
	}
	else if (action == 2) {
		// Draw card from front
	}
	else if (action == 3){
		// insert Claim route logic
	}
	else if (action == 4) {
		// new destination card logic
	}
	else {
		std::cout << "No Real Action Selected" << std::endl;
	}
}

bool Game::check_gameover() {
	// If player has 2 or less trains left
	// Do one final round and game is over
	return true;
}

int Game::calculate_score() {
	return 0;
}