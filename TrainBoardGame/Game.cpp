#include "Game.h"

// Setup of game
Game::Game(int numPlayers)
{
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

	// Setup Destination Cards - player normally has choice, will forgo that for now and just give 2 or 3 
	dests = generateDests(gameBoard.cities);

	// Assign first player - will forgo for now maybe implement way later server-side
}
