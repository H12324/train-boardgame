#pragma once
#include "Board.h"
#include "Player.h"
#include "Card.h"

#include <vector>

using namespace std;

class Game
{
private:
	std::vector<TrainCard> deck;
	std::vector<TrainCard> face; // Cards face-up in turn
	vector<DestinationCard> dests;
	Board gameBoard;
	vector<Player> players;
	bool gameOver;
	// Longest Route?

public:
	Game(int numPlayers);
	int calculate_score(); // Should probably be consistent about snake vs camel
	void player_turn(Player player);
	void run_game();
};