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
	vector<DestinationCard> dests;
	Board gameBoard;

public:
	void setupGame();
	int calculate_score(); // Should probably be consistent about snake vs camel
	void setup_board();
	void run_game();
	bool is_over();
};